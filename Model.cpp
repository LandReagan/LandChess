#include "Model.h"

Model::Model()
{
   std::clog << "CONSTR : Model" << std::endl;
}

Model::~Model()
{
   std::clog << "DESTR : Model" << std::endl;

   // OBSERVER DESTRUCTION:
   for (size_t i = 0; i < vec_Obs.size(); ++i)
      removeObserver(vec_Obs[i]);
}

void
Model::addObserver(Observer* obs)
{
   std::clog << "Model::addObserver() invoquée" << std::endl;
   vec_Obs.push_back(obs);
   notifyObservers();
}

void
Model::removeObserver(Observer* obs)
{

   std::clog << "Model::removeObserver() invoquée - ";

   for (size_t i = 0; i < vec_Obs.size(); ++i)
      if (vec_Obs[i] == obs)
      {
         vec_Obs.erase(vec_Obs.begin() + i);
         std::clog << "1 observer trouvé et détruit";
      }
   std::clog << std::endl;
}

void
Model::notifyObservers()
{
   std::clog << "Model::notifyObserver() invoquée" << std::endl;

   for (size_t i = 0; i < vec_Obs.size(); ++i)
      vec_Obs[i]->update();
}
