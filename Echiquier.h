#ifndef ECHIQUIER_H_INCLUDED
#define ECHIQUIER_H_INCLUDED

#include <vector>

#include "Model.h"
#include "Case.h"

class Echiquier : public Model
{
   public:
      Echiquier();
      virtual ~Echiquier();

   private:
      std::vector<Case*> vec_Case;
};

#endif // ECHIQUIER_H_INCLUDED
