// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
     vector<int> ans;
     int row_start=0;
     int row_end=r-1;
     int col_start=0;
     int col_end=c-1;
     while(row_start<=row_end && col_start<=col_end)
     {
         for(int i=col_start;i<=col_end;i++)
         {
             ans.push_back(matrix[row_start][i]);
         }
         row_start++;
         for(int i=row_start;i<=row_end;i++)
         {
             ans.push_back(matrix[i][col_end]);
         }
         col_end--; 
         if(row_start<=row_end){
         for(int i=col_end;i>=col_start;i--)
         {
             ans.push_back(matrix[row_end][i]);
         }
         row_end--;
         }
         if(col_end>=col_start){
         for(int i=row_end;i>=row_start;i--)
         {
             ans.push_back(matrix[i][col_start]);
         }
         col_start++;
         }
     }
     return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends