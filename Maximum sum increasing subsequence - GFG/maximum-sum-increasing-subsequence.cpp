//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int dp[1002][1003];
class Solution{
	private:
	int solve(int i,int prev,int arr[],int n){
	    if(i>=n)
	     return 0;
	    int take=0;
	    int not_take=0;
	    if(dp[i][prev+1]!=-1)
	      return dp[i][prev+1];
	    if(arr[prev]<arr[i] || prev==-1){
	        take=arr[i]+solve(i+1,i,arr,n);
	    }
	    not_take=solve(i+1,prev,arr,n);
	    return dp[i][prev+1]=max(take,not_take);
	}
	public:
	int maxSumIS(int arr[], int n)  
	{   
	    memset(dp,-1,sizeof(dp));
	    return solve(0,-1,arr,n);
	}   
}; 

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends