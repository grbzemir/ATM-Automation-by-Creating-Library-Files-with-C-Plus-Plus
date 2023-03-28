#ifndef MUSTERIISLEM_H
#define MUSTERIISLEM_H
#include "MusteriBilgi.h"
#include <string>

class MusteriIslem

{

   private:
    MusteriBilgi m1;

    public:
     MusteriIslem();
        ~MusteriIslem();

        MusteriIslem( MusteriBilgi );
        
        void paraCek();
        void paraYatir();
        void bakiye();
        void havale();
        void HareketKaydet( char * , char * );
        void hesapHareketleri();
        void sifreDegistir();
        int musteriMenu();
        void musteriGiris( MusteriBilgi );
    




};




#endif


