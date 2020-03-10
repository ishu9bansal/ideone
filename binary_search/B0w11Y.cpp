#include <iostream>
#include <vector>
using namespace std;
struct less_than_k {
	int k;
	less_than_k(int x) : k(x) {}
	bool operator() (int m,vector<int> &v) { return v[m]<k;}
	// this assumes that the above condition is true for the first part of the range [l,r)
	// and it is false for the remaining part the search will return the first element 
	// in the search space which gives false for above condition
	
	// Hence, above condition maps as the follow over the search space
	// t t t t t t t t t t t t t t t t f f f f f f f f f f 
	// function will find the index of ^ element
};
struct less_than_equal_k {
	int k;
	less_than_equal_k(int x) : k(x) {}
	bool operator() (int m,vector<int> &v) { return v[m]<=k;}
};
template <class T, class Comp>
int binarySearch(int l, int r, Comp comp, T& t){
	int m = (l+r)/2;
	while(l<r){
		if(comp(m,t))	l = m+1;
		else	r = m;
		m = (l+r)/2;
	}
	return m;
}
int binarySearch(vector<int> &a, int k, bool strict = false){
	if(strict)	return binarySearch(0,a.size(),less_than_equal_k(k),a);
	return binarySearch(0,a.size(),less_than_k(k),a);
}
int main() {
	vector<int> a = {1,1,3,3,3,3,4,4,4,5,5};
	cout<<"4th index is less than 2: "<<less_than_k(2)(4,a)<<endl;
	cout<<"6th index is less than equal 4: "<<less_than_equal_k(4)(6,a)<<endl;
	
	cout<<"Size of array is "<<binarySearch(a,6)<<endl;
	cout<<"Count of 3 in array is "<<binarySearch(a,3,true)-binarySearch(a,3)<<endl;
	cout<<"Index of first 4 is "<<binarySearch(a,4,false)<<endl;
	cout<<"Index of last 4 is "<<binarySearch(a,4,true)-1<<endl;
	cout<<"Count of 2 in array is "<<binarySearch(a,2,true)-binarySearch(a,2)<<endl;
	return 0;
}
