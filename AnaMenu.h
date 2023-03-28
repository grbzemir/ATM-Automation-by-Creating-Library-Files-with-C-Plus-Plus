#ifndef ANAMENU_H
#define ANAMENU_H
#include "MusteriBilgi.h"

class AnaMenu
{

    public:
       AnaMenu();
       ~AnaMenu();

       MusteriBilgi m1;
       void yetkiliKontrol();
         void musteriKontrol();

         int menu();
         void giris();


};


#endif 


