class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& bus, vector<int>& pas, int cap) {
        int n=bus.size();
        int m=pas.size();
        sort(bus.begin(),bus.end());
        sort(pas.begin(),pas.end());
        unordered_map<int,int>mp;
        for(auto it: pas)
            mp[it]++;
        int last=0;
        int i=0;
        int j=0; 
        int cc=0;
        while(i<n){
            int c=cap;
            while(j<m && c && bus[i]>=pas[j]){
                c-=1;
             last=pas[j];
                j++;
           }
            i++;
            cc=c;
        } 
        int x=last;
        if(cc>0)
            x=bus[n-1];
        while(mp[x])
            x--;
        return x;
    }
};