//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{ 
    private:
    int solve(int i,int j,string &a,string &b,vector<vector<int>>&dp)
    {
        if(i<0 || j<0)
        return 0; 
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(a[i]==b[j])
        return dp[i][j]= 1+ solve(i-1,j-1,a,b,dp); 
        else
        
        return dp[i][j]= max(solve(i-1,j,a,b,dp),solve(i,j-1,a,b,dp));
        
    }
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string a, string b)
    {
        // your code here  
        vector<int>prev(y+1,0); 
        for(int i=1;i<=x;++i){ 
            vector<int>curr(y+1,0);
            for(int j=1;j<=y;++j){ 
                int l=0;
                int r=0;
                if(a[i-1]==b[j-1]){
                    l=1+prev[j-1];
                }
                else 
                r=max(prev[j],curr[j-1]); 
                curr[j]=max(l,r);
            } 
            prev=curr;
        }
        
        return prev[y];
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends