//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here  
      int n=s1.size();
      int m=s2.size();   
       if(n==1 || m==1){
           if(s1[0]=='0' || s2[0]=='0')
           return "0";
       } 
       bool sign=0; 
       if(s1[0]=='-' ||  s2[0]=='-')
       {
          if(s1[0]=='-' && s2[0]=='-'){
            //   sign=1;
           string temp=s1.substr(1);
           s1=temp;
            // sign==1
           string temp1=s2.substr(1);
           s2=temp1;
           sign=0;
          }
          else if(s1[0]=='-'){
             string temp=s1.substr(1);
              s1=temp; 
              sign=1;
        }
        else if(s2[0]=='-'){
             string temp1=s2.substr(1);
             s2=temp1;
             sign=1;
        } 
       }
       string ans=""; 
       vector<int>ds(n+m,0); 
       int k=0; 
       int l=0;
       bool flag=0;  
        int carry=0;
       for(int i=s1.size()-1;i>=0;--i){ 
          k=l; 
          carry=0;
           for(int j=s2.size()-1;j>=0;--j){ 
                 int a=s1[i]-'0';
                 int b=s2[j]-'0'; 
                 int temp=a*b+carry+ds[k];
                  ds[k]=temp%10;
                  k++;
                  carry=temp/10;
           } 
           if(carry)
           ds[k++]=carry;
           l++; 
       }

      for(int i=0;i<ds.size();++i){ 
             ans+=ds[i]+'0';
            flag=1;
      }
       reverse(ans.begin(),ans.end()); 
        int i=0;
        while(i<ans.size()){
            if(ans[i]=='0'){
            i++;
            continue;
           } 
           else
           break;
        } 
        if(sign){
            return "-"+ans.substr(i);
        } 
        else
        return ans.substr(i);
    //   return ans.se=;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends