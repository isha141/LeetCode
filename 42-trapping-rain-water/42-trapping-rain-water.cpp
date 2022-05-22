class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        int i=0; 
        int ans=0;
        int j=n-1;
        int left=0;
        int right=0;
        int count=0;
        while(i<=j)
        {
            if(h[i]<=h[j])
            {
                if(h[i]>=left)
                    left=h[i];
                else
                    count+=left-h[i];
                i++;
            }
            else 
            {
                if(h[j]>=right)
                    right=h[j];
                else
                    count+=right-h[j];
                j--;
            }
        }
        return count;
    }
};