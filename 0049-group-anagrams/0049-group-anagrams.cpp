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
            ans.push_back(itr.second);
       }
        return ans;
    }
};