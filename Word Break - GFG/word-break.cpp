//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
    private:
    int n;
    int solve(int i,string &s,map<string,int>&mp){
          if(i>=n)
            return 1;
          int ans=0;
          for(int j=i;j<n;++j){
              string temp=s.substr(i,j-i+1);
              if(mp.find(temp)!=mp.end()){
                  ans=ans|solve(j+1,s,mp);
              }
          }
        return ans;
    }
public:
    int wordBreak(string a, vector<string> &b) {
        //code here
        n=a.size();
        map<string,int>mp;
        for(auto itr: b)
        mp[itr]++;
        return solve(0,a,mp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends