long long ans[1004][1004];
class Solution {
    private: 
    int mod=1e9+7;
    void ok(int n){ 
          memset(ans,0,sizeof(ans));
          for(int i=0;i<n;++i){
            // ans[i].resize(i+1); 
            if(i==0){
                ans[0][0]=1;
                continue;
            }
            // cout<<i<<".,,";
            ans[i][0]=1;
            ans[i][i]=1;
            for(int j=1;j<i;++j){ 
                 // cout<<i<<";;"<<j<<endl;
                ans[i][j]=(ans[i-1][j-1]+ans[i-1][j])%mod;
            }
            
        }
    }
    long long solve(vector<int>&nums,int n){ 
         if(nums.size()<3)
             return 1;
        vector<int>left,right; 
        int root=nums[0];
        for(int i=1;i<nums.size();++i){
            if(nums[i]<root)
                  left.push_back(nums[i]);
            else if(nums[i]>root)
                right.push_back(nums[i]);
        } 
        int t=nums.size();
        long long leftways=solve(left,n);
        long long rightways=solve(right,n);
        return ((leftways*rightways)%mod*(ans[t-1][left.size()])%mod)%mod;
    }
public:
    int numOfWays(vector<int>& nums) {
        int n=nums.size(); 
        ok(1001);
        return solve(nums,n)-1;
    }
};