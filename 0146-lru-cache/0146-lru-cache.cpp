
class LRUCache { 
    class node{
        public:
        int key;
        node * next;
        node * prev;
        int val;
        node(int key,int val){
            this->key=key;
            this->val=val;
        }
    };
public: 
    int cap=0;
    node * head=new node(0,0);
    node * tail=new node(0,0);
      int size=0;
    map<int,node* >mp;
    LRUCache(int capacity) {
        size=capacity;
         head->next=tail;
         head->prev=NULL;
         tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            node *temp=mp[key]; 
            int val=temp->val;
            node * temp1=temp->next;
            temp1->prev=temp->prev;
            temp->prev->next=temp1; 
            node * a=new node(key,val);
            node *b=head->next;
            a->next=head->next;
            a->prev=head;
            head->next=a;
            b->prev=a;
            mp[key]=a;
            return val;
        } 
        return -1;
        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
             cap--;
            node *a=mp[key];
            mp.erase(a->key);  
            node *b=a->next;
            b->prev=a->prev;
            a->prev->next=b;
        }
       else if(cap>=size){ 
            cap--;
            node *a=tail->prev;
            mp.erase(a->key); 
            node* b=a->prev;
            b->next=tail;
            tail->prev=b;
        }
        node * a=new node(key,value);
            node *b=head->next;
            a->next=head->next;
            a->prev=head;
            head->next=a;
            b->prev=a;
            mp[key]=a;
            cap++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */