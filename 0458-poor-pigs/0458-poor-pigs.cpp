class Solution { 
    private:
    long long ok(int rows,int i){
        return (long long)pow(rows,i);
    }
public:
    int poorPigs(int buckets, int todie, int totest) {
        int  trials=(totest)/todie;
        int rows=trials+1;
        for(int i=0;i<=101;++i){
            if(ok(rows,i)==buckets)
                  return i;
            if(ok(rows,i)>buckets)
                  return i;
        }
        return -1;
    }
};