class Solution { 
    private: 
    int n; 
    int m;
    int count(int mid,vector<vector<int>>&mat){
         int c=0;
         int j=0;
          for(int i=0;i<n;++i){
              if(mat[i][m-1]<=mid){
                  c+=m;
              } 
              else {
                  int j=m-1;
                  while(j>=0 && mat[i][j]>mid)
                      j--;
                  c+=j+1;
              }
          }
        return c;
    }
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
         n=mat.size();
         m=mat[0].size(); 
        int low=mat[0][0];
        int high=mat[n-1][n-1]; 
        int ans=0;
        while(low<=high){
            int mid=(low+high)>>1; 
            if(count(mid,mat)>=k){
                ans=mid;
                high=mid-1;
            }
            else{
                  low=mid+1;
            }
        }
        return ans;
        
    }
};