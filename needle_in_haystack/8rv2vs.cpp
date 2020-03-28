#include <iostream>
#include <vector>
using namespace std;
int mod = 1000000007;
int l = 26;
char a = 'a';
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
void push_back(long long &seed, int c){
	seed = (26*seed + c%l)%mod;
}
void pop_front(long long &seed, int c, long long x){
	x *= c%l;
	x = mod - x%mod;
	seed = (seed+x)%mod;
}

vector<int> match(const string &s, const string &w){
	vector<int> p;
	
	int n = w.size();
	if(!n)	return p;
	
	int h_minus = exp(l,n-1);
	
	long long h = 0;
	for(char c: w)	push_back(h,c-a);
	cout<<"Hash value of the word: "<<h<<endl;
	
	if(s.size()<n)	return p;
	int i=0;
	long long x=0;
	while(i<n)	push_back(x,s[i++]-a);
	if(h==x)	p.push_back(i-n);
	
	while(i<s.size()){
		pop_front(x,s[i-n]-a,h_minus);
		push_back(x,s[i++]-a);
		if(h==x)	p.push_back(i-n);
	}
	return p;
}
int main() {
	string s;
	string w;
	cin>>s>>w;
	vector<int> ans = match(s,w);
	cout<<"The given word is matched in the string at following positions:"<<endl;
	for(int x: ans)	cout<<x<<' ';
	cout<<endl;
	cout<<s<<endl;
	int j=0;
	for(int i=0; i<s.size()&&j<ans.size(); i++){
		if(i==ans[j]&&++j)	cout<<'^';
		else	cout<<' ';
	}
	cout<<endl;
	return 0;
}
