//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution { 
    private:
    int dx[4]={1,0,0,-1};
    int dy[4]={0,1,-1,0};
  public:
    int MinimumEffort(vector<vector<int>>& h) {
        // Code here 
        int n=h.size();
        int m=h[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[0][0]=0;
        pq.push({0,{0,0}}); 
        int ans=0;
        while(!pq.empty()){
            auto itr=pq.top();
            pq.pop();
            int node=itr.first; 
            int x=itr.second.first;
            int y=itr.second.second; 
            ans=max(ans,node);
            if(x==n-1 && y==m-1){ 
                 return ans;
            }
            for(int k=0;k<4;++k){
                int nx=dx[k]+x;
                int ny=dy[k]+y;
                if(nx>=0 && ny>=0 && nx<n && ny<m && dis[nx][ny]>abs(h[x][y]-h[nx][ny])){
                    pq.push({abs(h[x][y]-h[nx][ny]),{nx,ny}});
                      dis[nx][ny]=abs(h[x][y]-h[nx][ny]);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends