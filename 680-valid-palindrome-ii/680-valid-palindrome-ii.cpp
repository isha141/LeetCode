class Solution { 
    private: 
    bool flag=0;
    bool solve(int ind,string &temp,int n)
    {
        if(ind>=n)
            return true;
        else if(temp[ind]==temp[n])
           return  solve(ind+1,temp,n-1); 
       else if(flag)
            return false;
        flag=1;
        return solve(ind+1,temp,n)|| solve(ind,temp,n-1);
    }
public:
    bool validPalindrome(string s) {
        int n=s.size();
        return solve(0,s,n-1);
    }
};