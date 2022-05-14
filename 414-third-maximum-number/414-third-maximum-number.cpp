class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n=nums.size();
        set<int>s;
        for(auto itr:nums)
        {  
            s.insert(itr);
            if(s.size()>3)
                s.erase(s.begin());
        }
        return s.size()==3? *s.begin(): *s.rbegin();
    }
};