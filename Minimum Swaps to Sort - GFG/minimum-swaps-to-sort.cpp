// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here 
	    vector<pair<int,int>>v; 
	    int n=nums.size();
	    vector<int>vis(n,false);
	    for(int i=0;i<nums.size();i++)
	    {
	        v.push_back({nums[i],i});
	    }
	    sort(v.begin(),v.end());
	    int count=0;
	    for(int i=0;i<n;i++)
	    {
	        if(vis[i] || v[i].second==i)
	        continue; 
	        int j=i; 
	        int size=0;
	        while(!vis[j])
	        {
	            vis[j]=1;
	            j=v[j].second; 
	            size++;
	        } 
	       //if(size>1)
	        count+=size-1;
	    }
	    return count;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends