class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()<nums1.size())
             return findMedianSortedArrays(nums2,nums1);
        int n=nums1.size();
        int m=nums2.size();
        int req=(nums1.size()+nums2.size()+1)>>1;
        int low=0;
        int high=n;
        while(low<=high){
            int mid=(low+high)>>1;
            int cut1=mid;
            int cut2=req-mid;
            int l1=cut1==0?INT_MIN:nums1[cut1-1];
            int l2=cut2==0?INT_MIN: nums2[cut2-1];
            int r1=cut1==n?INT_MAX:nums1[cut1];
            int r2=cut2==m?INT_MAX:nums2[cut2];
            if(l1<=r2 && l2<=r1){
                if((n+m)%2==0) 
                    return (double)(max(l1,l2)+min(r1,r2))/(2.0);
                else 
                    return (double) max(l1,l2);
            }
            if(l1>r2){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return 0.0;
    }
};