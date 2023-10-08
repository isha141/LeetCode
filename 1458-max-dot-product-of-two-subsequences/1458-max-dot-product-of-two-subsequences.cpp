int dp[503][503];
class Solution {
    private:
    int n,m;
    private:
    int solve(int i,int j,vector<int>&nums1,vector<int>&nums2,bool flag){
        if(i>=n || j>=m){
         return 0;
            // return INT_MIN;
        }
        if(dp[i][j]!=0)
              return dp[i][j];
        int take=INT_MIN;
        int not_take=INT_MIN;
        take=(nums1[i]*nums2[j])+solve(i+1,j+1,nums1,nums2,1);
        not_take=max(solve(i,j+1,nums1,nums2,0),max(solve(i+1,j,nums1,nums2,flag),solve(i+1,j+1,nums1,nums2,flag)));
        return dp[i][j]=max(take,not_take);
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
          n=nums1.size();
          m=nums2.size();
          int fMini=INT_MAX;
          int fMaxi=INT_MIN;
          int sMini=INT_MAX;
          int sMaxi=INT_MIN;
          for(auto itr: nums1){
              fMini=min(fMini,itr);
              fMaxi=max(fMaxi,itr);
          }
          for(auto itr: nums2){
              sMini=min(sMini,itr);
              sMaxi=max(sMaxi,itr);
          } 
          if(fMaxi<0 && sMini>0){
              return fMaxi*sMini;
          }
           if(sMaxi<0 && fMini>0){
               return sMaxi*fMini;
           }
          memset(dp,0,sizeof(dp));
          return solve(0,0,nums1,nums2,0);
    }
};