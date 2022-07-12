class Solution {
public:
    int strStr(string a, string b) {
        int m=a.size();
        int n=b.size();
        for(int i=0;i<=m-n;++i){ 
            int j=i,k=0;
            while(j<a.size() && k<b.size()){
                if(a[j]!=b[k])
                    break;
                j++,k++;
            }
            if(k==n)
                return i;
        }
        return -1;
    }
};