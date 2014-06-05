#ifndef ECHIQUIER_H_INCLUDED
#define ECHIQUIER_H_INCLUDED

#include <vector>

#include "Model.h"
#include "Case.h"
#include "Snapshot.h"

class Echiquier : public Model
{
   public:
      Echiquier();
      virtual ~Echiquier();

      void notifyObservers() const;

      Snapshot* get_snapshot() const {return snap;}

   private:
      std::vector<Case*> vec_Case;
      Snapshot* snap;

      void update_snapshot();
};

#endif // ECHIQUIER_H_INCLUDED
