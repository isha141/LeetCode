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
        if(pal.size()==1)
            return "";
        bool flag=0;  
        if(pal.size()==3){
            if(pal[pal.size()-1]=='a'){
                pal[pal.size()-1]='b';
            return pal;
            }
        }
        for(auto itr: pal){
            if(itr!='a')
                flag=1;
        }
        if(!flag){
            pal[pal.size()-1]='b';
        return pal;
         }
        char ch='a';
    for(int i=0;i<pal.size();++i){
        if(pal[i]!='a'){
           char t=pal[i];
            pal[i]='a';
            if(!palin(pal))
                 return pal;
            pal[i]=t;
        }
     }
        if(pal[pal.size()-1]=='a'){
            pal[pal.size()-1]='b'; 
        }
        return pal;
    }
};