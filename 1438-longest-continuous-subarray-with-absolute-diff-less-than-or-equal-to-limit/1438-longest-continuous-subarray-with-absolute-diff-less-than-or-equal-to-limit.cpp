class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        int ans=1; 
        multiset<int>m;
        int i=0;
        int j=0; 
        while(j<n){
            m.insert(nums[j]);
            if(*m.rbegin()-*m.begin()>limit){
                m.erase(m.find(nums[i++]));
            }
            j++;
        }
        return j-i;
        // return 
    }
};