class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ans="";
        int i=0;
        int n=s.size();
       while(i<n){
           ans+=s[i];
           auto ind=s.find(ans,i+1);
           if(ind!=string::npos){
               int j=i+1;
                bool flag=1; 
               int m=ans.size();
              while((j+m)<=n){
             string temp=s.substr(j,m);
                 if(temp!=ans){
                   flag=0;
                    break;
                }
                j+=m;
             } 
              if(flag && j>=n){ 
                   return 1;
               }
           } 
           i+=1;
       } 
        return 0;
    }
};