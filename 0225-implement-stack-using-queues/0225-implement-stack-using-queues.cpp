class MyStack { 
    queue<int>q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
            q.push(x);
            int n=q.size();
        for(int i=1;i<n;++i){
            auto itr=q.front();
            q.push(itr);
            q.pop();
        }
    }
    
    int pop() {
        int temp=q.front();
        q.pop();
        return temp;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size()==0;
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