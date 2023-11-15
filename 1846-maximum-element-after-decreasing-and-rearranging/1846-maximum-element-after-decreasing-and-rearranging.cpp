class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
         int n=arr.size();
         sort(arr.begin(),arr.end());
         int first=arr[0];
         if(arr[0]!=1)
             first=1;
         for(int i=1;i<n;++i){
              if(arr[i]-first<=1)
                  first=arr[i];
              else{
                  first+=1;
              }
         }
        return first;
    }
};