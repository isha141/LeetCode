class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int first=0;
        int a=-1;
        for(int i=0;i<n;++i){
            if(a==-1 || first==0){
                first+=1;
                a=nums[i];
            }
            else if(a==nums[i]){
                first+=1;
            }
            else {
                first-=1;
                // a=nums[i];
            }
        }
        return a;
    }
};