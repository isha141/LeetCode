class Solution {
public:
    bool closeStrings(string w1, string w2) {
        vector<int>v1(26),v2(26);
        // set<char>s1,s2;
        for(auto itr: w1){
            v1[itr-'a']++;
            // s1.insert(itr);
        }
        for(auto itr: w2){
            v2[itr-'a']++;
             // s2.insert(itr);
        }
        return multiset(v1.begin(),v1.end())==multiset(v2.begin(),v2.end()) && 
             set(w1.begin(),w1.end())==set(w2.begin(),w2.end());
    }
};