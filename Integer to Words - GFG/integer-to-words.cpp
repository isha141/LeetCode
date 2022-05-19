// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{ 
    private:
    string twenty[10]={"","","twenty ","thirty ","forty ","fifty ","sixty ","seventy ","eighty ","ninety "};
    string ones[20]={"","one ","two ","three ","four ","five ","six ","seven ","eight ","nine ","ten ","eleven ","twelve ","thirteen ","fourteen ","fifteen ","sixteen ","seventeen ","eighteen ","nineteen "};
    private:
    string solve(long num,string temp)
    { 
        string res="";
        if(num>19)
        {
            res+=twenty[num/10]+ ones[num%10];
        }
        else
        res+=ones[num];
        if(num)
        res+=temp; 
        return res;
    }
public:
    string convertToWords(long n) {
        // code here 
        string ans="";
        if(n==0)
        return "";
        // string twenty[]={"","","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
        // string less_than_20={"","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
        ans+=solve((n/10000000),"crore "); 
        ans+=solve((n/100000)%100, "lakh ");
        ans+=solve((n/1000)%100 , "thousand ");
        ans+=solve((n/100)%10 , "hundred ");
        if(n>100 && n%100)
        ans+="and ";
        ans+=solve(n%100 ,"");
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long n;
        cin >> n;
        Solution ob;
        auto ans = ob.convertToWords(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends