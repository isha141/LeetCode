class Solution {
public:
    int numSub(string s) {
       int n=s.size();  
        int mod=1e9+7;
        long long ans=0;
        for(long long  i=0,j=0;i<=s.size();i++)
        {
            if( i==s.size() || s[i]=='0' ){
              ans=ans+((i-j)*long (i-j+1)/2)%mod;  
                j=i+1;
            }
        }
        return ans;
    }
};