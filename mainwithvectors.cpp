#include "vars.h"

int main() {
  int *rod;
  std::list<Studentas> studentai;
  int pasirinkimas;
  char taipArbaNe;
  int ivedimoPorank;
  char ived;
  int ka;
  double skirtumas;
  

  std::cout << "Ar norite sukurti nauja faila ? Y/N" << std::endl;
  std::cin >> ived;

  if(ived == 'Y' || ived == 'y'){
    random_gen();
  }
  
  std::cout << std::endl;
  std::cout << "Pasirinkite kas turetu buti isvedama: Vidurkis ar Mediana: ";
  ivedimas(pasirinkimas);
  std::cout << std::endl;
  
  std::cout << "Kaip ivesite irasus:" << std::endl;
  std::cout << "0 - Irasai ivedami ranka" << std::endl;
  std::cout << "1 - Irasai nuskaitomi is failo" << std::endl;

  std::cin >> ivedimoPorank;

  ivedimoPorankis(studentai, pasirinkimas, ivedimoPorank, taipArbaNe);

  std::list<Studentas> kietekai;
  std::list<Studentas> vargsiukai;

  studentai.sort([](const Studentas &a, const Studentas &b ) {return a.name < b.name || (a.name == b.name && a.surname < b.surname); });

  auto pradzia = std::chrono::steady_clock::now( );
  splitOutput(studentai, kietekai, vargsiukai);
  auto pabaiga = std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::steady_clock::now( ) - pradzia );

  std::cout << "Skirstymas i atskiras kategorijas uztruko: " << pabaiga.count() << " ms" << std::endl;
  
  std::cout << "\nAr norite isvesti i konsole ar i atskira faila ?" << std::endl;
  std::cout << "0 - i konsole" << std::endl;
  std::cout << "1 - i faila" << std::endl;
  std::cin >> ka;

  if(ka == 0){
    print(studentai, vargsiukai, kietekai, pasirinkimas);
  }
  else if(ka==1){
    
    outputToFile(kietekai, vargsiukai, pasirinkimas);
  }

  
}