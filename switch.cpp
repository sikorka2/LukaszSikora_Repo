//Program sprawdza który mamy dzień tygodnia po wpisaniu cyfry używająć Switcha
#include <iostream>
using namespace std;

int main() {
    cout << "Podaj numer i sprawdź który to dzień tygodnia: ";
    int day;
    cin >> day;
  switch (day) {
    case 1:
      cout << "Jest Poniedziałek";
      break;
    case 2:
      cout << "Jest wtorek";
      break;
    case 3:
      cout << "Jest środa";
      break;  
    case 4:
      cout << "Jest czwartek";
      break;      
    case 5:
      cout << "Jest piątek";
      break;
    case 6:
      cout << "Jest sobota";
      break;
    case 7:
      cout << "Jest niedziela";
      break;
    default:
      cout << "Podałeś złą liczbę!";
  }
  return 0;
}
