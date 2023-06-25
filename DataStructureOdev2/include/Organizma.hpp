#ifndef Organizma_hpp
#define Organizma_hpp
#include "Sistem.hpp"
class Organizma
{
private:
   
public:
  Organizma();
  ~Organizma();
  void organizmayaEkle(Sistem* ekle);
  void organizmaYazdir();
  void organizmaEkranaYazdir();
  Sistem* organizmaIlk;
};



#endif