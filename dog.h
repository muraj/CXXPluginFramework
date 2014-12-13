#ifndef __DOG_H__
#define __DOG_H__

#include "animal.h"
#include "dog_export.h"

class DOG_NO_EXPORT Dog : public Animal {
public:
  Dog();
  virtual ~Dog();
  /*virtual*/ void speak();
};

#endif // __DOG_H__
