#ifndef __ANIMAL_H__
#define __ANIMAL_H__

class Animal {
public:
  Animal() {}
  virtual ~Animal() {}
  virtual void speak() = 0;
};

#endif // __ANIMAL_H__
