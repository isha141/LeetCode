class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
      map<int,vector<int>>mp;
        int i=0;
        int j=0;
        for(auto itr: nums){
            j=0;
            for(auto it: itr){
                mp[i+j].push_back(it);
                j++;
            }
            i++;
        }
        vector<int>ans;
        for(auto itr: mp){
            vector<int>ds=itr.second;
            // sort(ds.rbegin(),ds.rend());
            reverse(ds.begin(),ds.end());
            for(auto itr: ds)
                ans.push_back(itr);
        }
        return ans;
    }
};