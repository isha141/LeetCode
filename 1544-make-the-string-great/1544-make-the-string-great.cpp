class Solution {
public:
    string makeGood(string s) {
        int n=s.size();
        string ans=""; 
        while(1) { 
            bool flag=0;
        for(int i=0;i<n-1;++i){
            if(islower(s[i]) && isupper(s[i+1]) || islower(s[i+1]) && isupper(s[i]) ){
                char ch=tolower(s[i+1]);  
                char t=tolower(s[i]);
                if(ch==t)
                {
                    string temp=s.substr(0,i) +s.substr(i+2);
                    flag=1;
                    s=temp;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(!flag)
            return s;
        }
    return s;
    }
};