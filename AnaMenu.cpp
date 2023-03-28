#include "AnaMenu.h"
#include "YetkiliIslem.h"
#include "MusteriIslem.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "fstream"
#include <string.h>

using namespace std;

AnaMenu::AnaMenu()

{
    //ctor

}

AnaMenu::~AnaMenu()

{

    //dtor
}



void  AnaMenu:: yetkiliKontrol()

{

    system("cls");
    char kullaniciAdi[ 10 ];
    char sifre[ 10 ];

    cout<<"\nYetkili Giris Ekranina Hosgeldiniz\n"<<endl<<endl;
    cout<<"Kullanici Adi: ";
    cin>>kullaniciAdi;
    cout<<"Sifre: ";
    cin>>sifre;

    if (strcmp(kullaniciAdi, "admin") == 0 && strcmp(sifre, "1234") == 0)

    {

        YetkiliIslem y1;
        y1.yetkiliGiris();

    }

    else
    {
        cout<<"Kullanici Adi veya Sifre Yanlis"<<endl;
        cout<<"Ana Menuye Yonlendiriliyorsunuz..."<<endl;
        system("pause");
        menu();
    }
    
        


}

void  AnaMenu:: musteriKontrol()

{

    system("cls");
    char kullaniciAdi[ 10 ];
    char sifre[ 10 ];
     
    cout<<"\nMusteri Giris Ekranina Hosgeldiniz\n"<<endl<<endl;
    cout<<"Musteri Numarasi / TcNo  : ";
    cin>>kullaniciAdi;
    cout<<"Sifre: ";
    cin>>sifre;

    char dosyaAdi[30];
    strcpy(dosyaAdi, kullaniciAdi);
    strcat(dosyaAdi, ".txt");

    ifstream file(dosyaAdi);

    if (! file.is_open())

    {
        cout<<"\nHatali Musteri Numarasi / TcNo"<<endl<<endl;

        
    }

    else
    {

        file.read((char*)&m1, sizeof(MusteriBilgii));   

        if (strcmp(sifre , m1.getsifre()) == 0)

        {
            MusteriIslem mi;
            mi.musteriGiris(m1);
        }

        else
        {
            cout<<"Sifre Yanlis"<<endl;
            cout<<"Ana Menuye Yonlendiriliyorsunuz..."<<endl;
            system("pause");
            menu();
        }
        
        
        
        file.close();
        system("pause");
    }



}
int  AnaMenu:: menu()

{

    system("cls");
    int secim;
    cout<<"\n\tBANKAMATIK SISTEMINE HOSGELDINIZ"<<endl<<endl;
    cout<<"\t[1]. Yetkili Giris"<<endl;
    cout<<"\t[2]. Musteri Giris"<<endl;
    cout<<"\t[0]. Cikis"<<endl;
    cout<<"\n\tSeciminiz: ";
    cin>>secim;

    return secim;



}

void  AnaMenu:: giris()
{

    int secim = menu();

    while (secim !=0)

    {

        case 1:
            yetkiliKontrol();
            break;

        case 2:
            musteriKontrol();
            break;

        case 0:
            exit(0);
            break;

        default:
            cout<<"Hatali Secim"<<endl;
            cout<<"Ana Menuye Yonlendiriliyorsunuz..."<<endl;
            system("pause");
            menu();
            break;
        
    }




}