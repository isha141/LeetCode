 class node{
    public:
    int x;
    int y;
    int dir;
    node(int x,int y,int dir){
        this->x=x; this->y=y; this->dir=dir;
    }
};
class Robot {
    int pos=0;
    int x=0;
    int y=0;
    int w,h;
    int dir=3;
         bool init=0;
    int per=0;
    vector<node>ds;
public:
    
    Robot(int width, int height) {
        w=width;
        h=height;
        per=2*(w+h)-4;
        // ds=new node[per];
        for(int i=0;i<per;++i){
            ds.push_back(node(x,y,dir));
            if(x==0 && y==0)
                dir=0;
            else if(x==w-1 && y==0) dir=1;
            else if(x==w-1 && y==h-1) dir=2;
            else if(x==0 && y==h-1) dir=3;
            if(dir==0) x++;
            else if(dir==1) y++;
            else if(dir==2) x--;
            else
                y--;
        }
    }
    
    void step(int num) {
        init=1;
        pos=(pos+(num%per))%per;
    }
    
    vector<int> getPos() {
       return {ds[pos].x,ds[pos].y}; 
    }
    
    string getDir() {
        if(!init) return "East";
        int temp=ds[pos].dir;
        if(temp==0) return "East";
        else if(temp==1) return "North";
        else if(temp==2) return "West";
        else
            return "South";
        
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */