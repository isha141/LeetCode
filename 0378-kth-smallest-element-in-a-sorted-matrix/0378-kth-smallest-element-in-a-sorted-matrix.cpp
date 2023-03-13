class Solution {  
    private:
    int n,m;
    int ok(int mid,vector<vector<int>>&mat){
        int ans=0;
        for(int i=0;i<n;++i){
            if(mat[i][m-1]<=mid){
                ans+=m;
            }
            else{
                int j=m-1;
                while(j>=0 && mat[i][j]>mid)
                    j--;
                ans+=(j+1);
            }
        }
        return ans;
    }
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
            n=mat.size();
            m=mat[0].size();
        int low=mat[0][0];
        int high=mat[n-1][m-1]; 
        int ans=0;
        while(low<=high){
            int mid=(low+high)>>1;  
            if(ok(mid,mat)>=k){ 
                // cout<<mid<<"::"<<endl;
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