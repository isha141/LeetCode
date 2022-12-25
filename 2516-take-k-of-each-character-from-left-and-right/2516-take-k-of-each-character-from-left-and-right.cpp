class Solution {
public:
    int takeCharacters(string s, int k) {
        int n=s.size();
        map<char,int>mp;
        for(auto itr: s){ 
            if(itr=='a')
            mp['a']++;
            if(itr=='b')
                mp['b']++;
            if(itr=='c')
                mp['c']++;
        } 
        int a=mp['a'];
        int b=mp['b'];
        int c=mp['c'];
        if(a<k || b<k || c<k) return -1;
        a-=k;
        b-=k;
        c-=k;
        int ans=0;
        int ca=0;int cb=0; int cc=0;
        int i=0;
        int j=0;
        while(j<n){
            if(s[j]=='a')
                ca++;
            if(s[j]=='b')
                cb++;
            if(s[j]=='c')
                cc++;
            while(i<=j && a<ca|| b<cb|| c<cc){
                if(s[i]=='a') ca--;
                if(s[i]=='b') cb--;
                if(s[i]=='c') cc--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return n-ans;
    }
};