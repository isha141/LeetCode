class Solution {
public:
    int leastInterval(vector<char>& task, int n) {
     priority_queue<int>pq;
        queue<int>q; 
        int ans=0; 
        map<char,int>mp;
        for(auto itr: task)
            mp[itr]++; 
        
        
        
        for(auto [x,y]: mp)
            pq.push(y); 
        
        
        while(pq.size())
        { 
            int res=0;
            for(int j=0;j<n+1;++j){
                if(pq.size()){
                int t=pq.top();
                pq.pop();
                if(t-1>0)
                q.push(t-1);
                res++;
                }
            }
            while(!q.empty()){ 
                pq.push(q.front());
                q.pop();
            }   
            if(pq.size()==0)
            ans+=res;
            else
                ans+=n+1;
        }
        return ans;
    }
};