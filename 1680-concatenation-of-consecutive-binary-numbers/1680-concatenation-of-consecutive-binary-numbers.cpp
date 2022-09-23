// class Solution {
//     public:
//    string to_binary(int i)
//     {
//         string ans;
//         while(i){
//             ans+=(i%2?'1':'0');
//             i/=2;
//         } 
//        return ans;
//     }
//     int concatenatedBinary(int n) {
//         string s;
//         while(n)
//         {            s+=to_binary(n);
//          n--;
//         }
//         long long ans=0;
//         long long p=1;
//        int const mod=1e9+7;
//         for(auto &c: s){
//             if(c=='1'){
//                 ans+=p;
//                 ans%=mod;
//             }
//             p=p*2;
//             p%=mod;
//         }
//         return ans;
//         // return 0;
//     }
// };
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