#pragma once

#include <cmath>
#include <iomanip>
#include <iostream>
#include <climits>
#include <fstream>
#include <string>
#include <chrono>
#include <vector>
#include <list>
#include <iterator>
#include <cctype>
#include <algorithm>



struct Studentas {
  std::string name;
  std::string surname;
  int n;
  std::vector<int> nd_rezultatas;
  double egzamino_rezultatas;
  double bendras_pazymys;
};


double diffclock( clock_t , clock_t);

void bubbleSort(std::list<Studentas>::iterator, int );

int digitCounter(int);

void random_gen();

void compare(Studentas*);

void ivedimas(int&);

void input(Studentas*); 

void input_result(std::list<Studentas>::iterator);

void validityCheck(Studentas*);

void naujasIrasas(char*, int*);

void galutinioSkaiciavimas(Studentas&, int&);

bool comparation(std::list<Studentas>::iterator, std::list<Studentas>::iterator);

bool compare(const Studentas &first,const Studentas &second);

void splitOutput(std::list<Studentas>, std::list<Studentas>&, std::list<Studentas>&);

void print(std::list<Studentas> , std::list<Studentas>, std::list<Studentas>, int );

void outputToFile(std::list<Studentas>, std::list<Studentas>, int);

void readFile(std::list<Studentas>&, int, int);

void ivedimoPorankis(std::list<Studentas>&, int&, int , char );