// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
    private:
    bool solve(int ind,vector<int>&arr,int sum,vector<vector<int>>&dp)
    {
        if(sum==0)
        return 1;
        if(ind<0)
        return 0; 
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        int not_pick=solve(ind-1,arr,sum,dp); 
        int pick=0;
        if(arr[ind]<=sum)
        pick=solve(ind-1,arr,sum-arr[ind],dp);
        return dp[ind][sum]= (pick||not_pick);
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here  
        int n=arr.size(); 
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(n-1,arr,sum,dp);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends