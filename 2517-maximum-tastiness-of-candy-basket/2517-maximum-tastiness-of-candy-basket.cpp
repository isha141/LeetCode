class Solution {  
    int n;
    bool isvalid(long long mid,vector<int>&p,int k){
       set<int>s;
        int i=0;
        int j=0;
        while(j<n && s.size()!=k){
            if(abs(p[i]-p[j])>=mid){
                s.insert(p[i]);
                s.insert(p[j]);
                i=j;
            }
            j++;
        } 
        // cout<<mid<<"**"<<endl;
        // for(auto it=s.begin();it!=s.end();++i){
        //     cout<<*it<<" ";
        // }
        // cout<<endl;
        return s.size()>=k;
    }
public:
    int maximumTastiness(vector<int>& p, int k) {
         n=p.size();
        long low=1;
        sort(p.begin(),p.end());
        long high=p[n-1]-p[0];
        long ans=0;
        while(low<=high){
            long long mid=(low+high)>>1; 
            // cout<<mid<<" ";
            if(isvalid(mid,p,k)){
                ans=mid; low=mid+1;}
            else
                high=mid-1;
        }
        return ans;
    }
};