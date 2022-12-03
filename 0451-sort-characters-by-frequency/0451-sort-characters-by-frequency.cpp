class Solution {
public:
    string frequencySort(string s) {
        vector<int>ds(128,0);
        for(auto itr: s)
            ds[itr]++;
        sort(s.begin(),s.end() ,[&](char a,char b){
            return ds[a]>ds[b] || (ds[a]==ds[b] && a<b);
        });
        return s;
    }
};