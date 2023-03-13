class Solution {
public:
    int leastInterval(vector<char>& t, int n) {
        int ans=0;
        map<char,int>mp;
        for(auto itr: t){
            mp[itr]++;
        }
        priority_queue<int>pq;
        for(auto &[x,y]: mp){
            pq.push(y);
        }
        queue<int>q; 
        while(!pq.empty()){
              auto itr=pq.top();
              pq.pop(); 
             ans+=1;
            if(itr-1>0)
                q.push(itr-1);
            for(int i=0;i<n;++i){
                if(pq.size()==0 && q.size()==0) return ans; 
                if(pq.size()){
                 auto itr=pq.top();
                 pq.pop();
                if(itr-1>0)
                    q.push(itr-1);
                }
                ans+=1;
            }
            while(!q.empty()){
                pq.push(q.front());
                q.pop();
            }
        }
        return ans;
    }
};