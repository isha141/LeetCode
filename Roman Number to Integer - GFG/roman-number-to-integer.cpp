//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        int ans=0;
        int n=str.size();
        map<char,int>mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        for(int i=0;i<n;++i){
            if((i-1)>=0 && mp[str[i-1]]<mp[str[i]]){
                ans-=mp[str[i-1]];
                int temp=mp[str[i]]-mp[str[i-1]];
                ans+=temp;
            }
            else{
                ans+=mp[str[i]];
            }
            // cout<<i<<"-->"<<ans<<endl;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends