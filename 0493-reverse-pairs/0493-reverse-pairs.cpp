class Solution {
    private:
    void merge(int low,int mid,int high,vector<int>&nums,vector<int>&temp){
        int i=low;
        int j=mid+1;
        int k=low;
        while(i<=mid && j<=high){
            if(nums[i]<nums[j]){
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
    }
    int countpairs(int low,int mid,int high,vector<int>&nums){
        int ans=0;
        int j=mid+1;
        for(int i=low;i<=mid;++i){
            while(j<=high && nums[i]>(2*1ll*nums[j])){
                j++;
            }
              ans+=(j-(mid+1));
        }
        return ans;
    }
    int solve(int low,int high,vector<int>&nums,vector<int>&temp){
        int cnt=0;
        if(low<high){
            int mid=(low+high)>>1;
            cnt+=solve(low,mid,nums,temp);
            cnt+=solve(mid+1,high,nums,temp);
            cnt+=countpairs(low,mid,high,nums);
            merge(low,mid,high,nums,temp);
        }
        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
         int n=nums.size();
         vector<int>temp(n,0);
         return solve(0,n-1,nums,temp);
         // return ans;
    }
};