//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{ 
    private:
    int solve(int i,int arr[],int n,int prev,vector<vector<int>>dp){
        if(i>=n)
        return 0;
        if(dp[i][prev+1]!=-1)
        return dp[i][prev+1];
        int take=0;
        int not_take=0;
        if(prev==-1 || arr[i]>arr[prev])
        take=1+solve(i+1,arr,n,i,dp);
        not_take=solve(i+1,arr,n,prev,dp);
        return dp[i][prev+1]=max(take,not_take);
    }
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int arr[])
    {
       // your code he re  
    //   int prev=-1;
       vector<vector<int>>dp(n+1,vector<int>(n+1,0)); 
       for(int i=n-1;i>=0;--i){
           for(int prev=i-1;prev>=-1;--prev){ 
               int take=0;
               int not_take=0;
               if(prev==-1 || arr[prev]<arr[i])
               take=1+dp[i+1][i+1];
               not_take=dp[i+1][prev+1];
               dp[i][prev+1]=max(take,not_take);
           }
       } 
       return dp[0][0];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends