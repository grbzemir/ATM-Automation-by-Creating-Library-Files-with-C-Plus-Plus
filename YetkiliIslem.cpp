#include "YetkiliIslem.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <fstream>


using namespace std; 



 YetkiliIslem:: YetkiliIslem()

{

}

YetkiliIslem::~YetkiliIslem()

{


}


void  YetkiliIslem:: musteriEkle()

{
	char kelime[30]; 

	float sayi; 

	system("cls") ; 

	cout<<"\nMusteri Ekleme Islemleri... "<< endl<< endl; 
	cout<<"Musteri TcNo : "; 
    cin>>kelime;
    m1.setTcNo(kelime);

    cout<<"Ad/Soyad     : ";
    cin>>kelime;
    m1.setAdSoyad(kelime);

    cout<<"Adres        : ";
    cin>>kelime;
    m1.setAdres(kelime);

    cout<<"Telefon      : ";
    cin>>kelime;
    m1.setTel(kelime);

    m1.setSifre(m1.getTcNo());

    cout<<"Bakiye       : ";
    cin>>sayi;
    m1.setBakiye(sayi);

	
	char dosyaAdi[30]; 

	strcpy(dosyaAdi, m1.getTcNo()) ; 
	strcat(dosyaAdi, ".txt") ; 

	ofstream file(dosyaAdi) ; 

	file.write((char*)&m1, sizeof(MusteriBilgi ) ) ; 
	file.close(); 

	cout<<"Yeni Musteri Kaydi Tamam "<< endl; 

	system("pause"); 
	
	
}

void  YetkiliIslem:: musteriSil()
{
	char kelime[30]; 
	float sayi; 

	system("cls") ; 

	cout<<"\nMusteri Silme Islemleri... "<< endl<< endl; 
	cout<<"Musteri TcNo : ";
    cin>>kelime; 
	
	
	char dosyaAdi[30]; 

	strcpy(dosyaAdi, kelime ) ; 
	strcat(dosyaAdi, ".txt") ; 
	ifstream file(dosyaAdi) ; 


	if( ! file.is_open() )
		cout<<kelime<< " numarali musteri kaydi bulunamadi !!! "<< endl; 

	else 

	{
		char tercih; 
		file.read ((char*)&m1, sizeof(MusteriBilgi ) ) ; 
		cout<<"Ad/Soyad     : "<< m1.getAdSoyad( ) << endl ;
		cout<<"Adres        : "<< m1.getAdres( ) << endl ;
		cout<<"Telefon      : "<< m1.getTel( ) << endl ;
		cout<<"Bakiye       : "<<  m1.getBakiye( ) << " TL" << endl ; 
		cout<<endl; 
		
		cout<<"Musteri kaydini silmek istediginize emin misiniz ? [E/H] : "; 
        cin>>tercih; 

		if( tercih =='e' || tercih == 'E') 

		{

			file.close(); 
			remove(dosyaAdi) ; 
			cout<<"Musteri Kaydi Silindi "<< endl; 

		}

		else

		{

			cout<<"Silme islemi iptal edildi "<< endl; 
		}

	} 

	file.close(); 

	system("pause"); 
	
	
} 
void  YetkiliIslem:: musteriAra()
{
	char kelime[30]; 
	float sayi; 
	system("cls") ; 
	cout<<"\nMusteri Arama Islemleri... "<< endl<< endl; 
	cout<<"Musteri TcNo : ";
    cin>>kelime;
	
	
	char dosyaAdi[30]; 

	strcpy(dosyaAdi, kelime ) ; 
	strcat(dosyaAdi, ".txt") ; 
	ifstream file(dosyaAdi) ; 

	if( ! file.is_open() )

		cout<<kelime<< " numarali musteri kaydi bulunamadi !!! "<< endl; 

	else 

	{

		file.read ((char*)&m1, sizeof(MusteriBilgi ) ) ; 
		cout<<"Ad/Soyad     : "<< m1.getAdSoyad( ) << endl ;
		cout<<"Adres        : "<< m1.getAdres( ) << endl ;
		cout<<"Telefon      : "<< m1.getTel( ) << endl ;
		cout<<"Bakiye       : "<<  m1.getBakiye( ) << " TL" << endl ; 
		cout<<endl; 

	} 

	file.close(); 

	system("pause"); 

}

void  YetkiliIslem:: musteriGuncelle()
{
	char kelime[30]; 
	float sayi; 
	system("cls") ; 
	cout<<"\nMusteri Guncelleme Islemleri... "<< endl<< endl; 
	cout<<"Musteri TcNo : "; 
    cin>>kelime; 
	
	
	char dosyaAdi[30]; 
	strcpy(dosyaAdi, kelime ) ; 
	strcat(dosyaAdi, ".txt") ; 
	ifstream file(dosyaAdi) ; 
	if( ! file.is_open() )

		cout<<kelime<< " numarali musteri kaydi bulunamadi !!! "<< endl; 

	else 

	{
		file.read ((char*)&m1, sizeof(MusteriBilgi ) ) ; 
		cout<<"Ad/Soyad     : "<< m1.getAdSoyad( ) << endl ;
		cout<<"Adres        : "<< m1.getAdres( ) << endl ;
		cout<<"Telefon      : "<< m1.getTel( ) << endl ;
		cout<<"Bakiye       : "<<  m1.getBakiye( ) << " TL" << endl ; 
		cout<<endl; 
		cout<<endl; 
		file.close();
		
		
		cout<<"Adres        : "; 
        cin>>kelime;

		cout<<"Telefon      : "; 
        cin>>kelime;
		
		ofstream file(dosyaAdi) ; 
		file.write((char*)&m1, sizeof(MusteriBilgi ) ) ; 
		file.close(); 
		cout<<"Musteri bilgileri guncellendi "<< endl; 
		
	} 

	file.close(); 

	system("pause"); 
	
	
}

int  YetkiliIslem:: yetkiliMenu()
{
	system("cls") ; 

	int secim; 
	cout<<"\n\nHosgeldiniz sayin Admin... "<< endl<<endl; 
	cout<<"[1]- Musteri Ekle "<< endl; 
	cout<<"[2]- Musteri Sil "<< endl; 
	cout<<"[3]- Musteri Ara "<< endl; 
	cout<<"[4]- Musteri Guncelle "<< endl; 
	cout<<"[0]- CIKIS YAP  "<< endl; 
	cout<<"Seciminiz    :  "; cin>>secim;  
	return secim; 
	
} 
void  YetkiliIslem:: yetkiliGiris ()

{
	int secim= yetkiliMenu() ; 

	while( secim != 0 )

	{
		switch (secim )

		{
			case 1: 
            musteriEkle (); 
            break; 

			case 2:
             musteriSil (); 
             break; 

			case 3: 
            musteriAra ();
             break; 

			case 4: 
            musteriGuncelle (); 
            break; 

			case 0:  
            break;
			default : cout<<"Hatali secim yaptiniz !!! "<< endl;  
			
		}

		secim = yetkiliMenu();
	}
	
} 


