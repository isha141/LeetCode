//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        vector<int>ans;
        while(N!=0){
            if(N>=2000){
                int temp=N/2000;
                for(int i=0;i<temp;++i)
                ans.push_back(2000);
                N%=2000;
            }
            else if(N>=500){
                int temp=N/500;
                for(int i=0;i<temp;++i)
                ans.push_back(500);
                N%=500;
            }
            else if(N>=200){
                int temp=N/200;
                for(int i=0;i<temp;++i){
                    ans.push_back(200);
                }
                N%=200;
            }
            else if(N>=100){
                int temp=N/100;
                for(int i=0;i<temp;++i)
                ans.push_back(100); 
                N%=100;
            }
            else if(N>=50){
                int temp=N/50;
                for(int i=0;i<temp;++i)
                ans.push_back(50);
                N%=50;
            }
            else if(N>=20){
                int temp=N/20;
                for(int i=0;i<temp;++i)
                ans.push_back(20);
                N%=20;
            }
            else if(N>=10){
                int temp=N/10;
                for(int i=0;i<temp;++i)
                ans.push_back(10);
                N%=10;
            }
            else if(N>=5){
                int temp=N/5;
                for(int i=0;i<temp;++i)
                ans.push_back(5);
                N%=5;
            }
            else if(N>=2){
                int temp=N/2;
                for(int i=0;i<temp;++i)
                ans.push_back(2);
                N%=2;
            }
             else if(N>=1){
                int temp=N/1;
                for(int i=0;i<temp;++i)
                ans.push_back(1);
                N%=1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends