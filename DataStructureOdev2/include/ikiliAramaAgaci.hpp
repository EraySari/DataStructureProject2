#ifndef ikiliAramaAgaci_hpp
#define ikiliAramaAgaci_hpp
#include "Doku.hpp"

class ikiliAramaAgaci
{
public:
  ikiliAramaAgaci();
  void insert(Doku*eklenecek);
  void dokulariGez(Doku* root);
  void diziyeEkle(ikiliAramaAgaci* organIkili);
  bool isEmpty();
  int height(Doku* ikiliHeight);
  int height();
  int different(Doku* ikili);
  Doku* getRoot();
  ikiliAramaAgaci* next;
  ikiliAramaAgaci* back;
  ikiliAramaAgaci* diziIlk;
  ikiliAramaAgaci* diziNext;
  ikiliAramaAgaci* sistemNext;
  
  Doku* root;
private:
  
  void insert(Doku*eklenecek,Doku* start);
};
#endif