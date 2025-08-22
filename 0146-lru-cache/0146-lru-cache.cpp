class LRUCache {
   struct Node{
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k,int v):key(k),value(v),prev(NULL),next(NULL){}
   };
   int cap;
   int size;
   unordered_map<int,Node*>mp;
   Node*head;
   Node*tail;
    
public:
    LRUCache(int capacity) {
        cap=capacity;
        size=0;
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
    }
    void remove(Node *node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    void insertFront(Node *node){
        node->next=head->next;
        node->prev=head;
        head->next=node;
        node->next->prev=node;
    }
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
        Node *node=mp[key];
        remove(node);
        insertFront(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node *node=mp[key];
            node->value=value;
            remove(node);
            insertFront(node);
        }else{
            if(size==cap){
                Node*lru=tail->prev;
                remove(lru);
                mp.erase(lru->key);
                delete lru;
                size--;
            }
            Node*node=new Node(key,value);
            insertFront(node);
            mp[key]=node;
            size++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */