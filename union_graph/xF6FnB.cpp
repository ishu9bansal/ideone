#include <iostream>
#include <unordered_map>
using namespace std;
class Union{
private:
    unordered_map<int,int> h;
public:
    unordered_map<int,int> mapping(){
        return h;
    }
    int get(int i){
        if(h.find(i)==h.end())  h[i] = i;
        int p = h[i];
        while(p!=h[p]) p = h[p];
        int t = h[i];
        while(t!=i){
            h[i] = p;
            i = t;
            t = h[i];
        }
        return p;
    }
    void set(int i, int p){
        i = get(i);
        p = get(p);
        if(p>i) swap(i,p);
        h[i] = p;
    }
};
int main() {
	// your code goes here
	return 0;
}
