int dp[1002];
class Solution {
    private:
    bool ok(string &a,string &b){
        int n=a.size();
        int m=b.size();
        if(m-n!=1) return 0;
        int count=0;
        int i=0;
        int j=0;
        while(i<n && j<m){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else{
                j++;
                count+=1;
            }
        }
        while(i<n){
              count+=1;
            i++;
        }
        while(j<m){
            count+=1;
            j++;
        }
        if(count==1) return 1;
        return 0;
        
    }
    int solve(int i,vector<string>&word,string temp){
        if(dp[i]!=-1)
              return dp[i];
        int ans=0;
        for(int j=0;j<word.size();++j){
            if(temp.size()==0 || ok(temp,word[j])){
                ans=max(ans,1+solve(j,word,word[j]));
            }
        }
        return dp[i]=ans;
    }
public:
    int longestStrChain(vector<string>& words) { 
        memset(dp,-1,sizeof(dp));
        return solve(0,words,"");
    }
};