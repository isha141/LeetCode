class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>adj[n+1]; 
        map<int,int>mp;
        for(auto itr: trust){
            adj[itr[0]].push_back(itr[1]); 
            mp[itr[1]]++;
        }
        for(int i=1;i<=n;++i){
            if(adj[i].size()==0 && mp[i]==n-1)
                return i;
        }
        return -1;
    }
};