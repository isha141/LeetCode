class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
        int n=s.size();
        int ans=0;
        priority_queue<int>pq;
        for(auto itr: s){
            pq.push(itr);
        }
        while(pq.size()>1){
            auto itr=pq.top();
            pq.pop();
            auto itr1=pq.top();
            pq.pop();
            if(abs(itr-itr1)!=0){
                pq.push(abs(itr-itr1));
            }
        } 
        if(pq.size())
        return pq.top();  
        else 
            return 0;
    }
};