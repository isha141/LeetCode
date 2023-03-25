#define  ll long long
class Solution { 
    void  dfs(int node,vector<vector<int>>&adj, long long int &c,vector<int>&visited)
    {
         visited[node]=1;
        c++;
        for(auto &itr: adj[node]){
            if(!visited[itr])
                dfs(itr,adj,c,visited);
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) { 
        long long int count=0;  
        count=((ll) n*(n-1))/2;
       vector<vector<int>>adj(n);
        for(auto &itr: edges){
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        } 
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){   
            if(visited[i]==0){
            //cout<<i <<endl;
           long long int temp=0; 
          dfs(i,adj,temp,visited);   
           // cout<< i <<"  "<<(temp*(temp-1))/2<<endl;
               count-=(temp*(temp-1))/2; 
            }
        }
        return count;
    }
};