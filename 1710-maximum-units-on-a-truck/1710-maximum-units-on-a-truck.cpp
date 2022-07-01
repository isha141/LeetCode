bool cmp(vector<int>a,vector<int>b){
    return a[1]>b[1];
}
class Solution { 
public:
    int maximumUnits(vector<vector<int>>& b, int size) {
        int n=b.size();
        sort(b.begin(),b.end(),cmp);  
        int ans=0; 
        int k=0;
        while(size>0 && k<n ){ 
            if(size>=b[k][0]){
            ans+=(b[k][0]*b[k][1]);
                size-=b[k][0];
                k++;
            } 
            else if(size<=0) return ans;
            else{
                ans+=b[k][1]*size;
                size=0;
                k++;
            }
           // cout<<size<<" ";
        }
        return ans;
    }
};