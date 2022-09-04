class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size(); 
        map<int,int>mp;
        for(int i=0;i<n;++i)
            mp[(arr[i]%k+k)%k]++; 
        // for(auto itr: mp)
        //     cout<<itr.first<<" "<<itr.second<<endl;
        for(auto [x,y]: mp){
            if(x%k==0){
                if(y%2)
                    return 0;
            } 
            else if(x<0)
            {
                if(mp[x]==mp[abs(x)])
                    continue;
            }
           else if(mp[k-x]!=mp[x])
                return 0;
            
        }
        return 1;
    }
};