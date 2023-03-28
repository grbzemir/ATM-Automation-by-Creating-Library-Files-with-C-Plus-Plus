#ifndef MUSTERIBILGI_H
#define MUSTERIBILGI_H


class MusteriBilgi

{

    private:
    char tcNo[11];
    char adSoyad[20];
    char adres[50];
    char tel[11];
    char sifre[10];

    float bakiye;

    public:
        MusteriBilgi();
        ~MusteriBilgi();

        MusteriBilgi(char *tcNo, char *adSoyad, char *adres, char *tel, char *sifre , float bakiye);

        void setTcNo(char *ptr);
        char getTcNo();
        
        void setAdSoyad(char *ptr);
        char getAdSoyad();

        void setAdres(char *ptr);
        char getAdres();

        void setTel(char *ptr);
        char getTel();

        void setSifre(char *ptr);
        char getSifre();

        void setBakiye(float  bakiye);
        float getBakiye();








};

#endif 



