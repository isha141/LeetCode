class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total=0;
        int current=0;
        int start=0;
        for(int i=0;i<n;++i){
            current+=gas[i]-cost[i];
            total+=gas[i]-cost[i];
            if(current<0){
                current=0;
                start=(i+1)%n;
            }
            
        }
        if(total<0)
            return -1;
        return start;
        
    }
};