class Solution {
public:
    int maximumProduct(vector<int>& nums) {
      // sort(nums.begin(),nums.end());  
        int mini1=INT_MAX;
        int mini2=INT_MAX;
        int maxi1=INT_MIN;
        int maxi2=INT_MIN;
        int maxi3=INT_MIN;
        int n=nums.size();
        for(auto itr: nums)
        {
            if(itr<=mini1)
            {
                mini2=mini1;
                mini1=itr;
            } 
            else if(itr<=mini2)
            {
                mini2=itr;
            }
            if(itr>= maxi1)
            { 
                maxi3=maxi2;
                maxi2=maxi1;
                maxi1=itr;
            }
            else if(itr>=maxi2)
            {
                maxi3=maxi2;
                maxi2=itr;
            } 
            else if(itr>=maxi3)
                maxi3=itr;
        }
        return max((mini1*mini2*maxi1),(maxi1*maxi2*maxi3));
       
    }
};