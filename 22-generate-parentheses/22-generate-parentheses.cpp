class Solution { 
    private:
    void solve(int n,int op,int cl,vector<string>&ans,string temp)
    {
        if(op==n && cl==n)
            ans.push_back(temp);
        else{
        if(op<n)
            solve(n,op+1,cl,ans,temp+'(');
        if(cl<op)
            solve(n,op,cl+1,ans,temp+')');
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp="";
        solve(n,0,0,ans,temp);
        return ans;
    }
};
// class Solution {
// public:
//     vector<string> generateParenthesis(int n) {
//         vector<string> parens;
//         string paren;
//         generate(n, 0, 0, paren, parens);
//         return parens;
//     }
// private:
//     void generate(int n, int l, int r, string paren, vector<string>& parens) {
//         if (l == n && r == n) {
//             parens.push_back(paren);
//         } else {
//             if (l < n) {
//                 generate(n, l + 1, r, paren + '(', parens);
//             }
//             if (r < l) {
//                 generate(n, l, r + 1, paren + ')', parens);
//             }
//         }
//     }
// };