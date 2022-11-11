class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int k=0;
        for(int i=1;i<n;++i){
            if(nums[i]!=nums[i-1]) {
                // cout<<"isha";
                nums[++k]=nums[i];
            }
        } 
        cout<<k<<endl;
        return k+1;
    }
};