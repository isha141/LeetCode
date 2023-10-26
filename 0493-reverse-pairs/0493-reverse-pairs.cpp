class Solution {
    private: 
    int count(int low,int mid,int high,vector<int>&nums){
        int ans=0;
        int j=mid+1;
        while(low<=mid){
            while(j<=high && nums[low]>(1ll*2*nums[j])){
                 j+=1;
            }
            ans+=(j-mid-1);
            low+=1;
        }
        return ans;
    }
    int merge(int low,int mid,int high,vector<int>&nums,vector<int>&temp){
         int ans=0;
         ans=count(low,mid,high,nums);
         int i=low;
         int j=mid+1;
         int k=low;
         while(i<=mid && j<=high){
             if(nums[i]<=nums[j]){
                  temp[k++]=nums[i++];
             }
             else{
                 temp[k++]=nums[j++];
             }
         }
         while(i<=mid){
              temp[k++]=nums[i++];
         }
         while(j<=high){
              temp[k++]=nums[j++];
         }
         for(int i=low;i<=high;++i){
              nums[i]=temp[i];
         }
         return ans;
    }
    int solve(int low,int high,vector<int>&nums,vector<int>&temp){
          if(low>high)
               return 0;
        int ans=0;
         if(low<high){
             int mid=(low+high)>>1;
             ans+=solve(low,mid,nums,temp);
             ans+=solve(mid+1,high,nums,temp);
             ans+=merge(low,mid,high,nums,temp);
         }
        return ans;
    }
public:
    int reversePairs(vector<int>& nums) {
         int n=nums.size();
          vector<int>temp(n,0);
        return solve(0,n-1,nums,temp);
    }
};