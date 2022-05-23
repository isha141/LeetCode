// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here 
    	vector<pair<int,int>>v;
    	for(int i=0;i<n;i++)
    	v.push_back({arr[i],dep[i]});
    	sort(v.begin(),v.end());
    	vector<int>temp; 
    	for(auto itr: v)
    	{ 
    	    int flag=0; 
    	    int d=itr.second;
    	    if(!temp.empty())
    	    {
    	        for(int i=0;i<temp.size();i++)
    	        {
    	            if(temp[i] <itr.first && temp[i]<d)
    	            {
    	                temp[i]=d;
    	                flag=1;
    	                break;
    	            }
    	        }
    	    } 
    	      if(!flag)
    	    temp.push_back(d);
    	   
    	} 
    	//for(auto itr: temp)
    	//cout<<itr<<" ";
    	return temp.size();
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends