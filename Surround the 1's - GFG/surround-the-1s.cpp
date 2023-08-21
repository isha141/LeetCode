//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution { 
    int dx[8]={-1,1,0,0,-1,-1,1,1};
    int dy[8]={0,0,1,-1,1,-1,1,-1};
public:
    int Count(vector<vector<int> >& matrix) {
        // Code here 
        int count=0;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                int res=0;
                if(matrix[i][j]==0) continue;
                for(int k=0;k<8;++k){
                    int nx=dx[k]+i;
                    int ny=dy[k]+j;
                    if(nx>=0 && nx<n && ny>=0 && ny<m){
                        if(matrix[nx][ny]==0)
                         res+=1;
                    }
                }
                if(res%2==0 && res!=0)
                  count+=1;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends