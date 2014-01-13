#ifndef OBSERVABLE_H_INCLUDED
#define OBSERVABLE_H_INCLUDED

#include <vector>

#include "Observer.h"

class Observable
{
   public:
      virtual void addObserver(Observer* obs) = 0;
      virtual void removeObserver(Observer* obs) = 0;
      virtual void notifyObservers() = 0;

   protected:
      std::vector<Observer*> vec_Obs;
};

#endif // OBSERVABLE_H_INCLUDED
