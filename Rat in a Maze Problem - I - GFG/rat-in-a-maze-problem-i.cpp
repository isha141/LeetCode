// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{ 
    private:
    void solve(int i,int j,int *di,int *dj,vector<vector<int>> &m,int n,vector<string>&ans,string temp,vector<vector<int>>&v)
    {
        if(i==n-1 && j==n-1)
        {
            ans.push_back(temp); 
//cout<<temp<<" ";
            return ;
        }
        string s="DLRU"; 
        //cout<<temp<<" ";
        for(int k=0;k<4;k++)
        {
            int x=i+di[k];
            int y=j+dj[k];
            if(x>=0  && x<n && y>=0  && y<n && m[x][y]==1 && v[x][y]==0)
            { 
                v[i][j]=1;
                solve(x,y,di,dj,m,n,ans,temp+s[k],v);
                v[i][j]=0;
            }
        }
    }
    public:
    vector<string> findPath(vector<vector<int>> &maze, int n) {
        // Your code goes here  
        vector<string> ans; 
        vector<vector<int>>v(n,vector<int>(n,0));
        string temp;
        int di[4]={1,0,0,-1};
        int dj[4]={0,-1,1,0};
        if(maze[0][0]==1) 
        solve(0,0,di,dj,maze,n,ans,temp,v);
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