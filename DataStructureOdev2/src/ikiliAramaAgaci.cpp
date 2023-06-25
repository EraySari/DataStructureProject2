/**
* @file DataStructureOdev2
* @description  LinkedList, BinaryTree yapilarini birlikte kullanarak ekrana verileri kullanarak görsel cikarma
* @course 1-C
* @assignment 2.Ödev
* @date 25.12.2022
* @author Eray Sari eray.sari2@ogr.sakarya.edu.tr
*/

#include "ikiliAramaAgaci.hpp"
#include<iostream>
using namespace std;

ikiliAramaAgaci::ikiliAramaAgaci()
{
  root = 0;
  next = 0;
  back = 0;
  diziNext = 0;
  diziIlk = 0;
  sistemNext = 0;
};
void ikiliAramaAgaci::insert(Doku* eklenecek)
{
  insert(eklenecek,root);
};

void ikiliAramaAgaci::insert(Doku*eklenecek ,Doku* start)
{
  if(root == NULL)
  {
    root = eklenecek;
  }
  else
  {
      if(start->ortancaDeger >= eklenecek->ortancaDeger)
      {
        if(start->left)
          insert(eklenecek,start->left);
        else
        {
          start->left = eklenecek;
        }
          
      }
      else if(start->ortancaDeger < eklenecek->ortancaDeger)
      {
        if(start->right)
        {
          insert(eklenecek,start->right);
        }
        else
        {
          start->right = eklenecek;
        }
      }
  }
}
int ikiliAramaAgaci::height(Doku* ikiliHeight)
{
  if(ikiliHeight)
  {
    int left = height(ikiliHeight->left);
    int right = height(ikiliHeight->right);
    return max(left,right)+1;
  }
  else
    return 0;
}

int ikiliAramaAgaci::height()
{
  return height(root);
}
void ikiliAramaAgaci::diziyeEkle(ikiliAramaAgaci* organIkili)
{
  if(diziIlk == 0)
  {
    diziIlk = organIkili;
  }
  else
  {
    ikiliAramaAgaci* yedek = diziIlk;
    while (yedek->diziNext != 0)
    {
      yedek = yedek->diziNext;
    }
    yedek->diziNext = organIkili;
  }
}
int ikiliAramaAgaci::different(Doku* ikili)
{
  return height(ikili->left)-height(ikili->right);
}
bool ikiliAramaAgaci::isEmpty()
{
  return root == NULL;
}
Doku* ikiliAramaAgaci::getRoot()
{
  return root;
}
