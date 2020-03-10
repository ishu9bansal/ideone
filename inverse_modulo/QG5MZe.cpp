#include <iostream>
using namespace std;
int mod = 1000000007;
long long exp(int b, int e){
	long long a = 1;
	long long x = b;
	while(e){
		if(e%2)	a = (a*x)%mod;
		x = (x*x)%mod;
		e = e/2;
	}
	return a;
}
long long inv(int n){
	return exp(n,mod-2);
}
int main() {
	cout<<inv(12);
	return 0;
}
