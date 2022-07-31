class MedianFinder { 
    priority_queue<int>maxi;
    priority_queue<int,vector<int>,greater<int>>mini;
public:
    MedianFinder() {
    }
    void addNum(int num) { 
        // cout<<maxi.size()<<" ";
        if(maxi.size()==0 || maxi.top()>=num){
            maxi.push(num); 
        }
        else
            mini.push(num); 
        
        if(maxi.size()<mini.size()){
          maxi.push(mini.top());
         mini.pop();
         } 
    else if(mini.size()+1< maxi.size()){
        mini.push(maxi.top());
        maxi.pop();
    }
    }
    
    double findMedian() { 
        // cout<<mini.size()<<" "<<maxi.size()<<endl; 
        double ans=0.0;
    if(maxi.size()==mini.size())
        ans= double(double(maxi.top())+double(mini.top()))/2.0; 
        else
          ans= maxi.top(); 
        return ans;
    } 
    
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */