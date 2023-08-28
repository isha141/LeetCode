class MyStack { 
    queue<int>q;
public:
    MyStack() {
        
    }
    
    void push(int x) { 
           q.push(x);
          int n=q.size();
        if(n>1){
            for(int i=1;i<n;++i){
         int temp=q.front();
                q.pop();
                q.push(temp);
            }
        }
        
    }
    
    int pop() { 
        int t=q.front();
        q.pop();
        return t;
        
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */