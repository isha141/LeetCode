class Solution { 
    private:
    int solve(long long mid,vector<int>nums){
     // if(nums[0]>mid)
         // return 0;
        long long ans=0; 
        long long ex=0;
        // if(nums[0]<mid)
        //     ex+=mid-nums[0];
        for(int i=0;i<nums.size();++i){
             if(nums[i]>mid && ex<nums[i]-mid)
                 return 0; 
            if(nums[i]>mid)
              ex-=nums[i]-mid;
            else
                ex+=mid-nums[i];
        }
        return 1;
    }
public:
    int minimizeArrayValue(vector<int>& nums) {
       long long low=0;
        long long high=1000000000;
        long long ans=0;
        while(low<=high){
            long long mid=(low+high)>>1;
            if(solve(mid,nums)){
                ans=mid; 
                cout<<mid<<" ";
               high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};