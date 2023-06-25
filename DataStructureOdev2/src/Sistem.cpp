/**
* @file DataStructureOdev2
* @description  LinkedList, BinaryTree yapilarini birlikte kullanarak ekrana verileri kullanarak görsel cikarma
* @course 1-C
* @assignment 2.Ödev
* @date 25.12.2022
* @author Eray Sari eray.sari2@ogr.sakarya.edu.tr
*/

#include "Sistem.hpp"
#include<iostream>
using namespace std;

Sistem::Sistem()
{
  sistemIlk = 0;
  organizmaNext = 0;
}
Sistem::~Sistem()
{
  delete sistemIlk;
}
void Sistem::sistemOlustur(ikiliAramaAgaci* veri)
{
  if(sistemIlk == 0)
  {
    sistemIlk = veri;
  }
  else
  {
    
    ikiliAramaAgaci* yedek = sistemIlk;
    while (yedek->sistemNext != 0)
    {
      yedek = yedek->sistemNext;
    }
    yedek->sistemNext = veri;
  }
  
}
void Sistem::sistemYazdir()
{
  ikiliAramaAgaci* yedek = sistemIlk;
  while (yedek !=0)
  {
    cout << yedek->getRoot()->ortancaDeger << endl;
    yedek = yedek->diziNext;
  }
  
}