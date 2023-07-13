//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

int dp[75][75][75];
class Solution { 
    private:
    int n,m;
    int solve(int i,int j1,int j2,vector<vector<int>>&mat){
        if(i<0 || j1<0 || j2<0|| i>=n || j1>=m || j2>=m) 
        return 0;
        if(i==n-1){
            if(j1==j2)
             return mat[i][j1];
            else 
            return mat[i][j1]+mat[i][j2];
        } 
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2]; 
        int left=0;
        if(j1==j2)
        left=mat[i][j1];
        else
        left=mat[i][j1]+mat[i][j2];
        int maxi=INT_MIN;
        for(int k=-1;k<=1;++k){ 
            int ans=0;
             for(int t=-1;t<=1;++t){
                    ans=max(ans,left+solve(i+1,j1+k,j2+t,mat));
                maxi=max(maxi,ans);
             }
        } 
        return dp[i][j1][j2]=maxi;
    }
  public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here  
        this->n=n;
        this->m=m; 
        memset(dp,-1,sizeof(dp));
        return solve(0,0,m-1,grid);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends