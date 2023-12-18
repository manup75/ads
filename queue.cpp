#include<iostream>

using namespace std;
 
 class Queue
 {
  public:
  int *arr;
  int size;
  int qfront;
  int rear;
  Queue(int size)
  { 
    this->size=size;
    arr=new int[size];
    int qfront=0;
    int rear=0;
  }
    void enque( int data){
                 if(qfront==size)
                 {
                    cout<<"Queue is full"<<endl;
                 }
                 else{ 
                      
                    arr[rear]=data;
                    rear++;
                 }
    }
    void deque()
    {  
         if(qfront==rear)
         {
             cout<<"queue is full";
         }
         else
         {
            arr[qfront]=-1;
            qfront++;
            if(qfront==rear)
            {
                qfront=0;
                rear=0;
            }
         }
    }
    int front()
    {
        if(qfront==rear)
        {
            return -1;
        }
        else
        {
          return arr[qfront];
        }
    }
   bool isEmpty()
   {
    if(qfront==rear)
    {
        return true;
    }
    else{
        return false;
    }
   }
 };

int main()
{
       Queue q(5);
       q.enque(5);
       q.enque(6);
       q.deque();
       int d=q.front();
      cout<<"Front element is:"<<d<<endl;
    return 0;
}