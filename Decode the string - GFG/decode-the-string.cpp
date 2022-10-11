//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here 
        int n=s.size();
        stack<string>st;
        int prev=0;
        string curr="";
        int currno=0; 
        string prevs="";
        int j=0;
        while(j<s.size()){
            if(s[j]=='[')
            {
                st.push(curr);
                st.push(to_string(currno));
                currno=0;
                curr=""; 
                j++;
                continue;
            }
            else if(s[j]==']'){
                string temp=st.top();
                st.pop();  
                prev=0; 
                // cout<<temp<<" ";
                for(auto it: temp)
                prev=prev*10+it-'0'; 
                // cout<<prev<<" ";
                // string prevs="";
                string prevs=st.top();
                st.pop();  
                string t="";
                for(int i=0;i<prev;++i){
                    t+=curr;
                }  
                prevs+=t;
                // cout<<prevs<<endl;
                
                // cout<<t<<" ";
                // t+=prevs;
                // cout<<t<<" ";
                // st.push(t); 
                j++; 
                curr=prevs;
                continue;
                
            }
            else if(isdigit(s[j])){
                currno=currno*10+s[j]-'0';
            } 
            else
            curr+=s[j];
            j++;
        }
        return curr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends