//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
        int first=-1;
        int second=-1;
        int maxi=INT_MAX;
        for(int i=0;i<n;++i){
            int val=arr[i];
            int rem=x-val;
            int ind=lower_bound(brr,brr+m,rem)-brr;
            // cout<<arr[i]<<"==>"<<rem<<";; "<<brr[ind]<<endl;
            if(maxi>abs(x-(arr[i]+brr[ind]))){
                maxi=abs(x-(arr[i]+brr[ind]));
                first=arr[i];
                second=brr[ind];
            }
            if(ind-1>=0  && maxi >abs(x-(arr[i]+brr[ind-1]))){
                maxi=abs(x-(arr[i]+brr[ind-1]));
                first=arr[i];
                second=brr[ind-1];
            }
        }
        return {first,second};
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends