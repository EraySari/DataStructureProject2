/**
* @file DataStructureOdev2
* @description  LinkedList, BinaryTree yapilarini birlikte kullanarak ekrana verileri kullanarak görsel cikarma
* @course 1-C
* @assignment 2.Ödev
* @date 25.12.2022
* @author Eray Sari eray.sari2@ogr.sakarya.edu.tr
*/

#include "Kontrol.hpp"
#include<iostream>
using namespace std;


Kontrol::Kontrol()
{

}
bool Kontrol::bolunuyorMu(Doku* root)
{
  if(root->ortancaDeger % 50 == 0)
  {
    return 1;
  }
  else
    return 0;  
}
void Kontrol::ciftMi(Doku* root)
{
  if(root)
  {
    Hucre* yedek = root->ilk;
    for(int i = 0; i< root->hucreSayisi;i++)
    {
      if(yedek->dnaUzunluk %  2 == 0)
      {
        yedek->dnaUzunluk = yedek->dnaUzunluk/2;
      }   
      yedek = yedek->sonraki;
    }
    ciftMi(root->left);
    ciftMi(root->right);
  }
}
void Kontrol::mutasyonPostOrder(Doku* mutasyonluDokuKok, int mutasyonTutanDizi[],int* siraliMutason,Doku* guncellenecek[],int &index,ikiliAramaAgaci* mutasyonBst)
{
  Doku* mutasyonluDoku = new Doku();
  if(mutasyonluDokuKok)
  {
    
    mutasyonPostOrder(mutasyonluDokuKok->left,mutasyonTutanDizi,siraliMutason,guncellenecek,index,mutasyonBst);
    mutasyonPostOrder(mutasyonluDokuKok->right, mutasyonTutanDizi,siraliMutason,guncellenecek,index,mutasyonBst);

    Hucre* yedek = mutasyonluDokuKok->ilk;
    for(int i = 0; i< mutasyonluDokuKok->hucreSayisi;i++)
    {
      
      mutasyonTutanDizi[mutasyonSayi] = yedek->dnaUzunluk;
      yedek = yedek->sonraki;
      mutasyonSayi++;
    }
    for(int i=0;i<mutasyonSayi;i++)
    {
      mutasyonluDoku->hucreEkle(mutasyonTutanDizi[i]);
    }
    
    Radix *radix = new Radix(mutasyonTutanDizi,mutasyonSayi);

    //siraliMutason icinde mutasyonun sirali hali var
    siraliMutason = radix->sirala();

    guncellenecek[index]->ilk = mutasyonluDoku->ilk;
    guncellenecek[index]->hucreSayisi = mutasyonluDoku->hucreSayisi;
    guncellenecek[index]->ortancaDeger = siraliMutason[mutasyonSayi/2];

    ilkMi++;

    //ikili mutasyonlu hucreler ile guncellenecek
    if(ilkMi == 0) 
      mutasyonBst->root = 0;

    mutasyonBst->insert(guncellenecek[index]);//Burada hata veriyor

    index++;
    mutasyonSayi = 0;
    delete radix;
    delete siraliMutason; 

  }
}
