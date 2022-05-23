class Solution {
public:
    string convertToTitle(int col) {
        string ans="";
        while(col)
        {
            int temp=col%26;
            if(temp==0)
            {
                ans+='Z';
                col=col/26-1;
            }
            else
            {
                ans+=temp-1+'A';
                col=col/26;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};