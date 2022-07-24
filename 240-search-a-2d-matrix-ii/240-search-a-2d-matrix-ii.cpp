class Solution { 
    private:
    bool solve(vector<int>&ds,int target){
        int low=0;
        int high=ds.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(ds[mid]==target) return 1;
            if(ds[mid]<target)
                low=mid+1;
            else
                high=mid-1;
        }
        return 0;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int low=0;
     int i=0;
        int j=matrix[0].size()-1;
        while(i<matrix.size() && j>=0){
            if(matrix[i][j]==target)
                return 1;
            if(matrix[i][j]<target){
                i++;
            } 
            else
                j--;
        }
        return 0;
    }
};