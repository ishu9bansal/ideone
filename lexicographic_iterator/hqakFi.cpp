#include <iostream>
using namespace std;
void f(int i, string &s, int &k, bool virgin=true){
	if(k<=0)	return;
	if(!i){
		cout<<s<<endl;
		k--;
		return;
	}
	char &x = s[s.size()-i];
	for(char c='a'; c<'d'; c++){
		if(virgin&&c<x)	continue;
		x = c;
		f(i-1,s,k,virgin);
		virgin = false;
	}
}
int main() {
	int t,n,k;
	string s;
	cin>>t;
	while(t--){
		cin>>s>>k;
		n = s.size();
		cout<<"n: "<<n<<endl;
		f(n,s,k);
	}
	return 0;
}
