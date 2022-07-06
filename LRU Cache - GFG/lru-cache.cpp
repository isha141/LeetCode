// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way
class node { 
    public:
    int data; 
    int val;
    node *prev=NULL;
    node *next=NULL; 
    node(int key,int val){
       this->data=key;
       this->val=val;
    }
};
class LRUCache
{
    private:
    map<int,node *>mp; 
    node *head=new node(0,0);
    node *tail=new node(0,0); 
    int size; 
    private:
    void removing(node *del){ 
        mp.erase(del->data);
        node *delprev=del->prev;
        node *delnext=del->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here 
        size=cap;
        head->next=tail;
        tail->prev=head;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {    
        int ans=-1;
        if(mp.count(key)){
           node * t=mp[key];
           mp.erase(key); 
           ans=t->val;
          removing(t);
        node *p=new node(key,ans);
        // p->next=NULL;
        // p->prev=NULL; 
        node *temp=head->next;
        p->next=temp; 
        temp->prev=p;
        head->next=p;
        p->prev=head;
        mp[key]=p;
        }
        
        return ans;
        // your code here 
        
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // your code here   
        int ans=0;
        if(mp.find(key)!=mp.end()){
            node * t=mp[key];
           mp.erase(key); 
           removing(t);
        } 
        if(mp.size()==size){ 
            mp.erase(tail->prev->data);
             removing(tail->prev); 
        }
        node *p=new node(key,value);
        // p->next=NULL;
        // p->prev=NULL; 
        node *temp=head->next;
        p->next=temp; 
        temp->prev=p;
        head->next=p;
        p->prev=head;
        mp[key]=p;
    } 
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends