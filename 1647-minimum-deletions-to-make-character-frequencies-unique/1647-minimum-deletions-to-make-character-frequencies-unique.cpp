class Solution {
public:
    int minDeletions(string s) {
        map<int,int>mp;
        vector<int>ans(26,0);
        for(int i=0;i<s.size();i++)
            ans[s[i]-'a']+=1;  
        int a=0;
        for(int i=0;i<26;++i){
            if(ans[i]!=0  && mp.count(ans[i])){  
                    int temp=ans[i];
                    while(mp.count(temp) && temp!=0){ 
                         // cout<<char(i+'a')<<" ";
                        temp--; 
                      a+=1; 
                    } 
                    if(temp>0)
                        mp[temp]++; 
                } 
            else
                mp[ans[i]]++;
        }
        return a;
    }
};