class SnapshotArray { 
    unordered_map<int,map<int,int>>mp;
    int snap_id=0;
public:
    SnapshotArray(int length) {
        
    }
    
    void set(int index, int val) {
        mp[index][snap_id]=val;
    }
    
    int snap() {
        snap_id+=1; 
        return snap_id-1;
    }
    
    int get(int index, int snap_id) {
        auto itr=mp[index].upper_bound(snap_id);
        return itr==begin(mp[index])?0: prev(itr)->second; 
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */