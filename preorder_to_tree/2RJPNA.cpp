#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct Node {
	int x;
	Node *l;
	Node *r;
	Node(int value=0, Node* left=NULL, Node* right=NULL) : x(value), l(left), r(right) {}
};

void print_binary_tree(vector<string> &v, Node* node, string s="", int depth=0){
	// can be optimized better, taking up too much heap space
	if(!node)	return;
	print_binary_tree(v, node->r, s+"|\t" , depth+1);
	v.push_back(s+to_string(node->x));
	print_binary_tree(v, node->l, s+"|\t", depth+1);
	return;
}
void insert(Node* &root, Node* node){
    if(!root)   root = node;
    else insert(node->x<root->x?root->l:root->r, node);
}
Node* preorderd_to_bst(const vector<int> &v){
	Node* root = NULL;
	for(int x: v)
        insert(root,new Node(x));
    return root;
}
vector<int> bst_to_preorder(Node* root){
	stack<Node*> h;
	Node* node;
	h.push(root);
	vector<int> v;
	while(!h.empty()){
		node = h.top();
		h.pop();
		if(!node)	continue;
		v.push_back(node->x);
		h.push(node->r);
		h.push(node->l);
	}
	return v;
}
void random_run(int n = 100){
	Node* root = NULL;
	while(n--)
        insert(root,new Node(rand()%1000));
	vector<string> s;
	s.clear();
	print_binary_tree(s,root);
	cout<<"Original Tree"<<endl;
	for(string &str: s)
		cout<<str<<endl;
	cout<<endl;
	vector<int> preorder = bst_to_preorder(root);
	cout<<"Preorder Traversal"<<endl;
	for(int x: preorder)
		cout<<x<<' ';
	cout<<endl;
	root = preorderd_to_bst(preorder);
	s.clear();
	print_binary_tree(s,root);
	cout<<"Answer Tree"<<endl;
	for(string &str: s)
		cout<<str<<endl;
	cout<<endl;
}
int main() {
	int t,n,x;
	Node* root;
	vector<int> v;
	vector<string> s;
	cin>>t;
	while(t--){
		cin>>n;
		v.clear();
		while(n--&&cin>>x)	v.push_back(x);
		root = preorderd_to_bst(v);
		s.clear();
		print_binary_tree(s,root);
		for(string &str: s)
			cout<<str<<endl;
		cout<<endl;
	}
	random_run();
	return 0;
}
