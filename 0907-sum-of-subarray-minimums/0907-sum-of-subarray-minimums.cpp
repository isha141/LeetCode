class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
         int n=arr.size();
         int sum=0;  
         int mod=1e9+7;
         stack<pair<int,int>>s;
         vector<int>pre(n+1,0);
         vector<int>suff(n+1,0);
         pre[0]=1;
         suff[n-1]=1;
         s.push({arr[0],1});
         for(int i=1;i<n;++i){ 
              int ans=0;
             while(!s.empty() && s.top().first>arr[i]){
                 ans+=s.top().second;
                 s.pop();
             }
             pre[i]=ans+1;
             s.push({arr[i],ans+1});
         }
         while(!s.empty())
             s.pop();
         for(int i=n-1;i>=0;--i){
             int ans=0;
             while(!s.empty() && s.top().first>=arr[i]){
                 ans+=s.top().second;
                 s.pop();
             }
             suff[i]=ans+1;
             s.push({arr[i],ans+1});
         }
          for(int i=0;i<n;++i){
              int temp=(1ll*pre[i]*suff[i]*arr[i])%mod;
              sum=(1ll*sum%mod+temp%mod)%mod;
          }
         return sum;
    }
};