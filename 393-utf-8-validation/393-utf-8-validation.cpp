class Solution {
public:
    bool validUtf8(vector<int>& data) {
       int rl=0;
        for(auto it: data){
            if(rl==0){
                if((it>>7)==0b0){
                     // cout<<"hy1";
                    rl=0;
                }
                else if((it>>5)==0b110){
                     // cout<<"hy2";
                    rl=1;
                }
                else if((it>>4)==0b1110){
                     // cout<<"hy3";
                    rl=2;
                }
                else if((it>>3)==0b11110){
                     // cout<<"hy4";
                    rl=3;
                } 
                else return 0;
               
            }
            else { 
                if(rl) {
                   if((it>>6)==0b10){
                    rl--;
                   }
                else
                return 0; 
                }
             } 
        }
        if(rl) 
            return 0;
       // cout<<"issha"; 
        return 1;
    }
};