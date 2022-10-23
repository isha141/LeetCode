class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
          vector<int>ans;
        int n=nums.size();
        int xe=0;
        for(int i=1;i<=n;++i)
            xe^=i;
        // int numsxe=0;
        for(auto itr: nums)
            xe^=itr; 
        int x=0;
        int y=0; 
        int set_bits= xe & ~(xe-1);
        for(int i=1;i<=n;++i){
            if(i& set_bits)
                x^=i;
            else  
                y^=i;
        }
        for(auto itr: nums){
            if(itr & set_bits)
                x^=itr;
            else
                y^=itr;
        }
         bool found=0;
        for(auto itr: nums){
            if(itr==x){
                found=1;
            }
        }
        if(found)
            return {x,y};
        else
            return {y,x};
        
    }
    
};