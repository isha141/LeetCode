class Solution { 
    private: 
    int n;
    void solve(int i,unordered_map<int,string>&mp,vector<string>&ans,string &d,string &temp)
    {
        if(i>=n){
            ans.push_back(temp);
            return ;
        }
        string p=mp[d[i]-'0']; 
        // cout<<p<<" ";
        for(int j=0;j<p.size();++j){
            temp+=p[j];
            solve(i+1,mp,ans,d,temp);
            temp.pop_back();
        }        
    }
public:
    vector<string> letterCombinations(string d) {
        vector<string>ans;
         n=d.size(); 
        if(n==0)
            return ans;
        unordered_map<int,string>mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        string temp="";
        solve(0,mp,ans,d,temp);
        return ans;
        
    }
};