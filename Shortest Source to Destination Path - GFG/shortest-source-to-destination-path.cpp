//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution { 
    private:
    int n,m;  
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    int solve(int i,int j,vector<vector<int>>&a,int x,int y){
        queue<pair<int,int>>q;
        q.push({0,0}); 
        int c=0;
        a[0][0]=0;
        while(!q.empty()){
             int t=q.size();
              while(t--){
                  auto itr=q.front();
                  q.pop();
                  int i=itr.first;
                  int j=itr.second; 
                  if(i==x && j==y){
                      return c;
                  }
                  for(int k=0;k<4;++k){
                     int nx=dx[k]+i;
                     int ny=dy[k]+j;
                     if(nx>=0 && nx<n && ny>=0 && ny<m && a[nx][ny]==1){
                         a[nx][ny]=0;
                         q.push({nx,ny});
                     }
                  }
              }
            c+=1;
        }
        return -1;
    }
  public:
    int shortestDistance(int N, int M, vector<vector<int>> a, int x, int y) {
        // code here 
        n=N;
        m=M;
        if(a[0][0]==0){
          return -1; 
        }
        if(a[x][y]==0){
             return -1;
        }
        int ans=solve(0,0,a,x,y); 
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends