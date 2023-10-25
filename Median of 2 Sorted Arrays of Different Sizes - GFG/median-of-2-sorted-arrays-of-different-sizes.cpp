//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& arr1, vector<int>& arr2)
    {
         double ans=0;
         int i=0;
         int j=0;
         int n=arr1.size();
         int m=arr2.size();
         vector<int>ds(n+m,0);
         int k=0;
        while(i<n && j<m){
             if(arr1[i]<arr2[j]){
                 ds[k++]=arr1[i++];
             }
             else{
                 ds[k++]=arr2[j++];
             }
        }
        while(i<n){
            ds[k++]=arr1[i++];
        } 
        while(j<m){
            ds[k++]=arr2[j++];
        }
        if((n+m)%2==0){
            return (ds[(n+m)/2-1]+ds[(n+m)/2])/2.0;
        }
        return ds[(n+m)/2];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends