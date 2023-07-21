//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{ 
    private:
    int solve(int i,int n,int w, int val[],int wt[],int curr,vector<vector<int>>&dp){
        if(i>=n)
         return 0;
        int take=INT_MIN; 
        if(dp[i][curr]!=-1)
          return dp[i][curr];
        if((wt[i]+curr)<=w){
            take=val[i]+solve(i,n,w,val,wt,curr+wt[i],dp);
        }
        int not_take=solve(i+1,n,w,val,wt,curr,dp);
        return dp[i][curr]=max(take,not_take);
    }
public:
    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(n,vector<int>(w+1,0));
        for(int i=0;i<=w;++i){
            //   if(i>=wt[0]){
               int temp=(i/wt[0]);
               dp[0][i]=(temp*val[0]); 
            // }
        }
        for(int i=1;i<n;++i){
            for(int j=0;j<=w;++j){
                int not_take=dp[i-1][j];
                int take=0;
                if(j>=wt[i]){
                    take=dp[i][j-wt[i]]+val[i];
                }
                dp[i][j]=max(take,not_take);
            }
        } 
        // for(int i=0;i<n;++i){
        //      for(int j=0;j<=w;++j){
        //          cout<<dp[i][j]<<" ";
        //      }
        //      cout<<endl;
        // }
        return dp[n-1][w];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends