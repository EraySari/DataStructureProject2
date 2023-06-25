#ifndef Sistem_hpp
#define Sistem_hpp
#include "Organ.hpp"

class Sistem
{
private:
  
public:
  Sistem();
  ~Sistem();
  void sistemOlustur(ikiliAramaAgaci* veri);
  void sistemYazdir();
  ikiliAramaAgaci* sistemIlk;
  Sistem* organizmaNext;
};

#endif