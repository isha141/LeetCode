// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{  
    private:
    int count(vector<vector<int>> &matrix,int k,int c)
    {
        int c1=0;
        for(auto itr: matrix)
        {
            int low=0;
            int high=c-1;
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(itr[mid]<=k)
                {
                    low=mid+1;
                }
                else
                high=mid-1;
            }
            c1+=low;
        } 
      //  cout<<c1<<" ";
        return c1;
    }
public:
    int median(vector<vector<int>> &mat, int r, int c){
        // code here  
        int mini=INT_MAX;
        int maxi=0;
        for(auto itr: mat)
        {
            mini=min(mini,itr[0]);
            maxi=max(maxi,itr[c-1]);
        }
        int low=mini;
        int high=maxi; 
       /// cout<<low<<" "<<high<<endl;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(count(mat,mid,c)<=(r*c)/2)
                low=mid+1;
            else
            high=mid-1;
        }
        return low;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends