class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        long ans=0;
        map<char,int>mp;
        int i=0;
        int j=0;
        // while(j<3){
        //     mp[s[j]]++;
        //     j++;
        // } 
        // if(mp.size()==3 && n==3)
        //     return 1;
        // j--;
        while(j<n){
             mp[s[j]]++;
            if(mp.size()==3){ 
                while(i<j && mp.size()==3){
                  ans+=(n-j);
                  mp[s[i]]--; 
                    if(mp[s[i]]==0)
                        mp.erase(s[i]);
                i++;
                }
            }
            j++;
        }
        return ans;
        
    }
};