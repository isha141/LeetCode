class Solution {
public:
    bool winnerOfGame(string colors) {
        int n=colors.size();
        int a=0;
        int b=0;
        int i=0;
        while(i<n){
            if(colors[i]=='A'){
                int j=i+1;
                int count=0;
                while(j<n && colors[i]==colors[j]){
                    count+=1;
                    j++;
                }
                i=j;
                a+=max(0,count-1);
            }
            else{
                int j=i+1;
                int count=0;
                while(j<n && colors[i]==colors[j]){
                    count+=1;
                    j++;
                }
                i=j;
                b+=max(0,count-1);
            }
        }
        if(b>a)
             return 0;
        if(a==b) return 0;
        return 1;
    }
};