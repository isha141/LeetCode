class Solution {  
    private:
    void solve(vector<int>Adj[],vector<int>&in,vector<int>&ans)
    {
        queue<int>q;
        for(int i=0;i<in.size();++i){
            if(in[i]==1){
                q.push(i); 
                in[i]--;
            }
        }
        while(!q.empty())
        {
            int n=q.size(); 
          vector<int>ds;
            while(n--){
              int itr=q.front();
                q.pop();
                ds.push_back(itr);
                for(auto it : Adj[itr]){
                    in[it]--; 
                    // cout<<it<<" ";
                    if(in[it]==1){
                        q.push(it);
                    }
                }
            } 
            ans=ds;
            // ans.clear();
        }
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& e) {
        vector<int>ans; 
        int m=e.size();
        vector<int>indegree(n,0);
        vector<int>Adj[n];
        for(int i=0;i<m;++i){ 
            // cout<<"ishu"<<endl;
            Adj[e[i][0]].push_back(e[i][1]);
             Adj[e[i][1]].push_back(e[i][0]); 
            indegree[e[i][0]]++;
            indegree[e[i][1]]++;
        }  
       // for(int i=0;i<n;++i){
       //     for(auto it: Adj[i])
       //         cout<<it<<" ";
       //     cout<<endl;
       // } 
    solve(Adj,indegree,ans); 
        if(ans.size()==0)
            return {0};
        return ans;
    }
};