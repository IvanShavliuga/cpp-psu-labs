#include <iostream>
using namespace std;

//Compiler version g++ 6.3.0

class Counter {
  private:
    int count=0;
  public:
    Counter() {
      this->count=10;
    }
    int summ();
    void print();
    void setCount(int count);
};
int Counter::summ() {
  int summ=0;
  for (int i=0; i<this->count; i++) {
      summ += i;
    }
  return summ;
}
void Counter::print() {
    cout << "count: " << this->count  << "\n";
    cout << "sunn: " << this->summ() << endl;
}
void Counter::setCount(int count) {
  this->count = count;
}
int main()
{
    Counter *counter = new Counter();
    counter->print();
    cout << "Hello, Dcoder!\n";
}