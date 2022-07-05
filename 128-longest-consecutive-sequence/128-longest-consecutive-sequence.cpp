class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int ans=0; 
        unordered_set<int>s;
        for(auto itr: nums)
            s.insert(itr);
        for(auto itr: nums){
            if(s.count(itr-1));
            else{
                int temp=itr+1; 
                int c=1;
                while(s.count(temp))   c++, temp++; 
                
                ans=max(ans,c);
            }
        }
        return ans;
    }
};