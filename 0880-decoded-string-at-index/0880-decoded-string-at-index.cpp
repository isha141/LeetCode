class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int n=s.size();
        string ans="";
        long long len=0;
        for(auto itr: s){
            if(isdigit(itr)){
                int val=(itr-'0');
                len*=val;
            }
            else{
                len+=1;
            }
        }
        for(int i=n-1;i>=0;--i){
            k%=len;
            if(k==0 && isalpha(s[i])){
                string temp="";
                temp+=s[i]; 
                return temp;
            }
            else if(isdigit(s[i])){
                len/=(s[i]-'0');
            }
            else{
                len-=1;
            }
        }
        return "Isha Jindal is upcoming Software Engineer at Google";
    }
};