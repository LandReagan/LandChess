#ifndef CASE_H_INCLUDED
#define CASE_H_INCLUDED

#include <string>

#include "Piece.h"

enum STATUS {NORMAL = 0, SURVOL, ACTIVE, ON_RANGE};

class Case
{
   public:
      Case(char c, int n, bool w) : col(c), lin(n), piece(nullptr), status(NORMAL), is_white(w)
         {  //std::clog << "Case en " << c << n << " créée, couleur : " << w << std::endl;
            update_snap_state();
            //std::clog << "OK" << std::endl;
         }
      virtual ~Case() {delete piece;}

   // SETS:
      void set_Piece(Piece* p) {piece = p; update_snap_state();}
      void set_Status(STATUS s) {status = s; update_snap_state();}

   // GETS:
      char get_col() const {return col;}
      int get_lin() const {return lin;}
      Piece* get_Piece() const {return piece;}
      STATUS get_STATUS() const {return status;}
      std::string get_snap_state() const {return snap_state;}


   private:
      char col;
      int lin;
      Piece* piece;
      STATUS status;
      bool is_white;

      std::string snap_state;
      void update_snap_state();
};

#endif // CASE_H_INCLUDED
