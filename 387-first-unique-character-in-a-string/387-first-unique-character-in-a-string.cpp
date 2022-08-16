class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int>mp;
        for(int i=0;i<s.size();++i){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]=i;
            }
            else{
                mp[s[i]]=-1;
            }
        } 
        int ans=s.size();
        for(auto [x,y]: mp){
            if(y!=-1)
                ans=min(ans,y);
        }
        return ans==s.size()?-1:ans;
    }
};