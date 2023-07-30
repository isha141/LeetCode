//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

int dp[1002][1002];
class Solution{
  private:
   int solve(int i,int j,string &str){
        if(i==j){
            return 0;
        } 
        if(i>j) return 0;
        int take=1e9;
        int not_take=1e9;
        if(dp[i][j]!=-1)
         return dp[i][j];
        if(str[i]==str[j]){
            take=solve(i+1,j-1,str);
        }
        else{
            not_take=1+min(solve(i+1,j,str),solve(i,j-1,str));
        }
        return dp[i][j]=min(take,not_take);
   }
  public:
    int countMin(string str){
    //complete the function here 
      memset(dp,-1,sizeof(dp));
      return solve(0,str.size()-1,str);
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