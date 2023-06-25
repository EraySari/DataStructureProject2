#ifndef Organ_hpp
#define Organ_hpp
#include "Doku.hpp"
#include "ikiliAramaAgaci.hpp"

class Organ
{
public:
  Organ();
  void organOlustur(ikiliAramaAgaci* bst);
  void organYazdir();
  int organElemanSayisi;
  ikiliAramaAgaci* organIlk;
private:
  
};
 
#endif