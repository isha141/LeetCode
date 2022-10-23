class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
      vector<int>ans;
        map<int,int>mp;
        int n=nums.size();
        for(auto itr: nums){
            if(mp.find(itr)!=mp.end())
                ans.push_back(itr);
           mp[itr]++;
        }
        // int 
        for(int i=1;i<=n;++i){
            if(mp.find(i)==mp.end())
                ans.push_back(i);
        }
        return ans;
        
        
    }
};