class MyCircularDeque {
    vector<int>q;
    int front;
    int rear;
    int cap;
    int count;
public:
    MyCircularDeque(int k) {
       q.resize(k);
       cap=k;
       front=0;
       rear=k-1;
       count=0;
    }
    
    bool insertFront(int value) {
       if(isFull())return false;
       front=(front+cap-1)%cap;
       q[front]=value;
       count++;
       return true;
    }
    
    bool insertLast(int value) {
      if(isFull())return false;
      rear=(rear+1)%cap;
      q[rear]=value;
      count++;
      return true;
    }
    
    bool deleteFront() {
      if(isEmpty())return false;
      front=(front+1)%cap;
      count--;
      return true;
    }
    
    bool deleteLast() {
       if(isEmpty())return false;
       rear=(rear+cap-1)%cap;
       count--;
       return true;
    }
    
    int getFront() {
        if(isEmpty())return -1;
       return q[front];
    }
    
    int getRear() {
        if(isEmpty())return -1;
        return q[rear];
    }
    
    bool isEmpty() {
      return count==0;
    }
    
    bool isFull() {
     return count==cap;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */