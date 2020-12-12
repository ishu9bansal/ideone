#include <iostream>
#include <set>
using namespace std;

int main() {
	set<int> h;
	set<int>::iterator i;
	h.insert(2);
	i = h.find(2);
	cout<<"two: "<<*i<<endl;
	// cout<<"position: "<<i-h.begin()<<endl;	// compilation error
	h.insert(3);
	i++;
	i--;
	cout<<"three-one: "<<*i<<endl;
	// cout<<"position: "<<i-h.begin()<<endl;	// compilation error
	h.insert(1);
	cout<<"one+one: "<<*i<<endl;
	// cout<<"position: "<<i-h.begin()<<endl;	// compilation error
	return 0;
}
