#include "vars.h"
Studentas tuscias;

void bubbleSort(std::list<Studentas>::iterator pavyzdys, int n) {
	bool exchanges;
	do {
		exchanges = false;
		for (int c = 0; c < n - 1; c++) {
			if (pavyzdys->nd_rezultatas[c] > pavyzdys->nd_rezultatas[c + 1]) {
				double temp = pavyzdys->nd_rezultatas[c];
				pavyzdys->nd_rezultatas[c] = pavyzdys->nd_rezultatas[c + 1];
				pavyzdys->nd_rezultatas[c + 1] = temp;
				exchanges = true;
			}
		}
	} while (exchanges);
}

int digitCounter(int no){
		int a = 0;
		if(no == -1){
				a = 0;
		}
		else if(no==0){
				no=1;
		}
		while(no>0){
				no=no/10;
				a++;
		}
		return a;
}

void random_gen(){
		int n, kiekis;
		int temp = -1;
		std::string pavadinimas;
		std::string name = "Vardas";
		std::string surname = "Pavarde";
		std::string nd = "ND";
		srand(time(NULL));
		std::cout << "Iveskite namu darbu kieki: ";
		std::cin >> n;
		std::cout << "\nIveskite irasu kieki: ";
		std::cin >> kiekis;
		std::cout << std::endl;
		std::cout << "Iveskite naujo failo pavadinima: " << std::endl;
		std::cin >> pavadinimas;
		std::cout << std::endl;

		std::ofstream failas;
		failas.open(pavadinimas + ".txt");
		failas << std::setw(20) << std::left << name << std::setw(20) << std::left << surname;
		for(int i=1; i< n+1; i++){
				failas << std::setw(5) << std::right << nd << i ;
		}
		failas << std::setw(10) << std::right << "Egz_Rez" << std::endl;
		for(int i=0; i<kiekis; i++){
				failas << std::right <<  name << i;

				failas << std::setw(20-digitCounter(i)) << std::right;

				failas << surname << i;

				for(int j=0; j<n; j++){
						
						if(j==0){
								failas << std::setw(18-digitCounter(i)) << std::right;
						}
						else{
								failas << std::setw(7) << std::right;
								}
						
						failas  << rand() % 10 + 1;
				}
				
				failas << std::setw(6) << std::right << rand() % 10 + 1 ;
				if(i != kiekis-1){
					failas << std::endl;
				}
		}

}

void compare(std::list<Studentas>::iterator pavyzdys) {
	if (pavyzdys->n <= 0) {
		std::cout << "Uzduociu kiekis negali buti maziau 1" << std::endl;
		std::cout << "Iveskite uzduociu kieki: ";
		std::cin >> pavyzdys->n;
		compare(pavyzdys);
	}
}

void ivedimas(int &pvz) {
	std::string pavyzdys;
	std::cin >> pavyzdys;
	if (pavyzdys == "Vidurkis" || pavyzdys == "vidurkis") {
		pvz = 0;
	} else if (pavyzdys == "Mediana" || pavyzdys == "mediana") {
		pvz = 1;
	} else {
		std::cout << "Neteisingai ivedete, iveskite Vidurkis arba Mediana: ";
		ivedimas(pvz);
	}
}

void input(std::list<Studentas>::iterator pavyzdys) {
	int indeksas = 0;
	while (indeksas < pavyzdys->n) {
		pavyzdys->nd_rezultatas.push_back(int());
		std::cout << indeksas + 1 << " - ";
		std::cin >> pavyzdys->nd_rezultatas[indeksas];
		while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cout << "Neteisinga reiksme, iveskite skaiciu: " << std::endl;
			std::cout << indeksas + 1 << " - ";
			std::cin >> pavyzdys->nd_rezultatas[indeksas];
		}
		try {
				if(pavyzdys->nd_rezultatas[indeksas] > 10 || pavyzdys->nd_rezultatas[indeksas] < 0){
						throw pavyzdys->nd_rezultatas[indeksas];
				}
				else{
						indeksas++;
				}
		}
		catch(int x){
				std::cout <<"\n" << x << " netelpa i intervala nuo 0 iki 10";
		}

	}
	indeksas = 0;
}

void input_result(std::list<Studentas>::iterator pavyzdys) {
	std::cin >> pavyzdys->egzamino_rezultatas;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Neteisinga reiksme, iveskite skaiciu: " << std::endl;
		std::cin >> pavyzdys->egzamino_rezultatas;
	}
	if (pavyzdys->egzamino_rezultatas > 10 || pavyzdys->egzamino_rezultatas < 1) {
		std::cout << "Egzamino rezultatas privalo buti intervale nuo 1 iki 10, iveskite "
						"tinkama rezultata:"
				 << std::endl;
		input_result(pavyzdys);
	}
}

void validityCheck(std::list<Studentas>::iterator pavyzdys) {
	std::cin >> pavyzdys->n;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Neteisinga reiksme, iveskite skaiciu: " << std::endl;
		std::cin >> pavyzdys->n;
	}
}

void naujasIrasas(char *rankis, int *numeriukas){
	if(*numeriukas == 0){
		std::cout << "Ar norite prideti nauja irasa ? (Y/N)" << std::endl;
	}
	else if(*numeriukas > 0){
		std::cout << "Neteisingai ivedete - iveskite Y arba N" << std::endl;
	}
	std::cin >> *rankis;
	numeriukas++;
}

void galutinioSkaiciavimas(Studentas& it, int &porankis){

	int suma = 0;
	for (int a = 0; a < it.nd_rezultatas.size() ; a++) {
		suma += it.nd_rezultatas[a];
	}

	double mediana;
	if (porankis == 1) {

		if (it.nd_rezultatas.size()% 2 != 0) {
			int abc = round(it.nd_rezultatas.size() / 2);
			mediana = it.nd_rezultatas[abc];
		}

		else if ( it.nd_rezultatas.size() % 2 == 0) {
			mediana = ( it.nd_rezultatas[it.nd_rezultatas.size() / 2 - 1] + it.nd_rezultatas[ it.nd_rezultatas.size() / 2] )/2;
		}
		it.bendras_pazymys = (0.4 * mediana) + (0.6 * it.egzamino_rezultatas);
	}

	else if(porankis == 0){
		it.bendras_pazymys = (0.4 * ( suma / it.nd_rezultatas.size() ) ) + (0.6 * it.egzamino_rezultatas );
	}

}

bool comparation(std::list<Studentas>::iterator a, std::list<Studentas>::iterator b){
	return (a->name < b->name || (a->name == b->name && a->surname < b->surname));
}

bool compare(const Studentas &first,const Studentas &second){
  if (first.name < second.name)
    return true;
  else
    return false;
}

void splitOutput(std::list<Studentas> vektoriux, std::list<Studentas> &kietekai, std::list<Studentas> &vargsiukai){
	for(int k=0; k<vektoriux.size(); k++){
		auto it = std::next( vektoriux.begin(), k);
		if(it->bendras_pazymys >= 5){
			kietekai.push_back( *it );
		}
		else if(it->bendras_pazymys < 5){
			vargsiukai.push_back( *it );
		}
	}
	
}

void print(std::list<Studentas> printeris, std::list<Studentas> vargsiukai, std::list<Studentas> kietekai, int pasirinkimas){
	std::cout << std::endl;
	int hehehey;
	std::cout << "Ar norite isvesti visus studentus ar sukategorizuotus ?" << std::endl;
	std::cout << "0 - Isvedami visi studentai" << std::endl;
	std::cout << "1 - Isvedami sukategorizuoti studentai" << std::endl;
	std::cin >> hehehey;
	std::cout << std::endl;

	

	if(hehehey == 0){

		std::cout<< std::endl;
		std::cout.width(15);
		std::cout << std::left << "Vardas";
		std::cout.width(15);
		std::cout << std::left << "Pavarde";
		std::cout.width(16);

		if (pasirinkimas == 0) {
			std::cout << std::left << "Galutinis (Vid.)" << std::endl;
		}

		else if (pasirinkimas == 1) {
			std::cout << std::left << "Galutinis (Med.)" << std::endl;
		}

		std::cout << printeris.size() << std::endl;

		for (int n = 0; n < 60; n++) std::cout << "-";

		for(int sup=0; sup < printeris.size(); sup++) {
			auto it = std::next(printeris.begin(), sup);
			std::cout << std::endl;
			
			std::cout.width(15);
			std::cout << std::left << it->name;
			std::cout.width(20);
			std::cout << std::left << it->surname;
			std::cout << std::fixed << std::setprecision(2) << it->bendras_pazymys << std::endl;
		}

	}

	else if(hehehey == 1){
		std::cout << "                         " << "VARGSIUKAI:" << std::endl;

		std::cout.width(15);
		std::cout << std::left << "Vardas";
		std::cout.width(15);
		std::cout << std::left << "Pavarde";
		std::cout.width(16);

		if (pasirinkimas == 0) {
			std::cout << std::left << "Galutinis (Vid.)" << std::endl;
		}

		else if (pasirinkimas == 1) {
			std::cout << std::left << "Galutinis (Med.)" << std::endl;
		}

		for (int n = 0; n < 60; n++) std::cout << "-";

		for(int sup=0; sup < vargsiukai.size(); sup++) {
			auto it = std::next(vargsiukai.begin(), sup);
			std::cout << std::endl;
			std::cout.width(15);
			std::cout << std::left << it->name;
			std::cout.width(20);
			std::cout << std::left << it->surname;
			std::cout << std::fixed << std::setprecision(2) << it->bendras_pazymys << std::endl;
		}
		std::cout<< std::endl;
		std::cout<< std::endl;
		
		std::cout << "                         " << "KIETEKAI:" << std::endl;

		std::cout<< std::endl;
		std::cout.width(15);
		std::cout << std::left << "Vardas";
		std::cout.width(15);
		std::cout << std::left << "Pavarde";
		std::cout.width(16);

		if (pasirinkimas == 0) {
			std::cout << std::left << "Galutinis (Vid.)" << std::endl;
		}

		else if (pasirinkimas == 1) {
			std::cout << std::left << "Galutinis (Med.)" << std::endl;
		}

		for (int n = 0; n < 60; n++) std::cout << "-";

		for(int sup=0; sup < kietekai.size(); sup++) { 
			auto it = std::next(kietekai.begin(), sup);
			std::cout << std::endl;
			std::cout.width(15);
			std::cout << std::left << it->name;
			std::cout.width(20);
			std::cout << std::left << it->surname;
			std::cout << std::fixed << std::setprecision(2) << it->bendras_pazymys << std::endl;
	}

	}

	std::cout << std::endl;
}

void outputToFile(std::list<Studentas> kiec,std::list<Studentas> vargs, int pasirinkimas){
	std::ofstream vargsiukai;
	std::ofstream kietekai;
	vargsiukai.open("vargsiukai.txt");
	kietekai.open("kietekai.txt");

	//vargsiuku outputas
		vargsiukai.width(15);
		vargsiukai << std::left << "Vardas";
		vargsiukai.width(15);
		vargsiukai << std::left << "Pavarde";
		vargsiukai.width(16);

		if (pasirinkimas == 0) {
			vargsiukai << std::left << "Galutinis (Vid.)" << std::endl;
		}

		else if (pasirinkimas == 1) {
			vargsiukai << std::left << "Galutinis (Med.)" << std::endl;
		}
		for (int n = 0; n < 60; n++) vargsiukai << "-";

	//kieteku outputas
		kietekai.width(15);
		kietekai << std::left << "Vardas";
		kietekai.width(15);
		kietekai << std::left << "Pavarde";
		kietekai.width(16);

		if (pasirinkimas == 0) {
			kietekai << std::left << "Galutinis (Vid.)" << std::endl;
		}

		else if (pasirinkimas == 1) {
			kietekai << std::left << "Galutinis (Med.)" << std::endl;
		}
		for (int n = 0; n < 60; n++) kietekai << "-";

	
		for(int sup=0; sup < kiec.size(); sup++) {
				auto it = std::next(kiec.begin(), sup);
				kietekai << std::endl;
				kietekai.width(15);
				kietekai << std::left << it->name;
				kietekai.width(20);
				kietekai << std::left << it->surname;
				kietekai << std::fixed << std::setprecision(2) << it->bendras_pazymys << std::endl;
		}
		for(int b=0; b<vargs.size(); b++){
				auto it = std::next(vargs.begin(), b);
				vargsiukai << std::endl;
				vargsiukai.width(15);
				vargsiukai << std::left << it->name;
				vargsiukai.width(20);
				vargsiukai << std::left << it->surname;
				vargsiukai << std::fixed << std::setprecision(2) << it->bendras_pazymys << std::endl;
		}
}

void readFile(std::list<Studentas>& printeris, int k, int pasirinkimas){
		
	std::string Value = "";
	int count = 0;
	std::string file = "kursiokai.txt";
	std::ifstream failas("kursiokai.txt");
	

	try{
		failas.exceptions(std::ifstream::failbit);
	}
	catch(std::ios_base::failure& fail){
		std::cerr <<"\n Failas -  " << file << "  - nerastas; ikelkite faila i programos vykdymo aplanka ir paspauskite Enter mygtuka"; 
		std::cin.ignore();
		std::cin.get();
		readFile(printeris, k, pasirinkimas);
	}

	

	failas >> Value >> Value >> Value;
	
	while(Value[0] == 'N'){
		failas >> Value;
		count++;
	}
	Studentas it;

	while( !failas.eof() ){
		
		failas >> it.name >> it.surname; 
		
		
		for(int l = 0; l < count; l++){
			it.nd_rezultatas.push_back(int());
			failas >> it.nd_rezultatas[l];
		} 
		failas >> it.egzamino_rezultatas;
		
		galutinioSkaiciavimas(it, pasirinkimas);

		printeris.push_back(it);

		k++;
		if(k%1000 == 0){
			std::cout << k << std::endl;
		}
	}
	
	failas.close();
		
}

void ivedimoPorankis(std::list<Studentas> &printeris, int &pasirinkimas, int ivedimoPorank, char option){
	int k=0;
	if(ivedimoPorank == 0){
		auto it = std::next(printeris.begin(), k);
		printeris.push_back( *it );
		std::cout << "Iveskite studento varda" << std::endl;
		std::cin >> it->name >> it->surname;

		char rodyklius;
		int rodiklius = 0;

		while ( k >= 0 ) {
			char *porankis;
			if (k > 0){
				int *skaiciuks;
				skaiciuks = &rodiklius;
				porankis = &rodyklius;
				naujasIrasas(porankis, skaiciuks);

				if(rodyklius == 'y' || rodyklius == 'Y'){
					printeris.push_back(*it);
					std::cout << "Iveskite studento varda" << std::endl;
					std::cin >> it->name;
					std::cin >> it->surname;
				}
				else if(rodyklius == 'n' || rodyklius == 'N'){
					break;
				}
				else{
					naujasIrasas(porankis, skaiciuks);
				}
			}

			std::cout << "Ar norite rezultatus sugeneruoti atsitiktinai ? Y/N" << std::endl;
			std::cin >> option;

			if (option == 'Y' || option == 'y') {

				srand(time(0));
				it->n = rand() % 15 + 1;
				for (int a = 0; a < it->n; a++) {
					it->nd_rezultatas.push_back(int());
					it->nd_rezultatas[a] = rand() % 10 + 1;
				}
				it->egzamino_rezultatas = rand() % 10 + 1;
				std::cout << std::endl;
				std::cout << std::endl;
				bubbleSort(it, it->n);
				std::cout << "Namu darbu rezultatai: " << std::endl;
				for (int a = 0; a < it->n; a++) {
					std::cout << it->nd_rezultatas[a] << std::endl;
				}
				std::cout << std::endl;
				std::cout << std::endl;
				std::cout << "Egzamino rezultatas: " << std::endl;
				std::cout << it->egzamino_rezultatas << std::endl;
				std::cout << std::endl;
			} 

			else if (option == 'N' || option == 'n') {
				std::cout << "Iveskite studento egzamino rezultata: " << std::endl;
				input_result(it);
				std::cout << std::endl;

				std::cout << "Iveskite studento namu darbu uzduociu kieki ir kiekvienos uzduoties ivertinima:"
						<< std::endl;
				std::cout << std::endl;

				std::cout << "Namu darbu uzduociu kiekis: ";

				validityCheck(it);
				compare(it);  // jei n mazesnis uz 0, useriui metamas erroras
				std::cout << std::endl;

				std::cout << "Namu darbu uzduociu ivertinimai: " << std::endl << std::endl;
				input(it);

			}

			else {
				std::cout << "Iveskite Y arba N:" << std::endl;
				std::cin >> option;
			}
			Studentas test;
			galutinioSkaiciavimas(test, pasirinkimas);

			it->bendras_pazymys = test.bendras_pazymys;
			
			k++;
			rodiklius = 0;
		}
	}

	else if(ivedimoPorank == 1){
		auto startas = std::chrono::steady_clock::now( );
		
		readFile(printeris, k, pasirinkimas);
		
		auto finisas = std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::steady_clock::now( ) - startas );
		std::cout << std::endl;
		std::cout << "Nuskaitymas is failo uztruko: " << finisas.count() << " ms" << std::endl;
		std::cout << std::endl;

	}
	

}