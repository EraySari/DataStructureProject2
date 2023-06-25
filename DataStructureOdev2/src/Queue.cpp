/**
* @file DataStructureOdev2
* @description  LinkedList, BinaryTree yapilarini birlikte kullanarak ekrana verileri kullanarak görsel cikarma
* @course 1-C
* @assignment 2.Ödev
* @date 25.12.2022
* @author Eray Sari eray.sari2@ogr.sakarya.edu.tr
*/

#include "Queue.hpp"
#include <iomanip>
#include<stdexcept>
Queue::Queue()
{
    ilk=son=0;
    satirSayac=0;
}
Queue::~Queue()
{
    while(ilk!=0)
    {
        Hucre*gec= ilk;
        ilk=ilk->sonraki;
        delete gec;
    }
}
bool Queue::bosmu()
{
    if(ilk==0)
        return true;
    return false;
}

void Queue::ekle(int veri)
{
    if(ilk==0)
    {
        ilk=new Hucre(veri);
        son= ilk;

    }
    else
    {
        Hucre*yeni = new Hucre(veri);
        son->sonraki = yeni;
        son = yeni;

    }
    satirSayac++;
}
void Queue::cikar()
{
    if(ilk!=0)
    {
        Hucre*gec = ilk->sonraki;
        delete ilk;
        ilk=gec;
        if(ilk==0)
            son=0;
        satirSayac--;
    }
}
int Queue::getir()
{
    if(ilk!=0)
        return ilk->dnaUzunluk;
    throw std::out_of_range("Kuyruk Bos");
}

int Queue::elemanSayisiGetir()
{
    return satirSayac;
}
ostream& operator<<(ostream& os,Queue& kuyruk)
{
    if(kuyruk.ilk==0)
        os<<"----KUYRUK BOS----";
    Hucre*gec= kuyruk.ilk;
    while(gec!=0)
    {
        os<<setw(5)<<gec->dnaUzunluk;
        gec = gec->sonraki;  
    }

    os<<endl; 
    return os;
}
