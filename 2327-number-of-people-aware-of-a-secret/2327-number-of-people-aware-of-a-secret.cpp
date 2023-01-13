typedef long long ll; 
#define mod 1000000000+7;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
       vector<vector<ll>>ds;
        int days=2;
        ds.push_back({1+delay,1+forget,1});
        while(days<=n){
            // remove all the people who forget the secret 
            while(!ds.empty() && ds[0][1]==days){
                ds.erase(ds.begin());
            }
           ll cnt=0;
            // inserting the people who comes to know the secret 
             for(auto itr: ds){
                 if(days>=itr[0])
                     cnt+=itr[2]; 
                     cnt%=mod;
             } 
            // if(cnt>0)
            ds.push_back({days+delay,days+forget,cnt});
            days+=1;
        }
        ll ans=0;
        for(auto itr: ds){
            ans+=itr[2];
            ans%=mod;
        }
        return ans;
    }
};