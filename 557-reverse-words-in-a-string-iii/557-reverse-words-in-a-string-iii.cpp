class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string ans="";
        int i=0;
        string temp="";
        while(i<n){
            if(s[i]!=' ')
                temp+=s[i];
            else{
                reverse(temp.begin(),temp.end());
                ans+=temp;
                ans+=' ';
                temp="";
            }
            i++;
        }
        if(temp.size())
            reverse(temp.begin(),temp.end());
            ans+=temp;
        return ans;
    }
};