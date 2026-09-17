class LRUCache {

 struct Cnode{
int key;int val;
Cnode* prev;
Cnode* next;
 
 Cnode(int k=0,int val=0){
    this->key=k;
    this->val=val;
    this->prev=NULL;
    this->next=NULL;
 }
 
 };
 int cap;
 unordered_map<int,Cnode*>cache;
 Cnode* head;
 Cnode*  tail;

public:
 void remove(Cnode* node){
node->prev->next=node->next;
node->next->prev=node->prev;
return;
 }
 void addtohead(Cnode* node){
    node->next=head->next;
    node->next->prev=node;
    node->prev=head;
    head->next=node;
    return;
 }

    LRUCache(int capacity) {
        this->cap=capacity;
        head=new Cnode();
        tail=new Cnode();
        head->next=tail;
        tail->prev=head;

    }
    
    int get(int key) {
        if(cache.find(key)==cache.end())return -1;
        Cnode* x=cache[key];
        remove(x);
        addtohead(x);
        return x->val;

            }
    
    void put(int key, int val) {
        if(cache.find(key)!=cache.end()){
            Cnode* x=cache[key];
            remove(x);
            x->val=val;
            addtohead(x);
        }
        else{
            if(cache.size()>=cap){
                Cnode* lru=tail->prev;
                remove(lru);
                cache.erase(lru->key);
                delete lru;
            }

            Cnode * newnode=new Cnode(key,val);
            addtohead(newnode);
            cache[key]=newnode;
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */