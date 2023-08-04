class Solution { 
    private:
    vector<string> ans;  
    int n;
    void solve(int i,string &s,map<string,int>&mp,string temp){
        if(i>=n){ 
            temp.pop_back();
            ans.push_back(temp);
            return ;
        }
        string a="";
        for(int j=i;j<n;++j){
              a+=s[j];
              if(mp.find(a)!=mp.end()){
                  solve(j+1,s,mp,temp+a+" ");
              }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& w) {
        map<string,int>mp; 
        n=s.size();
        for(auto itr: w){
            mp[itr]++;
        }
          solve(0,s,mp,"");
           return ans;
        
    }
};