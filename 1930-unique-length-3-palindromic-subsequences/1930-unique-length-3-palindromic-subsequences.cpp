class Solution {
public:
    int countPalindromicSubsequence(string s) {
          int n=s.size();
          map<char,int>right;
          map<char,int>left;
         int ans=0;
        vector<vector<int>>dp(26,vector<int>(26,0));
          for(int i=0;i<n;++i){
              right[s[i]]++;
              if(right[s[i]]==3)
                  ans+=1;
              dp[s[i]-'a'][s[i]-'a']++;
          }
          for(int i=0;i<n;++i){
              for(int j=0;j<26;++j){
                  if(dp[s[i]-'a'][j]==0 && left.find(j+'a')!=left.end() && right.find(j+'a')!=right.end()){ 
                      ans+=1;
                      dp[s[i]-'a'][j]++;
                  }
              }
              left[s[i]]++;
              right[s[i]]--;
              if(right[s[i]]==0)
                   right.erase(s[i]);
          }
         return ans;
    }
};