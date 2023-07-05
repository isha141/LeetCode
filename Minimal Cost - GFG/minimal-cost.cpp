//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    int solve(int i,vector<int>&h,int n,int k,vector<int>&dp){
        if(i>=n) return 0;
        int ans=INT_MAX;
         int temp=0; 
         if(dp[i]!=-1) 
         return dp[i];
        for(int j=1;j<=k;++j){ 
            if((i+j)<n){
                temp=abs(h[i]-h[i+j]);
            }
            temp+=solve(i+j,h,n,k,dp);
            ans=min(ans,temp);
        }
        return dp[i]=ans;
    }
  public:
    int minimizeCost(vector<int>& h, int n, int k) {
        // Code here  
        vector<int>dp(n+1,-1);
        return solve(0,h,n,k,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends