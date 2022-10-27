class Solution { 
    private:
    int n;  
    int ans=0;
    int solve(int r,int c,vector<vector<int>>& a, vector<vector<int>>& b){
        int t=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(((i+r)<0 || (i+r)>=n || (j+c)<0 || (j+c)>=n ))
                   continue;
                 if(a[i][j]==1 && b[i+r][j+c]==1)
                   t++;
            }
        }
        return t;
        
        
        
        
        
        
        
    }
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
         n=img1.size();
        for(int i=-n;i<n;++i){
            for(int j=-n;j<n;++j){
                ans=max(ans,solve(i,j,img1,img2));
            }
        }
        return ans;
    }
};