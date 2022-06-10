class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int low=0;
        int high=0;
        int ans=0; 
        map<char,int>mp;
        while(high<n){
            if(!mp.count(s[high])){
              mp[s[high]]=high;
                ans=max(ans,high-low+1);
            } 
            else if(mp[s[high]]>=low){
                low=mp[s[high]]+1;
                mp[s[high]] =high;
            }else{
                mp[s[high]] =high;
            }
             ans=max(ans,high-low+1);
            high++;
        }
        return ans;
    }
};