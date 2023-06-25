/**
* @file DataStructureOdev2
* @description  LinkedList, BinaryTree yapilarini birlikte kullanarak ekrana verileri kullanarak görsel cikarma
* @course 1-C
* @assignment 2.Ödev
* @date 25.12.2022
* @author Eray Sari eray.sari2@ogr.sakarya.edu.tr
*/

#include "Organizma.hpp"
#include "Kontrol.hpp"
#include<iostream>
using namespace std;

Organizma::Organizma()
{
  organizmaIlk = 0;
}
Organizma::~Organizma()
{
  delete organizmaIlk;
}
void Organizma::organizmayaEkle(Sistem* sistemAktar)
{
  if(organizmaIlk == 0)
  {
    organizmaIlk = sistemAktar;
  }
  else
  {
    Sistem * yedek = organizmaIlk;
    while (yedek->organizmaNext != 0)
    {
      yedek = yedek->organizmaNext;
    }
    yedek->organizmaNext = sistemAktar;
  }
}

void Organizma::organizmaYazdir()
{
  Sistem* yedek = organizmaIlk;
  while (yedek != 0)
  {
    cout << yedek->sistemIlk->getRoot()->ortancaDeger << endl; 
    yedek = yedek->organizmaNext;
  }
  
}
void Organizma::organizmaEkranaYazdir()
{
  Sistem* yedek = organizmaIlk;
  while (yedek != 0)
  {
    cout << yedek->sistemIlk->getRoot()->ortancaDeger << endl;
    yedek = yedek->organizmaNext;
  }
}