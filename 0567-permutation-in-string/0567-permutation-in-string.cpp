class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int>mp1,mp2; 
        for(auto itr: s1)
            mp1[itr]++;
        int i=0; 
        int m=s1.size();
        int n=s2.size();
        if(m>n) return 0;
        while(i<m){
            mp2[s2[i]]++;
            i++;
        }
        int j=i;
        while(j<n){
            if(mp1==mp2)
                  return 1;
            mp2[s2[j]]++;
            mp2[s2[j-m]]--;
            if(mp2[s2[j-m]]==0)
                mp2.erase(s2[j-m]);
                j++;
        } 
        if(mp1==mp2)
            return 1;
        return 0;
    }
};