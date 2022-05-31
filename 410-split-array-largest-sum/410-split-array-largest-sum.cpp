class Solution { 
private:
    int isvalid(vector<int>& nums,int mid)
    { 
        int sum=0;
        int count=0;
        for(int i: nums)
        {
            if(sum+i<=mid){
                sum+=i;
                
            }
            else{
                count++;
                sum=i;
            }
        }
        return count+1;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int low=0;
        int high=0; 
        int ans=0;
        for(auto itr: nums)
        {
            low=max(low,itr);
            high+=itr;
        }
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(isvalid(nums,mid)<=m)
            {
               ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};
// class Solution { 
//     private:
//     bool isvalid(vector<int>& nums,int mid,int m)
//     {
//         int sum=0; 
//         int count=0;
//         for(auto itr: nums)
//         { 
//             if(sum+itr<=mid)
//             { 
//                 //cout<<sum<<" ";
//                   sum+=itr;
//             }
//             else
//             {
//                 count++;
//                 sum=itr; 
//             }
//         } 
//        return count+1;
//     }
// public:
//     int splitArray(vector<int>& nums, int m) {
//         int ans=0;
//         int low=0;
//         int high=0;
//         for(auto itr: nums){
//             high+=itr;
//             low=max(low,itr);
//         }
//         while(low<=high)
//         {
//             int mid=(low+high)/2; 
//             cout<<low<<" "<<mid<<" "<<high<<endl;
//             if(isvalid(nums,mid,m)<=m)
//             {
//                 ans=mid;
//                   high=mid-1; }
//             else
//                 low=mid+1;
//         }
//         return ans;
//     }
// };