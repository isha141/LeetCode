class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        vector<vector<int>> ans; 
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<n;i++)
        {
            vector<int>ds;
            for(int j=0;j<m;j++)
            {
                ds.push_back(mat[j][i]);
            }
            ans.push_back(ds);
        }
        return ans;
    }
};