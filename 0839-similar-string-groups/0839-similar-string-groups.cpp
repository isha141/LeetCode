class Solution { 
    private:
    bool ok(string &a,string &b){
        int n=a.size();
        int count=0;
        for(int i=0;i<n;++i){
            if(a[i]!=b[i]){
                count++;
            }
            if(count>2)
                 return 0;
        }
        return count==2|| count==0;
    }
    void solve(string &temp,vector<string>&strs,set<string>&vis){
          vis.insert(temp);
          for(auto itr: strs){
              if(vis.find(itr)==vis.end() && ok(itr,temp)){
                  solve(itr,strs,vis);
              }
          }
        return ;
    }
public:
    int numSimilarGroups(vector<string>& strs) {
         set<string>vis;
        int ans=0;
        for(auto itr: strs){
            if(vis.find(itr)==vis.end()){
                ans+=1;
                solve(itr,strs,vis);
            }
        }
        return ans;
    }
};