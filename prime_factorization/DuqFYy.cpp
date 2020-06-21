#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;
int N=65537;
vector<bool> a(N,false);
vector<int> prime;

string getPrint(const vector<vector<int>> &v){
	string s;
	stringstream ss;
	for(int i=0; i<v[0].size(); i++){
		if(i)	ss<<'*';
		if(v[1][i]==1)	ss<<v[0][i];
		else	ss<<'('<<v[0][i]<<'^'<<v[1][i]<<')';
	}
	ss>>s;
	return s;
}

vector<vector<int>> primeFactorization(unsigned int n){
	vector<vector<int>> v(2,vector<int>());
	int i=0;
	int c=0;
	int l=prime.size();
	int p;
	while(n>1){
		while(i<l&&prime[i]<=sqrt(n)&&n%prime[i])	i++;
		if(i==l||prime[i]>sqrt(n))	p = n;
		else	p = prime[i];
		v[0].push_back(p);
		c=0;
		while(n%p==0){
			n /= p;
			c++;
		}
		v[1].push_back(c);
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
