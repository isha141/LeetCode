class Solution { 
    private: 
    int maxi=0; 
    int n; 
    bool ispalin(string s)
    {
        if(s.size()==0)
            return 0;
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])
                return 0;
            i++;
            j--;
        } 
        return 1;
    }
    void solve(int i,string &s,string &s1,string &s2)
    {
        if(i>=s.size()){
            if(ispalin(s1) && ispalin(s2)){
                int m=s1.size();
                int o=s2.size();
                maxi=max(maxi,m*o);
            }
               return ;
        }
     s1+=s[i]; 
     solve(i+1,s,s1,s2);
     s1.pop_back();

               
                 
     s2+=s[i];
     solve(i+1,s,s1,s2);
     s2.pop_back();
               
               
               
               
     solve(i+1,s,s1,s2);
               
    }
public:
    int maxProduct(string s) {
        n=s.size(); 
        string s1="";
        string s2="";
        solve(0,s,s1,s2); 
        return maxi;
        
    }
};