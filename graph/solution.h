#include <vector>

using namespace std;

#include "graph.h"

class SolutionSubRoutine {
public:
    virtual void precompute(const Graph &graph) {
        // do nothing
    }
    virtual vector<int> ditancesFromSource(int source, const Graph &graph) {
        return vector<int>();
    }
};

class MSPSubRoutine: public SolutionSubRoutine {
private:
    unordered_map<int,int> v;
    int f(Tree* node, unordered_map<int,int> &dist, unordered_map<int,int> &revDist) {
        int x = node->vertex;
        int y, d;
        unordered_map<int, unordered_map<int,int> > revDistMap;
        int m1 = 0; // this value of initialization i.e. zero is important
        int m2 = 0;
        int maxChildNode = -1;
        for(Tree* child: node->children){
            unordered_map<int,int> temp;
            y = child->vertex;
            d = f(child, dist, temp) + 2 - (y%2);
            revDistMap[y] = temp;
            if(d>m1){
                swap(m1, d);
                maxChildNode = y;
            }
            if(d>m2)    m2 = d;
        }
        for(Tree* child: node->children){
            y = child->vertex;
            d = m1;
            if(y==maxChildNode) d = m2;
            for(auto p: revDistMap[y]){
                revDist[p.first] = p.second + 2 - (x%2);
                if(revDist[p.first]+d>dist[p.first]){
                    dist[p.first] = revDist[p.first] + d;
                }
            }
        }
        revDist[x] = 0;
        return m1;
    }
    void setMaxDistances(Tree* tree) {
        unordered_map<int,int> dist, revDist;
        f(tree, dist, revDist);
        v = dist;
    }
public:
    MSPSubRoutine() {}
    void precompute(const Graph &graph) override {
        Tree* tree = graph.minimumSpanningTree();
        setMaxDistances(tree);
    }
    vector<int> ditancesFromSource(int source, const Graph &graph) override {
        return vector<int>(1,v[source]);
    }
};

class DijkstraSubRoutine: public SolutionSubRoutine {
public:
    DijkstraSubRoutine() {}
    vector<int> ditancesFromSource(int source, const Graph &graph) override {
        return graph.dijkstra(source);
    }
};

class BellmanFordSubRoutine: public SolutionSubRoutine {
public:
    BellmanFordSubRoutine() {}
    vector<int> ditancesFromSource(int source, const Graph &graph) override {
        return graph.bellmanFord(source);
    }
};

class JohnsonSubRoutine: public SolutionSubRoutine {
private:
    vector<vector<int> > v;
public:
    JohnsonSubRoutine() {}
    void precompute(const Graph &graph) override {
        v = graph.johnson();
    }
    vector<int> ditancesFromSource(int source, const Graph &graph) override {
        return v[source];
    }
};

class FloyedWarshallSubRoutine: public SolutionSubRoutine {
private:
    vector<vector<int> > v;
public:
    FloyedWarshallSubRoutine() {}
    void precompute(const Graph &graph) override {
        v = graph.floydWarshall();
    }
    vector<int> ditancesFromSource(int source, const Graph &graph) override {
        return v[source];
    }
};

vector<int> fImpl(vector<vector<int> > &v, SolutionSubRoutine *routine) {
    int n = 1+v.size();
    Graph graph = new Graph(true, 1000000); // assuming INFINITY = 10^6
    for(auto p: v){
        graph.addEdge(p[0],p[1],2 - (p[1]%2));
        graph.addEdge(p[1],p[0],2 - (p[0]%2));
    }
    routine->precompute(graph);
    
    vector<int> ans(n,0);
    vector<int> temp;
    for(int i=0; i<n; i++){
        temp = routine->ditancesFromSource(i, graph);
        for(int x: temp){
            ans[i] = max(ans[i], x);
        }
    }
    return ans;
}

vector<int> f(vector<vector<int> > &v) {
    // return fImpl(v, new BellmanFordSubRoutine());
    // return fImpl(v, new FloyedWarshallSubRoutine());
    // return fImpl(v, new DijkstraSubRoutine());
    // return fImpl(v, new JohnsonSubRoutine());
    return fImpl(v, new MSPSubRoutine());
}
