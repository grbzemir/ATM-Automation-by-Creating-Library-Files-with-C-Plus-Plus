#ifndef YETKILIISLEM_H
#define YETKILIISLEM_H
#include "MusteriBilgi.h"

class YetkiliIslem

{

   public:
    MusteriBilgi m1;
    YetkiliIslem();
    ~YetkiliIslem();

    void musteriEkle();
    void musteriSil();
    void musteriAra();
    void musteriGuncelle();
    int yetkiliMenu();
    void yetkiliGiris();



};

#endif 


