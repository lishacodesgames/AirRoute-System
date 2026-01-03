#include <iostream>
#include <ctime>
using namespace std;

void printTitle() {
  #if defined(_WIN32) 
    system("cls");
  #elif defined(__APPLE__)
    cout << "\033c";
  #endif
  cout << "******************* LISHA'S AMAZING AIRPORT *******************\n";  
}

int main() {
  srand(time(0));
  printTitle();  
  
  
  cout<<'\n';
  return 0;
}