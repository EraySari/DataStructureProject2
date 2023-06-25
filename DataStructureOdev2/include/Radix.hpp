#ifndef Radix_hpp
#define Radix_hpp
#include "Queue.hpp"

class Radix
{
public:
    Radix(int* sayilar,int adet);
    ~Radix();
    int* sirala();

private:
    int     maxBasamakSayisiGetir();
    int     basamakSayisiGetir(int sayi);
    void    kuyruklariYazdir();
    void    kuyrukUzunluklariGetir(int* uzunluklar);
    Queue** kuyruklar;
    int*    sayilar;
    int     sayiAdedi;
};

#endif