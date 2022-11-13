class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n=nums.size();
        int c=0;
        for(int i=0;i<n;++i){
            for(int j=i,lcm=1;j<n && k%lcm==0 ;++j){
               lcm=lcm*nums[j]/(gcd(lcm,nums[j]));
                if(lcm==k)
                    c++;
            }
        }
        return c;
    }
};