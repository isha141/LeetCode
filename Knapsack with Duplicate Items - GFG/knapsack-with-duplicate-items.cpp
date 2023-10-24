//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

int dp[1001][1001];
class Solution{
    private:
    int solve(int i,int weight,int val[],int wt[]){
         if(i<0) 
         return 0;
         if(weight==0)
           return 0;
          if(dp[i][weight]!=-1)
            return dp[i][weight];
         int take=0;
         int not_take=0;
         if(wt[i]<=weight){
             take=val[i]+solve(i,weight-wt[i],val,wt);
         }
         not_take=solve(i-1,weight,val,wt);
        return dp[i][weight]=max(take,not_take);
    }
public:
    int knapSack(int n, int w, int val[], int wt[])
    {  
        memset(dp,-1,sizeof(dp));
        return solve(n-1,w,val,wt);
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