//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout << missingNumber(str)<<endl;
    }
	return 0;
}

// } Driver Code Ends


/* You are required to complete this function
which return the required missing number
if present else return -1*/
int missingNumber(const string& str)
{
    // Code here 
     int n=str.size();
     int ans=0;
     int start=0; 
     int m=0; 
     for(int i=0;i<n;++i){
         start=start*10+str[i]-'0';
         int j=i+1;
         int prev=start;  
         m++;
         ans=INT_MIN;
         bool flag=0;
         while(j<n){
             int count=0;
             int res=0; 
             while(j<n && res<prev && count<m){
                  res=res*10+str[j]-'0';
                  j++;
             }
            //  cout<<res<<"::"<<prev<<endl;
             if(res-prev==1){
                 prev=res;
                 continue;
             }
            else if(res-prev==2){ 
                 ans=prev+1;
                 prev=res;
                     continue;
            } 
            else if(res<prev){
                 if(j<n){
                     res=res*10+str[j]-'0';
                     if(res-prev==1){
                         j++; 
                         prev=res;
                         continue;
                     }
                     else if(res-prev==2){
                         ans=prev+1;
                         j++;
                         continue;
                     }
                     else 
                     flag=1;
                 }
                 else
                 flag=1;
             }  
            else  
                 flag=1;
             if(flag) break;
         }
         if(j>=n && ans!=INT_MIN && flag==0)
          return ans;
     }
     return -1;
}