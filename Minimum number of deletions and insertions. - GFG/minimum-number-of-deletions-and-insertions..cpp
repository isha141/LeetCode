// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	private:
	int solve(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
	    if(i<0 && j<0)
	    return 0;
	    if(i<0 )
	    return j+1;
	    else if(j<0) return i+1;
	    if(dp[i][j]!=-1)return dp[i][j];
	    int left=INT_MAX;
	    int right=INT_MAX;
	    if(s1[i]==s2[j])
	    left=solve(i-1,j-1,s1,s2,dp);
	    else 
	    right=1+ min(solve(i-1,j,s1,s2,dp),solve(i,j-1,s1,s2,dp));
	    return dp[i][j]=min(left,right);
	}

	public:
	int minOperations(string s1, string s2) 
	{ 
	    // Your code goes here
	    int m=s1.size();
	    int n=s2.size();
	    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
	    return solve(m-1,n-1,s1,s2,dp);
	    
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends