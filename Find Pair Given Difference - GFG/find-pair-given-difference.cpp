// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    //code 
    sort(arr,arr+size);
    int low=0;
    int high=size-1;
    for(int i=0;i<size;i++)
    {
        int temp=n+arr[i];
        int low=i+1;
        int high=size-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]==temp)
            return 1;
            else if(arr[mid]<temp)
            low=mid+1;
            else
            high=mid-1;
        }
    }
    return 0;
}
// while(low<high)
//     {
//         if(arr[high]-arr[low]==n)
//         return true;
//         else if(arr[high]-arr[low]<n) 
//         high--;
//         else
//         low++;
        
//     } 
// sort(arr,arr+size);
//     int low=0;
//     int high=size-1;
//     for(int i=0;i<size;i++)
//     {
//         int temp=n+arr[i];
//         int low=i+1;
//         int high=size-1;
//         while(low<=high)
//         {
//             int mid=(low+high)/2;
//             if(arr[mid]==temp)
//             return 1;
//             else if(arr[mid]<temp)
//             low=mid+1;
//             else
//             high=mid-1;
//         }
//     }
//     return 0;