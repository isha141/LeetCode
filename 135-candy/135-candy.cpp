class Solution {
public:
    int candy(vector<int>& ratings) {
      int n=ratings.size();
        int ans=0;
        vector<int>left(n,1);
        for(int i=1;i<n;++i){
            if(ratings[i]>ratings[i-1]){
                left[i]=left[i-1]+1;
            }
        }
        int sum=0;
        sum=left[n-1];
        for(int i=n-2;i>=0;--i){
            if(ratings[i]>ratings[i+1]){
                left[i]=max(left[i],left[i+1]+1);
            }
            sum+=left[i];
        }
        return sum;
    }
};