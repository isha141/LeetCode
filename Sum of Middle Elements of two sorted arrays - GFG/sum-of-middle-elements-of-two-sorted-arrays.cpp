//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int findMidSum(int ar1[], int ar2[], int n) {
            // code here  
            int i=0;
            int j=0;
            int count=0; 
            if(n==1){
                return (ar1[0]+ar2[0]);
            }
            while(i<n && j<n){
                if(ar1[i]<=ar2[j]){
                    i++;
                    count+=1;
                } 
                else{
                    j++; 
                    count+=1;
                }
                if(count==n-1){
                    int temp1=0;
                    int temp2=0;
                    if(i<n){
                    if(ar1[i]<=ar2[j]){
                        temp1=ar1[i];
                        i++;
                    }
                    else{
                        temp1=ar2[j];
                        j++;
                    } 
                    }
                    else{
                        temp1=ar2[j];
                          j++;
                    }
                    if(i<n){ 
                        if(j<n && ar1[i]<=ar2[j]){
                            temp2=ar1[i];
                            i++;
                        }
                        else if(j==n){
                            temp2=ar1[i]; 
                            i++;
                        }
                        else{
                            temp2=ar2[j];
                            j++;
                        }
                    }
                    else{ 
                        // cout<<"isha"<<endl;
                        temp2=ar2[j];
                    } 
                    // cout<<temp1<<"l;;"<<temp2<<endl;
                 return (temp1+temp2);
                    
                }
            }
        return 0; 
    } 
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends