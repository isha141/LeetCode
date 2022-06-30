# define mod 1000000007
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>left,right;
        stack<pair<int,int>>s; 
        int n=arr.size();
        for(int i=0;i<n;++i){ 
            int count=0;
            while(!s.empty() && arr[s.top().first]>arr[i]){
                count+=s.top().second;
                s.pop();
            }
            left.push_back(count+1); 
            s.push({i,count+1});
        }   
        // for(auto itr: left)
        //     cout<<itr<<" ";
        while(!s.empty()) s.pop();
        for(int i=n-1;i>=0;--i){
            int count=0;
            while(!s.empty() && arr[s.top().first]>=arr[i]){
                count+=s.top().second;
                s.pop();
            }
            right.push_back(count+1);
            s.push({i,count+1});
        } 
        reverse(right.begin(),right.end()); 
        // for(auto itr: right)
        //     cout<<itr<<" ";
        int ans=0;
        for(int i=0;i<n;++i){
                long long t=(left[i]*right[i])%mod ;
                  long long c= (t*arr[i]%mod);
                        ans=(ans+c)%mod;
        }
        return ans;
        // cout<<71+55+55+55+55+55+55+82+55+55<<endl; 
        // return 0;
    }
};