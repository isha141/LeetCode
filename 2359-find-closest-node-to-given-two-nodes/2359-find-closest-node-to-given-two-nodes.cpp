class Solution { 
    private:
    void solve(int node1,vector<int>&edges,vector<int>&dist)
    {
        queue<int>q;
        q.push(node1); 
        int c=0;
        dist[node1]=0;
        while(!q.empty())
        {
            int n=q.size(); 
            c++;
                auto itr=q.front();
                q.pop();
                if(edges[itr]!=-1 && dist[edges[itr]]==-1){
                    q.push(edges[itr]);
                    dist[edges[itr]]=c;
                }
        }
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int>adj[n+1];
        for(int i=0;i<n;++i){
            if(edges[i]!=-1){
                adj[i].push_back(edges[i]);
            }
        }  
       vector<int>a(n+1,-1);
        vector<int>b(n+1,-1);
        solve(node1,edges,a);
        solve(node2,edges,b); 
        int res=INT_MAX;
        int ans=-1;
        // for(auto itr: a) cout<<itr<<" "; 
        // cout<<endl;
        // for(auto itr: b) cout<<itr<<" ";
         for(int i=0;i<n;++i){
             if(a[i]==-1 || b[i]==-1)
                 continue;
             if(res>max(a[i],b[i])){
                 res=max(a[i],b[i]); 
                 // cout<<i<<" ";
                 ans=i;
             }
         }
        return ans;
    }
};