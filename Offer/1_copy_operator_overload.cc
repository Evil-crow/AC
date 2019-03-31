/*
 * @filename:    offer_1.cc
 * @author:      Crow
 * @date:        03/09/2019 22:29:04
 * @description: 剑指Offer第一题: 实现Class的拷贝赋值运算符
 */

#include <iostream>
#include <cstring>
#include <cassert>

class Temp {
 public:
   Temp(const char *str);
   ~Temp();
   Temp(const Temp &);
   Temp &operator=(const Temp &);
   const char *Show() { return str; }

  private:
   char *str;
};

Temp::Temp(const char *str) {
  this->str = new char[strlen(str) + 1];
  ::memcpy(this->str, str, strlen(str) + 1);
}

Temp::~Temp() {
  delete[] str;
}

Temp::Temp(const Temp &rhs) {
  str = new char[strlen(rhs.str) + 1];
  ::memcpy(this->str, rhs.str, strlen(rhs.str) + 1);
}

// Temp &Temp::operator=(const Temp &rhs) {
//   if (this == &rhs)
//     return *this;
//
//   delete str;
//   str = new char[strlen(rhs.str)];
//   ::memcpy(this->str, rhs.str, strlen(rhs.str));
//   return *this;
// }

Temp &Temp::operator=(const Temp &rhs) {
  Temp temp(rhs);
  std::swap(*this, temp);

  return *this;
}

int main(void)
{
  Temp t("Hello World");
  std::cout << t.Show() << std::endl;

  Temp p = t;
  std::cout << p.Show() << std::endl;

  Temp &x = t;
  assert(&t == &x);
  t = x;
  std::cout << t.Show() << std::endl;
}
