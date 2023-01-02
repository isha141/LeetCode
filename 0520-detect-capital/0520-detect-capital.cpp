class Solution {
public:
    bool detectCapitalUse(string word) {
        bool flag=0;
        int up=0;
        int down=0;
        int cap=0;
        int j=0;
        int n=word.size();
        if(n==1) return 1;
        if(word[0]>='A' && word[0]<='Z') {
            cap++; j=1;
        }
        for(int i=j;i<n;++i){
            if(word[i]>='A' && word[i]<='Z'){
                up++;
            }
            else if(word[i]>='a' && word[i]<='z')
                down++;
        }
        if(down==n) return 1;
        if(cap && up==0 && down==n-1)
            return 1;
        if(down==0 && up==n-1 && cap) 
            return 1;
        return 0;
    }
};