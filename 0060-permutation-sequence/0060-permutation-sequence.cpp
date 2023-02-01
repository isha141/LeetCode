class Solution { 
    int factorial(int n){
        if(n<=1)
            return 1;
        return n* factorial(n-1);
    }
public:
    string getPermutation(int n, int k) {
        // if(n==1)
        //     return "1";
        vector<int>ds(n);
        for(int i=0;i<n;++i)
            ds[i]=i+1;
        string ans="";
        int fact=factorial(n-1);
        k--;
        // cout<<fact<<" "<<k<<endl;
        while(true){
            ans+=to_string(ds[k/fact]); 
            ds.erase(ds.begin()+(k/fact));
            if(ds.size()==0)
                break;
            k=k%fact;
             fact=fact/ds.size();
        }
        return ans;
        
    }
};