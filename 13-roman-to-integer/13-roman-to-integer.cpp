class Solution {
public:
    int romanToInt(string s) {
        map<char,int>mp;
        mp['I']=1; 
        mp['V']=5; 
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000; 
        int n=s.size()-1;
        int ans=mp[s[n]];  
        char ch=s[n];
        for(int i=n-1;i>=0;i--)
        { 
            if(mp[ch]<=mp[s[i]]){ 
                ans=ans+mp[s[i]]; 
                // cout<<ans<<" ";
            }
            else
                ans-=mp[s[i]]; 
            ch=s[i];
        }
       return ans; 
    }
};