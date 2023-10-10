//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

int dp[102][103];
class Solution{
    private:
    int solve(int start,int end,int arr[]){
        if(start==end)
         return 0;
        if(dp[start][end]!=-1)
          return dp[start][end];
        int ans=INT_MAX;
        for(int k=start;k<end;++k){
            int steps=(arr[start-1]*arr[k]*arr[end]+solve(start,k,arr)+solve(k+1,end,arr));
            ans=min(ans,steps);
        }
        return dp[start][end]=ans;
    }
public:
    int matrixMultiplication(int n, int arr[])
    {
        memset(dp,-1,sizeof(dp));
        return solve(1,n-1,arr);
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
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends