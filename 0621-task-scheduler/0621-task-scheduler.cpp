class Solution {
public:
    int leastInterval(vector<char>&tasks, int n) {
        map<char,int>mp;
        for(auto itr: tasks){
            mp[itr]++;
        }
        priority_queue<int>pq;
        for(auto itr: mp){
            pq.push(itr.second);
        } 
        queue<int>q;
        int ans=0;
        while(!pq.empty()){
            auto itr=pq.top();
            pq.pop();
            ans+=1;
            if((itr-1)>0)
                q.push(itr-1);
            for(int i=0;i<n;++i){
                if(pq.size()==0 && q.size()==0)
                      return ans;
                if(pq.size()){
                auto itr=pq.top();
                pq.pop();
                if(itr-1>0){
                    q.push(itr-1);
                }
              }
              ans+=1;
            }
            while(!q.empty()){
                auto itr=q.front();
                q.pop();
                pq.push(itr);
            }
        }
        return ans;
    }
};