class Solution { 
    private:
    bool ispalin(string s)
    {
        int i=0;
        int j=s.size()-1;
        while(i<=j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    private:
    void solve(int ind,string s,vector<string>&ds,vector<vector<string>>&ans)
    {
        if(ind==s.size())
        {
            ans.push_back(ds);
             return ;
        } 
        
        for(int i=ind;i<s.size();i++)
        {
            if(ispalin(s.substr(ind,i-ind+1)))
            {
                ds.push_back(s.substr(ind,i-ind+1));
                solve(i+1,s,ds,ans);
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>ds;
        solve(0,s,ds,ans);
        return ans;
    }
};