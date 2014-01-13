#include <iostream>
#include <fstream>

#include "View.h"

using namespace std;

int main()
{
   // Stream redirection:
   std::ofstream log ("log.txt");
   std::ofstream err ("err.txt");
   std::streambuf* oldlog = std::clog.rdbuf(log.rdbuf());
   std::streambuf* olderr = std::cerr.rdbuf(err.rdbuf());

   View* view = new View();

   delete view;

   std::clog.rdbuf(oldlog);
   std::cerr.rdbuf(olderr);

   return 0;
}
