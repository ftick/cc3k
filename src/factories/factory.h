#ifndef __FACTORY_H__
#define __FACTORY_H__

#include <vector>
#include <cstdlib>

template<class T>
class Factory {
    std::vector<T *(*)()> generators;
  public:
    Factory();
    void add(int probability, T *(*create)());
    T *operator()();
};

template<class T, class R>
T *creator() {
  return new R();
}

template<class T>
Factory<T>::Factory() {}

template<class T>
void Factory<T>::add(int probability, T *(*create)()) {
  for (int i = 0; i < probability; ++i) {
    generators.push_back(create);
  }
}

template<class T>
T *Factory<T>::operator()() {
  int i = rand() % generators.size();
  return generators[i]();
}

#endif
