class Solution { 
    private:
    int solve(int i,vector<int>&nums){
        int c=0;
        for(auto itr: nums)
            c+=abs(itr-i);
        return c;
    }
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int low=0;
        int high=nums[nums.size()/2];
        int ans=0;
        // while(low<=high){
            // int mid=(low+high)>>1;
            int temp=solve(high,nums);
             // if(ans>=temp){
                 // ans=temp;
                 // high=mid-1;
             // }
            // else
                // low=mid+1;
        // }
        return temp;
    }
};