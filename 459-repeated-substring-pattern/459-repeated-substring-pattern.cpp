class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string S=s+s;
        return S.substr(1,S.size()-2).find(s)!=-1;
    }
};