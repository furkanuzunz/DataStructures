#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept> // eception sinifi icin
using namespace std;

class DinamikDizi
{
private:
    int m_boyut;
    int m_kullanilan;
    int *m_adres; // dinamik dizimiz.
public:
    DinamikDizi()
    {
        m_boyut = 5;
        m_adres = new int[m_boyut];
        m_kullanilan = 0;
    }
    ~DinamikDizi()
    {
        // bu dizi yok edildiğinde sinifin heapten aldigi dizinin de yok edilmesi gerekiyor.
        delete[] m_adres;
    }
    int getir(int sira) const
    {
        if(sira < 0 || sira >= m_kullanilan) // out_of_range, exception sınıfından türetilmiş bir sınıftır ve bir string argümanı alabilir
        {
            throw out_of_range("getir sinir problemi");
        }
        return m_adres[sira]; // icerdeki degeri dondurcek.
    }
    int boyut() const
    {
        return m_boyut;
    }
    int kullanilan() const
    {
        return m_kullanilan;
    }
    void sonaEkle(int yeniSayi)
    {
        if(m_kullanilan >= m_boyut)
            genislet(m_boyut); // boyutan byük hale gelirsek artıkbir sey ekleyemeylim.
        // her siniri astigimizda bizim dizimiz kendini ikiye katlicak.
        
        // biz m_adres pointerimin m_kullanilan elemanina gidiyorum ve oraya yeni sayimi ekliyorum.
       m_adres[m_kullanilan] = yeniSayi;   //bizim eleman sayimizi ifade eder aslinda.kac tanesini kullaniyosak onalar bizim elemanimizidri aslinda
        // ayni zamanda diziler sifirdan basladigi icin de m_kullanilan bizim yeni ekleyeceğimzi elemanin indeksini belirtir.
       m_kullanilan++;

    }
    void genislet(int ustuneEklenilecekOlanboyut)
    {
        int *yeniAlan =  new int[m_boyut + ustuneEklenilecekOlanboyut];
        for(int i = 0;i < m_kullanilan;i++)// kullanilan kadarini kopyalayalım
        {
            yeniAlan[i] = m_adres[i];
        }
        delete[] m_adres; // m adresi silmedim.gösterdiği yeri sildim heapte bulunan yeri.
        m_adres = yeniAlan; // yeni adrese işaret ettirdik.

        m_boyut = m_boyut + ustuneEklenilecekOlanboyut; // toplam boyutu güncelledik.
    }

    void arayaEkle(int nereye,int veri) // 2 ye yazcaksak diğerlerini ötelicek.
    {// var olan elemanlarin arasina ekleyebilelim.
        if(nereye >= 0 && nereye <= m_kullanilan) //sona ekleme fonk umuz var zaten
        {
            if(m_kullanilan >= m_boyut)// sinirdayse önce bi genislettik
            {
                genislet(m_boyut);
            }
            for (int i = m_kullanilan;i >= nereye;i--)
            {           
                m_adres[i + 1] = m_adres[i]; //bir sonraki elemana öncekini kopyaladık ve böylelikle kaydi sağa doğru.
            }
            m_adres[nereye] = veri;
            m_kullanilan++;
        }

    }


    friend ostream &operator<<(ostream &os, const DinamikDizi &diziNesne)
    {
        os << "|";
        for (int i = 0; i < diziNesne.boyut(); i++)
            os << setw(3) << i << setw(1) << "|";
        os << endl<< "|";
//üst kısım  çiktidaki ilk satir icin

        for (int i = 0; i < diziNesne.boyut(); i++)
            os << setw(3) << "---" << setw(1) << "|";
        os << endl << "|";
// buras ikinci satiri yaziyo.

///burdan alti ise ucuncu satiri 2 asamada yaziyo
        for (int i = 0; i < diziNesne.kullanilan(); i++)
        {
            os << setw(3) << diziNesne.getir(i) << setw(1) << "|";
        }//dolu olan hücreleri yazar
        for (int i = diziNesne.kullanilan(); i < diziNesne.boyut(); i++)
        {
            os << setw(3) << "bos" << setw(1) << "|";
        }//bos olanlari yazar.
        os << endl << endl;
        return os;
    }
};

int main()
{
    DinamikDizi dizi;
    
    while(true)
    {
        system("cls"); //ekrani temizler.
        cout << dizi; //friend fonksiyonu cagirildi

        cout << "1..sona ekle"<<endl;
        cout << "2..araya ekle"<<endl;
        cout << "3..cikar"<<endl;
        cout << "4..cikis"<< endl;
        int secim;
        cin >> secim;
        if(secim == 1)
        {
            dizi.sonaEkle(rand() % 100);
        }
        else if(secim == 2)
        {
            int nereye;
            cout << "sira:"<<endl;
            cin >> nereye;
            dizi.arayaEkle(nereye,rand() % 100);
        }
        else if(secim == 3)
        {

        }
        else
        {
            break;
        }
            
    }







    // try
    // {
    //     int sayi = dizi.getir(-5);
    // }
    // catch(exception& e) // exceptiron türünden bir exception yakalicaz.ve firlatilan exceptionu kopyasını değil bi referansını aldım.fırlattıgımız exception nesnesinin ta kendisidr.onu referans aldım cunku. 
    // {
    //     cout << e.what() <<endl;
    // }

/*
genisletme mevzusu icin;
 1- yeni alan al
 2- eski alandaki bilgileri yeni alandaki bilgilere kopyala
 3- eski alanı serbest bırak
 4- eski adres işaretçisni yeni alanın başlangıç adresine ata
*/
}
