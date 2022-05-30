// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{ 
    private:
    void solve(int i,int j, vector<vector<int>> &m,string temp,vector<string>&ans,int n,vector<vector<int>>&vis)
    {
        if(i==n-1 && j==n-1){ 
            if(m[i][j]==1)
                 ans.push_back(temp);
        return ;
       }   
      if(m[i][j]==0)
      return ;
       if(i+1<n && !vis[i+1][j]){ 
           vis[i][j]=1;
       solve(i+1,j,m,temp+'D',ans,n,vis); 
       vis[i][j]=0;
       }
       if(j+1<n &!vis[i][j+1] ){ 
           vis[i][j]=1;
       solve(i,j+1,m,temp+'R',ans,n,vis);  
       vis[i][j]=0;
       }
       if(j-1>=0 && !vis[i][j-1]){ 
           vis[i][j]=1;
        solve(i,j-1,m,temp+'L',ans,n,vis);  
        vis[i][j] =0;
       }
        if(i-1>=0 && !vis[i-1][j]){ 
            vis[i][j]=1;
        solve(i-1,j,m,temp+'U',ans,n,vis);
        vis[i][j]=0;
        }
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here 
        vector<string> ans;
        string temp=""; 
        vector<vector<int>> vis(n,vector<int>(n,0));
        solve(0,0,m,temp,ans,n,vis);
        return ans;
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends