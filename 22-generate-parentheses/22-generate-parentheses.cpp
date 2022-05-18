class Solution { 
    private:
    void solve(int n,int op,int cl,vector<string>&ans,string &temp)
    {
        if(op==n && cl==n){
            ans.push_back(temp);
            return ;}
        else{
        if(op<n){ 
            temp+='(';
            solve(n,op+1,cl,ans,temp);
            temp.erase(temp.size()-1);
        }
        if(cl<op){ 
           temp+=')';
            solve(n,op,cl+1,ans,temp);
             temp.erase(temp.size()-1);
        }
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
