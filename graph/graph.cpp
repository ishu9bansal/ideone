#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <vector>
#include <fstream>
using namespace std;

class Graph{
private:
    long long INF;
    // TODO: relax this constraint of int nodes
    // Let the graph itself store the vertex properties
    // TODO: extend the distance to use any data type and a custom distance function
    unordered_map<int,unordered_map<int,int> > adjacencyList;
    unordered_set<int> vertices;
    bool isDirected;
    int V;
    void floydWarshallImpl(unordered_map<int,unordered_map<int,int> > &mat) const {
        int n = vertices.size();
        int d;
        for(int k: vertices){
            for(int j: vertices){
                for(int i: vertices){
                    if(mat[i].find(k)!=mat[i].end() && mat[k].find(j)!=mat[k].end()){
                        d = mat[i][k] + mat[k][j];
                        if(mat[i].find(j)==mat[i].end() || mat[i][j] > d){
                            mat[i][j] = d;
                        }
                    }
                    
                }
            }
        }
    }
    bool bellmanFordSubRoutine(unordered_map<int, int> &dist) const {
        bool changeHappened = false;
        int i, j, d;
        for(auto &h: adjacencyList){
            i = h.first;
            for(auto &p: h.second){
                j = p.first;
                if(dist.find(i)!=dist.end()){
                    d = dist[i] + p.second;
                    if (dist.find(j)==dist.end() || dist[j] > d){
                        dist[j] = d;
                        changeHappened = true;
                    }
                }
            }
        }
        return changeHappened;
    }
    unordered_map<int, int> bellmanFordImpl(int s) const {
        unordered_map<int, int> dist;   // undefined is assumed to be INFINTIY
        dist[s] = 0;    // distance of the starting node will be zero
        int n = vertices.size();
        n--;    // n-1 subroutines will correctly find all the distances
        while(n--)
            if(!bellmanFordSubRoutine(dist))
                break;
        return dist;
    }
    unordered_map<int,unordered_map<int,int> > adjacencyMatrixImpl(int selfAdj) const {
        unordered_map<int,unordered_map<int,int> > mat; // this'll be copy of the adjacency list itself
        for(auto &h: adjacencyList){
            for(auto &p: h.second){
                mat[h.first][p.first] = p.second;
            }
        }
        // TODO: Implement multi edge support
        // change the adjacency list to have a list of distances
        // and the matrix will be something like least weight matrix

        for(int i=0; i<V; i++){
            mat[i][i] = selfAdj;
            // TODO: Implement self loops support
            // this value needs to be the weight of the self loop
        }
        return mat;
    }
    vector<int> serialize(const unordered_map<int, int> &h, int inf) const {
        // assuming that no vertices are skipped when this method is triggered
        // i.e., V == vertices.size() is true
        if(V!=vertices.size()) {
            cout<<"Warning: Adjacency matrix called before all the vertices are introduced"<<endl;
        }

        vector<int> v(V, inf);
        for(auto &p: h){
            v[p.first] = p.second;
        }
        return v;
    }
    vector<vector<int> > serialize(const unordered_map<int,unordered_map<int,int> > &h, int inf) const {
        // assuming that no vertices are skipped when this method is triggered
        // i.e., V == vertices.size() is true
        if(V!=vertices.size()) {
            cout<<"Warning: Adjacency matrix called before all the vertices are introduced"<<endl;
        }

        vector<vector<int> > v(V);
        for(auto &p: h){
            v[p.first] = serialize(p.second, inf);
        }
        return v;
    }
public:
    Graph(bool directedGraph = false, int infinity = INT_MAX) : isDirected(directedGraph), INF(infinity), V(0) {}
    void addEdge(int from, int to, int weight) {
        // record vertices
        vertices.insert(from);
        vertices.insert(to);

        // update the max vertex id
        V = max(V,from+1);
        V = max(V,to+1);

        // add weighted edge to adjacency list
        adjacencyList[from][to] = weight;

        if(!isDirected){
            // if undirected graph, add the other direction as well
            adjacencyList[to][from] = weight;
        }
    }
    vector<vector<int> > adjacencyMatrix(int selfAdjacencyDistance = 0) {
        unordered_map<int,unordered_map<int,int> > mat = adjacencyMatrixImpl(selfAdjacencyDistance);
        return serialize(mat, INF);
    }

    vector<vector<int> > floydWarshall() const {
        unordered_map<int,unordered_map<int,int> > mat = adjacencyMatrixImpl(0);
        floydWarshallImpl(mat);
        return serialize(mat,INF);
    }

    vector<int> bellmanFord(int s) const {
        unordered_map<int, int> dist = bellmanFordImpl(s);
        return serialize(dist, INF);
    }

    vector<int> bellmanFord(int s, bool &hasNegativeCycle) const {
        unordered_map<int, int> dist = bellmanFordImpl(s);
        hasNegativeCycle = bellmanFordSubRoutine(dist);
        return serialize(dist, INF);
    }
};

void printMat(const vector<vector<int> > &v) {
    int n = v.size();
    cout<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<v[i][j]<<'\t';
        }
        cout<<endl;
    }
    cout<<endl;
}

void printVec(const vector<int> &v) {
    for(int x: v){
        cout<<x<<'\t';
    }
    cout<<endl;
}

class SolutionSubRoutine {
public:
    virtual void precompute(const Graph &graph) {
        // do nothing
    }
    virtual vector<int> ditancesFromSource(int source, const Graph &graph) {
        return vector<int>();
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
    return fImpl(v, new FloyedWarshallSubRoutine());
}


template <class T>
T inputImpl(ifstream &fs, T*){
    T x;
    fs>>x;
    return x;
}

template <class X>
vector<X> inputImpl(ifstream &fs, vector<X> *){
    int n;
    fs>>n;
    vector<X> v;
    while(n--){
        v.push_back(inputImpl(fs, static_cast<X*>(0)));
    }
    return v;
}

template <class T>
T input(ifstream &fs){
    return inputImpl(fs, static_cast<T*>(0));
}

int main(int argc, char* argv[]) {
    string relativePath = "";
    if(argc>1){
        relativePath = argv[1];
    }
    string inputFilePath = relativePath + "/input.in";
    ifstream inputFile;
    inputFile.open(inputFilePath);  // relative to the build location
    vector<vector<vector<int> > > inputs = input<vector<vector<vector<int> > > >(inputFile);
    vector<int> output;
    for(auto &v: inputs){
        output = f(v);
        printVec(output);
    }
    return 0;
}

// implement pending methods, bellmon-ford, dijkstras, johnsons etc.
// run it for the leetcode question
// improve the INF handling by using unordered_map instead of vector