// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> nums, long long n, long long m){
    //code
      long long low=0;
      long long high=low+m-1; 
      long long ans=LONG_MAX;
      sort(nums.begin(),nums.end());
      while(high<n)
      {
          ans=min(ans,nums[high]-nums[low]);
          low++;
          high++;
      }
      return ans;
    }   
};

// { Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}  // } Driver Code Ends