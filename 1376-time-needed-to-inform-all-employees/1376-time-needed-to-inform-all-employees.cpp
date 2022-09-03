class Solution { 
    int maxi=0;
    int ans=0;
    private:
    void solve(int head,int sum,vector<int>adj[],
vector<int>&inform)
    {
         maxi=max(maxi,sum);
        for(auto itr: adj[head]){   
            solve(itr,sum+inform[itr],adj,inform);
        }
        return ;
    }
public:
    int numOfMinutes(int n, int head, vector<int>& man, vector<int>& inform) {
            vector<int>adj[n];
        for(int i=0;i<n;++i){
           int manager=man[i];
            if(manager!=-1){
              adj[manager].push_back(i);  
            }
        } 
        int sum=inform[head];
        solve(head,sum,adj,inform);
        return maxi;
    }
        
};