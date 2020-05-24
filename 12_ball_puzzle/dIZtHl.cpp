#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
int faulty;

int balance(const vector<int> &vl, const vector<int> &vr){
	// 1 means first param heavy
	// 2 means invalid measurement
	if(vl.size()>6||vr.size()>6)	return 2;
	unordered_set<int> l(vl.begin(), vl.end());
	unordered_set<int> r(vr.begin(), vr.end());
	if(l.size()!=vl.size()||r.size()!=vr.size())	return 2;
	unordered_set<int> o(vl.begin(), vl.end());
	o.insert(vr.begin(),vr.end());
	if(o.size()!=l.size()+r.size())	return 2;
	if(l.size()>r.size())	return 1;
	if(l.size()<r.size())	return -1;
	if(l.find(faulty)!=l.end()||r.find(-faulty)!=r.end())	return 1;
	if(l.find(-faulty)!=l.end()||r.find(faulty)!=r.end())	return -1;
	return 0;
}
pair<int,int> puzzle_12(){
	// return value:
	// {faulty_index, heavy/light}
	// heavy: 1, light: -1
	
	vector<int> o = {12,1,2,3};
	vector<int> b = {4,5,6,7};
	vector<int> h = {8,9,10,11};
	
	int x = balance(b,h);	// 1 means first heavy
	if(x==-1)	swap(b,h);
	if(x){
		o.push_back(h[3]);
		h[3] = b[3];
		h.push_back(b[2]);
		x = balance(h,o);
		if(x==1){
			h = {b[3]};
			b = {b[2]};
			x = balance(b,h);
			if(x)	return {x==1?b.back():h.back(),1};
			else	return {o.back(),-1};
		}
		else if(x==-1){
			o = {h[1]};
			b = {h[2]};
			x = balance(o,b);
			if(x)	return {x==1?b.back():o.back(),-1};
			else	return {h[0],-1};
		}
		else{
			o = {b[0]};
			h = {b[1]};
			x = balance(o,h);
			return {x==1?o.back():h.back(),1};
		}
	}
	else{
		int O = o.back();
		o.pop_back();
		int B = b.back();
		b.pop_back();
		x = balance(o,b);
		if(x){
			int X = x;
			O = o.back();
			o.pop_back();
			b = {o.back()};
			o.pop_back();
			x = balance(o,b);
			if(x)	return {x==X?o.back():b.back(),X};
			else	return {O,X};
		}
		else{
			o = {O};
			b = {B};
			x = balance(o,b);
			return {O,x};	// 1 means heavy
		}
	}
}
int main() {
	pair<int,int> p;
	for(faulty=-12; faulty<=12; faulty++){
		if(!faulty)	continue;
		p = puzzle_12();
		cout<<"Ball at index "<<p.first<<" is "<<(p.second==1?"heavy":"light")<<endl;
	}
	return 0;
}
