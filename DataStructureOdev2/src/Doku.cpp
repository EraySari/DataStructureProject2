/**
* @file DataStructureOdev2
* @description  LinkedList, BinaryTree yapilarini birlikte kullanarak ekrana verileri kullanarak görsel cikarma
* @course 1-C
* @assignment 2.Ödev
* @date 25.12.2022
* @author Eray Sari eray.sari2@ogr.sakarya.edu.tr
*/

#include "Doku.hpp"
#include<iostream>
using namespace std;

Doku::Doku()
{
  ilk = NULL;
  hucreSayisi = ortancaDeger =kullanilan = 0;

  //binarytree icin
  right = left = NULL;

  dnaUzunluklar = new int[100];
};
Doku::~Doku()
{
  delete[] dnaUzunluklar;
}
void Doku::hucreEkle(int veri)
{
  Hucre* yeniHucre = new Hucre(veri);
  if(ilk == NULL)
  {
    ilk = yeniHucre;
    dnaUzunluklar[0] = ilk->dnaUzunluk;
    kullanilan++;
  }
  else
  {
    Hucre* gecici = ilk;
    while (gecici->sonraki != 0)
    {
      gecici = gecici->sonraki;
    }
    gecici->sonraki = yeniHucre;
    dnaUzunluklar[kullanilan] = yeniHucre->dnaUzunluk;
    kullanilan++;
  }
  hucreSayisi++;
};
