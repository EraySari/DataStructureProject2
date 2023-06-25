#ifndef Doku_hpp
#define Doku_hpp
#include "Hucre.hpp"

class Doku
{
public:
  Doku();
  ~Doku();
  void hucreEkle(int hucre);
  int hucreSayisi;
  int ortancaDeger;
  int* dnaUzunluklar; 
  int kullanilan; 

  //binarytree icin
  Doku* right;
  Doku* left;  
  Hucre* ilk;
private:
  
};
#endif