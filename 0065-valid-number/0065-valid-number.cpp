class Solution {
public:
    bool isNumber(string s) {
        int n=s.size();
        int count=0; 
        int char1=0;
        for(auto itr: s){
            if(itr=='.')  count++;
            if(itr>='a' && itr<='z' && itr!='e') return  0;
            if(itr>='A' && itr<='Z'  && itr!='E') return 0;
            if(itr=='E' || itr=='e') char1++;
        }
        if(count>=2) return 0; 
        if(char1>=2) return 0;
        // if(!isdigit(s[0])) return 0;
         if(n==1){
             if(!isdigit(s[0]))
                   return 0;
             return 1;
         }
        if(n==2){
             if(isdigit(s[0]) && s[1]=='e' ||s[1]=='E') return 0;
             if(isdigit(s[0]) && isdigit(s[1])) return 1;
              if(isdigit(s[0]) && s[1]=='.') return 1;
             if(s[0]=='.' || s[0]=='+' || s[0]=='-'){
                 if(isdigit(s[1])) return 1;
             }
            return 0;
        }
        int j=0; 
        bool flag=0;
        while(j<n){ 
             if(isdigit(s[j])){
                 j++; continue;
             }
             if(s[j]=='+'){
                  // cout<<j<<";;"<<endl; 
                 if(j==n-1) return 0;
                if(j>0 && isdigit(s[j-1])) return 0;
                if(j>0 && (s[j-1]=='E' || s[j-1]=='e')){
                    j++; 
                    continue;
                }
                if(j>0){
                return 0;
                }
                j++;  
                // cout<<j<<"&&&"<<endl;
                continue;
            }
            else if(s[j]=='-'){ 
                if(j==n-1) return 0;
                if(j>0 && isdigit(s[j-1])) return 0;
                if(j>0 && (s[j-1]=='E' || s[j-1]=='e')) {
                    j++;
                    continue;
                }
                if(j>0){
                    return 0;
                }
                 j++;
                continue;
            }
            else if(s[j]=='.'){ 
                if(flag) return 0;
                if(j>0 && isdigit(s[j-1])){
                    j++; 
                    continue;
                }
                if(j==1 && (s[j-1]=='+' || s[j-1]=='-')){
                    j++;
                    continue;
                }
                if(j>0){
                    return 0;
                }
                j++; 
                continue;
            }
            else if(s[j]=='e'){ 
                if(j==n-1) return 0;
                 flag=1;
                if(j>0 &&  isdigit(s[j-1]))  { 
                     if(j==n-1) return 0;
                     j++; continue;
                }
                if(j>0  && j!=1  && s[j-1]=='.'){
                    j++;
                    continue;
                } 
                return 0;
            } 
            else if(s[j]=='E'){ 
                if(j==n-1) return 0;
                if(j>0 && !isdigit(s[j-1]))
                     return 0;
                j++;
            }
        }
        return 1;
    }
};