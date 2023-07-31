long long dp[101][11][2][2];
class Solution { 
    private:
    int mod=1e9+7;
    void reversearray(){
        for(int i=0;i<101;++i){
            for(int j=0;j<11;++j){
                for(int k=0;k<2;++k){
                    for(int l=0;l<2;++l){
                        dp[i][j][k][l]=-1;
                    }
                }
            }
        }
    } 
    long long solve(string &s,int ind,int isprev,int istight,int iszero){
        if(ind>=s.size()){
            if(iszero)
                  return 0;
            return 1;
        } 
        if(dp[ind][isprev+1][istight][iszero]!=-1)
             return dp[ind][isprev+1][istight][iszero]%mod;
        int limit=s[ind]-'0';
        if(!istight){
            limit=9;
        } 
        long ans=0;
        for(int curr=0;curr<=limit;++curr){
            int nextight=(istight && (curr==limit));
            int nextzero=(iszero && (curr==0));
             if(abs(curr-isprev)==1 || iszero){
                ans+=solve(s,ind+1,curr,nextight,nextzero);
            }
        }
        return dp[ind][isprev+1][istight][iszero]=(ans+mod)%mod;
    }
public:
    int countSteppingNumbers(string low, string high) {
        reversearray();
        long long ans=solve(high,0,-1,1,1);
        reversearray();
        ans-=solve(low,0,-1,1,1);  
        ans=(ans+mod)%mod;
        bool flag=0;
        for(int i=0;i<low.size()-1;++i){
            int ch1=low[i]-'0';
            int ch2=low[i+1]-'0';
            if(abs(ch1-ch2)!=1){ 
                flag=1;
                 break;
            }
        } 
        if(!flag){
            ans=(ans+mod+ 1)%mod;
        }
         return ans;
        
        
    }
};