//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{ 
    private:
    int solve(int i,int j,string &a,string &b,vector<vector<int>>dp)
    {
        if(i==0 && j==0){
            return a[0]==b[0];
        } 
        if(i<0)
        return 0;
        if(j<0)
        return 0; 
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(a[i]==b[j]){
            return dp[i][j]=1+solve(i-1,j-1,a,b,dp);
        }
        return dp[i][j]=max(solve(i-1,j,a,b,dp),solve(i,j-1,a,b,dp));
    }
  public:
    int longestPalinSubseq(string a) {
        //code here 
        int n=a.size();
        string temp=a;
        reverse(temp.begin(),temp.end()); 
        vector<int>prev(n+1,0);  
        for(int i=1;i<=n;++i){
                vector<int>curr(n+1,0);
            for(int j=1;j<=n;++j){
                int take=0;
                int not_take=0;
                if(a[i-1]==temp[j-1]){
                    take=1+prev[j-1];
                }
                else
                not_take=max(prev[j],curr[j-1]);
            curr[j]=max(take,not_take);
            } 
            prev=curr;
        } 
        return prev[n-1+1];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends