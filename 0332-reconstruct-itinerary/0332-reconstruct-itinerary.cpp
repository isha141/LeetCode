class Solution { 
    private:
    vector<string>ans;
    map<string,priority_queue<string,vector<string>,greater<string>>>adj; 
     void solve(string temp){
         auto &edges=adj[temp];
          while(!edges.empty()){
              auto itr=edges.top();
               edges.pop();
               solve(itr);
          }
         ans.push_back(temp);
     }
public:
    vector<string> findItinerary(vector<vector<string>>& t) {
          for(auto itr: t){
              adj[itr[0]].push(itr[1]);
          }
          solve("JFK");
        reverse(ans.begin(),ans.end());
         return ans;
    }
};