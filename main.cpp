#include <iostream>
#include <fstream>

#include "GUI.h"

using namespace std;

int main(int argc, char **argv)
{
   // Stream redirection:
   std::ofstream log ("./LOGS/log.txt");
   std::ofstream err ("./LOGS/err.txt");
   std::streambuf* oldlog = std::clog.rdbuf(log.rdbuf());
   std::streambuf* olderr = std::cerr.rdbuf(err.rdbuf());

   GUI* gui = new GUI(); // sets everything up (MVC, SDL...)

   gui->exec(); // Launch event loop, and the game.

   delete gui;

   std::clog << "Fin du programme !" << std::endl;

   std::clog.rdbuf(oldlog);
   std::cerr.rdbuf(olderr);

   return 0;
}
