class Solution { 
    private:
    int solve(string &b,string &a)
    {
        for(int i=0;i<=a.size()-b.size();++i){ 
            int k=0; 
            int j=i;
            while(j<a.size() && k<b.size()){
                if(a[j]!=b[k])
                    break;
                j++;
                k++;
            }
            if(k==b.size())
                return true;
        }
        return false;
    }
public:
    int repeatedStringMatch(string a, string b) {
        int m=a.size();
        int n=b.size();
         string temp=a;
        int count=1;
        while(a.size()<b.size())
           a+=temp,count++;
        // cout<<a<<" ";
        if(solve(b,a))
            return count; 
        a+=temp;
        if(solve(b,a))
            return count+1;
        else
            return -1;
    }
};