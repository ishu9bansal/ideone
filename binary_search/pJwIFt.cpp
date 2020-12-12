#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &a, int k, bool strict = false){
	// if strict is false, returns first index of a, greater than or equal to k
	// if strict is true, returns first index of a, strctly greater than k
	int l = 0;
	int r = a.size();
	int m = (l+r)/2;
	while(l<r){
		if(strict?a[m]<=k:a[m]<k)	l = m+1;
		else	r = m;
		m = (l+r)/2;
	}
	return m;
}

int main() {
	vector<int> a = {1,1,3,3,3,3,4,4,4,5,5};
	cout<<"Size of array is "<<binarySearch(a,6)<<endl;
	cout<<"Count of 3 in array is "<<binarySearch(a,3,true)-binarySearch(a,3)<<endl;
	cout<<"Index of first 4 is "<<binarySearch(a,4,false)<<endl;
	cout<<"Index of last 4 is "<<binarySearch(a,4,true)-1<<endl;
	cout<<"Count of 2 in array is "<<binarySearch(a,2,true)-binarySearch(a,2)<<endl;
	return 0;
}
