#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;
int N=65537;
vector<bool> a(N,false);
vector<int> prime;

string getPrint(const map<int,int> &v){
	string s;
	stringstream ss;
	for(auto p: v)
		if(p.second==1)	ss<<p.first<<'*';
		else	ss<<'('<<p.first<<'^'<<p.second<<')'<<'*';
	ss>>s;
	s.pop_back();
	return s;
}

map<int,int> primeFactorization(unsigned int n){
	map<int,int> v;
	int i=0;
	int c=0;
	int l=prime.size();
	int p;
	int s = sqrt(n);
	while(n>1){
		while(i<l&&prime[i]<=s&&n%prime[i])	i++;
		if(i==l||prime[i]>s)	p = n;
		else	p = prime[i];
		c=0;
		while(n%p==0){
			n /= p;
			c++;
		}
		v[p] = c;
		s = sqrt(n);
	}
	return v;
}

void initializePrimes(){
	int m, n=N;
	a[0]=a[1]=true;
	for(int i=0; i<=sqrt(n); i++){
		if(a[i])	continue;
		prime.push_back(i);
		m = i*i;
		while(m<n){
			a[m]=true;
			m += i;
		}
	}
	for(int i=sqrt(n); i<n; i++)
		if(!a[i])	prime.push_back(i);
	
	cout<<"Prime size is "<<prime.size()<<endl;
}

int main() {
	initializePrimes();
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<n<<" = "<<getPrint(primeFactorization(n))<<endl;
	}
	return 0;
}
