class MyCircularQueue {
private:
    int *queue;  // pointer to the array for the queue
    int head;    // index of the front element
    int tail;    // index of the rear element
    int capacity; // size of the queue
    int count;   // current number of elements

public:
    // Constructor to initialize the queue with size k
    MyCircularQueue(int k) {
        capacity = k;
        queue = new int[k];
        head = -1;
        tail = -1;
        count = 0;
    }
    
    // Destructor to free up the memory
    ~MyCircularQueue() {
        delete[] queue;
    }
    
    // Check if the queue is full
    bool isFull() {
        return count == capacity;
    }
    
    // Check if the queue is empty
    bool isEmpty() {
        return count == 0;
    }
    
    // Add an element to the rear of the queue
    bool enQueue(int value) {
        if (isFull()) return false;
        
        if (isEmpty()) head = 0;  // If first element, move head to 0
        
        tail = (tail + 1) % capacity;
        queue[tail] = value;
        count++;
        return true;
    }
    
    // Remove an element from the front of the queue
    bool deQueue() {
        if (isEmpty()) return false;
        
        if (head == tail) {  // If only one element, reset queue
            head = -1;
            tail = -1;
        } else {
            head = (head + 1) % capacity;
        }
        count--;
        return true;
    }
    
    // Get the front item
    int Front() {
        if (isEmpty()) return -1;
        return queue[head];
    }
    
    // Get the last item
    int Rear() {
        if (isEmpty()) return -1;
        return queue[tail];
    }
};
