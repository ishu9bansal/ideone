#include <vector>

using namespace std;

#include "graph.h"

template <class V, class T>
class MaxN {
private:
    vector<pair<V,T> > h;
    int N;
    pair<V,T> defaultPair;
public:
    MaxN(int n = 2, V defaultValue = 0, T defaultNode = -1): N(n) {
        defaultPair = make_pair(defaultValue, defaultNode);
    }
    void push(V value, T node) {
        pair<V,T> p = make_pair(value, node);
        for(auto &x: h){
            if(p>x) swap(x,p);
        }
        if(h.size()<N)  h.push_back(p);
    }
    pair<V,T> get(int i){
        if(i<0 || i>=h.size())  return defaultPair;
        return h[i];
    }
};

class SolutionSubRoutine {
public:
    virtual void precompute(const Graph &graph) {
        // do nothing
    }
    virtual vector<int> ditancesFromSource(int source, const Graph &graph) {
        return vector<int>();
    }
};

class TreeRoutine: public SolutionSubRoutine {
private:
    unordered_map<int,int> v;
    void dfs(int i, unordered_map<int, unordered_set<int> > &tree, unordered_map<int, MaxN<int,int> > &dp){
        if(dp.find(i)!=dp.end())    return;
        dp[i] = MaxN<int,int>(2,0,-1);
        int d;
        for(int x: tree[i]){
            dfs(x,tree,dp);
            d = dp[x].get(0).first + 2 - (x%2);
            dp[i].push(d, x);
        }
    }
    void dfs(int i, int p, unordered_map<int, unordered_set<int> > &tree, unordered_map<int, MaxN<int,int> > &dp) {
        int d;
        if(p!=-1){
            d = (dp[p].get(0).second == i) ? 1 : 0;
            d = dp[p].get(d).first + 2 - (p%2);
            dp[i].push(d,p);
        }
        for(int x: tree[i]){
            dfs(x,i,tree,dp);
        }
    }

    bool makeTree(int i, unordered_map<int, unordered_set<int> > &tree, unordered_map<int,unordered_map<int,int> > &mat){
        if(tree.find(i)!=tree.end())    return false;
        tree[i] = unordered_set<int>();
        for(pair<int, int> p: mat[i]) {
            if(makeTree(p.first,tree,mat))
                tree[i].insert(p.first);
        }
        return true;
    }

public:
    TreeRoutine() {}
    void precompute(const Graph &graph) override {
        unordered_map<int,int> dummy;
        unordered_map<int, unordered_set<int> > tree = graph.makeDfsTreeFromRoot(0);
        unordered_map<int, MaxN<int,int> > dp;
        dfs(0, tree, dp);
        dfs(0,-1,tree,dp);
        for(auto p: dp){
            v[p.first] = p.second.get(0).first;
        }
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
    return fImpl(v, new TreeRoutine());
}
