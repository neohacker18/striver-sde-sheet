// Link to the problem : https://www.codingninjas.com/codestudio/problems/2099908?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

class Queue {
public:
    int* arr;
    int _front;
    int rear;
    int size;
    Queue() {
        size=5001;
        arr=new int[size];
        _front=0;
        rear=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return _front==rear;
    }

    void enqueue(int data) {
        if(rear==size)
            return;
        
        arr[rear++]=data;
    }

    int dequeue() {
        if(_front==rear)
            return -1;
        
        int x=arr[_front++];
        if(_front==rear)
        {
            _front=0;
            rear=0;
        }
        return x;
    }

    int front() {
        if(_front==rear)
            return -1;
        
        return arr[_front];
    }
};