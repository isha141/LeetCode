class Solution { 
    bool isvalid(int start,int end,vector<int>&rows)
    {
        for(auto it: rows){
            if(it>=start && it<=end)
                return 0;
        }
        return 1;
    }
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& res) {
        map<int,vector<int>>mp;
        for(auto it: res){
            if(it[1]==1 || it[1]==10) continue;
         mp[it[0]].push_back(it[1]);
        } 
        int ans=(n-mp.size())*2; 
        for(auto itr: mp){
            if(isvalid(2,5,itr.second)|| isvalid(4,7,itr.second)|| isvalid(6,9,itr.second))
                ans++;
        }
        return ans;
    }
};