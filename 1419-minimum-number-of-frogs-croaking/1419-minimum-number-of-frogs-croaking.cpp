class Solution {
public:
    int minNumberOfFrogs(string cr) {
       int n=cr.size(); 
        int ans=0; 
        int inuse=0; 
        int c=0;
        int r=0,o=0,a=0,k=0;
        for(auto c1:cr){ 
            switch(c1){
        case'c':
                    c++;
                    inuse++;
                    break; 
        case'r': 
                    r++;
                    break;
        case'o':
                    o++;
                    break;
        case 'a':
                    a++;
                    break;
        case 'k': 
                    k++;
                    inuse--;
                    break;
            } 
            if(c<r || r<o|| o<a || a<k)
                return -1;
            ans=max(ans,inuse);
        }
        if(inuse==0 && c==r && r==o && o==a && a==k)
            return ans;  
        // cout<<inuse<<" "<<c<<" "<<r<<" "<<o<<" "<<k<<" "<<endl;
        return -1;
   }
};