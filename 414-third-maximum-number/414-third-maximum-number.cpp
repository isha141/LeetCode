class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n=nums.size();
        set<int>s;
        for(auto itr: nums)
            s.insert(itr);
        int c=0; 
        int ans=0;
        priority_queue<int>pq;
        for(auto itr: s)
            pq.push(itr);
        int a=0; 
        int cur=0;
        while(a<2)
        {
            cur=max(cur,pq.top());
            pq.pop();
            a++;
        }
        if(pq.empty())
            return cur;
        return pq.top();
    }
};