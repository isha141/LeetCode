class Solution {
    private:
    vector<int>ans; 
    int m;
    void solve(int i,int curr,int target,vector<int>&people,map<string,int>&mp,vector<int>&ds,vector<vector<int>>&dp){
         if(i>=m){
            if(curr==target){ 
                  // cout<<"ju"<<endl;
                if(ans.size()==0){
                    ans=ds;
                }
                else if(ans.size()>ds.size()){
                    ans=ds;
                }
            }
             return ;
         } 
        if(dp[i][curr]!=-1){
            if(dp[i][curr]<=ds.size()) 
              return ;
        }
         int temp=people[i];
        // cout<<i<<"-->"<<(curr|temp)<<endl;
        
        solve(i+1,curr,target,people,mp,ds,dp);
        ds.push_back(i); 
        solve(i+1,(curr|temp),target,people,mp,ds,dp);
        ds.pop_back();
         if(ds.size()>0)
            dp[i][curr]=ds.size();
    }
public:
    vector<int> smallestSufficientTeam(vector<string>& req, vector<vector<string>>& peo) {
         map<string,int>mp; 
        m=peo.size();
         int n=req.size();
          for(int i=0;i<n;++i){
               mp[req[i]]=(1<<i);
          } 
          int target=(1<<n)-1;
          // int ans=0;  
           vector<int>people;
          for(auto itr: peo){
              int temp=0;
              for(auto iit: itr){ 
                   if(mp.find(iit)!=mp.end())
                  temp|=mp[iit];
              }
              people.push_back(temp);
          }  
          vector<vector<int>>dp(m+1,vector<int>((1<<n)+5,-1));
          vector<int>ds;
          solve(0,0,target,people,mp,ds,dp);
           return ans;
    }
};