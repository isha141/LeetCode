class Solution {
public:
    int countHomogenous(string s) {
         int n=s.size();
         int ans=0;
         int i=0;
         int mod=1e9+7;
         while(i<n){
             int len=1;
             int j=i+1;
             int count=0;
             while(j<n && s[i]==s[j]){
                 len+=1;
                 j++;
             }
             ans+=((1ll*len%mod*1ll*(len+1)%mod)/2)%mod;
             i=j;
         }
        return ans;
    }
};