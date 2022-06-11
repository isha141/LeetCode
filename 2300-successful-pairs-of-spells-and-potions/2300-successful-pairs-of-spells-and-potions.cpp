
class Solution { 
    int issolve(vector<int>& po,int tar,long long k)
    { 
        int low=0;
        int high=po.size()-1; 
        int ans=-1;
        while(low<=high){ 
            int mid=(low+high)>>1;
            if(((long long)po[mid]*(long long)tar)>=k){
               ans=mid;
                high=mid-1;
            }
            else
            low=mid+1; 
        }
        return ans;
    }
public:
    vector<int> successfulPairs(vector<int>& sp, vector<int>& po, long long suc) { 
        sort(po.begin(),po.end()); 
        vector<int>ans;  
        for(int i=0;i<sp.size();i++){ 
            int count=0;
             int temp=issolve(po,sp[i],suc); 
            if(temp==-1)
                ans.push_back(0);
            else
                ans.push_back(po.size()-temp);
        }
        return ans;
    }
};