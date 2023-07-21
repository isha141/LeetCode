//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution { 
    private:
    int sum=0;
    int mod=1e9+7;
    int solve(int i,vector<int>&arr,int n,int d,int curr,vector<vector<int>>&dp){
        if(i>=n){
            if(curr==d){ 
             return 1;
            }
            return 0;
        } 
        if(curr>d)  return 0;
        if(dp[i][curr]!=-1)
          return dp[i][curr];
        int take=solve(i+1,arr,n,d,curr+arr[i],dp);
        int not_take=solve(i+1,arr,n,d,curr,dp);
        return dp[i][curr]=(take + not_take)%mod;
    }
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here 
        for(auto itr : arr)
         sum+=itr;   
        if(sum<d) return 0;
        int temp=(sum-d);
        if(temp%2) return 0;
        vector<vector<int>>dp(n,vector<int>((temp/2)+1,0)); 
        // for(int i=0;i<n;++i){
            // dp[i][0]=1;
        // } 
        if(arr[0]==0){
            dp[0][0]=2;
        } 
        else dp[0][0]=1;
       if(arr[0]!=0 && arr[0]<=temp/2){
            dp[0][arr[0]]=1;
        }
        for(int i=1;i<n;++i){
            for(int target=0;target<=temp/2;++target){
                int take=0;
                if(arr[i]<=target){
                    take=dp[i-1][target-arr[i]];
                }
                int not_take=dp[i-1][target];
                dp[i][target]=(take+not_take)%mod;
            }
        }
        return dp[n-1][temp/2];
        // return res/2;
    } 
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends