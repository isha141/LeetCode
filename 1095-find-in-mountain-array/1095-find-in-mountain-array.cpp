/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
          int n=mountainArr.length();
         int low=0;
          int high=n-2;
         int peak=0;
         while(low<=high){
             int mid=(low+high)>>1;
             if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                 peak=mid;
                 low=mid+1;
             }
             else{
                 high=mid-1;
                 
             }
         }
          low=0;
          high=peak; 
          
          while(low<=high){
              int mid=(low+high)>>1;
              // cout<<mid<<"--"<<endl;
              if(mountainArr.get(mid)==target)
                    return mid;
              if(mountainArr.get(mid)>target){
                  high=mid-1;
              }
              else{
                  low=mid+1;
              }
          } 
        low=peak+1;
        high=n-1;
          while(low<=high){
              int mid=(low+high)>>1;
              if(mountainArr.get(mid)==target)
                    return mid;
              if(mountainArr.get(mid)>target){
                   low=mid+1;
              }
              else{
                    high=mid-1;
              }
          }
          return -1;
    }
};