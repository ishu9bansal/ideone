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

void print_binary_tree(Node* node, int depth=0){
	if(!node)	return;
	print_binary_tree(node->r, depth+1);
	string str = "";
	for(int i=0; i<depth; i++)
		cout<<"|\t";
	cout<<node->x<<endl;
	print_binary_tree(node->l, depth+1);
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
	cout<<"Original Tree"<<endl;
	print_binary_tree(root);
	cout<<endl;
	vector<int> preorder = bst_to_preorder(root);
	cout<<"Preorder Traversal"<<endl;
	for(int x: preorder)
		cout<<x<<' ';
	cout<<endl<<endl;
	root = preorderd_to_bst(preorder);
	cout<<"Answer Tree"<<endl;
	print_binary_tree(root);
	cout<<endl;
}
int main() {
	int t,n,x;
	Node* root;
	vector<int> v;
	cin>>t;
	while(t--){
		cin>>n;
		v.clear();
		while(n--&&cin>>x)	v.push_back(x);
		root = preorderd_to_bst(v);
		print_binary_tree(root);
		cout<<endl;
	}
	random_run();
	return 0;
}
