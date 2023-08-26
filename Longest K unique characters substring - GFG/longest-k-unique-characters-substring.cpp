//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
       int n=s.size();
       map<char,int>mp;
    //   int count=0;
       int j=0; 
       int ans=0;
       for(int i=0;i<n;++i){
           mp[s[i]]++;
           int count=mp.size();
           if(count==k){
               ans=max(ans,i-j+1);
           }
           else if(count>k){
               while(j<=i && mp.size()>k){
                         mp[s[j]]--;
                         if(mp[s[j]]==0)
                         mp.erase(s[j]);
                    j++;
               }
               ans=max(ans,i-j+1);
           }
       }
       return ans==0?-1:ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends