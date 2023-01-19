class Solution {
public:
    int trap(vector<int>& a) {
        int n=a.size();
        int ans=0;
        int leftmax=0;
        int rightmax=0;
        int i=0;
        int j=n-1;
        while(i<=j){
            if(a[i]<=a[j]){
                if(leftmax<=a[i]) leftmax=a[i];
                else
                    ans+=leftmax-a[i];
                i++;
            } 
            else{
                if(rightmax<=a[j])
                    rightmax=a[j];
                else
                    ans+=rightmax-a[j];
                  j--;
            }
        }
        return ans;
    }
};