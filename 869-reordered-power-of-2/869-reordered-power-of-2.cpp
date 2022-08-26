class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int x=pow(10,9);
        map<int,vector<int>>mp;
        for(int i=1;i<=x;i=i*2){
            int k=i; 
            vector<int>v(10,0);
            while(k){
                int r=k%10;
                v[r]++;
                k=k/10;
            }
            mp[i]=v;
        }
        // cout<<"isha"<<endl;
        vector<int>a(10,0);
        while(n){
            int r=n%10;
            a[r]++;
            n=n/10;
        }
        for(int i=1;i<=x;i=i*2){
            if(a==mp[i])
                return 1;
        }
        return 0;
        
    }
};