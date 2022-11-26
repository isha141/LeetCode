int dp[100000005];
class Solution { 
    private: 
    int n;
    int solve(int ind,vector<vector<int>>&ds,int prev){
        if(ind>=n)
            return 0; 
        if(dp[ind]!=-1) return dp[ind];
        int take=0; 
        int not_take=0; 
        int i; 
        // cout<<ind<<" "<<prev<<" "<<ds[ind][1]<<endl;
        for(i=ind+1;i<n;++i){
            if(ds[i][0]>=ds[ind][1])
                break;
        }
        take=ds[ind][2]+solve(i,ds,ds[ind][1]);
        not_take=solve(ind+1,ds,prev);
        return dp[ind]=max(take,not_take);
    }
public:
    int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& p) {
         n=start.size();
        vector<vector<int>>ds;
        for(int i=0;i<n;++i){
            ds.push_back({start[i],end[i],p[i]});
        } 
        int prev=-1;
        memset(dp,-1,sizeof(dp));
        sort(ds.begin(),ds.end()); 
        // for(auto itr: ds)
        //     cout<<itr[0]<<" "<<itr[1]<<" "<<itr[2]<<endl;
        return solve(0,ds,prev);
    }
};