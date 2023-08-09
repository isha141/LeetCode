class Solution { 
    private:
     int ok(int mid,vector<int>&nums){
           int c=0;
          int i=0;
           int n=nums.size();
           while(i<n){
               if(i+1<n && abs(nums[i]-nums[i+1])<=mid){
                     c+=1;
                     i+=2;
               }
               else{
                   i++;
               }
           }
          return c;
     }
public:
    int minimizeMax(vector<int>& nums, int p) {
           int n=nums.size();
           int ans=0;
           sort(nums.begin(),nums.end());
           int low=0;
           int high=1e9; 
           while(low<=high){
               int mid=(low+high)>>1;
               if(ok(mid,nums)>=p){
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