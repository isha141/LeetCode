class Solution {
public:
    int maxProduct(vector<int>& nums) {
          int n=nums.size();
          vector<int>pre(n,1);
          vector<int>suff(n,0);
          pre[0]=nums[0];
          for(int i=1;i<n;++i){
              if(pre[i-1]==0){
                  pre[i]=nums[i];
                  continue;
              }
              pre[i]=pre[i-1]*nums[i];
          }
          suff[n-1]=nums[n-1];
          for(int i=n-2;i>=0;--i){
              if(suff[i+1]==0){
                  suff[i]=nums[i];
                  continue;
              }
              suff[i]=suff[i+1]*nums[i];
          }
          int ans=INT_MIN;
          for(int i=0;i<n;++i){
              ans=max(ans,pre[i]);
              ans=max(ans,suff[i]);
              if(nums[i]<0 && (i-1)>=0){
                  ans=max(ans,pre[i-1]);
              }
              if(i+1<n && nums[i]<0){
                  ans=max(ans,suff[i+1]);
              }
          }
          return ans;
    }
};