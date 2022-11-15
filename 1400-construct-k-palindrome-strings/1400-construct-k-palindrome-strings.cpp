class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        if(n==k)
            return 1;
        if(n<k)
            return 0;
       map<char,int>mp;
        for(auto itr: s)
            mp[itr-'a']++;
        int c=0;
        for(auto itr: mp){
            if(itr.second%2)
                c+=1;
        }
        if(c>k)
            return 0;
        return 1;
    }
};