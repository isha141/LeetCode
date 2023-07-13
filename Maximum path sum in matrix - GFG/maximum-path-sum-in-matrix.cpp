//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

int dp[505][505];
class Solution{ 
    private:  
     int n;
    int solve(int i,int j,vector<vector<int>>&mat){
        if(i>=n || j>=n || i<0 || j<0) return 0; 
        if(i==n-1 && j==n-1)
          return mat[i][j];
         if(dp[i][j]!=-1)
          return dp[i][j];
        
        return dp[i][j]=mat[i][j]+max(solve(i+1,j,mat),max(solve(i+1,j-1,mat),solve(i+1,j+1,mat)));
    }
public:
    int maximumPath(int n, vector<vector<int>> mat)
    {
        // code here
         this->n=n;  
         for(int i=0;i<n;++i){
             dp[0][i]=mat[0][i];
         }
         for(int i=1;i<n;++i){
             for(int j=0;j<n;++j){
                 int left=0;
                 int right=0;
                 int down=0;
                 if(i>0){
                   left=dp[i-1][j]+mat[i][j];  
                 }
                 else{
                     left=mat[i][j];
                 }
                 if(j>0 && i>0){
                     right=dp[i-1][j-1]+mat[i][j];
                 } 
                 else right=mat[i][j];
                 if(i>0 && j+1<n){
                     down=dp[i-1][j+1]+mat[i][j];
                 } 
                 else down=mat[i][j];
                 dp[i][j]=max(left,max(right,down));
             }
         } 
         int ans=0;
         for(int i=0;i<n;++i){
             ans=max(ans,dp[n-1][i]);
         }
         return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends