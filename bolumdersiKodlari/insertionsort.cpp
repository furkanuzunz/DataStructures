#include <iostream>
#include <stdio.h>

int main()
{
    int A[6] = {2,1,7,5,3,9};
    int anahtar;
    int len = 6;
    int bosluk;

    // Başlangıç dizisini yazdır
    std::cout << "Baslangic dizisi: ";
    for(int i = 0; i < len; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << "\n\n";

    for(int i = 1; i < len; i++) {
        std::cout << "-------- " << i << ". ADIM --------\n";
        
        anahtar = A[i];
        std::cout << "Siranin neresine yerlestirilecek sayi (anahtar): " << anahtar << "\n";
        
        bosluk = i - 1;
        std::cout << "Karsilastirmaya baslanan pozisyon: " << bosluk << "\n";

        while(bosluk >= 0 && A[bosluk] > anahtar) {
            std::cout << A[bosluk] << " > " << anahtar << " oldugu icin " << A[bosluk] << " sayisi saga kaydirildi\n";
            A[bosluk + 1] = A[bosluk];
            bosluk = bosluk - 1;
        }
        
        A[bosluk + 1] = anahtar;
        
        std::cout << "Dizinin su anki hali: ";
        for(int j = 0; j < len; j++) {
            std::cout << A[j] << " ";
        }
        std::cout << "\n\n";
    }

    std::cout << "Son hali: ";
    for(int i = 0; i < len; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << "\n";

    return 0;
}