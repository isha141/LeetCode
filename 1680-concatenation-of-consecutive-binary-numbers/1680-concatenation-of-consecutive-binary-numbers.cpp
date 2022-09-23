
class Solution { 
public: 
    string solve(int i)
    { 
        string ans;
        while(i){
            ans+=(i%2?'1':'0');
            i/=2;
        } 
        return ans;
    }
    int concatenatedBinary(int n) {
        string s;
        while(n){
            s+=solve(n);
            n--;
        } 
        const int mod=1e9 + 7;
        long long p=1;
        long long res=0;
        for(auto &c: s){
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