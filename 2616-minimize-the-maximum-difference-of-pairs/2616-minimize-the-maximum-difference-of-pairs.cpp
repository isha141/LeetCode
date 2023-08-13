class Solution { 
    private:
    bool ok(int mid,vector<int>&nums,int p){
        int count=0;
        int i=0;
        int n=nums.size();
        while(i<n-1){
            if(nums[i+1]-nums[i]<=mid){
                count+=1;
                i+=2;
            }
            else{
                i+=1;
            }
        }
        if(count>=p)
             return 1;
        return 0;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
         int n=nums.size();
         sort(nums.begin(),nums.end());
         int low=0;
         int high=1e9; 
         int ans=0;
         while(low<=high){
             int mid=(low+high)>>1;
             if(ok(mid,nums,p)){
                 ans=mid;
                 high=mid-1;
             }
             else
                low=mid+1;
         }
         return ans;
    }
};