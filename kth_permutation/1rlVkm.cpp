#include <iostream>
using namespace std;
void f(string &s, long long k){
	int N = s.size();
	int n = 0;
	long long fac = 1;
	while(n<N&&fac<=k)
		fac *= ++n;
	while(k){
		fac /= n--;
		// worst case maximum num of swaps = 19*20/2 = 190
		for(int j=0; j<k/fac; j++)
			swap(s[N-n-1],s[N-n+j]);
		k %= fac;
	}
}
int main() {
	int t;
	long long k;
	string s;
	cin>>t;
	while(t--){
		cin>>s>>k;	// to avoid long long overflow, keep k < 20!
		f(s,k);
		cout<<s<<endl;
	}
	return 0;
}
