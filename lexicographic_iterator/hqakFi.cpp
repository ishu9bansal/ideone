#include <iostream>
using namespace std;
void f(int i, string &s){
	if(!i){
		cout<<s<<endl;
		return;
	}
	for(char c='a'; c<'d'; c++){
		s[s.size()-i] = c;
		f(i-1,s);
	}
}
int main() {
	int t,n;
	string s;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<"n: "<<n<<endl;
		s = string(n,'a');
		f(n,s);
	}
	return 0;
}
