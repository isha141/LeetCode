class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int len=0;
        int i=0;
        vector<int>ds;
        ds=nums;
        sort(ds.begin(),ds.end());
        int mini=n;
        int maxi=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(ds[i]!=nums[i]){
                 mini=min(mini,i);
                maxi=max(maxi,i);
            }
                
        } 
        if(mini==n)
            return 0;
        return maxi-mini+1;
    }
};