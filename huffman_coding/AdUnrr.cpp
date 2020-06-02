#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
struct Node{
	int x;
	Node* l;
	Node* r;
	Node(int X=0, Node* L=NULL, Node* R=NULL) : x(X), l(L), r(R) {}
};
struct comp {
	unordered_map<char,int> &h;
	comp(unordered_map<char,int> &x) : h(x) {}
	bool operator() (const char &a, const char &b) { return h[a]<h[b]; }
};
int min(queue<Node*> &leaves, queue<Node*> &nodes, unordered_map<char,int> &h, Node* &ans){
	if(leaves.empty()&&nodes.empty()){
		ans = NULL;
		return 0;
	}
	bool l_or_n;
	if(leaves.empty()||nodes.empty())	l_or_n = leaves.empty();
	else	l_or_n = nodes.front()->x < h[leaves.front()->x];
	//			tie breaker here ^^^^^^^^^^^^ leads to a minimum variance
	if(l_or_n){
		ans = nodes.front();
		nodes.pop();
		return ans->x;
	}
	else{
		ans = leaves.front();
		leaves.pop();
		return h[ans->x];
	}
}
Node* huffman_tree(const string &s){
	if(!s.size())	return NULL;
	unordered_map<char,int> h;
	unordered_set<char> uniq_s;
	for(char c: s)
		h[c]++, uniq_s.insert(c);
	vector<char> v(uniq_s.begin(), uniq_s.end());
	sort(v.begin(), v.end(), comp(h));
	queue<Node*> leaves;
	queue<Node*> nodes;
	for(char c: v)
		leaves.push(new Node(c));
	Node* node;
	int node_f = min(leaves, nodes, h, node);
	Node* temp;
	int temp_f;
	while(leaves.size()||nodes.size()){
		temp_f = min(leaves, nodes, h, temp);
		nodes.push(new Node(node_f+temp_f, node, temp));
		node_f = min(leaves, nodes, h, node);
	}
	return node;
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
void print_binary_tree(Node* node, int depth=0, bool leaf_check=false){
	// this will print a leaf node differently if the leaf_check is set to true
	// print format for leaf can be defined in else block below.
	if(!node)	return;
	print_binary_tree(node->r, depth+1, leaf_check);
	string str = "";
	for(int i=0; i<depth; i++)
		cout<<"|\t";
	if(!leaf_check||node->l||node->r)	cout<<node->x;
	else	print(node->x);	// print in this format if it's a leaf
	cout<<endl;
	print_binary_tree(node->l, depth+1, leaf_check);
	return;
}
void print(const vector<bool> &v){
	for(const auto &x: v)
		cout<<x;
	cout<<endl;
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
	print_binary_tree(h,0,true);
	cout<<endl<<endl;
	unordered_map<char,vector<bool>> t = huffman_table(h);
	int sum = 0;
	for(auto p: t){
		print(p.first);
		cout<<'\t';
		print(p.second);
		sum += p.second.size();
	}
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
	string text = decode(v,h);
	cout<<"Check if the original text and decoded text matches? ";
	cout<<(p==text?"Yes.":"No.")<<endl;
	cout<<endl<<text<<endl;
	return 0;
}
