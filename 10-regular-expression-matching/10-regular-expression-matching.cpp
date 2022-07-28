class Solution { 
    private: 
    int prev=-1;
    bool solve(int i,int j,string &p,string &s) 
    {
            if(i<0 && j<0) 
                return 1;
            if(j==-1 && p[i]=='*')
                return solve(i-2,j,p,s);
        if(i<0 || j<0) return 0;
     if(p[i] =='.' || p[i]==s[j])
           return  solve(i-1,j-1,p,s);
        else if(p[i]=='*'){
         if(i-1>=0 && p[i-1]==s[j] || p[i-1]=='.')
             return (solve(i,j-1,p,s)|| solve(i-2,j,p,s));
            else{
                return solve(i-2,j,p,s);
            }
        } 
        else 
            return 0;
    }
public:
    bool isMatch(string s, string p) { 
        int ans=0;
       return solve(p.size()-1,s.size()-1,p,s); 
    }
};