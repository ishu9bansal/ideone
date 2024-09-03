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
    unordered_map<int,unordered_map<int,long long> > adjacencyList;
    unordered_set<int> vertices;
    bool isDirected;
    int V;
    int addEdgeWeights(int a, int b) {
        if(a>=INF)  return INF;
        if(b>=INF)  return INF;
        return a+b;
    }
    void floydWarshallImpl(vector<vector<int> > &v) {
        int n = v.size();
        for(int k=0; k<n; k++){
            for(int j=0; j<n; j++){
                for(int i=0; i<n; i++){
                    v[i][j] = min(v[i][j], addEdgeWeights(v[i][k],v[k][j]));
                }
            }
        }
    }
    bool bellmanFordSubRoutine(unordered_map<int, int> &dist) {
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
    unordered_map<int, int> bellmanFordImpl(int s) {
        unordered_map<int, int> dist;   // undefined is assumed to be INFINTIY
        dist[s] = 0;    // distance of the starting node will be zero
        int n = vertices.size();
        n--;    // n-1 subroutines will correctly find all the distances
        while(n--)
            if(!bellmanFordSubRoutine(dist))
                break;
        return dist;
    }
    vector<int> serialize(const unordered_map<int, int> &h, int inf) {
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
    vector<vector<int> > serialize(const unordered_map<int,unordered_map<int,int> > &h, int inf) {
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
    vector<vector<int> > adjacencyMatrix() {
        // assuming that no vertices are skipped when this method is triggered
        // i.e., V == vertices.size() is true
        if(V!=vertices.size()) {
            cout<<"Warning: Adjacency matrix called before all the vertices are introduced"<<endl;
        }

        // assuming no self loops and no multiple edges for the same pair of vertices
        // assuming V is sufficiently small to form an adjacency matrix

        vector<vector<int> > v(V, vector<int>(V, INF));

        for(int i=0; i<V; i++){
            v[i][i] = 0;    // assuming distace to self is zero
            // TODO: Implement self loops support
            // this value needs to be the weight of the self loop
        }

        int i,j;
        for(auto &h: adjacencyList){
            i = h.first;
            for(auto &p: h.second){
                j = p.first;
                v[i][j] = p.second;
            }
        }
        // TODO: Implement multi edge support
        // change the adjacency list to have a list of distances
        // and the matrix will be something like least weight matrix

        return v;
    }

    vector<vector<int> > floydWarshall() {
        vector<vector<int> > v = adjacencyMatrix();
        floydWarshallImpl(v);
        return v;
    }

    vector<int> bellmanFord(int s) {
        unordered_map<int, int> dist = bellmanFordImpl(s);
        return serialize(dist, INF);
    }

    vector<int> bellmanFord(int s, bool &hasNegativeCycle) {
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

vector<int> f(vector<vector<int> > &v) {
    int n = 1+v.size();
    Graph graph = new Graph(true, 1000000); // assuming INFINITY = 10^6
    for(auto p: v){
        graph.addEdge(p[0],p[1],2 - (p[1]%2));
        graph.addEdge(p[1],p[0],2 - (p[0]%2));
    }
    
    vector<int> ans(n,0);
    vector<int> temp;
    for(int i=0; i<n; i++){
        temp = graph.bellmanFord(i);
        for(int x: temp){
            ans[i] = max(ans[i], x);
        }
    }
    return ans;
}

void printVec(const vector<int> &v) {
    for(int x: v){
        cout<<x<<'\t';
    }
    cout<<endl;
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