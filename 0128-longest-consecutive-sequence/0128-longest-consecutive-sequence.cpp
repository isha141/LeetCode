class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int ans=0;
        set<int>s;
        for(auto itr: nums){
            s.insert(itr);
        }
        for(auto itr: nums){
            if(s.find(itr-1)==s.end()){
                int count=0;
                int num=itr;
                while(s.find(num)!=s.end()){
                    count++;
                    num++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};