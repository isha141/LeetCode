// 10  3  6  
// 8  1  0  
// 9  9  4  
// 10  14  15  
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>ds(n,vector<int>(m,0));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                ds[i][j]=mat[i][j];
                if(i-1>=0){
                    ds[i][j]^=ds[i-1][j];
                }
                if(j-1>=0) 
                    ds[i][j]^=ds[i][j-1]; 
                if(i-1>=0 && j-1>=0){
                    ds[i][j]^=ds[i-1][j-1];
                }
            }
        } 
        priority_queue<int>pq;
        for(auto itt: ds){
            for(auto itr: itt){
                pq.push(itr);
                // cout<<itr<<"::";
            }
            cout<<endl;
        }
        while(--k) pq.pop();
        return pq.top();
        // return 0;
    }
};