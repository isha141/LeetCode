class Solution {  
    private: 
    int n;
    bool ispalin(string &s)
   {
    int i=0;
    int j=s.size()-1;
    while(i<=j){
        if(s[i]!=s[j])
            return 0;
        i++;
        j--;
    }
    return 1;
  }
    private:
    void solve(int i,string &s,vector<vector<string>>&ans,vector<string>&ds)
    { 
        if(i>=n) {  
            // for(auto itr: ds){
            //     cout<<itr<<" ";
            // }
            ans.push_back(ds);
            return ;
        }
        string temp="";
       for(int k=i;k<n;++k){
           temp+=s[k];
           if(ispalin(temp)){
               ds.push_back(temp); 
               // cout<<temp<<" "; 
               // for(auto itr: ds)
               //     cout<<itr<<" ";
               solve(k+1,s,ans,ds); 
               ds.pop_back();
           }
       } 
    }
public:
    vector<vector<string>> partition(string s) { 
         n=s.size();
        vector<vector<string>>ans;
        if(s.size()==0) return ans; 
        vector<string>ds;
         solve(0,s,ans,ds);  
        return ans;
    }
};