class MedianFinder { 
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxheap.push(num);
        minheap.push(maxheap.top());
        maxheap.pop();
        if(maxheap.size()<minheap.size())
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() { 
        double ans=0;
        if(maxheap.size()>minheap.size()){
            ans=maxheap.top();
        }
        else  {
            ans=(maxheap.top()+minheap.top())/2.0;
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */