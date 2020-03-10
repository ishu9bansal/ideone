#include <iostream>
#include <vector>
using namespace std;
pair<int,int> dir(int d){
	d %= 4;
	return make_pair(d/2?d%2*2-1:0,d/2?0:d%2*2-1);
}
int main() {
	vector<string> v = {"left","right","up","down"};
	cout<<"i\tj"<<endl;
	for(int i=0; i<4; i++)
		cout<<dir(i).first<<'\t'<<dir(i).second<<"\td:"<<i<<'\t'<<v[i]<<endl;
	
	// second approach
	vector<int> dirs={0,1,0,-1,0};
	v = {"right","down","left","up"};
	cout<<endl<<"i\tj"<<endl;
	for(int i=0; i<4; i++)
		cout<<dirs[i]<<'\t'<<dirs[i+1]<<"\td:"<<i<<'\t'<<v[i]<<endl;
		
	return 0;
}
