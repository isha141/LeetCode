class LRUCache { 
    class node{ 
        public:
        int data;
        int val;
        node *prev;
        node *next;
        node(int key,int x){
            data=key;
            val=x;
        }
    }; 
    private:
    void insert(node* newnode)
    { 
        node *temp=head->next;
        newnode->next=temp;
        temp->prev=newnode;
        newnode->prev=head;
        head->next=newnode;
    }
    void remove(node *del)
    {
        node *delprev=del->prev;
        node *delnext=del->next;
        delprev->next=delnext;
        delnext->prev=delprev; 
        //delete(del);
    }
public: 
    int size=0; 
    node *head=new node(0,0);
    node *tail=new node(0,0);
    unordered_map<int,node*>mp;
    LRUCache(int capacity) {
        size=capacity; 
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.count(key))
        {
            node *temp=mp[key]; 
            int x=temp->val;
            mp.erase(temp->data);
             remove(temp);
            node *p=new node(key,x);
            insert(p);
            mp[key]=p;
            return x;
        }
        else
            return -1;
    }
    
    void put(int key, int value) { 
        if(mp.find(key)!=mp.end()){ 
            node *temp=mp[key];
            mp.erase(key);
            remove(temp);
        }
           
        if(mp.size()==size){
            mp.erase(tail->prev->data);
            remove(tail->prev);
        } 
        node *p=new node(key,value); 
            insert(p);
            mp[key]=p;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */