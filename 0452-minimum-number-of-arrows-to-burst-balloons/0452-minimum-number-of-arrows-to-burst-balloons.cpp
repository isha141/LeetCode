class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size(); 
        sort(points.begin(),points.end());
        int c=0;
        int i=0;
        while(i<n){ 
            int last=points[i][1];
            int first=points[i][0];
            int second=points[i][1]; 
            i++;
            while(i<n){ 
                // cout<<i<<"****"<<" ";
                if(second>=points[i][0]){
                    second=min(second,points[i][1]);
                    first=min(first,points[i][0]);
                }
                else {
                    c++;
                    break;
                }
                i++;
            } 
            if(i>=n)
                c++;
            // cout<<"&&&&"<<endl;
            // cout<<i<<" ";
        }
        return c++;
    }
};