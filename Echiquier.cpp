#include "Echiquier.h"

Echiquier::Echiquier()
{
   std::clog << "CONSTR : Echiquier" << std::endl;

   // Snapshot creation (empty)
   snap = new Snapshot();

   // Case creation:
   bool white = false;
   for (int j = 8; j >= 1; --j)
   {
      white = !white;
      for (char c = 'a'; c <= 'h'; ++c)
      {
         Case* cas = new Case(c, j, white);
         vec_Case.push_back(cas);
         white = !white;
      }
   }

   update_snapshot();
}

Echiquier::~Echiquier()
{
   std::clog << "DESTR : Echiquier" << std::endl;

   // Snapshot destruction
   delete snap;

   // Case destruction
   for (size_t i = 0; i < vec_Case.size(); ++i)
      delete vec_Case[i];
}

void
Echiquier::update_snapshot()
{
    snap->v_snap.clear();
    for (size_t i = 0; i < vec_Case.size(); ++i)
        snap->v_snap.push_back(vec_Case[i]->get_snap_state());
}

// notifyObservers method overload (for snapshot)
void
Echiquier::notifyObservers() const
{
   std::clog << "Model::notifyObserver(snap!!!) invoquée" << std::endl;
   for (size_t i = 0; i < vec_Obs.size(); ++i)
      vec_Obs[i]->update();
}
