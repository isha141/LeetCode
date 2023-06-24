int dp[1005][26][26];
class Solution { 
     private:
    int n;
    int solve(int i,vector<string>&w,char first,char last){
        if(i>=n)
            return 0;
        string s=w[i]; 
        int ans=INT_MAX; 
        if(dp[i][first-'a'][last-'a']!=-1)
             return dp[i][first-'a'][last-'a'];
        if(last==s[0]){
            ans=min(ans,int(s.size())-1+solve(i+1,w,first,s[s.size()-1]));
        }
        else{
            ans=min(ans,int(s.size())+solve(i+1,w,first,s[s.size()-1]));
        }
        if(first==s[s.size()-1]){
            ans=min(ans,int(s.size())-1+solve(i+1,w,s[0],last));
        }
        else{
            ans=min(ans,int(s.size())+solve(i+1,w,s[0],last));
        }
        return dp[i][first-'a'][last-'a']=ans;
    }
public:
    int minimizeConcatenatedLength(vector<string>& w) {
         n=w.size();
         memset(dp,-1,sizeof(dp));
         string t=w[0];
         return t.size()+solve(1,w,t[0],t[t.size()-1]);
    }
};