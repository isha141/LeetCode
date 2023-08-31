class MyQueue {
    stack<int>s1,s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int temp=peek();
         s2.pop();
        return temp;
    }
    
    int peek() {
          if(s2.size()!=0){
              int temp=s2.top(); 
            return temp;
        }
        else{
            while(!s1.empty()){
                auto itr=s1.top();
                s2.push(itr);
                s1.pop();
            }
            int temp=s2.top();
            return temp;
        }
    }
    
    bool empty() {
         return (s1.size()==0 && s2.size()==0);
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