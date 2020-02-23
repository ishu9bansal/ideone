#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void f(int i, vector<int> &v, vector<int> &ans){
	while(i<v.size()){
		for(int x: ans)	cout<<x<<'\t';
		cout<<v[i]<<endl;
		ans.push_back(v[i]);
		f(++i, v, ans);
		ans.pop_back();
	}
}
int main() {
	int n,x;
	vector<int> v;
	cin>>n;
	while(n--&&cin>>x)	v.push_back(x);
	sort(v.begin(),v.end());
	vector<int> rec_temp;
	f(0,v,rec_temp);	//	recursive approach
	return 0;
	// iterative approach
	vector<vector<int>> ans;
	vector<int> temp;
	n = v.size();
	for(int i=n-1; i>=0; i--){
		x = ans.size();
		for(int j=0; j<x; j++){
			temp = vector<int>(1,v[i]);	//	array containing single element v[i]
			temp.insert(temp.end(),ans[j].begin(),ans[j].end());
			ans.push_back(temp);
		}
		temp = vector<int>(1,v[i]);
		ans.push_back(temp);
	}
	ans.push_back(vector<int>(0));
	x = ans.size();
	for(int i=x-1; i>=0; i--){
		for(int j=0; j<ans[i].size(); j++)	cout<<ans[i][j]<<'\t';
		cout<<endl;
	}
	return 0;
}
