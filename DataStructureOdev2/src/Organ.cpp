/**
* @file DataStructureOdev2
* @description  LinkedList, BinaryTree yapilarini birlikte kullanarak ekrana verileri kullanarak görsel cikarma
* @course 1-C
* @assignment 2.Ödev
* @date 25.12.2022
* @author Eray Sari eray.sari2@ogr.sakarya.edu.tr
*/

#include "Organ.hpp"
#include<iostream>
using namespace std;
Organ::Organ()
{
  organIlk = 0;
  organElemanSayisi = 0;
}
void Organ::organOlustur(ikiliAramaAgaci* bst)
{
  if(organIlk == 0)
  {
    organIlk = bst;
  }
  else
  {
    
    ikiliAramaAgaci* gecici = organIlk;
    while (gecici->next != 0)
    {
      gecici = gecici->next;
    }
    gecici->next = bst;
    bst->back = gecici;
  }

  organElemanSayisi++;
}
void Organ::organYazdir()
{
  ikiliAramaAgaci* yedek = organIlk;
  while (yedek != 0)
  {
    cout << yedek->getRoot()->ortancaDeger << endl;
    cout << yedek->back << "-" << yedek << "-" << yedek->next << endl;
    yedek = yedek->next;
  }
}