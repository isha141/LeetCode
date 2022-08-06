class Solution {
public:
    int leastInterval(vector<char>& task, int n) {
     priority_queue<int>pq;
        int i=0;
        int s=task.size(); 
        queue<int>q; 
        int ans=0; 
        map<char,int>mp;
        for(auto itr: task)
            mp[itr]++;
        for(auto [x,y]: mp)
            pq.push(y); 
        while(pq.size())
        { 
            int temp=pq.top();
            pq.pop(); 
            if(temp-1>0)
            q.push(temp-1);
            ans++;
            for(int j=0;j<n;++j){
                if(pq.size()==0 && q.size()==0)
                   return ans; 
                if(pq.size()){
                int t=pq.top();
                pq.pop();
                if(t-1>0)
                q.push(t-1);
                }
                ans++;
            }
            while(!q.empty()){ 
                pq.push(q.front());
                q.pop();
            }   
        }
        return ans;
    }
};