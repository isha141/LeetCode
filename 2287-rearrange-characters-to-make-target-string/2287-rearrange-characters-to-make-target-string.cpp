class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        map<char,int>mp1,mp2;
        for(auto &c:target)
            mp1[c]++;
        for(auto &c: s )
            mp2[c]++; 
        int ans=INT_MAX;
        for(auto itr: mp1)
        { 
                ans=min(ans,mp2[itr.first]/mp1[itr.first]); 
        }
        return ans;
    }
};