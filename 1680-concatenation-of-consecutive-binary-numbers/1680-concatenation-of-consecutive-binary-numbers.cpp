class Solution {
public:
    string bin(int x){
        string s;
        while(x){
            s+=(x%2?'1':'0');
            x/=2;
        }
        return s;
    }
    int concatenatedBinary(int n) {
        string ans;
        while(n){
            ans+=bin(n);
            n--;
        }
        long long res = 0;
        int const mod = 1e9 + 7;
        long long p=1;
        for(char &c:ans){
            if(c=='1'){
                res+=p;
                res%=mod;
            }
            p*=2;
            p%=mod;
        }
        return res;
        
    }
};