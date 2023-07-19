//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private: 
    long long solve(int i,int coins[],int n,int sum,int curr,vector<vector<long long>>&dp){ 
        if(sum==curr)
         return 1;
        if(i>=n)
        return 0;
        if(sum<curr) 
        return 0; 
        if(dp[i][curr]!=-1)
         return dp[i][curr];
        long long left=solve(i,coins,n,sum,curr+coins[i],dp);
        long long right=solve(i+1,coins,n,sum,curr,dp);
        return dp[i][curr]=(left + right);
    }
  public:
    long long int count(int coins[], int n, int sum) {

        // code here. 
        sort(coins,coins+n); 
        reverse(coins,coins+n);
        vector<vector<long long>>dp(n,vector<long long>(sum+1,-1));
        return solve(0,coins,n,sum,0,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends