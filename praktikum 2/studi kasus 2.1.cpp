#include <iostream>
#include <fstream>
using namespace std;

class FoodDelivery {
  public:
    string name;
    float total;
    float foodCost;
    float diliveryCost;
    float distance;
    float discont;

  void diliveryDistace() {
    if (distance > 3) {
      diliveryCost = 25000 ;
    } else {
      diliveryCost = 15000;
    }
  };

  void pickFood(float foodType) {
    foodCost += foodType;
  };

  float totalCost() {
    if (foodCost > 150000) {
      diliveryCost = diliveryCost - 8000;
      foodCost = foodCost * 0,35;
    } else if (foodCost >= 50000 & foodCost <= 150000) {
      diliveryCost = diliveryCost - 5000;
      foodCost = foodCost * 0,15;
    } else if (foodCost >= 25000 & foodCost <= 50000) {
      diliveryCost = diliveryCost - 3000;
    };

    return diliveryCost + foodCost;
  }
};



int main() {
  FoodDelivery fd;
  cout << "==================================\n";
  cout << "Masukan nama anda : \n";
  cout << "==================================\n";
  cin >> fd.name;


  cout << "==================================\n";
  cout << "Masukan jarak anda : \n";
  cout << "==================================\n";
  cin  >> fd.distance;
  fd.diliveryDistace();

  pesan:
  int menuInput = 0;
  float h;
  cout << "==================================\n";
  cout << "1. Ayam Geprek  : 21000\n" << endl;
  cout << "2. Ayam Goreng  : 17000\n" << endl;
  cout << "3. Udang Goreng : 19000\n" << endl;
  cout << "4. Cumi Goreng  : 20000\n" << endl;
  cout << "5. Ayam Bakar   : 25000\n" << endl;
  cout << "6. Selesai\n" << endl;
  cout << "Pilih menu : \n";
  cout << "==================================\n";
  cin >> menuInput;

  switch(menuInput) {
    case 1:
      h = 21000;
      break;
    case 2:
      h = 17000;
      break;
    case 3:
      h = 19000;
      break;
    case 4:
      h = 19000;
      break;
    case 5:
      h = 25000;
      break;
  }
  if (menuInput != 6){
    fd.pickFood(h);
    goto pesan;
  }


  cout<<"\nStruk Belanja\n";
  cout<<"Nama Pelanggan            : " << fd.name << "\n";
  cout<<"Harga Makanan             : " << fd.foodCost << "\n";
  cout<<"Ongkir                    : " << fd.diliveryCost << "\n";
  cout<<"==================================\n";
  cout<<"Total Belanja anda adalah : " << fd.totalCost() << "\n";

  ofstream txt("struk.txt");
  txt<<"\nStruk Belanja\n";
  txt<<"Nama Pelanggan            : " << fd.name << "\n";
  txt<<"Harga Makanan             : " << fd.foodCost << "\n";
  txt<<"Ongkir                    : " << fd.diliveryCost << "\n";
  txt<<"==================================\n";
  txt<<"Total Belanja anda adalah : " << fd.totalCost() << "\n";
  txt.close();
}
