#include "Echiquier.h"

Echiquier::Echiquier()
{
   std::clog << "CONSTR : Echiquier" << std::endl;

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
}

Echiquier::~Echiquier()
{
   std::clog << "DESTR : Echiquier" << std::endl;

   for (size_t i = 0; i < vec_Case.size(); ++i)
      delete vec_Case[i];
}
