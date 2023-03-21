class BrowserHistory { 
    stack<string>history,future; 
    string curr;
public:
    BrowserHistory(string homepage) {
        curr=homepage;
    }
    
    void visit(string url) {
        history.push(curr);
        curr=url;
        future=stack<string>();
    }
    
    string back(int steps) {
        while(steps>0 && history.size()){ 
            future.push(curr);
             curr=history.top();
            history.pop();
            // future.push(itr); 
            steps--;
        }
        // if(history.size())
        //     return history.top();
        // else
            return curr;
    }
    
    string forward(int steps) {
        while(steps>0 && future.size()){ 
            history.push(curr);
            curr=future.top();
            future.pop();
            // history.push(itr);
            steps--;
        }
        // if(future.size()) return 
        return curr;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */