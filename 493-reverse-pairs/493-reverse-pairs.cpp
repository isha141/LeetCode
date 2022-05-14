class Solution { 
    private:
    int counting(vector<int>& nums,vector<int>&temp,int low,int mid,int high)
    {
        int c=0; 
        int j=mid+1;
        while(low<=mid)
        {
            while(j<=high && nums[low]> 2*(long)nums[j])
            {
                j++;
            }
            c+=(j-(mid+1));
            low++;
        }
        return c;
    }
    private:
    int merge(vector<int>& nums,vector<int>&temp,int low,int mid,int high)
    {
        int i=low;
        int j=mid+1;
        int inv=0; 
        int k=low; 
        inv=counting(nums,temp,low,mid,high);
        while(i<=mid && j<=high)
        {
            if(nums[i]<nums[j])
                temp[k++]=nums[i++];
            else{
                temp[k++]=nums[j++];
            }
        }
        while(i<=mid)
            temp[k++]=nums[i++];
        while(j<=high)
            temp[k++]=nums[j++]; 
        for(int i=low;i<=high;i++)
            nums[i]=temp[i];
        return inv;
    }
    private:
    int solve(vector<int>& nums,vector<int>&temp,int i,int j)
    {  
        if(i==j)
            return 0;
        int inv=0;
        if(i<j)
        {
            int mid=(i+j)/2;
            inv=solve(nums,temp,i,mid);
            inv+=solve(nums,temp,mid+1,j);
            inv+=merge(nums,temp,i,mid,j);
        }
        return inv;
    }
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size(); 
        vector<int>temp(n);
        return solve(nums,temp,0,n-1);
    }
};