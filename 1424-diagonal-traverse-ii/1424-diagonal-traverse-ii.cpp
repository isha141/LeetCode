class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
      map<int,vector<pair<int,int>>>mp;
        int i=0;
        int j=0;
        for(auto itr: nums){
            j=0;
            for(auto it: itr){
                mp[i+j].push_back({i,it});
                j++;
            }
            i++;
        }
        vector<int>ans;
        for(auto itr: mp){
            vector<pair<int,int>>ds=itr.second;
            sort(ds.rbegin(),ds.rend());
            for(auto itr: ds)
                ans.push_back(itr.second);
        }
        return ans;
    }
};