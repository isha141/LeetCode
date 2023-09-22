class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // [[1,2,3]]   // [[1,4,7]]
        // [[4,5,6]]   // [[2,5,8]]
        // [[7,8,9]]   // [[3,6,9]]
         for(int i=0;i<n;++i){
             reverse(matrix[i].begin(),matrix[i].end());
         }
        return ;
    }
};