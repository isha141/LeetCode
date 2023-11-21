class Solution {
    private:
    void solve(int node,int parent,map<int,vector<int>>&mp,vector<int>&ans,set<int>&seen){
        ans.push_back(node);
         seen.insert(node);
          vector<int>ds=mp[node];
        for(auto iit: ds){
            if(iit==parent) continue;
            if(seen.find(iit)==seen.end()){
                solve(iit,node,mp,ans,seen);
            }
        }
    }
public:
    vector<int> restoreArray(vector<vector<int>>& adj) {
          int n=adj.size();
          map<int,vector<int>>mp;
          for(auto itr: adj){
              int u=itr[0];
              int v=itr[1];
              mp[u].push_back(v);
              mp[v].push_back(u);
          }
          int start=-1;
          for(auto itr: mp){
              if(itr.second.size()==1){
                      start=itr.first;
                      break;
            }
          }
          vector<int>ans;
          set<int>seen;
          solve(start,-1,mp,ans,seen);
          return ans;
    }
};