#include "vars.h"


void bubbleSort(Studentas pavyzdys, int n) {
	bool exchanges;
	do {
		exchanges =	false;
		for (int c = 0; c < n - 1; c++) {
			if (pavyzdys.nd_rezultatas[c] > pavyzdys.nd_rezultatas[c + 1]) {
				double temp = pavyzdys.nd_rezultatas[c];
				pavyzdys.nd_rezultatas[c] = pavyzdys.nd_rezultatas[c + 1];
				pavyzdys.nd_rezultatas[c + 1] = temp;
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

		auto paradzia = std::chrono::steady_clock::now( );

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
				if(i!=kiekis-1){
					failas << std::endl;
				}
		}

		auto pbaiga = std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::steady_clock::now( ) - paradzia );

		std::cout << "Failo generavimas uztruko: " << pbaiga.count() << " ms" << std::endl;
}

void compare(Studentas *pavyzdys) {
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

void input(Studentas *pavyzdys) {
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

void input_result(Studentas &pavyzdys) {
	std::cin >> pavyzdys.egzamino_rezultatas;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Neteisinga reiksme, iveskite skaiciu: " << std::endl;
		std::cin >> pavyzdys.egzamino_rezultatas;
	}
	if (pavyzdys.egzamino_rezultatas > 10 || pavyzdys.egzamino_rezultatas < 1) {
		std::cout << "Egzamino rezultatas privalo buti intervale nuo 1 iki 10, iveskite "
						"tinkama rezultata:"
				 << std::endl;
		input_result(pavyzdys);
	}
}

void validityCheck(Studentas *pavyzdys) {
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

void galutinioSkaiciavimas(Studentas &rodiklis, int &porankis){

	int suma = 0;
	for (int a = 0; a < rodiklis.nd_rezultatas.size() ; a++) {
		suma += rodiklis.nd_rezultatas[a];
	}

	double mediana;
	if (porankis == 1) {

		if (rodiklis.nd_rezultatas.size()% 2 != 0) {
			int abc = round(rodiklis.nd_rezultatas.size() / 2);
			mediana = rodiklis.nd_rezultatas[abc];
		}

		else if ( rodiklis.nd_rezultatas.size() % 2 == 0) {
			mediana = ( rodiklis.nd_rezultatas[rodiklis.nd_rezultatas.size() / 2 - 1] + rodiklis.nd_rezultatas[ rodiklis.nd_rezultatas.size() / 2] )/2;
		}
		rodiklis.bendras_pazymys = (0.4 * mediana) + (0.6 * rodiklis.egzamino_rezultatas);
	}

	else if(porankis == 0){
		rodiklis.bendras_pazymys = (0.4 * ( suma / rodiklis.nd_rezultatas.size() ) ) + (0.6 * rodiklis.egzamino_rezultatas );
	}

}

bool comparation(Studentas &a, Studentas &b){
	return (a.name < b.name || (a.name == b.name && a.surname < b.surname));
}

void splitOutput(std::vector<Studentas> &vektoriux, std::vector<Studentas> &vargsiukai){
	int kitasCount = 0;

	for(int k=0; k<vektoriux.size() ; k++){
		if(vektoriux[k].bendras_pazymys < 5){
			vargsiukai.push_back(Studentas());
			vargsiukai[kitasCount] = vektoriux[k];
			vektoriux.erase(vektoriux.begin() + k);
			kitasCount++;
			--k;
		}
	}
}

void print(std::vector<Studentas> printeris, std::vector<Studentas> vargsiukai, int pasirinkimas){
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

		for (int n = 0; n < 60; n++) std::cout << "-";

		for(int sup=0; sup < printeris.size(); sup++) {
			std::cout << std::endl;
			std::cout.width(15);
			std::cout << std::left << printeris[sup].name;
			std::cout.width(20);
			std::cout << std::left << printeris[sup].surname;
			std::cout << std::fixed << std::setprecision(2) << printeris[sup].bendras_pazymys << std::endl;
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
			std::cout << std::endl;
			std::cout.width(15);
			std::cout << std::left << vargsiukai[sup].name;
			std::cout.width(20);
			std::cout << std::left << vargsiukai[sup].surname;
			std::cout << std::fixed << std::setprecision(2) << vargsiukai[sup].bendras_pazymys << std::endl;
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

		for(int sup=0; sup < printeris.size(); sup++) { 
			std::cout << std::endl;
			std::cout.width(15);
			std::cout << std::left << printeris[sup].name;
			std::cout.width(20);
			std::cout << std::left << printeris[sup].surname;
			std::cout << std::fixed << std::setprecision(2) << printeris[sup].bendras_pazymys << std::endl;
	}

	}

	std::cout << std::endl;
}

void outputToFile(std::vector<Studentas> kiec,std::vector<Studentas> vargs, int pasirinkimas){
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
			
				kietekai << std::endl;
				kietekai.width(15);
				kietekai << std::left << kiec[sup].name;
				kietekai.width(20);
				kietekai << std::left << kiec[sup].surname;
				kietekai << std::fixed << std::setprecision(2) << kiec[sup].bendras_pazymys << std::endl;
		}
		for(int b=0; b<vargs.size(); b++){
				vargsiukai << std::endl;
				vargsiukai.width(15);
				vargsiukai << std::left << vargs[b].name;
				vargsiukai.width(20);
				vargsiukai << std::left << vargs[b].surname;
				vargsiukai << std::fixed << std::setprecision(2) << vargs[b].bendras_pazymys << std::endl;
		}
}

void readFile(std::vector<Studentas> &printeris, int k, int pasirinkimas){
		
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

				while(!failas.eof()){
						printeris.push_back(Studentas());
						failas >> printeris[k].name >> printeris[k].surname; 
						
						for(int l = 0; l < count; l++){
								printeris[k].nd_rezultatas.push_back(int());
								failas >> printeris[k].nd_rezultatas[l];
						} 
						failas >> printeris[k].egzamino_rezultatas;
						galutinioSkaiciavimas(printeris[k], pasirinkimas);
						
						k++;
						if(k%1000 == 0){
								std::cout << k << std::endl;
						}
				}
				
				failas.close();
		
}

void ivedimoPorankis(std::vector<Studentas> &printeris, int &pasirinkimas, int k, int ivedimoPorank, char option){

	if(ivedimoPorank == 0){
			printeris.push_back(Studentas());
			std::cout << "Iveskite studento varda" << std::endl;
			std::cin >> printeris[k].name >> printeris[k].surname;

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
						printeris.push_back(Studentas());
						std::cout << "Iveskite studento varda" << std::endl;
						std::cin >> printeris[k].name;
						std::cin >> printeris[k].surname;
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
					printeris[k].n = rand() % 15 + 1;
					for (int a = 0; a < printeris[k].n; a++) {
						printeris[k].nd_rezultatas.push_back(int());
						printeris[k].nd_rezultatas[a] = rand() % 10 + 1;
					}
					printeris[k].egzamino_rezultatas = rand() % 10 + 1;
					std::cout << std::endl;
					std::cout << std::endl;
					bubbleSort(printeris[k], printeris[k].n);
					std::cout << "Namu darbu rezultatai: " << std::endl;
					for (int a = 0; a < printeris[k].n; a++) {
						std::cout << printeris[k].nd_rezultatas[a] << std::endl;
					}
					std::cout << std::endl;
					std::cout << std::endl;
					std::cout << "Egzamino rezultatas: " << std::endl;
					std::cout << printeris[k].egzamino_rezultatas << std::endl;
					std::cout << std::endl;
				} 

				else if (option == 'N' || option == 'n') {
					std::cout << "Iveskite studento egzamino rezultata: " << std::endl;
					input_result(printeris[k]);
					std::cout << std::endl;

					std::cout << "Iveskite studento namu darbu uzduociu kieki ir kiekvienos uzduoties ivertinima:"
							<< std::endl;
					std::cout << std::endl;

					std::cout << "Namu darbu uzduociu kiekis: ";

					Studentas *rodyklele = &printeris[k];
					validityCheck(rodyklele);
					compare(rodyklele);  // jei n mazesnis uz 0, useriui metamas erroras
					std::cout << std::endl;

					std::cout << "Namu darbu uzduociu ivertinimai: " << std::endl << std::endl;
					Studentas *wazeep;
					wazeep = &printeris[k];
					input(wazeep);

				}

				else {
					std::cout << "Iveskite Y arba N:" << std::endl;
					std::cin >> option;
				}

				galutinioSkaiciavimas(printeris[k], pasirinkimas);
				
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