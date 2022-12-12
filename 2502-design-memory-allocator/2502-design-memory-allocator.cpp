class Allocator { 
    vector<int>ds;
    int n;
public:
    Allocator(int n) {
        this->n=n;
        ds.resize(n,-1);
    }
    
    int allocate(int size, int mid) {
        int ind=-1;
        int count=0;
        bool flag=0;
        for(int i=0;i<n;){
              if(ds[i]!=-1){
                  i++;
                  continue;
              }
            int j=i;
            while(j<n && ds[j]==-1 && j-i<size)
                j++;
            if(j-i==size){
                for(int k=i;k<i+size;++k)
                    ds[k]=mid;
                return i;
            }
            i=j;
        }
        return -1;
    }
    int free(int mID) {
        int c=0;
        for(int i=0;i<n;++i){
            if(ds[i]==mID){
                c++;
                ds[i]=-1;
            }
        }
        return c;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 **/