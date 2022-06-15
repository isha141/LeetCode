// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string exp)
    {
        // Your code here
        stack<int>s; 
    int n=exp.length();
    for(int i=0;i<n;i++){
        if(isdigit(exp[i]))
        s.push(exp[i]-'0');
        else{
            int temp1=s.top(); s.pop();
            int temp2=s.top();  
          //  cout<<temp1<<" "<<temp2<<endl;
            s.pop();
            if(exp[i]=='+'){
                int ans= temp1+temp2; 
                s.push(ans);
            }
            else if(exp[i]=='-'){
                int ans=-temp1+temp2;
                s.push(ans);
            }
            else if(exp[i]=='*'){
                int ans=temp1*temp2;
                s.push(ans);
            }
            else if(exp[i]=='/')
            {
                int ans= temp2/temp1; 
                s.push(ans);
            }
        }
    }
    return s.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends