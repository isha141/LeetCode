class Solution {
public:
    bool closeStrings(string w1, string w2) {
        if(w1.size()!=w2.size())
            return 0;
        map<char,int>mp1,mp2;
        set<char>s1,s2;
        for(auto itr : w1){
           s1.insert(itr);
            mp1[itr]++;
        }
        for(auto itr: w2){
           s2.insert(itr);
        mp2[itr]++;
        }
        if(s1!=s2)
            return  0;
        vector<int>v1,v2;
        for(auto itr: mp1){
           v1.push_back(itr.second);
        }
        for(auto itr: mp2){
          v2.push_back(itr.second);
        }
        sort(v1.begin(),v1.end());
        sort(begin(v2),end(v2));
        return v1==v2;
        // return 1;
        
    }
};