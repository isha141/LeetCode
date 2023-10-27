//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

int dp[1001][1001];
class Solution{
private:
  int solve(int i,int j,string &a,string &b){
        if(i<0  && j<0)
          return 0;
        if(i<0) 
         return 0;
        if(j<0)
        return 0;
        if(dp[i][j]!=-1)
          return dp[i][j];
        int take=0;
        int not_take=0;
        if(a[i]==b[j])
        take=1+solve(i-1,j-1,a,b);
        else
        not_take=max(solve(i-1,j,a,b),solve(i,j-1,a,b));
        return dp[i][j]=max(take,not_take);
  }
  public:
    int minimumNumberOfDeletions(string s) { 
        // code here
        string b=s;
        reverse(b.begin(),b.end());
        memset(dp,-1,sizeof(dp));
        int ans= solve(s.size()-1,b.size()-1,s,b);
        return b.size()-ans;
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends