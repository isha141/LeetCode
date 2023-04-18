class Solution { 
    private:
    
public:
    string mergeAlternately(string w1, string w2) {
         string ans="";
        int i=0;
        int j=0; 
        bool flag=0;
        while(i<w1.size() || j<w2.size()){
            if(i<w1.size() && !flag){
                ans+=w1[i++]; 
                flag=!flag; 
                continue;
            }
            else if(j<w2.size() && flag){
                ans+=w2[j++];
                flag=!flag; 
                continue;
            } 
            else{
                if(i<w1.size()){
                    ans+=w1[i++];
                }
                else{
                    if(j<w2.size()){
                        ans+=w2[j++];
                    }
                }
            }
        }
        return ans;
    }
};