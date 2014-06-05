#ifndef OBSERVER_H_INCLUDED
#define OBSERVER_H_INCLUDED

#include <vector>
#include <string>

class Observer
{
   public:
      virtual void update() = 0;
};

#endif // OBSERVER_H_INCLUDED
