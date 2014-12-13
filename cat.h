#ifndef __CAT_H__
#define __CAT_H__

#include "animal.h"
#include "cat_export.h"

class CAT_EXPORT Cat : public Animal {
public:
  Cat();
  virtual ~Cat();
  /*virtual*/ void speak();
};

#endif // __CAT_H__
