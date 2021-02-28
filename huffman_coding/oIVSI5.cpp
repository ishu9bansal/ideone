#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <climits>
using namespace std;
struct Node{
	int x;
	Node* l;
	Node* r;
	Node(int X=0, Node* L=NULL, Node* R=NULL) : x(X), l(L), r(R) {}
};
Node* huffman_tree(const string &s){
	if(!s.size())	return NULL;
	unordered_map<char,int> h;
	for(char c: s)
		h[c]++;
	multimap<int, Node*> v;
	for(auto p: h)
		v.insert({p.second, new Node(p.first)});
	pair<int,Node*> p = *v.begin();
	v.erase(v.begin());
	while(!v.empty()){
		auto it = v.begin();
		v.insert({p.first+it->first, new Node(p.first+it->first,p.second,it->second)});
		v.erase(it);
		it = v.begin();
		p = *it;
		v.erase(it);
	}
	return p.second;
}
void huffman_helper(unordered_map<char,vector<bool>> &t, Node* node, vector<bool> v){
	if(!(node->l||node->r)){
		t[node->x] = v;
		return;
	}
	v.push_back(false);
	huffman_helper(t,node->l,v);
	v.back() = true;
	huffman_helper(t,node->r,v);
}
unordered_map<char,vector<bool>> huffman_table(Node* h){
	unordered_map<char,vector<bool>> t;
	if(!h)	return t;
	huffman_helper(t,h,vector<bool>());
	return t;
}
void print(char c){
	if(c=='\s')	cout<<"\\s";
	else if(c=='\t')	cout<<"\\t";
	else if(c=='\n')	cout<<"\\n";
	else cout<<c;
}
void print(const vector<bool> &v){
	for(const auto &x: v)
		cout<<x;
}
class NodePrinter{
private:
	unordered_map<char,vector<bool>> t;
	int sum;
public:
	NodePrinter(unordered_map<char,vector<bool>> &huffman_table) : t(huffman_table), sum(0) {
		for(auto p: t)
			sum += p.second.size();
	}
	int getSum(){
		return sum;
	}
	void operator() (Node* node){
		if(node->l||node->r){
			cout<<node->x;
			return;
		}
		print(char(node->x));
		if(t.find(node->x)==t.end())	return;
		cout<<"\t->\t";
		print(t[node->x]);
	}
};
void print_binary_tree(Node* node, NodePrinter &printer, int depth=0){
	if(!node)	return;
	print_binary_tree(node->r, printer, depth+1);
	string str = "";
	for(int i=0; i<depth; i++)
		cout<<"|\t";
	printer(node);
	cout<<endl;
	print_binary_tree(node->l, printer, depth+1);
	return;
}
vector<bool> encode(const string &s, unordered_map<char,vector<bool>> &t){
	vector<bool> v;
	for(char c: s)
		for(bool b: t[c])
			v.push_back(b);
	return v;
}
string decode(const vector<bool> &v, Node* h){
	string s = "";
	Node* node = h;
	for(bool b: v){
		node = b?node->r:node->l;
		if(!(node->l||node->r)){
			s.push_back(char(node->x));
			node = h;
		}
	}
	return s;
}
int main() {
	// CAUTION: this method is an exception for the case 
	// when all text contains just one unique character.
	// E.g. ccccccccccccccccccccccccccccccc, without any whitespace etc.
	string s;
	string p="";
	while(getline(cin,s))
		p += s + "\n";
	Node* h = huffman_tree(p);
	unordered_map<char,vector<bool>> t = huffman_table(h);
	NodePrinter np(t);
	print_binary_tree(h,np);
	cout<<endl<<endl;
	int sum = np.getSum();
	cout<<endl;
	cout<<"Size of text: text_length*char_size = ";
	cout<<p.size()<<" * "<<sizeof(char)*CHAR_BIT<<" = ";
	cout<<p.size()*sizeof(char)*CHAR_BIT<<endl;
	cout<<"Size of table: uniq_chars*(char_size + avg_encoding_size) = ";
	cout<<t.size()<<" * ("<<sizeof(char)*CHAR_BIT<<" + "<<sum<<"/"<<t.size()<<") = ";
	cout<<t.size()*sizeof(char)*CHAR_BIT+sum<<endl;
	vector<bool> v = encode(p,t);
	cout<<"Size of encoded string: "<<v.size()<<endl;
	print(v);
	cout<<endl;
	cout<<endl;
	string text = decode(v,h);
	cout<<"Check if the original text and decoded text matches? ";
	cout<<(p==text?"Yes.":"No.")<<endl;
	cout<<endl<<text<<endl;
	return 0;
}
