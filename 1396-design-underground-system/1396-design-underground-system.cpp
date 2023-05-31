class UndergroundSystem { 
    private:
    map<int,string>id_tra;
    map<int,int>time_tra;
    map<string,map<string,pair<int,int>>>mp;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string name, int t) {
         id_tra[id]=name;
         time_tra[id]=t;
    }
    
    void checkOut(int id, string name, int t) {
        if(id_tra.find(id)!=id_tra.end()){
            string start=id_tra[id];
            string end=name;
             // curr=id_tra[t]; 
            int time1=t-time_tra[id];
            if(mp[start].find(end)!=mp[start].end()){
             auto itr=mp[start][end];
                mp[start][end]={itr.first+time1,itr.second+1};
            }
            else{
                mp[start][end]={time1,1};
            } 
            id_tra.erase(id);
            time_tra.erase(id);
        }
    }
    
    double getAverageTime(string s, string e) {
         auto itr=mp[s][e];
         int n=itr.second;
          double ans=(double)(itr.first)/n;
        return ans;
    } 
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */