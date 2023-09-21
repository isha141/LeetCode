class Solution {
public:
    int countPairs(vector<vector<int>>& coor,int k) {
          int n=coor.size();
          int ans=0;
          map<pair<int,int>,int>mp; 
          for(int i=0;i<n;++i){
              int x=coor[i][0];
              int y=coor[i][1];
              for(int j=0;j<=k;++j){
                  int val=(x^j);
                  int ny=(k-j)^y;
                  if(mp.find({val,ny})!=mp.end()){
                      ans+=mp[{val,ny}];
                  }
              }
              mp[{x,y}]++;

          }
        return ans;
    }
};