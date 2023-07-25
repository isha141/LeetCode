class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
          int n=arr.size();
           int low=0;
           int high=n-1;
           while(low<=high){
               int mid=(low+high)>>1;
               if(mid!=0 && mid!=n-1 && arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                   return mid;
               }
               if(mid>0 && arr[mid]>arr[mid-1]){ 
                     low=mid+1;
               }
               else{
                 high=mid-1;
               }
           }
        return low+1;
    }
};