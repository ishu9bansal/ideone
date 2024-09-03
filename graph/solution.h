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
    return fImpl(v, new DijkstraSubRoutine());
}
