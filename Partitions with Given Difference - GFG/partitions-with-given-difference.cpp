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
        vector<vector<int>>dp(n,vector<int>((temp/2)+1,-1));
        return solve(0,arr,n,temp/2,0,dp); 
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