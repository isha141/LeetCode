//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    private:
    int solve(int i,int coins[],int m,int v,vector<vector<int>>&dp){
         if(v==0)
         return 0;
         if(i>=m)
         return 1e9;
         if(dp[i][v]!=-1)
         return dp[i][v];
         int take=1e9;
         int not_take=1e9;
         if(coins[i]<=v){
             take=1+solve(i,coins,m,v-coins[i],dp);
         }
         not_take=solve(i+1,coins,m,v,dp);
         return dp[i][v]=min(take,not_take);
    }

	public:
	int minCoins(int coins[], int m, int v) 
	{ 
	    vector<vector<int>>dp(m,vector<int>(v+1,-1));
	    sort(coins,coins+m);
	    int ans=solve(0,coins,m,v,dp);
	    if(ans==1e9)
	    return -1;
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
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends