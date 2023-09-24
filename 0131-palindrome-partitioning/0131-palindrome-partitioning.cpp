class Solution {
    private: 
    int n; 
    bool ok(string &temp){
        int i=0;
        int j=temp.size()-1;
        while(i<j){
            if(temp[i]!=temp[j])
                  return 0;
            i++;
            j--;
        }
         return 1;
    }
    void solve(int i,string &s,vector<string>&ds,vector<vector<string>>&ans){
          if(i>=n){
              ans.push_back(ds);
                return;
          }
          for(int j=i;j<n;++j){
              string temp=s.substr(i,j-i+1);
              if(ok(temp)){
                  ds.push_back(temp);
                  solve(j+1,s,ds,ans);
                   ds.pop_back();
              }
          }
    }
public:
    vector<vector<string>> partition(string s) {
          n=s.size();
          vector<vector<string>>ans;
          vector<string>ds;
          solve(0,s,ds,ans);
          return ans;
    }
};