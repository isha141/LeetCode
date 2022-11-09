//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
 private: 
 int n;
void solve(int i,int arr[],int total,vector<vector<bool>>&dp){
     
    for(int i=0;i<n;++i)
    dp[i][0]=1;
    dp[0][arr[0]]=1;
    for(int i=1;i<n;++i){
        for(int target=1;target<=total;++target){
            bool not_pick=dp[i-1][target]; 
            bool pick=0;
            if(arr[i]<=target)
            pick=dp[i-1][target-arr[i]];
            dp[i][target]=(pick || not_pick);
        }
    }
    return ;
 }
  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here   
	    this->n=n;
	    int target=0;
	    for(auto i=0;i<n;++i)
	    target+=arr[i];
	    int ans=1e9;
	    vector<vector<bool>>dp(n,vector<bool>(target+1,0));
	    solve(0,arr,target,dp); 
	    for(int i=0;i<=target/2;++i){
	        if(dp[n-1][i]!=0){
	            int s1=i;
	            int s2=target-i;
	            ans=min(ans,abs(s1-s2));
	        } 
	       // cout<<dp[n-1][i]<<" ,";
	    }
	    return ans;
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
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends