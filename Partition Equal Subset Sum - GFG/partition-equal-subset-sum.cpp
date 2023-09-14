//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution{
    private:
    int n;
     int sum;
    int solve(int i,int arr[],int n,int tot,vector<vector<int>>&dp){
        if(tot==(sum/2))
          return 1;
        if(tot>sum/2)
          return 0;
        if(i>=n)
          return 0;
        if(dp[i][tot]!=-1)
           return dp[i][tot];
        bool l=solve(i+1,arr,n,tot+arr[i],dp);
        bool r=solve(i+1,arr,n,tot,dp);
        return dp[i][tot]=(l || r);
    }
public:
    int equalPartition(int n, int arr[])
    {
        // code here
         sum=accumulate(arr,arr+n,0);
         if(sum%2)
          return 0;
        vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
        //   memset(dp,-1,sizeof(dp));
        return solve(0,arr,n,0,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends