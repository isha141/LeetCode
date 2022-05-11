class Solution { 
    private:
    int count(vector<int>& nums,int mid)
    {
        int c=0;
        for(auto itr: nums)
        {
            if(itr<=mid)
                c++;
        }
        return c;
    }
public:
    int findDuplicate(vector<int>& nums) { 
        int n=nums.size();
        int low=1;
        int high=n-1;  
        int dup=-1;
        while(low<high)
        {
            int mid=(low+high)/2; 
            if(count(nums,mid)<=mid)
            {  
                low=mid+1;
            }
            else{ 
                high=mid;
            }
        }
        return low;
    }
};