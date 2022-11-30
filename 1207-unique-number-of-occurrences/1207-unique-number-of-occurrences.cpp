class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int>ds(2001,-1);
        for(auto itr: arr){
            if(ds[itr+1000]==-1){
                ds[itr+1000]=0;
                ds[itr+1000]++;
            }
            else 
                ds[itr+1000]++;
        }
        sort(ds.begin(),ds.end());
        int i=0;
        while(i<ds.size()){
            if(ds[i]==-1)
                i++;
            else
                break;
            // cout<<"hyy";
        }
        for(int j=i;j<ds.size()-1;++j){
            if(ds[j]==ds[j+1])
                return 0;
        }
        return 1;
    }
};