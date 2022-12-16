class MyQueue {
    stack<int>s,s1;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        int ans=peek();
        if(ans!=-1){
            if(s1.size())
                s1.pop();
            else
                s.pop();
        }
        return ans;
    }
    
    int peek() {
        if(s.size()==0 && s1.size()==0)
            return -1;
        if(s1.size()==0){
            while(!s.empty()){
                s1.push(s.top());
                 s.pop();
            }
            int ans= s1.top();
            return ans;
        }
        else{
           int ans=s1.top();
            // s.pop();
            return ans;
        }
        return -1;
    }
    
    bool empty() {
        return (s1.empty() && s.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */