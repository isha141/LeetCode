class ParkingSystem { 
     int big,small,medium; 
    int cb=0,cs=0,cm=0;
public:
    ParkingSystem(int big, int medium, int small) {
        this->big=big;
        this->medium=medium;
        this->small=small;
    }
    
    bool addCar(int car) {
        if(car==1){
            if(cb+1<=big){
                cb+=1; 
                return 1;
            }
            return 0;
        }
        if(car==2){
            if(cm+1<=medium){
                cm+=1;
                return 1;
            }
            return 0;
        }
        if(car==3){
            if(cs+1<=small){
               cs+=1;
                return 1;
            }
            return 0;
        }
        return 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */