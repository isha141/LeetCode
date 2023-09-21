//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends

class Solution
{
    private:
    int solve(int i,int arr[],int n,vector<int>&dp){
        if(i>=n)
          return 0;
        if(dp[i]!=-1)
           return dp[i];
        int take=0;
        int not_take=0;
        take=arr[i]+solve(i+2,arr,n,dp);
        not_take=solve(i+1,arr,n,dp);
        return dp[i]=max(take,not_take);
    }
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
         vector<int>dp(n,-1);
        return solve(0,arr,n,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends