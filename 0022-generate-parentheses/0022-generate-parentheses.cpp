class Solution {
    private:
    void solve(int n,vector<string>&ans,int open,int close,string &temp){
        if(open==n && close==n){
            ans.push_back(temp);
            return ;
        } 
        // cout<<open<<";;"<<close<<";;;"<<temp<<endl;
        if(open<n){
            temp+='(';
            solve(n,ans,open+1,close,temp);
            temp.pop_back();
        }
        if(close<open && close<n){
            temp+=')';
            solve(n,ans,open,close+1,temp);
            temp.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp="";
        solve(n,ans,0,0,temp);
        return ans;
    }
};