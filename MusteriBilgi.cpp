#include "MusteriBilgi.h"
#include <string.h>
#include <iostream>
#include <stdio.h>

MusteriBilgi:: MusteriBilgi()

{
	strcpy( tcNo, "");
	strcpy( adSoyad, "");
	strcpy( adres, "");
	strcpy( tel, "");
	strcpy( sifre, "");
	bakiye=0.0; 

}

MusteriBilgi::~MusteriBilgi()

{


}


MusteriBilgi:: MusteriBilgi(char *tcNo , char *adSoyad , char *adres , char * tel , char *sifre , float bakiye )

{

	strcpy( tcNo, tcNo );
	strcpy( adSoyad, adSoyad );
	strcpy( adres, adres );
	strcpy( tel, tel );
	strcpy( sifre, sifre);
	bakiye=bk ; 
	
}
			
void MusteriBilgi:: setTcNo (char *ptr ) 

{

	strcpy( tcNo, ptr); 
	
}

char * MusteriBilgi:: getTcNo ()

{

	return tcNo; 

}
 
void MusteriBilgi:: setAdSoyad(char *ptr )

{

	strcpy( adSoyad, ptr); 	

}

char * MusteriBilgi:: getAdSoyad()

{

	return adSoyad; 

}

void MusteriBilgi:: setAdres(char *ptr )

{

	strcpy( adres, ptr); 		

}

char * MusteriBilgi:: getAdres ()

{

	return adres; 

}

void MusteriBilgi:: setTel (char *ptr )

{

	strcpy( tel , ptr); 

}

char * MusteriBilgi:: getTel ()

{

	return tel; 

}
void MusteriBilgi:: setSifre (char *ptr )

{

	strcpy( sifre , ptr); 

}

char * MusteriBilgi:: getSifre()

{

	return sifre; 

}
 
void MusteriBilgi:: setBakiye ( float bakiye )

{

	bakiye = bakiye; 
}

float  MusteriBilgi:: getBakiye ()

{

	return bakiye; 

}