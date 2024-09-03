#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <vector>

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
    unordered_map<int,unordered_map<int,int> > normalizedAdjacencyMatrix(unordered_map<int,int> &normalizingWeights) const {
        unordered_map<int,unordered_map<int,int> > mat; // this'll be copy of the adjacency list itself
        for(auto &h: adjacencyList){
            for(auto &p: h.second){
                mat[h.first][p.first] = p.second + normalizingWeights[h.first] - normalizingWeights[p.first];
            }
        }
        return mat;
    }
    unordered_map<int, int> dijkstraImpl(int s, unordered_map<int,int> normalizingWeights) const {
        unordered_map<int,unordered_map<int,int> > mat = normalizedAdjacencyMatrix(normalizingWeights);
        unordered_map<int, int> dist;
        priority_queue<pair<int,int> > q;
        q.push(make_pair(0,s));
        pair<int,int> p;
        int x,y, d, w;
        while(dist.size()<vertices.size()){
            while(q.size() && dist.find(q.top().second)!=dist.end()){
                q.pop();
            }
            if(q.empty())   break;
            p = q.top();
            q.pop();
            x = p.second;
            d = -p.first;   // reverse negation
            dist[x] = d;
            for(auto edge: mat[x]){
                y = edge.first;
                if(dist.find(y)!=dist.end())    continue;
                w = -d-edge.second; // negation for min instead of max in priority queue
                q.push(make_pair(w,y));
            }
        }
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
    unordered_map<int, int>  minimumDistanceFromOuterSource() const {
        Graph g(true, INF);
        for(auto &h: adjacencyList){
            for(auto &p: h.second){
                g.addEdge(h.first, p.first, p.second);
            }
        }
        for(int x: vertices){
            g.addEdge(V,x,0);
        }
        return g.bellmanFordImpl(V);
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

    vector<int> dijkstra(int s) const {
        // Note: this has become the Johnson's algo due to normalization step addition
        unordered_map<int, int> normalizingWeights = minimumDistanceFromOuterSource();
        unordered_map<int, int> dist = dijkstraImpl(s, normalizingWeights);
        return serialize(dist, INF);
    }
};
