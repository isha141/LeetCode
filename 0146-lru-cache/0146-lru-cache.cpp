class LRUCache {
    class ListNode{
     public:
    ListNode *prev;
    ListNode *next;
    int key;
    int val;
       ListNode(int key,int val){
           this->key=key;
           this->val=val;
       } 
};
    private:
    private:
    ListNode *head=NULL;
    ListNode *tail=NULL;
    int size=0;
    map<int,ListNode*>mp;
public:
    LRUCache(int capacity) {
        head=new ListNode(0,0);
        head->prev=NULL;
        tail=new ListNode(0,0);
        head->next=tail;
        tail->prev=head;
        tail->next=NULL;
        size=capacity;
    }
    
    int get(int key) {
       if(mp.find(key)==mp.end())
             return -1;
        ListNode *temp=mp[key];
        ListNode *prev=temp->prev;
        ListNode *next=temp->next;
        prev->next=next;
        next->prev=prev;
        temp->next=head->next;
        head->next->prev=temp;
        temp->prev=head;
        head->next=temp;
        return temp->val; 
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            ListNode *p=mp[key];
            ListNode *prev=p->prev;
            ListNode *next=p->next;
            prev->next=next;
            next->prev=prev;
        }
        else if(mp.size()==size){
            ListNode *del=tail->prev;
            ListNode *prev=del->prev;
            prev->next=tail;
            tail->prev=prev;
            mp.erase(del->key);
            delete(del);
        }
        ListNode *p=new ListNode(key,value);
            ListNode *next=head->next;
            p->next=next;
            next->prev=p;
            head->next=p;
            p->prev=head;
            mp[key]=p;
        return ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */