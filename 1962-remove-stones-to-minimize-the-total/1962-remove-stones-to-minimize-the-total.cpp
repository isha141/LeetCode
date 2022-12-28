class Solution {
public:
    int minStoneSum(vector<int>& p, int k) {
        int n=p.size();
        priority_queue<int>pq;
        for(auto itr: p)
            pq.push(itr);
        while(k-- ){
            auto it=pq.top();
            pq.pop(); 
            // cout<<it<<" "<<floor(it/2)<<endl;
            int temp=it/2;
            if(it%2) temp++;
            pq.push(temp);
        }
        int ans=0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};