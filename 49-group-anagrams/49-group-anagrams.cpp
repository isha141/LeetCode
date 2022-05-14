class Solution { 
    private:
    string counters(string s)
    {
        char a[26]={0};
        for(int i=0;i<s.size();i++)
        {
            a[s[i]-'a']++;
        } 
        string temp="";
        for(int i=0;i<26;i++)
        {
            temp+=string(a[i],i+'a');
        } 
        return temp;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        for(auto &itr: strs)
        {
            string s=counters(itr);
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