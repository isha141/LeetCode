class Solution {
public:
    string makeGood(string s) {
        int n=s.size();
        string ans="";
        while(s.size()){
            bool flag=0;
            for(int i=0;i<s.size()-1;++i){
                if(islower(s[i]) && isupper(s[i+1])){
                    int ch1=s[i]-'a';
                    int ch2=s[i+1]-'A';
                    // cout<<i<<" "<<ch1<<" "<<ch2<<endl;
                    if(ch1==ch2){
                        s.erase(i,2);
                        // s.erase(i+1,1);
                        // cout<<s<<endl;
                        flag=1;
                        break;
                    }
                }
                 else if(isupper(s[i]) && islower(s[i+1])){
                    int ch1=s[i]-'A';
                    int ch2=s[i+1]-'a';
                    // cout<<i<<" "<<ch1<<" "<<ch2<<endl;
                    if(ch1==ch2){
                        s.erase(i,2);
                        // s.erase(i+1,1);
                        // cout<<s<<endl;
                        flag=1;
                        break;
                    }
                }
            }
            if(!flag)
                return s;
        }
        return "";
    }
};