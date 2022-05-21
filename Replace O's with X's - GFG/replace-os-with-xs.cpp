// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{ 
    private:
    void solve(int i,int j,vector<vector<char>> &mat)
    {
        if(i<0 || j<0 || i>=mat.size()|| j>=mat[0].size() || mat[i][j]!='O')
        {
            return ;
        }  
        mat[i][j]='1'; 
        solve(i-1,j,mat);
        solve(i+1,j,mat);
        solve(i,j+1,mat);
        solve(i,j-1,mat);
        
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here 
        for(int i=0;i<n;i++)
        { 
           // cout<<"k";
            for(int j=0;j<m;j++)
            { 
                //cout<<"hy";
               if(i==0 || j==0 || i==n-1 || j==m-1)
               {
                   if(mat[i][j]=='O')
                      solve(i,j,mat);
               } 
            //   cout<<"hu";
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]=='1')
                  mat[i][j]='O';
                else if(mat[i][j]=='O')
                mat[i][j]='X';
            }
        }
        return mat;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends