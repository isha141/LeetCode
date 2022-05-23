// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
bool cmp(Job arr1,Job arr2)
{
    return arr1.profit>arr2.profit;
}
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here 
        sort(arr,arr+n,cmp);  
        int temp[n+1];
        for(int i=0;i<=n;i++)
        temp[i]=-1;
        int count=0;
        int profit=0; 
        // for(int i=0;i<n;i++)
        // cout<<temp[i]<<" ";
        for(int i=0;i<n;i++)
        {
            int j=arr[i].dead; 
            //cout<<j<<" "<<temp[j]<<endl;
            while(j>0 && temp[j]!=-1)
            { 
                j--;
            } 
            if(j>0){
            temp[j]=arr[i].id;
            count++;
            profit+=arr[i].profit;
         }
        }
        vector<int>ans;
        ans.push_back(count);
        ans.push_back(profit);
        return ans;
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends