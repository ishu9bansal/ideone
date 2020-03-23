#include <iostream>
#include <vector>
using namespace std;
vector<int> table(const string &w){
	int n = w.size();
	vector<int> t(n+1,-1);
	int c = 0;
	int p = 1;
	while(p<n){
		if(w[p]==w[c])	t[p] = t[c];
		else{
			t[p] = c;
			c = t[c];
			while(c>=0&&w[p]!=w[c])
				c = t[c];
		}
		p++;	c++;
	}
	t[p] = c;
	return t;
}
vector<int> match(const string &s, const string &w){
	vector<int> t = table(w);
	cout<<"Table values of the word:"<<endl;
	for(int i=0; i<w.size(); i++)	cout<<w[i]<<'\t';
	cout<<endl;
	for(int i=0; i<t.size(); i++)	cout<<t[i]<<'\t';
	cout<<endl<<endl;
	int n = s.size();
	int j = 0;
	int k = 0;
	vector<int> p;
	while(j<n){
		if(w[k]==s[j]){
			j++;	k++;
			if(k==w.size()){
				p.push_back(j-k);
				k = t[k];
			}
		}
		else{
			k = t[k];
			if(k<0){
				j++; k++;
			}
		}
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
