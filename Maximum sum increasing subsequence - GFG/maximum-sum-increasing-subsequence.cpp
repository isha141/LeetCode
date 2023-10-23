//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int dp[1001][1002];
class Solution{
	private:
	int solve(int i,int arr[],int n,int last){
	      if(i>=n){
	            return 0;
	      }
	      if(dp[i][last+1]!=-1)
	        return dp[i][last+1];
	      int take=0;
	      int not_take=0;
	      if(last==-1 || arr[last]<arr[i]){
	          take=arr[i]+solve(i+1,arr,n,i);
	      }
	      not_take=solve(i+1,arr,n,last);
	      return dp[i][last+1]=max(take,not_take);
	}
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    memset(dp,-1,sizeof(dp));
	   return solve(0,arr,n,-1);
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