class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        priority_queue<int>pq;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
               pq.push(mat[i][j]);
                if(pq.size()>k)
                    pq.pop();
            }
        }
        return pq.top();
    }
};
