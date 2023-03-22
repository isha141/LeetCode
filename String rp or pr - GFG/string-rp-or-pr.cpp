//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int x,int y,string s){
      //code here 
       int n=s.size(); 
       stack<char>s1; 
       long long ans=0;
      if(x>y){
           for(int i=0;i<n;++i){
               if(s1.size() && s1.top()=='p' && s[i]=='r'){
                   ans+=x;
                   s1.pop();
               }
               else{
                   s1.push(s[i]);
               }
           }
           stack<char>s2;
           while(!s1.empty()){
               auto itr=s1.top();
               s1.pop(); 
               if(s2.size() &&  ((itr=='p' && s2.top()=='r') || (itr=='r' && s2.top()=='p'))){
                   ans+=y;
                   s2.pop();
               }
               else{
                   s2.push(itr);
               }
           }
           return ans;
      }
      else{
          for(int i=0;i<n;++i){
               if(s1.size() &&  ((s1.top()=='r' && s[i]=='p'))){
                   ans+=y;
                   s1.pop();
               }
               else{
                   s1.push(s[i]);
               }
           } 
           stack<char>s2;
           while(!s1.empty()){
               auto itr=s1.top();
               s1.pop();
               if(s2.size() && ((itr=='r' && s2.top()=='p')|| (s2.top()=='r' && itr=='p'))){
                   ans+=x;
                   s2.pop();
               }
               else{
                   s2.push(itr);
               }
           }
           return ans;
      }
     return ans;  
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends