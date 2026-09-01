using namespace std;
#include <vector>

class MyCircularQueue {
public:
  vector<int> circular_queue;
  int front = 0;
  int back = -1;
  int num_elements = 0;
  MyCircularQueue(int k) { circular_queue = vector<int>(k); }

  bool enQueue(int k) {
    if (isFull()) {
      return false;
    }
    back = (back + 1) % circular_queue.size();
    circular_queue[back] = k;
    num_elements++;
    return true;
  }

  bool deQueue() {
    if (isEmpty()) {
      return false;
    }
    front = (front + 1) % circular_queue.size();
    num_elements--;
    return true;
  }

  int Front() { return isEmpty() ? -1 : circular_queue[front]; }

  int Rear() { return isEmpty() ? -1 : circular_queue[back]; }

  bool isEmpty() { return num_elements == 0; }

  bool isFull() { return num_elements == circular_queue.size(); }
};
