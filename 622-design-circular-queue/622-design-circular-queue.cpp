class MyCircularQueue { 
    private:
    vector<int>ds;
    int k; 
    int front=-1;
    int end=-1; 
    int elements=0;
public:
    MyCircularQueue(int k) {
        vector<int>arr(k,0);
        ds=arr;
        this->k=k;
    }
    
    bool enQueue(int value) {
      if(isFull())
            return 0;
        ds[(end+1)%k]=value; 
        end=(end+1)%k;  
        elements++;
        if(front==-1)
            front=0;
        return 1;
    }
    
    bool deQueue() {
        if(isEmpty())
            return 0; 
        if(front==-1)
        {
            end=-1;
            return 0;
        }
        if(front==end){
            front=-1;
            end=-1;
        } 
        front=(front+1)%k; 
        elements--;
        return 1;
    }
    
    int Front() { 
       if(isEmpty())
               return -1;
         return ds[front%k];
    }
    
    int Rear() { 
       if(isEmpty())
            return -1;
         return ds[end%k]; 
    }
    
    bool isEmpty() {
        if(elements==0)
            return 1;
        return 0;
    }
    
    bool isFull() {
        return elements==k;
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