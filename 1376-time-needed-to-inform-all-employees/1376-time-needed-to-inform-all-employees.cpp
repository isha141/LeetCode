class Solution { 
    int maxi=0;
    int ans=0;
    unordered_map<int,vector<int>>adj;
    private:
    void solve(int head,int sum,vector<int>&inform)
    {
         maxi=max(maxi,sum);
        for(auto itr: adj[head]){   
            solve(itr,sum+inform[itr],inform);
        }
        return ;
    }
public:
    int numOfMinutes(int n, int head, vector<int>& man, vector<int>& inform) {
        for(int i=0;i<n;++i){
           int manager=man[i];
            if(manager!=-1){
              adj[manager].push_back(i);  
            }
        } 
        int sum=inform[head];
        solve(head,sum,inform);
        return maxi;
    }
        
};