class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int ans=0;
        map<char,int>mp;
        int j=0;
        int i=0;
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                while(i<j && mp.find(s[j])!=mp.end()){
                    mp.erase(s[i]);
                    i++;
                } 
                mp[s[j]]=j;
            }
            else{
                mp[s[j]]=j;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};