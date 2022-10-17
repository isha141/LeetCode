class Solution {
public:
    bool checkIfPangram(string sen) {
        int n=sen.size();
        map<int,int>mp;
        for(auto itr: sen)
            mp[itr-'a']++;
        return mp.size()==26;
    }
};