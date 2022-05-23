class Solution {
public:
    int minMoves(vector<int>& nums) { 
        int n=nums.size();
    return accumulate(nums.begin(),nums.end(),0L)-n* *min_element(begin(nums),end(nums));    
    }
};