class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<string>>ans;
        map<string,vector<string>>mp;
        for(auto itr: strs){
            string t=itr;
            sort(t.begin(),t.end());
            mp[t].push_back(itr);
        }
        for(auto itr: mp){
            vector<string>ds;
        for(auto it: itr.second)
            ds.push_back(it);
            ans.push_back(ds);
       }
        return ans;
    }
};