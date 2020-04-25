#include <iostream>
#include <unordered_map>
using namespace std;

template <class T>
struct LinkedList{
    LinkedList* remove(){
        if(l)   l->r = r;
        if(r)   r->l = l;
        return this;
    }
    void insert(LinkedList* &head){
        r = head;
        l = NULL;
        if(head)    head->l = this;
        head = this;
    }
    T x;
    LinkedList* l;
    LinkedList* r;
    LinkedList(T X, LinkedList* L=NULL, LinkedList* R=NULL) : x(X), l(L), r(R) {}
};

class LRUCache {
private:
    int n;
    LinkedList<pair<int,int>> *head;
    LinkedList<pair<int,int>> *tail;
    unordered_map<int,LinkedList<pair<int,int>>*> h;
public:
    LRUCache(int capacity) {
        n = capacity;
        head = tail = new LinkedList<pair<int,int>>(make_pair(0,0));
    }
    
    int get(int key) {
        if(h.find(key)==h.end())    return -1;
        if(head!=h[key])    h[key]->remove()->insert(head);
        return head->x.second;
    }
    
    void put(int key, int value) {
        if(h.find(key)==h.end())    h[key] = new LinkedList<pair<int,int>>({key,value});
        else    h[key]->x.second = value;
        get(key);
        while(h.size()>n){
            key = tail->l->remove()->x.first;
            delete(h[key]);
            h.erase(key);
        }
    }
};
int main() {
	LRUCache cache(2);
	cache.put(1, 1);
	cache.put(2, 2);
	cout<<cache.get(1)<<endl;	// returns 1
	cache.put(3, 3);			// evicts key 2
	cout<<cache.get(2)<<endl;	// returns -1 (not found)
	cache.put(4, 4);			// evicts key 1
	cout<<cache.get(1)<<endl;	// returns -1 (not found)
	cout<<cache.get(3)<<endl;	// returns 3
	cout<<cache.get(4)<<endl;	// returns 4
	return 0;
}
