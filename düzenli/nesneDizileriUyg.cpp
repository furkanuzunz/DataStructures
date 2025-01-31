//8.video

using namespace std;
#include <iostream>
class Sayi
{
public:
    Sayi()
    {
        s1 = rand() % 100;
        s2 = rand() % 100;
        cout << this << "  adresindelki nesne olusturuldu" << endl;
        // bir nesnenin adresini cikartmak sitiyorsanız thisi kullanabilirsiniz
        // bu this bir pointerdir, otomatik olarak, oluşturulan  nesnenin adresin götüyüro.
        // bu this sadece sınıfın icinde aktiftir .
    }
    ~Sayi()
    {
        cout << this << "adresindeki nesne yok edildi" << endl;
    }
    void yazdir()
    {
        cout << "s1,s2: " << s1 << "," << s2 << endl;
    }

private:
    int s1;
    int s2;
};

int main()
{
    // // Sayi *p = new Sayi;
    // /*
    // main fonksiyonunda Sayi *p = new Sayi; satırı ile oluşturulan nesne, p işaretçisi (pointer) tarafından işaret edilen bir nesnedir.
    // Yani p, heap'te (dinamik bellek bölgesi) oluşturulan Sayi sınıfının bir nesnesini gösterir.
    // */
    // /*
    //  new Sayi, heap'te (dinamik bellek bölgesi) Sayi sınıfından bir nesne oluşturur.

    //  Bu nesne, Sayi sınıfının varsayılan kurucusunu (constructor) çağırır.

    // Oluşturulan nesnenin adresi, p işaretçisine atanır.

    // kurucudaki this işaretçisi de olusturulan nesnenin adresini gösterir
    // */

//    // delete p; // simdi yikicida calisir iste. yikici bir nesnenin ömrü sonra erdiğinde otomatik olarka cağirilir.

//     Sayi *p = new Sayi[10]; 
//     /*
//         Bu dizi, Sayi sınıfından (class) oluşturulan 10 nesneyi içerir. Her bir dizi elemanı, 
//         Sayi sınıfının bir nesnesidir ve Sayi sınıfının varsayılan kurucusu (default constructor) ile başlatılır.
//     */

//    for(int i =0;i < 10;i++)
//    {

//     (p + i)->yazdir(); // ya da *(p + i).yazdir(); seklinde de cagirabilirim..
//     // ya da p[i].yazdir(); 
//    }
//    delete[] p;

// Sayi *p[10];
// // şuan 10 tane işaretçiye işaret eden bir dizim var.dizim nesne türünden.
// /*Sayi *p[10]; ifadesi, 10 elemanlı bir işaretçi dizisi oluşturur. Bu dizinin her bir elemanı, 
// Sayi sınıfı türünden bir işaretçidir (pointer). Yani bu dizi, Sayi sınıfından nesnelere işaret eden 10 adet işaretçi içerir. 
// Ancak bu işaretçiler henüz hiçbir nesneyi işaret etmezler; sadece bellekte yer ayrılmıştır.*/

// //p işaretçi dizisinin sıfırıncı elemani zaten bir işaretçi.ben buna bir nesne adresi döndürücem.
// p[0] = new Sayi; // nesnenin adresin bir işaretçiye atadim.
// /*new Sayi, heap'te (dinamik bellek bölgesi) Sayi sınıfından bir nesne oluşturur.

// Bu nesne, Sayi sınıfının varsayılan kurucusu (default constructor) ile başlatılır.

// Oluşturulan nesnenin adresi, p[0] işaretçisine atanır.
// Sayi sınıfının kurucusu, s1 ve s2 değişkenlerine rastgele değerler atar 
// ve nesnenin adresini ekrana yazdırır.
// */
// cout << "-------------\n";
// p[1] = new Sayi[10];
// // suan p[1] işaretçisi 10 elemanli bir nesne dizisinin başlangic adresine işaret eder.
// // bu islem 10 tane nesne olusacaagi icin her seferinde kurucu cagirilir.

// p[0]->yazdir(); // p[0] işaretçisinin işaret ettiği nesnenin üyelerine eriştik.

// p[1]->yazdir(); // ya da p[1][1].yazdir();
// p[1][1].yazdir(); // 1. işaretçi olan elemanin işaret ettigi nesnenin üyesine eriştik.

// // bu son sayesinde birden fazla diziye tek bir eleman üzerinden erişebiliyorun.

// //silerken dikkat etmeliyiz.

// delete p[0];
// cout <<"-------------"<<endl;
// delete[] p[1];

// // Sayi *p[10];
//  // bu sekilde aslında stackte olustu.
//  // pek dinamik olarak bunu nasıl olustururuz ?? heapte yani

 Sayi **p = new Sayi*[10]; 
// heapte bir 10 elemanlı işaretçi dizisi oluşturduk.Her biri işaretçi yani.
// bu 10 elemanlı işaretçi dizisinin başlangıç adresini bir double pointera atadık.
// double pointera atamlaıyız cunku, adresini verdigimiz dizi de bir işaretçi dizi o yüzden.



//  Sayi* türünden bir işaretçidir ifadesi, Sayi sınıfından bir nesneyi işaret eden bir işaretçi olduğunu belirtir. 
//  Bu, işaretçinin ne tür bir veriyi işaret ettiğini açıklar.
 

 // buradaki Sayi **p, Sayi* türünden bir işaretçiyi işaret eden bir işaretçidir.
// new Sayi*[10] , heapte Sayi* türünden 10 elemanli bir dizi oluşturur.
// Sayi* türünden derken aslinda her bir işaretçi Sayi sinifindan bir nesneyi işaret edebilir.

// 102.satirdaki ifade yazildiğinda herhangi bir nesne olusmadı dikkat edin.
/*
Sayi **p = new Sayi*[10]; ve Sayi *p[10]; ifadelerinde nesne oluşmamasının nedeni,
 bu ifadelerin nesne oluşturmak için değil, işaretçi oluşturmak için kullanılmasıdır.
*/


// şuan p, 10 elemanli bir dizinin başlangıç adresini tutar. yani mesela
// p[0] bir işaretçidir.ve adres tutar.
p[0] = new Sayi;
cout<<"----------------"<<endl;
/*new Sayi, heap'te bir Sayi nesnesi oluşturur ve bu nesnenin adresini p[0] işaretçisine atar.
Bu işlem,
 Sayi sınıfının varsayılan kurucusunu (default constructor) çağırır.*/
p[1] = new Sayi[10]; // p[1] işaretçisi de 10 elemanli bir nesne dizisine işaret etti.
/*p[1] = new Sayi[10]; Ne Yapar?
new Sayi[10], heap'te (dinamik bellek bölgesi) Sayi sınıfından 10 elemanlı bir nesne dizisi oluşturur.

Bu dizinin başlangıç adresi, p[1] işaretçisine atanır.

Her bir dizi elemanı, 
Sayi sınıfının varsayılan kurucusu (default constructor) ile başlatılır.*/






// peki simdi nasil bir serbest birakma yapacağim. az önce heapte işaretçi dizisi de oluşturmamiştik.
// Sayi *p[10] ifadesinden bahsediyorum. orada normal stackte olustu işaretçiler.
// sonra biz nesneleri heapte olusturduk onların adresleirni işaretçilere atadik.
// sonrada o alanlari saldik.
cout << "-------------"<<endl;
//şimdi ise 3 tane serbest bırakmamız lazım.
delete p[0];
cout <<"--------------"<<endl;
delete[] p[1];
cout <<"------------------"<<endl;
delete p;


}