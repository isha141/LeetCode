//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string str){
    //complete the function here 
    int n=str.size(); 
    string s=str;
    reverse(s.begin(),s.end());
     vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;++i){
           for(int j=1;j<=n;++j){
               int take=0;
               int not_take=0;
             if(s[i-1]==str[j-1]){
                 take=1+dp[i-1][j-1];
             }
             else{
                 not_take=max(dp[i-1][j],dp[i][j-1]);
             }
             dp[i][j]=max(take,not_take);
            }
        }
        return n-dp[n][n];
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends