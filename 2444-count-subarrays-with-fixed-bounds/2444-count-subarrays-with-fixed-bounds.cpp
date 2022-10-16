class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        int i=0;
        int j=0; 
        int maxi=0;
        int mini=0;
        int c=0;  
        bool minfound=0;
        bool maxfound=0;
        // int mini=0;
        long long  ans=0;
        int start=0;
        while(j<n){
           if(nums[j]==minK){
               mini=j;
               minfound=1;
           }
            if(nums[j]==maxK){
                maxi=j;
                maxfound=1;
            }
            if(nums[j]<minK || nums[j]>maxK){
                start=j+1;
                mini=j;
                maxi=j;
                minfound=0;
                maxfound=0;
            }
            if(minfound && maxfound){
                ans+=min(mini,maxi)-start+1;
                // cout<<start<<" "<<mini<<" "<<maxi<<endl;
            }
            j++;
        }
        return ans;
    }
};