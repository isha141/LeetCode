class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxi) {
          int n=maxi.size();
          long long ans=0; 
          stack<int>s;
          vector<long long>pre(n,0);
          vector<long long>suff(n,0);
          for(int i=0;i<n;++i){
              while(s.size() && maxi[s.top()]>maxi[i]){
                  s.pop();
              }
              if(s.size()==0){
                  pre[i]=1ll*(i+1)*maxi[i];
              }
              else{
                  pre[i]=pre[s.top()]+1ll*(i-s.top())*maxi[i];
              }
              s.push(i);
          }
         while(!s.empty()) s.pop();
         for(int i=n-1;i>=0;--i){
             while(s.size() && maxi[s.top()]>maxi[i])
                 s.pop();
             if(s.size()==0){
                 suff[i]=1ll*(n-i)*maxi[i];
             }
             else{
                 suff[i]=suff[s.top()]+1ll*(s.top()-i)*maxi[i];
             }
             s.push(i);
         } 
         for(int i=0;i<n;++i){
             ans=max(ans,pre[i]+suff[i]-maxi[i]);
         }
         return ans;
    }
};