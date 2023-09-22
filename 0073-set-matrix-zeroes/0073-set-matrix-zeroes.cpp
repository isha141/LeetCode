class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row_size=matrix.size();
        int col_size=matrix[0].size();
        bool col=0;
        for(int i=0;i<row_size;++i){
              for(int j=0;j<col_size;++j){
                  if(matrix[i][j]==0){
                      matrix[i][0]=0;
                      if(j!=0){
                          matrix[0][j]=0;
                      }
                      else{
                          col=1;
                      }
                  }
              }
        }
        for(int i=1;i<row_size;++i){
            for(int j=1;j<col_size;++j){
                if(matrix[i][0]==0|| matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0]==0){
            for(int i=0;i<col_size;++i){
                matrix[0][i]=0;
            }
        }
        if(col){
            for(int i=0;i<row_size;++i){
                matrix[i][0]=0;
            }
        }
        return ;
    }
};