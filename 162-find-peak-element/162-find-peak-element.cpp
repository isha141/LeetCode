class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0; 
        int n=nums.size()-1; 
        int high=nums.size()-1;
        //cout<<low<<" "<<high<<endl;
        while(low<high)
        {
            int mid=(low+high)/2; 
         //   cout<<mid<<" ";
            if((mid==0 or nums[mid]>nums[mid-1]) && (mid==n or  nums[mid]>nums[mid+1]))
                return mid;
            if(mid==0 or nums[mid-1]<nums[mid])
                low=mid+1;
            else
                high=mid-1; 
           /// cout<<low<<" "<<high<<endl;
        }
        return low;
    }
};