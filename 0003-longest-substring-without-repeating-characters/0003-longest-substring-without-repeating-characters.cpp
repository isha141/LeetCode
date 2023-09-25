class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int n=s.size();
          int ans=0;
          map<char,int>mp;
           int i=0;
           int last=0;
          while(i<n){
             if(mp.find(s[i])==mp.end()){
                 mp[s[i]]=i;
                 ans=max(ans,i-last+1);
             }
             else{
                 last=max(mp[s[i]]+1,last);
                 mp[s[i]]=i;
             }
             ans=max(ans,i-last+1);
              i++;
          }
        return ans;
    }
};