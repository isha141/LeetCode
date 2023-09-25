class Solution {
public:
    int trap(vector<int>& h) {
          int n=h.size();
          int ans=0;
          int low=0;
          int high=n-1;
          int leftMax=0;
          int rightMax=0;
         while(low<high){
            if(h[low]<h[high]){
                if(leftMax<h[low]){
                    leftMax=h[low++];
                }
                else{
                    ans+=leftMax-h[low];
                    low++;
                }
            }
            else{
                if(rightMax<h[high]){
                    rightMax=h[high--];
                }
                else{
                    ans+=rightMax-h[high];
                    high--;
                }
            }
         }
         return ans;
    }
};