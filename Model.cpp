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
   std::clog << "Model::addObserver() invoquée" << std::endl;
   vec_Obs.push_back(obs);
   notifyObservers();
}

void
Model::removeObserver(Observer* obs)
{

   std::clog << "Model::removeObserver() invoquée - NON CODEE !!!" << std::endl;
   // TO BE DONE !!!
}

void
Model::notifyObservers()
{
   std::clog << "Model::notifyObserver() invoquée" << std::endl;
   for (size_t i = 0; i < vec_Obs.size(); ++i)
      vec_Obs[i]->update();
}
