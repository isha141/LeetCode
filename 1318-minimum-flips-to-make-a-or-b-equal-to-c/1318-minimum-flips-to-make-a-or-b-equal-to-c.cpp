class Solution {
public:
    int minFlips(int a, int b, int c) {
       // int ans=0;
        vector<int>bita(64,0);
        vector<int>bitb(64,0);
        vector<int>bitc(64,0); 
        int pos=0;
        while(a){
            if(a &1){
                bita[pos]=1;
            } 
            pos++;
            a>>=1;
        } 
        pos=0;
        while(b){
            if(b &1){
                bitb[pos]++;
            }
            pos++;
            b>>=1;
        }
        pos=0;
        while(c){
            if(c & 1){
                bitc[pos]++;
            }
            pos++;
            c>>=1;
        }  
        int ans=0;
        for(int i=0;i<32;++i){
            if(bitc[i]!= (bita[i] | bitb[i])){
                if(bitc[i]==0){
                    if(bita[i])
                      ans++;
                    if(bitb[i])
                        ans++;
                }
                else if(bitc[i]==1 && (bita[i]==0 && bitb[i]==0))
                    ans++;
            }
        }
        return ans;
        
    }
};