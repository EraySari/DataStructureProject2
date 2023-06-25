#ifndef Queue_hpp
#define Queue_hpp
#include<iostream>
#include "Hucre.hpp"
using namespace std;

class Queue
{
public:
	Queue();
	~Queue();
	void ekle(int veri);
	void cikar();
  bool bosmu();
	int getir();
	int elemanSayisiGetir();
    friend ostream& operator<<(ostream& os,Queue& kuyruk);
private:
	Hucre* 	ilk;
	Hucre*	son;
	int satirSayac;
};

#endif