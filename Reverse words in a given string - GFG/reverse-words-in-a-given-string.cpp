// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
       vector<string>ds;
        string temp="";
        string ans="";
        for(auto itr: S)
        {
            if(itr=='.')
            {
                ds.push_back(temp);
                temp="";
            }
            else
            temp+=itr;
        } 
        ds.push_back(temp);
        reverse(ds.begin(),ds.end());
        for(auto itr: ds)
        ans+=itr+"."; 
        ans.erase(ans.size()-1);
        return ans;
    } 
    
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends