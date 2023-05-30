#include <iostream>
#include <string>
using namespace std;

// Declare a structure named "car"
struct car {
  string brand;
  string model;
  int year;
};

int main() {
    string brand;
  // Create a car structure and store it in myCar1;
  car myCar1;
  myCar1.brand = "Mazda";
  myCar1.model = "MX5";
  myCar1.year = 2008;

  // Create another car structure and store it in myCar2;
  car myCar2;
  myCar2.brand = "Nissan";
  myCar2.model = "GTR";
  myCar2.year = 2015;
 
 
    cout << "Podaj markę samochodu: "; 
  // Print the structure members
  cin >> brand;
  if(brand == "Mazda"){
    cout << myCar1.brand << " " << myCar1.model << " " << myCar1.year << "\n";
  }
    if(brand == "Nissan"){
    cout << myCar2.brand << " " << myCar2.model << " " << myCar2.year << "\n";
  }
 
  return 0;
}
