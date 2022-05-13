class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        if(n<3)
            return 0;
        sort(nums.begin(),nums.end());
        int i=0; 
        int ans=INT_MAX;
        int closest =nums[0]+nums[1]+nums[2];
        while(i<n-2)
        {  
            if(i>0 && nums[i]==nums[i-1]){
                i++;
                continue;
            }
            int j=i+1; 
            int k=n-1;
            while(j<k)
            {
               int curr=nums[i]+nums[k]+nums[j];
                 if(curr==target)
                   return curr;
                if(abs(target-curr)<abs(target-closest))
                 {
                   closest=curr;    
                 } 
               if(curr<target)
                   j++;
                   else
                   k--;
            }
            i++;
        }
        return closest;
    }
};