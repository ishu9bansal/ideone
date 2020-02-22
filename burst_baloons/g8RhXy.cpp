#include <iostream>
#include <vector>
using namespace std;
int f(const vector<int> &v, vector<vector<int>> &dp, int i, int j){
	if(dp[i][j]!=-1)	return dp[i][j];
	int l = 1;
	int r = 1;
	if(i)	l = v[i-1];
	if(j<v.size())	r = v[j];
	int ans = 0;	// ans = 0 when i==j
	for(int k=i; k<j; k++){
		int x = f(v,dp,i,k) + l*v[k]*r + f(v,dp,k+1,j);
		if(ans<x)	ans = x;
	}
	return dp[i][j] = ans;
}
int f(const vector<int> &v){
	int n = v.size();
	vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
	return f(v,dp,0,n);
}
int main() {
	int t,n,x;
	vector<int> v;
	cin>>t;
	while(t--){
		cin>>n;
		v.clear();
		while(n--&&cin>>x)	v.push_back(x);
		cout<<f(v)<<endl;
	}
	return 0;
}
