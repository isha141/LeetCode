class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int mid=0;
        while(mid<n)
        {
            if(nums[mid]!=0)
            {
                nums[low++]=nums[mid++];
            }
            else
                mid++;
        }
        for(int i=low;i<n;i++)
            nums[i]=0;
        
    }
};