#include "Model.h"

Model::Model()
{
   std::clog << "CONSTR : Model" << std::endl;
}

Model::~Model()
{
   std::clog << "DESTR : Model" << std::endl;
}

void
Model::addObserver(Observer* obs)
{
   vec_Obs.push_back(obs);
}

void
Model::removeObserver(Observer* obs)
{
   for (size_t i = 0; i < vec_Obs.size(); ++i)
      if (vec_Obs[i] == obs)
         this.
}
