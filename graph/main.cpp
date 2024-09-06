#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

#include "solution.h"

void printMat(const vector<vector<int> > &v, ostream &os = cout) {
    int n = v.size();
    os<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            os<<v[i][j]<<'\t';
        }
        os<<endl;
    }
    os<<endl;
}

void printVec(const vector<int> &v, ostream &os = cout) {
    for(int x: v){
        os<<x<<'\t';
    }
    os<<endl;
}

template <class T>
T inputImpl(istream &is, T*){
    T x;
    is>>x;
    return x;
}

template <class X>
vector<X> inputImpl(istream &is, vector<X> *){
    int n;
    is>>n;
    vector<X> v;
    while(n--){
        v.push_back(inputImpl(is, static_cast<X*>(0)));
    }
    return v;
}

template <class T>
T input(istream &is = cin){
    return inputImpl(is, static_cast<T*>(0));
}

int main(int argc, char* argv[]) {
    string relativePath = "";
    if(argc>1){
        relativePath = argv[1];
    }
    string inputFilePath = relativePath + "/input.in";
    string outputFilePath = relativePath + "/output.out";
    ifstream inputFile;
    ofstream outputFile;

    inputFile.open(inputFilePath);
    vector<vector<vector<int> > > inputs = input<vector<vector<vector<int> > > >(inputFile);
    inputFile.close();

    outputFile.open(outputFilePath);
    vector<int> output;
    for(auto &v: inputs){
        output = f(v);
        printVec(output, outputFile);
    }
    outputFile.close();
    return 0;
}
