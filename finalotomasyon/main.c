

#include <stdio.h>
#include <stdlib.h>
#define pi 3
#define isik_yili 9.46 * 10000000

typedef struct ATMOSFER_GAZI{
    char en_yogun_gaz[15];
    int gaz_sayisi;
}atmosfer;

typedef struct gezegen_ozellik{
    int id;
    int uydu_sayisi;
    char ad[50];
    atmosfer *gazlar;

}ozellik;

ozellik *gokpt;
int count=0;

int gokcismiekle()
{
    int i,adet ;
    printf("********GOK CISMI EKLEME********\n");
    printf("Kac adet gok cismi girisi yapilacak:");
    scanf("%d",&adet);
    gokpt=(ozellik *)malloc(adet*sizeof(ozellik));
    for(i=0;i<adet;i++)
    {
        count++;
        printf("Id giriniz:");
        scanf("%d",&(gokpt+i)->id);
        printf("Gok cisminin adini giriniz:");
        scanf("%s",&(gokpt+i)->ad);
        printf("Uydu sayisini giriniz:");
        scanf("%d",&(gokpt+i)->uydu_sayisi);


        (gokpt+i)->gazlar = (atmosfer*) malloc (2* sizeof (atmosfer));

        printf("Gok cismindeki en yogun gazi giriniz:");
        scanf("%s",&(gokpt+i)->gazlar->en_yogun_gaz);
        printf("Gok cisminin atmosferindeki gaz sayisini giriniz:");
        scanf("%d",&(gokpt+i)->gazlar->gaz_sayisi);

    }
     printf("\nYENI GOK CISMI EKLENDI\n");
     getch();
     system("cls");
}
int gokcismilistele()
{
    system("cls");
    printf("\n------- GOK CISIMLERI -------\n");
    printf("-------------------------------\n");
    int i;
    for(i=0; i<count; i++){
        if((gokpt+i)->id == -1){
            continue;
        }
        printf("ID: %d\n",(gokpt+i)->id);
        printf("Gok Cismi Adi: %s\n",(gokpt+i)->ad);
        printf("Uydu Sayisi: %d\n",(gokpt+i)->uydu_sayisi);
        printf("En Yogun Gazi: %s\n",(gokpt+i)->gazlar->en_yogun_gaz);
        printf("Gaz Sayisi: %d\n",(gokpt+i)->gazlar->gaz_sayisi);
        printf("------------------------------\n");
    }
    getch();
}
int gokcismisil()
{
    system("cls");
    int i,gokid,kontrol = 0;
    printf("-----------GOK CISMI SILME-------------\n");
    printf("Silmek istediginiz gok cisminin id'sini giriniz:");
    scanf("%d",&gokid);
    for(i=0; i<count; i++){
        if((gokpt+i)->id == gokid){
            (gokpt+i)->id = -1;
            printf("Basariyla silindi..\n");
            kontrol = 1;
        }
    }
    if(kontrol == 0){
        printf("Girilen id'de gok cismi bulunamadi!!\n\n");
        getch();
    }
}
int gokcismiguncelle()
{
    system("cls");
    int i,gokid,kontrol = 0;
    printf("\n-----------GOK CISMI GUNCELLEME-------------\n");
    printf("Guncellemek istediginiz gok cisminin id'sini giriniz:");
    scanf("%d",&gokid);
    for(i=0; i<count; i++){
        if((gokpt+i)->id == gokid){
            printf("Gok cisminin yeni adini giriniz:");
            scanf("%s",&(gokpt+i)->ad);
            printf("Yeni uydu sayisini giriniz:");
            scanf("%d",&(gokpt+i)->uydu_sayisi);
            printf("Gok cismindeki yeni yogun gazi giriniz:");
            scanf("%s",&(gokpt+i)->gazlar->en_yogun_gaz);
            printf("Gok cisminin atmosferindeki yeni gaz sayisini giriniz:");
            scanf("%d",&(gokpt+i)->gazlar->gaz_sayisi);
            printf("Basariyla guncellendi..\n");
            kontrol = 1;
        }
    }
    if(kontrol == 0){
        printf("Girilen id'de gok cismi bulunamadi!!\n\n");
        getch();
    }
}

int yas_hesapla()
{
    system("cls");
    int i,gokid,kontrol = 0;
    int yas;
    printf("-----------GOK CISMI YAS HESAPLAMA-------------\n");
    printf("Yasini hesaplamak istediginiz gok cisminin id'sini giriniz:");
    scanf("%d",&gokid);
    for(i=0; i<count; i++){
        if((gokpt+i)->id == gokid){
            yas = ((gokpt+i)->uydu_sayisi) * ((gokpt+i)->gazlar->gaz_sayisi) * pi;
            printf("\n%d Numarali Gok Cismin Yasi: %d\n",((gokpt+i)->id), yas);
            getch();
            kontrol = 1;
        }
    }
    if(kontrol == 0){
        printf("Girilen id'de gok cismi bulunamadi!!\n\n");
        getch();
    }
}
int uzaklik_hesapla()
{
    system("cls");
    int i,gokid,kontrol = 0;
    float uzaklik;
    printf("-----------GOK CISMI UZAKLIK HESAPLAMA-------------\n");
    printf("Uzakligini hesaplamak istediginiz gok cisminin id'sini giriniz:");
    scanf("%d",&gokid);
    for(i=0; i<count; i++){
        if((gokpt+i)->id == gokid){
            uzaklik = ((gokpt+i)->uydu_sayisi) * ((gokpt+i)->gazlar->gaz_sayisi) * isik_yili * pi;
            printf("\n%d Numarali Gok Cismin Dunyaya Uzakligi: %.5f\n",((gokpt+i)->id), uzaklik);
            getch();
            kontrol = 1;
        }
    }
    if(kontrol == 0){
        printf("Girilen id'de gok cismi bulunamadi!!\n\n");
        getch();
    }
}
int tur_belirle()
{
    system("cls");
    int yorunge, kutle, dolasma;
    printf("Gunesin etrafinda bir yorungede mi?(Evet - 1 , Hayir - 0): ");
    scanf("%d", &yorunge);
    printf("Kuresel bir kutleye sahip mi?(Evet - 1 , Hayir - 0): ");
    scanf("%d", &kutle);
    printf("Gunesin etrafindaki donusunu tamamlamis mi?(Evet - 1 , Hayir - 0): ");
    scanf("%d", &dolasma);

    if(yorunge && kutle && dolasma){
        printf("\nBu bir gezegendir.\n");
        getch();
    }
    else{
        printf("\nBu bir gezegen degildir, gok cismidir.\n");
        getch();
    }
}
int main()
{
    int secim;
    while(1==1)
    {
        printf("****************GOK CISMI OTOMASYONU******************\n");
        printf("1-Yeni Gok Cismi Ekleme\n"
           "2-Gok Cismi Silme\n"
           "3-Gok Cismi Guncelleme\n"
           "4-Gok Cismi Listele\n"
           "5-Gok Cismi Yasini Hesaplama\n"
           "6-Gok Cisminin Dunyaya Olan Uzakligini Hesaplama\n"
           "7-Gok Cisminin turunu belirleme\n"
           "8-Programdan Cik\n"
           "Seciminiz: ");
        scanf("%d",&secim);
        switch (secim)
        {
        case 1:
            gokcismiekle();
            break;
        case 2:
            gokcismisil();
            break;
        case 3:
            gokcismiguncelle();
            break;
        case 4:
            gokcismilistele();
            break;
        case 5:
            yas_hesapla();
            break;
        case 6:
            uzaklik_hesapla();
            break;
        case 7:
            tur_belirle();
            break;
        case 8:
            return 0;
        default:
            system("cls");
            printf("\nYanlis secim yaptiniz..\n");
            getch();
            break;
        }
    }
}

