//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution { 
    private:
    int n,m;
    int ds[4][2]={{-1,0},{0,1},{0,-1},{1,0}};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor) {
        n=image.size();
        m=image[0].size();
       int color=image[sr][sc];
        queue<pair<int,int>>q; 
        vector<vector<int>>ans(n,vector<int>(m,0));
        ans=image;
        q.push({sr,sc}); 
        image[sr][sc]=-2;
        while(!q.empty()){
            auto itr=q.front();
            q.pop();
            int x=itr.first;
            int y=itr.second; 
            ans[x][y]=newcolor;
            for(int xi=0;xi<4;++xi){
                    int currx=x+ds[xi][0];
                    int curry=y+ds[xi][1];
                    if(currx>=0 && curry>=0 && currx<n && curry<m && image[currx][curry]==color){
                        q.push({currx,curry}); 
                        image[currx][curry]=-2;
                    }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends