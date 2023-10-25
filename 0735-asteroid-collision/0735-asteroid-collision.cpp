class Solution {
public:
    vector<int> asteroidCollision(vector<int>& aster) {
          vector<int>ans;
          int n=aster.size();
          stack<pair<char,int>>s;
          for(int i=0;i<n;++i){
              char ch='L';
              if(aster[i]>0){
                  ch='R';
              }
              while(!s.empty() && s.top().first!=ch && s.top().second<abs(aster[i]) && ch=='L'){
                  s.pop();
              }
               bool flag=0;
              if(s.size()){
                  if(s.top().first!=ch && ch=='L'){
                      if(s.top().second==abs(aster[i])){
                          flag=1;
                          s.pop();
                      }
                      else if(s.top().second>abs(aster[i])){
                          flag=1;
                      }
                  }
              }
              if(flag==0){
                  s.push({ch,(aster[i])});
              }
          }
          while(!s.empty()){
              auto itr=s.top();
              s.pop();
              ans.push_back(itr.second);
          }
          reverse(ans.begin(),ans.end());
          return ans;
    }
};