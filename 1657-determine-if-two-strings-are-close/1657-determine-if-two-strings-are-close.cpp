class Solution {
public:
    bool closeStrings(string w1, string w2) {
        vector<int>v1(26,0),v2(26,0);
        set<char>s1,s2;
        for(auto itr: w1){
            v1[itr-'a']++;
            s1.insert(itr);
        }
        for(auto itr: w2){
            v2[itr-'a']++;
             s2.insert(itr);
        }
        if(s1!=s2) return 0;
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        return v1==v2;
    }
};