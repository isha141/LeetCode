class Solution { 
    private:
    void solve(vector<vector<int>>& image, int sr, int sc, int &color,int &t)
    {
        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size() || image[sr][sc]!=t)
            return ; 
        image[sr][sc]=color;
        solve(image,sr+1,sc,color,t);
        solve(image,sr,sc+1,color,t);
        solve(image,sr-1,sc,color,t);
        solve(image,sr,sc-1,color,t);
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) { 
        int t=image[sr][sc]; 
        if(image[sr][sc]==color)
            return image;
        solve(image,sr,sc,color,t); 
        return image;
    }
};