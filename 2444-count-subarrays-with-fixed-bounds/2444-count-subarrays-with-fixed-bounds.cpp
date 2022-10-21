class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        long long c=0; 
        int start=0;
        bool minifound=0;
        bool maxifound=0;
        int mini=-1;
        int maxi=-1;
        for(int i=0;i<n;++i){
            if(nums[i]==minK){
                mini=i;
                minifound=1;
            }
            if(nums[i]==maxK){
                maxi=i;
                maxifound=1;
            }
            if(nums[i]<minK|| nums[i]>maxK){
                minifound=0;
                maxifound=0; 
                start=i+1;
            }
            if(minifound && maxifound){
                c+=min(mini,maxi)-start+1;
            }
        }
        return c;
    }
};