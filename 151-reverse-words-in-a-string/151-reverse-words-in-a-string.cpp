class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int n=s.size();
        stringstream ss(s);
        string word="";
        while(ss>>word){
            //reverse(word.begin(),word.end());
            ans=word+(ans.size()?" ":"")+ans;
        }
        return ans;
    }
};