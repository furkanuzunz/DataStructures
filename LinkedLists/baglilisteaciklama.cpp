/*
bir siniftaki öğrencilerin notlarii düşünelim. her bir notun hafızada farkloı bir noktada bulunmasi
verilere erişimi zorlaştıracaktır.
bunun yerine büyün notlar (ilişkkisi olan verileri) bir dizide tutmak daha pratik olacaktır.

-dzi bütün verilierni hafızada ardışık konumlara yerleştirmektedir
işte veriler arasındaki bağ da bu olmıuş oluyor.a

-diziye eleman eklemek biraz yavas olabilir. eklemek icin hepsini kaydirmak vs gerekir.
-kimi durumlarda ise dizinin genişleme şansı yoktur. bunun icin eski diziyi yeni diziye kopyalayıp öncek verileri serbest birakmaniz vesaire gerekiyor.a

bunun icin yeni bir bakis acisi getiriyoruz. verileri hafızada farklı yerlerde tutmak yerine her bir veriye bir bağ oluşturuyoruz.
yani aslinda her bir elemani istedigim bir noktada olusturabilirsem. kolaylasir
fakat bu elemanlari bu sefer dolasmak zor hale gelecektir. bunun icin bir yola ihtiyacimiz olacaktir.
ben dizideki gibi tek bir isim kullanip bütün hücrelere rişmek istiyorum.
bunu da işte veriler arasında farklı bir bağ oluşturcaz
yeni sistemimizde dizideki gibi bir şey olacaktir. 

---------------------
bagli liste ile bag olusturmak.
sadece veriyi tutarak farklı adreslerdeki elemanlara ulasmak imkansız.
her bir eleman veri tutmanın yanı sıra sonraki elemanın konumunu barındırabilirse sorun çözülecek. 
veriyi ve sonraki verinin adresini de tutucaz.bu yapiya da işte düğüm denir. 

düğüm yapısı:
her düğüm kendi verisini ve sonraki düğümün adresini tutar.
eğer ben ilk düğüm diye düğüm türünde bir iaşretçi tanimlarsam.ve bu ilk düğüm listenin ilk elemanının adresini tutarsa,
ben bunu kullanarak diğer düğümlere de ulaşabilirim.ve böylece tüm listeyi dolaşabilirim.

Dugum d1(10);
Bu kod çalıştığında:

d1 için bellekte yer ayrılır.
Kurucu (Dugum(int veri)) çalıştırılır ve this, d1 nesnesinin adresini tutar.
this->veri = veri; satırı çalışır → d1 nesnesinin veri üyesine 10 atanır.
sonraki = NULL; ile sonraki işaretçisi NULL yapılır.
Kurucu tamamlanır ve d1 nesnesi oluşturulmuş olur.
Özet:
Evet, this aslında d1 nesnesinin adresini tutar.
Kurucu çalışırken, this o anda oluşturulan nesnenin adresini gösterir.
Yani this == &d1 ifadesi kurucu içinde doğrudur!
*/