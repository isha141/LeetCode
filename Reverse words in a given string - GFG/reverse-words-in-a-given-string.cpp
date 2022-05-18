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
        stack<string>s;
        string temp="";
        for(auto itr: S)
        {
            if(itr=='.')
            {
                s.push(temp);
                temp="";
            }
            else
            temp+=itr;
        }  
        s.push(temp);
        string ans="";
        while(!s.empty())
        {
            ans+=s.top();
            ans+=".";
            s.pop();
        }
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