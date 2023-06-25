#ifndef Kontrol_hpp
#define Kontrol_hpp
#include "ikiliAramaAgaci.hpp"
#include "Radix.hpp"

class Kontrol
{
public:
  Kontrol();

  bool bolunuyorMu(Doku* root);
  void ciftMi(Doku* doku);
  void dokuGuncelle(Doku* guncellenecekDoku);
  void mutasyonPostOrder(Doku* mutasyonluDoku, int dizi[],int*siraliMutason,Doku* guncellenecek[],int &sayac,ikiliAramaAgaci* bst);
  int mutasyonSayi = 0;
  int dokuSayac = -1;
  int ilkMi = -1;
private:

};
#endif