class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
         int n=mat.size();
         int m=mat[0].size();
         int low=0;
         int high=n*m-1;
         while(low<=high){
             int mid=(low+high)>>1;
             int row=mid/m;
             int col=mid%m;
             if(mat[row][col]==target)
                   return 1;
             if(mat[row][col]<target){
                 low=mid+1;
             }
             else{
                 high=mid-1;
             }
         }
        return 0;
    }
};