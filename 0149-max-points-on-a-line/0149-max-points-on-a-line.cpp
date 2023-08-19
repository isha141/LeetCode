class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
         int n=p.size();
        int ans=0;

// 
          for(int i=0;i<n;++i){ 
                     map<double,int>mp;
              for(int j=i+1;j<n;++j){
                  double temp=p[j][1]-p[i][1];
                  double temp2=p[j][0]-p[i][0];
                  if(temp==0){
                      mp[INT_MAX]++;
                      continue;
                  }
                  double ans=(temp2/temp);
                  mp[ans]++;
              } 
              for(auto itr: mp){
                  ans=max(ans,itr.second);
              }
         }
         // // int ans=0;
         //  for(auto itr: mp){
         //      ans=max(ans,itr.second);
         //  }
        return ans+1;
    }
};