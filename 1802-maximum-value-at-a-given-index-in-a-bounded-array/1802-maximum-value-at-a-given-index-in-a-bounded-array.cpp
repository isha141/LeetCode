class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
          int low=1;
          int high=maxSum;  
          int ans=0; 
          int rem=n-index-1;
         while(low<=high){
             int mid=(low+high)>>1;
              long long sum=(1ll*(mid-1)*mid)/2;  
              long long sumr=sum;
             // cout<<mid<<"ll"<<sum<<endl;
               if(mid>rem){
               long long rem_sum=0; 
                  long temp=mid-1-rem;
               rem_sum=(1ll*temp*(temp+1))/2;  // 
               sumr=sum-rem_sum;  // right 
             } 
             else{
                 long temp=rem-mid+1;
                 sumr+=temp;
             }
              // left 
              long suml=0;
              suml=(1ll*mid*(mid-1))/2;
             if(mid<=index){
                 long temp=index-mid+1;
                  suml+=temp;
             }  
             else {
                 long temp=mid-index-1;
                 long long rem_sum=(1ll*temp*(temp+1))/2;
                 suml-=rem_sum;
             }
             cout<<mid<<";;"<<suml<<";;"<<sumr<<endl;
             if((suml+sumr+mid)<=maxSum){
                 ans=mid;
                  low=mid+1;
             }
             else{ 
                  high=mid-1;
             }
         }
        return ans;
    }
};