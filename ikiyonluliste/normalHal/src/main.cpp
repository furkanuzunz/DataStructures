#include<iostream>
#include<iomanip>
#include "Liste.hpp"
using namespace std;



int main()
{
    Liste* liste = new Liste();
    liste->onuneEkle(3,99);
    liste->ekle(11);
    cout<<*liste;   
    liste->ekle(22);
      cout<<*liste;   
    liste->ekle(33);
    liste->ekle(44);  
    cout<<*liste;  

    

    cout<<*liste;
       
  //liste boşsa;
  // try{
  //   cout << liste->ilkGetir() << endl;

  // }catch (std::out_of_range& e)
  // {
  //   cout << e.what()<<endl;
  // }
     
    delete liste; 
}