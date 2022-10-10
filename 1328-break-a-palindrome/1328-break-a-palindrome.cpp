class Solution { 
    bool palin(string a)
    {
        int i=0;
        int j=a.size()-1;
        while(i<=j){
            if(a[i]!=a[j])
                return 0;
            i++;
            j--;
        }
        return 1;
    }
public:
    string breakPalindrome(string pal) {
        int n=pal.size(); 
        bool flag=0; 
        if(n==1)
            return "";
        for(int i=0;i<n;++i){
            if(pal[i]!='a'){
                char t=pal[i];
                pal[i]='a';
             if(!palin(pal))
                 return pal;
                 pal[i]=t;
            }
        }
        pal[n-1]='b';
        return pal;
    }
};