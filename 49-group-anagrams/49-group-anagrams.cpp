class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        for(auto itr: strs)
        {
            string s=itr;
            sort(s.begin(),s.end());
            mp[s].push_back(itr);
        }
        vector<vector<string>> ans;
        for(auto &itr: mp)
        {
            ans.push_back(itr.second);
        }
        return ans;
    }
};