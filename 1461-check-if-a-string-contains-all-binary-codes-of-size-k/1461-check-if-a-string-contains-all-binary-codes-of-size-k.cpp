class Solution {
public:
    bool hasAllCodes(string s, int k) {
       set<string>s1;
        if(k>s.size()) return 0;
        for(int i=0;i<=s.size()-k;i++)
        {
            s1.insert(s.substr(i,k));
        }
        
        return s1.size()==int(1<<k);
    }
};