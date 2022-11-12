class MedianFinder { 
    priority_queue<int>maxi;
    priority_queue<int,vector<int>,greater<int>>mini;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {  
        if(maxi.size()==0 || maxi.top()>=num)
          maxi.push(num); 
        else 
            mini.push(num);
        if(mini.size()>maxi.size()){
            maxi.push(mini.top());
            mini.pop();
        }
        if(mini.size()+1<maxi.size()){
            mini.push(maxi.top());
            maxi.pop();
        }
    }
    
    double findMedian() {
        if((maxi.size()+mini.size())%2==0)
            return (double)(maxi.top()+mini.top())/2.0;
        return maxi.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */