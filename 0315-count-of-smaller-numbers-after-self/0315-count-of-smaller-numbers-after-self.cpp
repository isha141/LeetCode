class Solution {
     private:    
     int merge(int low,int mid,int high,vector<pair<int,int>>&nums,vector<pair<int,int>>&temp,vector<int>&ans){
         int i=low;
         int j=mid+1; 
         int c=0;
         int k=low;
         while(i<=mid && j<=high){
             if(nums[i].first<=nums[j].first){
                 temp[k++]=nums[j++];
             }
             else{
                 ans[nums[i].second]+=(high-j+1);
                 temp[k++]=nums[i++];
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
         return c;
     }
    void solve(int low,int high,vector<int>&ans,vector<pair<int,int>>&ds,vector<pair<int,int>>&temp){
         if(low<high){
             int mid=(low+high)
                 >>1;
             solve(low,mid,ans,ds,temp);
             solve(mid+1,high,ans,ds,temp);
             merge(low,mid,high,ds,temp,ans);
         }
        return;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
         int n=nums.size();
         vector<int>ans(n,0); 
         vector<pair<int,int>>ds(n); 
         vector<pair<int,int>>temp(n);
         for(int i=0;i<n;++i){
             ds[i].first=nums[i];
             ds[i].second=i;
         }
         solve(0,nums.size()-1,ans,ds,temp);
         return ans;
    }
};