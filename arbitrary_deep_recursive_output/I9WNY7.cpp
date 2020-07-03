#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> v;
inline int f(int x){
    return ((x^(x<<2))>>1)&((1<<7)-2);
}
void precompute(){
	vector<int> temp(1<<8,0);
	for(int j=0; j<32; j++){
	    for(int i=0; i<temp.size(); i++)
	        temp[i] = j?v.back()[v.back()[i]]:f(i);
	    v.push_back(temp);
	}
}
int iterative(int x, int n){
	while(n--)
		x = v[0][x];
	return x;
}
int nth_transform(int x, int n){
	for(int i=0; i<32; i++)
		if(n&(1<<i))
			x = v[i][x];
	return x;
}
int main() {
	if(v.empty())
		precompute();
	int n,x;
	cin>>n>>x;
	x %= 256;	// f is designed to handle only finite (256) values.
	if(!x)	x = 256;
	for(int i=0; i<n; i++)
		for(int j=0; j<x; j++)
			if(iterative(j,i)!=nth_transform(j,i))
				cout<<"mismatch for x = "<<x<<" n = "<<n<<endl;
	cout<<"check executed successfully"<<endl;
	return 0;
}
