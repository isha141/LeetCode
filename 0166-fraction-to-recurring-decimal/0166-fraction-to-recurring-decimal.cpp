class Solution {
public:
    string fractionToDecimal(int num, int den) {
        bool flag=0; 
        long long n=num;
        long long d=den;
        if(num<0 && den<0) {n*=-1; d*=-1;}
        if(n<0){
            n*=-1;
            flag=1;
        }
        if(d<0){
            d*=-1;
            flag=1;
        }
        string ans="";
        long long temp=(n/d);
        long long rem=n%d;  
        if(flag) temp*=-1;
        if(rem==0) { return to_string(temp);};  
        // cout<<temp<<" "<<flag<<endl;
        if(temp==0 && flag==1)
            ans+='-'; 
        ans+=to_string(temp); 
        ans+='.';
        map<int ,int>mp; 
        if(rem<0) rem*=-1; 
        
        while(rem!=0){
            if(mp.find(rem)!=mp.end()){
                ans.insert(mp[rem],"(");
                ans+=')';
                return ans;
            }
            mp[rem]=ans.size();
            rem*=10;
            ans+=to_string(rem/d);
            rem%=d; 
            // cout<<ans<<" ,,"<<rem<<endl;
        }
        return ans;
    }
};