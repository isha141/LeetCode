class Solution { 
    private:
    int subarray(vector<int>&ds,int k)
    {
        int n=ds.size();
        int c=0; 
        int sum=0;
        map<int,int>mp; 
        mp[0]=1;
        for(int i=0;i<n;++i){
            sum+=ds[i]; 
            if(mp.count(sum-k))
                c+=mp[sum-k];
            mp[sum]++;
        }
        return c;
    }
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        int m=mat.size();  
        int count=0; 
        for(int i=0;i<m;++i){
            vector<int>ds(mat[0].size(),0);
            for(int j=i;j<m;++j){ 
                for(int k=0;k<mat[0].size();++k){
                     ds[k]+=mat[j][k];
                } 
                count+=subarray(ds,target); 
            }
        }
        return count;
    }
};