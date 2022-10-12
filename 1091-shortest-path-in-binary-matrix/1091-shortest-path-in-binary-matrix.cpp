class Solution { 
    private: 
    int m;
    int n;
    int solve(int x,int y,vector<vector<int>>& grid)
    {
        vector<pair<int,int>>v={{-1,-1},{1,-1},{-1,1},{1,1},{1,0},{-1,0},{0,1},{0,-1},};
        queue<pair<int,int>>q; 
        int count=0;
        q.push({0,0});
        if(grid[0][0]==1)
            return -1; 
        int i=0; 
        // cout<<m<<" "<<n<<endl;
        while(!q.empty())
        { 
            int t=q.size();
            count++; 
            while(t--){
            auto itr=q.front();
            q.pop(); 
            int x=itr.first;
            int y=itr.second;  
                // cout<<x<<" "<<y<<endl;
            grid[x][y]=1;
            for(auto direction: v)
            {
              int cx=x+direction.first;
                int cy=y+direction.second; 
                // cout<<cx<<" "<<cy<<endl; 
                // if(cx>=0 && cx<n && cy>=0 && c)
                if(cx>=0 && cx<m && cy>=0 && cy<n && (grid[cx][cy]==0))
                { 
                    if(cx==m-1 && cy==n-1)
                        return count+1;
                if(grid[cx][cy]==0){
                        q.push({cx,cy});
                       grid[cx][cy]=1; 
                      //  cout<<cx<<" "<<cy<<endl;
                     }
                }
            
            }
            }
           // i++;
           // q.pop();
        }
        return -1;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         m=grid.size();
         n=grid[0].size();  
        if(n==1 && m==1 && grid[0][0]==0)
            return 1;
        int count=0; 
        int ans=INT_MAX;
        return solve(0,0,grid); 
        // if(ans==INT_MAX)
        //     return -1;
        // return ans; 
    }
};