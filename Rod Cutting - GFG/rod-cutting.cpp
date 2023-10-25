//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int dp[1001][1001];
class Solution{
    private:
    int n;
    int solve(int i,int price[],int len){
         if(i>=n)
           return 0;
         if(len==0) 
          return 0;
         if(dp[i][len]!=-1)
          return dp[i][len];
         int take=0;
         int not_take=0;
        if(len>=i+1)
        take=price[i]+solve(i,price,len-i-1);
        not_take=solve(i+1,price,len);
        return dp[i][len]=max(take,not_take);
    }
  public:
    int cutRod(int price[], int n) {
          this->n=n;
          memset(dp,-1,sizeof(dp));
          return solve(0,price,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends