//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{ 
    priority_queue<int>maxi;
    priority_queue<int,vector<int>,greater<int>>mini;
    public:
    //Function to insert heap.
    void insertHeap(int &x)
    { 
        maxi.push(x);
        mini.push(maxi.top());
        maxi.pop();
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(maxi.size()<mini.size()){
            maxi.push(mini.top());
            mini.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if((maxi.size()+mini.size())%2==0){
            return double(maxi.top()+mini.top())/2.0;
        }
        return double(maxi.top());
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends