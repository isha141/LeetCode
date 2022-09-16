class Solution { 
    private:
    int solve(int i,vector<int>&arr,int &n,int &k,vector<int>&dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int maxi=INT_MIN;
        int len=0;
        int ans=INT_MIN;
        for(int l=i;l<min(n,i+k);l++){
             len++;
           maxi=max(maxi,arr[l]);
         int sum=(len*maxi)+solve(l+1,arr,n,k,dp);  
             ans=max(ans,sum);
        }
        return dp[i]=ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size(); 
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;--i){ 
            int len=0; 
            int maxi=INT_MIN; 
            int ans=INT_MIN;
            for(int j=i;j<min(n,i+k);++j){
                len++;
                maxi=max(maxi,arr[j]); 
               int sum= maxi*len + dp[j+1];
                ans=max(ans,sum);
            }
            dp[i]=ans;
        }
        return dp[0];
    }
};