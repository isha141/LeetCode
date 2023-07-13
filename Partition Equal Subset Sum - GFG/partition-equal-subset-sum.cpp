//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{ 
    private:
    int n;
    int solve(int i,int arr[],int target,vector<vector<int>>&dp){ 
        if(target==0) return 1;
        if(i>=n) return 0;
        if(target<0) return 0; 
        if(dp[i][target]!=-1) 
        return dp[i][target];
        int pick=solve(i+1,arr,target-arr[i],dp);
        int not_pick=solve(i+1,arr,target,dp);
        return dp[i][target]=(pick| not_pick);
    }
public:
    int equalPartition(int n, int arr[])
    {
        // code here 
        int sum=0; 
        this->n=n;
        for(auto i=0;i<n;++i) sum+=arr[i];
        if(sum%2) return 0; 
        vector<vector<int>>dp(n,vector<int>((sum/2)+1,0));
        for(int i=0;i<n;++i){
            dp[i][0]=1;
        }
        if(arr[0]<=sum/2)
        dp[0][arr[0]]=1;
        for(int i=1;i<n;++i){
            for(int target=1;target<=sum/2;++target){
                int not_pick=dp[i-1][target];
                int pick=0;
                if(arr[i]<=target){
                    pick=dp[i-1][target-arr[i]];
                }
                dp[i][target]=(pick | not_pick);
            }
        }
        return dp[n-1][sum/2];
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