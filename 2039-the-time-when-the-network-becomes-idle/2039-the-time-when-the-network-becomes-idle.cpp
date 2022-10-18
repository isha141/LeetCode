class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& e, vector<int>& pat) {
        int n=pat.size();
        vector<int>adj[n+1]; 
        // cout<<"hy";
        for(int i=0;i<e.size();++i){
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
        } 
        queue<int>q;
        vector<int>time(n+1,-1);
        q.push(0);
        time[0]=0;
        while(!q.empty()){
            int t=q.size();
            while(t--){
                auto itr=q.front();
                q.pop();
                for(auto it: adj[itr]){
                    if(time[it]==-1){
                        q.push(it);
                        time[it]=time[itr]+1;
                    }
                }
            }
        }
        int ans=0;
        for(int i=1;i<n;++i){
            int rec=2*time[i];
            int wait=rec-1;
            int resend=wait/pat[i];
            int maxi=rec+resend*pat[i];
            ans=max(ans,maxi);
        }
        return ans+1;
    }
};