class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        map<int,int>mp;
        set<int>s;
        for(auto itr: arr)
            mp[itr]++;
        for(auto itr: mp){
            if(s.find(itr.second)!=s.end()) return 0;
            s.insert(itr.second);
        }
        return 1;
    }
};