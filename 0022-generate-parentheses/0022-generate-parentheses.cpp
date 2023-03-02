class Solution { 
    private:
    vector<string>ans; 
    void solve(int open,int close,int n,string &s){
        if(s.size()>=2*n){
            ans.push_back(s);
            return ;
        }
        if(open<n){
            s+='(';
            solve(open+1,close,n,s); 
            s.pop_back();
        }
        if(open>close){
            s+=')';
            solve(open,close+1,n,s);
            s.pop_back();
        }
        return ;
    }
public:
    vector<string> generateParenthesis(int n) {
        if(n==0)
              return {}; 
        string s="";
        solve(0,0,n,s);
        return ans;
    }
};