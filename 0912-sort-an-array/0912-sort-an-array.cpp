class Solution {  
    private:
    void merge(int low,int mid,int high,vector<int>&nums,vector<int>&temp){
        int k=low;
        int i=low;
        int j=mid+1;
        while(i<=mid && j<=high){
            if(nums[i]<nums[j]){
                temp[k++]=nums[i++];
            }
            else{
                temp[k++]=nums[j++];
            }
        }
        while(i<=mid){
            temp[k++]=nums[i++];
        }
        while(j<=high){
            temp[k++]=nums[j++];
        }
        for(int i=low;i<=high;++i){
            nums[i]=temp[i];
        }
        return ;
    }
    void solve(int low,int high,vector<int>&nums,vector<int>&temp){
        if(low<high){
            int mid=(low+high)>>1;
            solve(low,mid,nums,temp);
            solve(mid+1,high,nums,temp);
            merge(low,mid,high,nums,temp);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) { 
        int n=nums.size();
       vector<int>temp(n,0);
        solve(0,n-1,nums,temp);
        return temp;
    }
};