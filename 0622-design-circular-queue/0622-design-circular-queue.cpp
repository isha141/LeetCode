class MyCircularQueue { 
    vector<int>ds;
    int last =-1;
    int curr=-1;
    int elements=0;
    int n;
public:
    MyCircularQueue(int k) {
        ds.resize(k,-1);
        n=k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return 0;
         ds[(curr+1)%n]=value;
        if(last==-1) {
            last =0;
        }
        curr=(curr+1)%n;
        elements+=1;
        return 1;
    }
    
    bool deQueue() {
        if(isEmpty()) return 0;
        if(last==curr){
            last=-1;
            curr=-1;
        }
        last=(last+1)%n;
        elements--;
        return 1;
        
    }
    
    int Front() {
        if(isEmpty()) return -1;
        if(last==-1) return 0;
        return ds[last%n];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        if(curr==-1) return 0;
        return ds[curr%n];
        
    }
    
    bool isEmpty() {
        return (elements==0);
    }
    
    bool isFull() {
        return elements==n;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */