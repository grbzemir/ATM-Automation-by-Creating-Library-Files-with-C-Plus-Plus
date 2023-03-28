#include "MusteriIslem.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>


#include <fstream>

using namespace std;

MusteriIslem:: MusteriIslem()
{
	
}
MusteriIslem:: MusteriIslem( MusteriBilgi mPtr )

{

	m1= mPtr; 
}


MusteriIslem::~MusteriIslem()

{

   
}

void  MusteriIslem:: paraCek() 

{

    system("cls");
    cout<<"\nPARA CEKME EKRANI"<<endl<<endl;
    cout<<"Bakiyeniz: "<<m1.getBakiye()<<endl;
    cout<<"Cekmek istediginiz tutar: ";
    cin>>tutar;

    if (sayi > m1.getBakiye())

    {

        cout<<"Yetersiz Bakiye"<<endl;
        
    }

    else

    {
        m1.setBakiye(m1.getBakiye() - sayi);

        char dosyaAdi[ 20 ];
        strcpy(dosyaAdi, m1.getTcNo());
        strcat(dosyaAdi, ".txt");

        ofstream file(dosyaAdi) ; 
        file.write((char*)&m1, sizeof(MusteriBilgi));
        file.close();
        cout<<"Para Cekme Islemi Basarili"<<endl;

        char msj[  ] "Para Cekildi";
        HareketKaydet(m1.getTcNo(), msj);


    }

    system("pause");

 
}



void MusteriIslem::  paraYatir()

{

    system("cls");
    float sayi;
    cout<<"\nPARA YATIRMA EKRANI"<<endl<<endl;
    cout<<"Bakiyeniz: "<<m1.getBakiye()<<endl;
    cout<<"Yatirmak istediginiz tutar: ";
    cin>>sayi;

    m1.setBakiye(m1.getBakiye() + sayi);

    char dosyaAdi[ 20 ];
    strcpy(dosyaAdi, m1.getTcNo());
    strcat(dosyaAdi, ".txt");

    ofstream file(dosyaAdi) ;
    file.write((char*)&m1, sizeof(MusteriBilgi));
    file.close();

    cout<<"Para Yatirma Islemi Basarili"<<endl;

    char msj[  ] "Para Yatirildi";
    HareketKaydet(m1.getTcNo(), msj);
    system("pause");

     
}


void  MusteriIslem:: bakiye()

{

    system("cls");
    cout<<"\nBAKIYE EKRANI"<<endl<<endl;
    cout<<"Bakiyeniz: "<<m1.getBakiye()<<endl;

    char msj[  ] "Bakiye Goruntulendi";
    HareketKaydet(m1.getTcNo(), msj);
    system("pause");


}




void MusteriIslem:: havale()

{

  system("cls");
  float sayi;
  char aliciNo[ 11 ];
  cout<<"\nHAVALE EKRANI"<<endl<<endl;
    cout<<"Bakiyeniz: "<<m1.getBakiye()<<endl;
    cout<<"Havale yapmak istediginiz tutar: ";
    cin>>sayi;

    if ( sayi > m1.getBakiye())

    {
       
       cout<<"Yetersiz Bakiye"<<endl;
 
    }

    else
    {
        
        cout<<"Havale yapmak istediginiz hesap numarasi: ";
        cin>>aliciNo;

        char dosyaAdi[ 20 ];
        strcpy(dosyaAdi, aliciNo);
        strcat(dosyaAdi, ".txt");

        ifstream file(dosyaAdi) ;
        MusteriBilgi m2;
        file.read((char*)&m2, sizeof(MusteriBilgi));

        if( !file.is_open())

        {

            cout<<"Hesap Bulunamadi"<<endl;

        }

        else
        {
            
            m2.setBakiye(m2.getBakiye() + sayi);
            m1.setBakiye(m1.getBakiye() - sayi);

            file.close();

            ofstream file2(dosyaAdi) ;

            file2.write((char*)&m2, sizeof(MusteriBilgi));
            file2.close();

            strcpy(dosyaAdi, m1.getTcNo());
            strcat(dosyaAdi, ".txt");   

            ofstream file(dosyaAdi) ;

            file.write((char*)&m1, sizeof(MusteriBilgi));
            file.close();

            cout<<"Havale Islemi Basarili"<<endl;

            char msj[  ] "Havale Yapildi";
            char msj2[  ] "Havale Geldi";
            HareketKaydet(m1.getTcNo(), msj);
            HareketKaydet(aliciNo, msj2);



        }

        file.close();
        
    }

    system("pause");

 
}



void  MusteriIslem:: HareketKaydet ( char *tcNo,  char * msj   )

{

    char dosyaAdi[ 20 ];
    strcpy(dosyaAdi, tcNo);
    strcat(dosyaAdi, ".txt");

    ofstream file(dosyaAdi, ios::app) ;
    file<<msj<<endl;
    file.close();
    

}


void MusteriIslem:: hesapHareketleri()

{

    system("cls");
    char dosyaAdi[ 20 ];
    strcpy(dosyaAdi, m1.getTcNo());
    strcat(dosyaAdi, "rapor.txt");

    ifstream file(dosyaAdi) ;

    char harf;

    while( file.getf(harf))

    {

        cout<<harf;
    }

    file.close();

    cout<<endl<<endl;

    system("pause");

 
}




void MusteriIslem:: sifreDegistir()


{
	char eSifre [20], ySifre[20];
	
	 
	system("cls") ; 
	cout<<"\nSifre Degistirme Islemleri... "<< endl<< endl; 
	cout<<"Eski Sifre : "; scanf(" %[^\n]s", eSifre ); 
	cout<<"Yeni Sifre : "; scanf(" %[^\n]s", ySifre ); 
	
	
	char dosyaAdi[30]; 

	strcpy(dosyaAdi, m1.getTcNo() ) ; 
	strcat(dosyaAdi, ".txt") ; 

	ifstream file(dosyaAdi) ; 

	if(  file.is_open() )

	{
		

		file.read ((char*)&m1, sizeof(MusteriBilgi ) ) ; 
		if(  strcmp( m1.getSifre() , eSifre   ) != 0 ) 

        {
		cout<<"Eski sifreyi hatali girdiniz !!! "<< endl; 

        }

		else 

		{
			file.close();
			ofstream file(dosyaAdi) ;
			m1.setSifre(ySifre) ; 
			file.write ((char*)&m1, sizeof(MusteriBilgi ) ) ; 
			cout<<"Sifre degistirildi "<< endl<< endl ;
			char msj[]="Sifre degistirildi "; 
			HareketKaydet(m1.getTcNo(), msj ) ;  

		}   

	} 

	file.close(); 

	system("pause"); 

	
}  
  



int  MusteriIslem:: musteriMenu()

{

    system("cls");
    int secim;
    cout<<"\n\nHosgeldiniz Sayin "<<m1.getAd()<<" "<<m1.getSoyad()<<endl<<endl;
    cout<<"Musteri No: "<<m1.getTcNo()<<endl;
    
    cout<<"[1]-Para Cek"<<endl;
    cout<<"[2]-Para Yatirma"<<endl; 
    cout<<"[3]-Bakiye Goruntule"<<endl;
    cout<<"[4]-Havale"<<endl;
    cout<<"[5]-Hesap Hareketleri"<<endl;
    cout<<"[6]-Sifre Degistir"<<endl;
    cout<<"[0]-Cikis"<<endl;
    cout<<"Seciminiz: ";
    cin>>secim;

    return secim;
     
}


void MusteriIslem ::  musteriGiris( MusteriBilgi mb  )

{

    m1= mb;

    int secim = musteriMenu();

    while (secim !=0)
    {

        switch (secim)
        {

        case 1:
            paraCek();
            break;

        case 2:
            paraYatir();
            break;

        case 3:
            bakiye();
            break;

        case 4:
            havale();
            break;

        case 5:
            hesapHareketleri();
            break;

        case 6:
            sifreDegistir();
            break;

        case 0;
            break;

        default:
            cout<<"Hatali secim"<<endl;
            break;
        }
        
        secim = musteriMenu();
    }



}