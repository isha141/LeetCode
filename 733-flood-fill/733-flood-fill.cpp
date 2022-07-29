class Solution { 
    private:
    void solve(vector<vector<int>>& image, int sr, int sc, int color)
    {
        int m=image.size();
        int p=image[0].size(); 
        vector<vector<int>>vis(m,vector<int>(p,0)); 
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1}; 
        vis[sr][sc]=1;  
        int col= image[sr][sc]; 
        cout<<col<<" ";
        image[sr][sc]=color;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        while(!q.empty()){ 
            int n=q.size();
            while(n--){ 
                auto itr=q.front();
                q.pop();
                int x=itr.first;
                int y=itr.second;
                for(int i=0;i<4;++i){
                 int xi=dx[i]+x;
                 int yi=dy[i]+y;  
                    // cout<<xi<<" "<<yi<<endl;
                if(xi>=0 && xi<m && yi>=0 && yi<p && image[xi][yi]==col && !vis[xi][yi] ){
                    q.push({xi,yi});
                    vis[xi][yi]=1; 
                    // cout<<"hy";
                    image[xi][yi]=color;
                }
             }
        }
        } 
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        solve(image,sr,sc,color);
        return image;
    }
};