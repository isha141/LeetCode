class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& ro, int add) {
        int n=cap.size();
        for(int i=0;i<n;i++)
            cap[i]-=ro[i];
        sort(cap.begin(),cap.end()); 
        
        int count=0; 
        int i=0;
        for( i=0;i<n && add!=0;i++)
        {
            if(cap[i]==0){
                count++;
            continue;
            } 
        else if(cap[i]<=add) {
            add-=cap[i];
            count++;
        }
        } 
        while(i<n){
            if(cap[i]==0)
                count++; 
            i++;
        }
        return count;
    }
};