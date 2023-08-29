class Solution {
public:
    int bestClosingTime(string c) {
        int n=c.size();
        int s=n;
        vector<int>prefix(n+1,0),suffix(n+1,0); 
        if(c[0]=='N')
            prefix[0]=1;
        if(c[n-1]=='Y') suffix[n-1]=1;
        for(int i=n-2;i>=0;--i){
            suffix[i]=suffix[i+1]+(c[i]=='Y'?1:0);
        } 
        for(int j=1;j<n;++j){
            prefix[j]=prefix[j-1]+(c[j]=='N'?1:0);
        } 
        for(int i=0;i<n;++i){
            cout<<suffix[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;++i) cout<<prefix[i]<<" ";
        cout<<endl;
        int sum=1e9;
        for(int i=0;i<n;++i){
            int ans=prefix[i]+suffix[i];
            if(sum>ans){
                sum=ans;
                s=i;
            }
            else if(sum==ans){
                sum=ans;
                s=min(s,i);
            }
        }
        if(s==0 && c[0]=='N'){
            return s;
        }
        return s+1;
    }
};