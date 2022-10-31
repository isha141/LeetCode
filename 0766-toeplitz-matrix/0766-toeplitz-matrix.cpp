class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size(); 
        for(int k=0;k<n;++k){
            int t=mat[k][0]; 
            int j=0; 
            int i=k;
            while(i<n && j<m){
                if(mat[i][j]!=t)
                    return 0;
                i++;
                j++;
            }
        }
        for(int k=0;k<m;++k){
            int temp=mat[0][k];
            int i=0; 
            int j=k;
            while(i<n && j<m){
                if(mat[i][j]!=temp)
                    return 0;
                i++;
                j++;
            }
        }
        return 1;
    }
};