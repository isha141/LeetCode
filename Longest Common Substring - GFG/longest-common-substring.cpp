//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here 
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));  
        vector<int>prev(m+1,0);
        int maxi=0;
        for(int i=1;i<=n;++i){ 
             vector<int>curr(m+1,0);
            for(int j=1;j<=m;++j){ 
                int take=0;
                if(s1[i-1]==s2[j-1]){
                    take=prev[j-1]+1; 
                    maxi=max(maxi,take);
                }
                else{
                    take=0;
                }
                curr[j]=max(take,curr[j]); 
                maxi=max(maxi,curr[j]);
            } 
            prev=curr;
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends