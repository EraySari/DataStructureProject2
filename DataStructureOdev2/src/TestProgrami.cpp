/**
* @file DataStructureOdev2
* @description  LinkedList, BinaryTree yapilarini birlikte kullanarak ekrana verileri kullanarak görsel cikarma
* @course 1-C
* @assignment 2.Ödev
* @date 25.12.2022
* @author Eray Sari eray.sari2@ogr.sakarya.edu.tr
*/
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include <sstream>
#include "Radix.hpp"
#include "Organ.hpp"
#include "Sistem.hpp"
#include "ikiliAramaAgaci.hpp"
#include "Organizma.hpp"
#include "Kontrol.hpp"
using namespace std;

int main()
{
  int satirSayac = 0;
  int elemanSayisi = 0;
  int binarySayac = 0;
  char mutasyon;

  fstream myFile;
   myFile.open("veri.txt",ios::in);
  if(myFile.is_open())
  {
    string veri;
    while (getline(myFile,veri))
    {
      satirSayac++;
    }
      myFile.close();
  }

  //Doku icin pointer dizisi olusturuluyor
  Doku* *dokuListe = new Doku*[satirSayac];

  //ikili agac icin pointer dizisi olusturuluyor
  ikiliAramaAgaci* *bst = new ikiliAramaAgaci*[satirSayac/20];

  //Sistem icin dizi
  Sistem* *sistem = new Sistem*[(satirSayac/20)/100];

  //Sisteme atilacak organlari tutan dizi
  ikiliAramaAgaci* *organTut = new ikiliAramaAgaci*[(satirSayac/20)/100];

  //Organizma icin 
  Organizma* organizma = new Organizma;


  myFile.open("veri.txt",ios::in);
  if(myFile.is_open())
  {
    satirSayac = 0;
    int ikiliKontrol = 0;
    int organSayac = 0;
    int sistemSayi = 0;
    int sonKalinanNokta = 0;
    int carp = 1;
    int sayac = 0;
    string veri;

    
    Organ* organ = new Organ;

    while (getline(myFile,veri))
    {
      if (veri.empty())
        continue;

      istringstream iss(veri);
      int next = 0;
      elemanSayisi = 0;

      dokuListe[satirSayac] = new Doku(); 
      
      ikiliKontrol++;
      //dokuya hucre ekleme
      while (iss >> next)
      {
        elemanSayisi++;
        dokuListe[satirSayac]->hucreEkle(next);
      }

      //dna uzunluklarini icerisine aktaracagimiz dizi olusturma. radix icin
      int kullanilanIndex = dokuListe[satirSayac]->kullanilan;
      int dnalar[kullanilanIndex];

      //dna uzunluklari olusturulan diziye aktarma
      for(int i = 0; i< kullanilanIndex;i++)
      {
        dnalar[i] = dokuListe[satirSayac]->dnaUzunluklar[i];
      }

      //radix ile siralama
      Radix *radix = new Radix(dnalar,kullanilanIndex);
      int *siraliSayilar = radix->sirala();

      //ortanca degera atama
      dokuListe[satirSayac]->ortancaDeger = siraliSayilar[(kullanilanIndex)/2];

      //20 dokuda 1 organ - ikili agac olusturma
      if(ikiliKontrol == 20)
      {
        bst[binarySayac] = new ikiliAramaAgaci();

        //20 geri gidilerek 20 degerde yazdiriliyor
        for(int i = satirSayac-(ikiliKontrol-1); i<=satirSayac;i++)
        {                 

          bst[binarySayac]->insert(dokuListe[i]);
          
          
          if(i+1 == satirSayac)
          {
            organ->organOlustur(bst[binarySayac]);
            organSayac++;
            if(organ->organElemanSayisi == 100*carp)
            {
              ikiliAramaAgaci* yedekOrgan = new ikiliAramaAgaci;

              organTut[sistemSayi] = new ikiliAramaAgaci;

              int say = 0;

              for(int i = 0; i < organ->organElemanSayisi; i++)
              {
                if(i == 0)
                {
                  yedekOrgan = organ->organIlk;            
                }  
                else
                {
                  yedekOrgan = yedekOrgan->next;               
                }
                say++;
              }
              
              //100 geri geliyorum
              for(int i = (carp-1)*100;i<organ->organElemanSayisi;i++){

                if(i == 0 || i % 100 == 0)
                {
                  if(say == i+100)
                  {
                    say = 0;
                    
                    //100 geri geliniyor
                    while (say != 99)
                    {
                      yedekOrgan = yedekOrgan->back;                
                      say++;
                    }  

                    say = 0;  
                    organTut[sistemSayi] = yedekOrgan;

                    //tekrar 100 ileri. Tek tek ekleniyor
                    while (say != 100)
                    {
                      organTut[sistemSayi]->diziyeEkle(yedekOrgan);
                      yedekOrgan = yedekOrgan->next;
                      say++;
                    }
                    int dongu = 0;

                    ikiliAramaAgaci* yedekOrganTut = organTut[sistemSayi]->diziIlk;

                    sistem[sistemSayi] = new Sistem();
                    while (dongu != 100)
                    {
                      sistem[sistemSayi]->sistemOlustur(yedekOrganTut);

                      yedekOrganTut = yedekOrganTut->diziNext;
                      dongu++; 
                    }          
                  }
                  sayac = sistemSayi;
                }
              }
              organizma->organizmayaEkle(sistem[sistemSayi]);
              sistemSayi++;
              carp++;
            }         
          }      
        }
        ikiliKontrol = 0;
        binarySayac++;
      }          
      satirSayac++;
      
   }
   Sistem* yedek = organizma->organizmaIlk;
   Kontrol kontrolEt;
   
   for(int i = 0; i<= sayac; i++)
   {
    
    //organizma icindeki organlari(ikilileri) geziyoruz
    if(i == 0)
        cout<< setw(28) << "ORGANIZMA" << endl;

    ikiliAramaAgaci* organYedek = yedek->sistemIlk;
    for(int j = 0; j<100; j++)
    {
      int fark = organYedek->different(organYedek->getRoot());
      

      //balik ekrana yazdiriliyor
      if(fark > 1 || fark < -1)
        cout << "#";
      else
        cout << " ";
      organYedek = organYedek->sistemNext;
    }
    yedek = yedek->organizmaNext;
    cout << endl;
   }

   //Mutasyon kismi
    mutasyon = cin.get();
    if(mutasyon == (int)'\n')
    { 
      system("CLS");
      int mutasyonSayisi = 0;
      ikiliAramaAgaci* organYedek = organ->organIlk;
      ikiliAramaAgaci* dokuGez = organYedek;
      int* siraliMutasyon;

      //Ikililer gezilip mutasyona ugrayacaklar seciliyor
      for(int i = 0; i < (sayac+1)*100; i++)
      {
        bool kalan = kontrolEt.bolunuyorMu(organYedek->getRoot());
        
        if(kalan)
        {
          int guncelKonum = i*20;
          ikiliAramaAgaci* mutasyonBst = new ikiliAramaAgaci();
          int sayac = 0;
          //Mutasyona giris
          mutasyonSayisi++;

          kontrolEt.ciftMi(dokuGez->getRoot());

          //mutasyonlu dna uzunluklarini post order olarak icerisine aktaracagimiz dizi olusturma. 
          int mutasyonTutanDizi[dokuGez->getRoot()->hucreSayisi];

          //post order olarak bir diziye alinacak ve ikili guncellenecek
          kontrolEt.mutasyonPostOrder(dokuGez->getRoot(), mutasyonTutanDizi,siraliMutasyon,dokuListe,guncelKonum,mutasyonBst);//gerekli dokularin mutasyonlu halini ekrana yaziyor      
          cout << endl;           
        }
        
        organYedek = organYedek->next;
        dokuGez = organYedek;
      }
    }
      myFile.close();
  }
}