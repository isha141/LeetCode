class Solution { 
    vector<vector<string>>ans; 
    bool palin(string s){
        int i=0;
        if(s.size()==1) return 1;
        int j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }
    int n; 
    void solve(int ind,string s,vector<string>&ds){
         if(ind>=n){
             ans.push_back(ds);
             return ;
         }
        for(int i=ind;i<n;++i){ 
           //  cout<<ind<<",,"<<i<<endl;
           // cout<<ind<<"..."<<s.substr(ind,i-ind+1)<<endl;
           //  cout<<"******"<<endl;
            if(palin(s.substr(ind,i-ind+1))){
                ds.push_back(s.substr(ind,i-ind+1)); 
              
                solve(i+1,s,ds);
                ds.pop_back();
            }
        } 
        return ;
    }
public:
    vector<vector<string>> partition(string s) {
        n=s.size(); 
        vector<string>ds;
        solve(0,s,ds);
        return ans;
        
    }
};