class Solution {  
    int n; 
    // vector<int>temp(n,0);
    int count(int low,int mid,int high,vector<int>&nums)
    { 
        int i=low;
        int c=0;
        int j=mid+1;
        while(i<=mid ){
            while(j<=high && nums[i]>2*(long long) nums[j])
                j++;
            c+=j-(mid+1);
            i++;
        }
        
        return c;
    }
    int merge(int low,int mid,int high,int temp[],vector<int>&nums)
    {
        int i=low;
        int j=mid+1;
        int k=low;
        int inv=0;
        inv=count(low,mid,high,nums);
        
        while(i<=mid && j<=high){
            if(nums[i]<nums[j]){
                temp[k++]=nums[i++];
            }
            else {
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
        return inv;
        
    }
    private:
    int solve(int low,int high,int temp[],vector<int>&nums)
    {  
        if(low==high)
            return 0;
        int inv=0;
        if(low<high){
            int mid=(low+high)>>1;
            inv+=solve(low,mid,temp,nums);
            inv+=solve(mid+1,high,temp,nums);
            inv+=merge(low,mid,high,temp,nums);
        }
        return inv;
    }
public:
    int reversePairs(vector<int>& nums) {
        n=nums.size(); 
        int temp[n];
        return solve(0,nums.size()-1,temp,nums);
    }
};