
class Solution { 
public: 
    string solve(int i)
    { 
        string as;
        while(i){
            as+=(i%2?'1':'0');
            i/=2;
        } 
        return as;
    }
    int concatenatedBinary(int n) {
        string s;
        while(n){
            s+=solve(n);
            n--;
        } 
        const int mod=1e9 + 7;
        long long p=1;
        long long ans=0;
        for(auto &c: s){
            if(c=='1'){
                ans+=p;
                ans%=mod;
            }
            p*=2;
            p%=mod;
        }
        return ans;
    }
};