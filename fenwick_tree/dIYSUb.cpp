#include <iostream>
#include <unordered_map>
#include <map>
#include <climits>
using namespace std;
template <class T>
class FenwickTree{
private:
    unordered_map<long long, T> v;
    long long ma;
    long long mi;
public:
    FenwickTree(int max = INT_MAX, int min = 1) : ma(max), mi(min-1L) {}
    void set(long long i, T d){
        if(i<=mi||i>ma) throw "bad_allocation";
        i -= mi;
        while(i<=ma-mi){
            v[i] += d;
            i += i&-i;
        }
    }
    T get(long long i){
        if(i<=mi)   return 0;
        if(i>ma)    i = ma;
        i -= mi;
        T x = NULL;
        while(i){
            x += v[i];
            i -= i&-i;
        }
        return x;
    }
};
class PrefixSum{
private:
    map<int, int> v;
public:
    void set(int i, int d){
    	v[i] += d;
    }
    int get(int i){
    	int x = 0;
    	for(auto p: v)
    		if(p.first>i)	break;
    		else	x += p.second;
    	return x;
    }
};
int main() {
	int n,q,p;
	cin>>n>>q>>p;
	p %= 101;	// p: should be a percentage
	FenwickTree<int> ft(n,1);
	PrefixSum ps;
	int i,d;
	while(q--){
		i = 1+rand()%n;
		d = rand()%100;
		if(d<p){
			if(ft.get(i)!=ps.get(i))
				cout<<"Mismatch at i = "<<i<<" q = "<<q<<endl;
		}
		else{
			d = rand()%100;
			ft.set(i,d);
			ps.set(i,d);
		}
	}
	if(ft.get(n)!=ps.get(n))
		cout<<"Final query mismatch"<<endl;
	else
		cout<<"Comparison finished"<<endl;
	return 0;
}
