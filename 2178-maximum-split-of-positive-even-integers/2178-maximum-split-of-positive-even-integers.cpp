class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalsum) {
        vector<long long>ds;
        if(finalsum%2) return {};
        long long last=-1;
        for(int i=2;i<1ll*1e14;i+=2){ 
            if(finalsum>=i){
            ds.push_back(i);
            last=i;
            finalsum-=i;
            }
            else{
                if(ds.back()>=finalsum){
                    long temp=ds.back()+finalsum;
                    ds.pop_back();
                    ds.push_back(temp);
                    return ds;
                }
                else{
                    ds.push_back(finalsum);
                    return ds;
                }
            }
            if(finalsum==0) return ds;
        }
        return ds;
    }
};