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
   // TO BE DONE !!!
}
