/*
 * @filename:    7_extra_queues_to_stack.cc
 * @author:      Crow
 * @date:        03/30/2019 10:28:07
 * @description:
 */

#include <queue>
#include <iostream>

template <typename T>
class QueueToStack {
 public:
  QueueToStack() = default;
  ~QueueToStack() = default;
  void Estack(const T &data);
  T Dstack();
 
 private:
  std::queue<T> queueA_;
  std::queue<T> queueB_;
};

// 入栈: 选择非空的队列进行元素的push即可
//    初始时, 选择任意一个即可, 我们一般选择queueA_
template <typename T>
void QueueToStack<T>::Estack(const T &data) {
  if (queueA_.empty() && queueB_.empty()) {           // 初始选择入栈的队列
    queueA_.push(data);
  } else {                                            // 栈不为空时, 每次入栈选择现在不为空的栈即可
    if(!queueA_.empty())
      queueA_.push(data);
    else
      queueB_.push(data);
  }
}

// 出栈: 将非空队列中所有元素转移到另外一个队列
//     之后出栈即可, 在两个队列间进行元素的流转
//     不需要指定某个队列作为指定的对象

template <typename T>
T QueueToStack<T>::Dstack() {
  if (queueA_.empty() && !queueB_.empty()) {
    while (queueB_.size() > 1) {
      queueA_.push(queueB_.front());
      queueB_.pop();
    }
    auto data = queueB_.front();
    queueB_.pop();

    return data;
  } else if (!queueA_.empty() && queueB_.empty()) {
    while (queueA_.size() > 1) {
      queueB_.push(queueA_.front());
      queueA_.pop();
    }
    auto data = queueA_.front();
    queueA_.pop();

    return data;
  } else {
    return T{};
  }
}

int main(void)
{
  QueueToStack<int> stack;

  stack.Estack(1);
  stack.Estack(2);
  stack.Estack(3);
  stack.Estack(4);

  std::cout << stack.Dstack() << std::endl;
  std::cout << stack.Dstack() << std::endl;
  std::cout << stack.Dstack() << std::endl;
  std::cout << stack.Dstack() << std::endl;

  return 0;
}
