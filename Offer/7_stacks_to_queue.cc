/*
 * @filename:    7_stacks_to_queue.cc
 * @author:      Crow
 * @date:        03/30/2019 10:12:36
 * @description: 
 *           题目: 使用两个栈实现队列的功能
 *           思路: 栈实现队列 => 入队: 正常入栈A,
 *                            => 出队: 若B为空, 则将A所有元素pop()进入栈B, 
 *                            之后出栈B即可
 */

#include <iostream>
#include <vector>
#include <stack>

template <typename T>
class StackToQueue {
 public:
  StackToQueue() = default;
  ~StackToQueue() = default;

  void Enqueue(const T &data);
  T Dequeue();

 private:
  std::stack<T> stackA_;
  std::stack<T> stackB_;
};

template <typename T>
void StackToQueue<T>::Enqueue(const T &data) {
  stackA_.push(data);
}

template <typename T>
T StackToQueue<T>::Dequeue() {
  if (stackB_.empty()) {
    while (!stackA_.empty()) {
      stackB_.push(stackA_.top());
      stackA_.pop();
    }
  }

  if (!stackB_.empty()) {
    auto data = stackB_.top();
    stackB_.pop();
    return data;
  }

  return T{};
}

int main(void) {
  StackToQueue<int> queue;

  queue.Enqueue(1);
  queue.Enqueue(2);
  queue.Enqueue(3);
  queue.Enqueue(4);

  std::cout << queue.Dequeue() << std::endl;
  std::cout << queue.Dequeue() << std::endl;
  std::cout << queue.Dequeue() << std::endl;
  std::cout << queue.Dequeue() << std::endl;

  return 0;
}
