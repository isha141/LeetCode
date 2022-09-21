class Solution {
public:
    int numWays(string s) {
       long long int n=s.size();
        int c=0;
        for(auto itr: s){
            if(itr=='1')
                c++;
        }
        if(c%3)
            return 0;  
        if(c==0)
            return ((n-1)*(n-2)/2)%1000000007;
        c/=3; 
        int cnt=0;
        long long int  ones=0;
        long long int two=0;
        for(int i=0;i<n;++i){
            if(s[i]=='1')
                cnt++;
            if(cnt==c)
                ones++;
            else if(cnt==2*c)
                two++;
        }
        return (ones*two)%1000000007;
        
    }
};