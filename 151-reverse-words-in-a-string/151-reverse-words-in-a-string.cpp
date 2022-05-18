class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        stringstream ss(s);
        string word="";
        while(ss>>word)
        {
            cout<<word<<" "; 
            ans=word+(ans.size()?" ":"")+ans;
        }
        return ans;
    }
};