#include "Bagliliste.hpp"
#include <iostream>
#include <iomanip>

BagliListe::BagliListe()
{
    ilk = 0;
}

BagliListe::~BagliListe()
{
    Dugum *gecici = ilk;
    while(gecici != 0)
    {//butun dugumleri tek tek gezeceğiz.
        //eğer silme işlemini gecici üzerine uygularsak bir sonraki dugume gidemeyiz.
        //cunku gosterdiği dugumu silmiş olurum.

        Dugum *silinecek = gecici;
        //bir sonraki dugume gecmeden once siradaki dugumun adresi silinecek işaretçisine yedeklenir

        gecici = gecici -> sonraki;
        //sıradaki dugume gecis yapildiktan sonra önceki dugum serbest bırakılır
        delete silinecek;
        // ve silindi
    }
}


void BagliListe::ekle(int veri)
{
    Dugum *yeni = new Dugum(veri);
    // ilk olarak yeni dugum nesnesi oluşturuluyor.
    // dugumun adresini yeni denilen işaretçiye yerleştirdik
    if (ilk == 0)
    {
        ilk yeni;
        return;
    }
    // hicbir düğümün olmadıgı durumda da yeni dugum ilk dugum olacaktır ve fonksiyon sonlanacaktır.
    // herhangi bir eleman yoksa,eleman gezmemiz hatali olur

    Dugum *gecici = ilk;
    // gecici işaretçsini, son düğüme ulasabilmek için oluşturduk.İşaretçi , ilk dugumun adresini tutuyor.
    while (gecici->sonraki != 0)
    {
        gecici = gecici->sonraki;
    }
    // döngü içerisinde son düğümün adresini alana kadar,gecici işaretçisinin degeri değişmektedir.
    // dongu bittiğinde gecici pointeri son düğümü göstericek ve biz de son düğümü sonraki elemanına atıcaz.
    // son dugumu yeni dugume baglayacagiz.
    gecici->sonraki = yeni; // artık sonraki son dugume kadar geldi,yeni dugumunu de ekledik iste ardından.
}

void BagliListe::yazdir()
{
    Dugum *gecici = ilk;//bunun avantahji döngü vs bittiğinde ilk işaretçisi,hala ilk dugumun adresini tutuyor.
    // ayrıca da gecici işaretçisi ile en sondaki dugumun adresini tutuyoruz.
    cout<<"---------------------------------"<<endl;
    cout<<setw(10)<<"Adres:"<<setw(10)<<"Veri:"<<setw(15)<<"Sonraki:"<<endl;
    cout<<"---------------------------------"<<endl;

    while (gecici != 0)
    {//dongunun her turunda gecici işaretçisi sıradaki düğümü gösterecektir.
        //fakat geçici işaretçisi son düğümü gösterdiğinde döngü içerisine girilmeyecektir.
        //bu yuzden dongu bittikten sonra son dugum icin ekran çıktısı vermemiz lazim.
        // ama bunu gecici->sonraki != 0 olan kosulu gecici != 0 yaparak degistirebilirim
       //yani gecici işaretçisi gecici->sonrakine eşitleniyor ya. bu koşulda içeri giriyor gene gecici = gecici->sonraki sağ taraf sıfır olunca gecici de sıfır oluyor.donguya girmiyor gene.ama 
       //zaten biz gecici->sonraki ni son dugume ulastirip yazdirabildik.
        cout << setw(10)<<gecici<<setw(10)<<gecici->veri<<setw(15)<<gecici->sonraki<<endl;
        cout << "------------------------------"<<endl;
        gecici = gecici->sonraki;
    }
}

void BagliListe::cikar()
{
    if(ilk == 0)
        return 
    
    if(ilk->sonraki == 0)
    {
        // ilk->sonraki = 0 ise zaten bir tek ilk vardır onu sileriz.
        delete ilk;
        ilk =0 0;
    }

    else
    {
        Dugum *gecici = ilk;
        while(gecici->sonraki != 0)
        {
            gecici = gecici->sonraki;
        }
        delete gecici->sonraki;//son dugume ulastik ve sildik.
        gecici->sonraki = 0; // son dugumu bosalttik.

    }
    
    
}