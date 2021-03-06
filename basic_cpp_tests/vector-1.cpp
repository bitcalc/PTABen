#include "aliascheck.h"
#include <iostream>
#include <vector>

using namespace std;

int global_obj;
int *global_ptr = &global_obj;

class A {
  public:
    virtual void f(int *i) const {
      MUSTALIAS(global_ptr, i);
    }
};

int main(int argc, char **argv)
{
  int *ptr = &global_obj;

  vector<A> vec;
  A a;
  vec.push_back(a);

  const A *aptr = &(vec[0]);
  aptr->f(ptr);

  return 0;
}
