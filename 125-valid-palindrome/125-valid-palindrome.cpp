class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        for(auto itr: s)
        {
            if(isdigit(itr) || itr>='a'  && itr<='z'|| itr>='A' && itr<='Z')
            {
                temp+=tolower(itr);
            }
        }
        int n=temp.size();
        for(int i=0;i<n/2;i++)
        {
            if(temp[i]!=temp[n-i-1])
                return false;
        }
        return true;
    }
};