# Studentų pažymių skaičiavimo programa
## Versijos:
---
  * #### v0.1
  1. Programa nuskaito įvestus duomenis:
  *Studentų vardus ir pavardes*
  *Namų darbų ir egzamino rezultatus*

  2. Išveda studento galutinį balą

  3. Galima pasirinkti galutinio balo skaičiavimo būdą: vidurkis arba mediana

  4. Balai gali būti generuojami atsitiktinai

 Įkeltos dvi versijos: su vektoriais ir su dinaminiu masyvu

  ---
  * #### v0.2
 **Pridėta:** 
 * studentų duomenu nuskaitymas iš failo,
 * surūšiuotas studentų irašų išvedimas

---
  * #### v0.3
  **Atliktas refactoring'as:** 
  * funkcijų apsirašymai, naujų duomenų tipų įvedimai perkelti į header failą, 
  * įvestas išimčių valdymas

---
  * #### v0.4
  **Pridėta:** 
* failų generavimas (įvedamas namų darbų kiekis ir įrašų kiekis), 
* išvedimo rūšiavimas pagal galutinį rezultatą (mažiau nei 5 - vargšiukai; 5 ir daugiau - kietekai),
* pridėta programos veikimo spartos matavimo galimybė (matuojama: failų kūrimo greitis, duomenų nuskaitymo iš failo greitis, studentų rūšiavimo greitis, surūšiuotų studentų išvedimo į failus greitis)
  *  [Nuoroda į programos veikimo analizę](https://github.com/ignasms12/antraUzduotis/releases/download/v0.4/v0.4.ataskaita.pdf)

---
  * #### v0.5
  #### Konteinerių testavimas
*laikai atvaizduoti milisekundėmis*

**Vektoriai:**

<center>

|Studentų kiekis|1 000|10 000|100 000|1 000 000|10 000 000|
|---|:-:|---|---|---|---|
|Duomenų nuskaitymas iš failų|11|65|613|6124|109989|
|Studentų rūšiavimas į dvi kategorijas|1|9|91|1079|16222|

</center>

**Sąrašai:**

<center>

|Studentų kiekis|1 000|10 000|100 000|1 000 000|10 000 000|
|---|:-:|---|---|---|---|
|Duomenų nuskaitymas iš failų|11|65|615|6231|80340|
|Studentų rūšiavimas į dvi kategorijas|4|399|133829|N/A|N/A|

</center>

**Dekos:**

<center>

|Studentų kiekis|1 000|10 000|100 000|1 000 000|10 000 000|
|---|:-:|---|---|---|---|
|Duomenų nuskaitymas iš failų|12|72|707|8454|116547|
|Studentų rūšiavimas į dvi kategorijas|3|32|330|9832|N/A|

</center>



#### Kompiuterio specifikacijos:

**CPU** - Intel Core m3-7Y32 1.2 GHz Dual-Core

**RAM** - 8 GB 1867 MHz LPDDR3

**Storage Device** - SSD

---
  * #### v1.0
  
Pritaikytos dvi skirtingos studentų dalinimo į kategorijas strategijos:

  * **1 strategija** - Bendro studentų konteinerio elementai rūšiuojami į du naujus konteinerius
  * **2 strategija** - Bendro studentų konteinerio elementai, atitinkantys nustatyta sąlygą, yra perkeliami į naują konteinerį ir pašalinami iš originalaus konteinerio

*Laikai atvaizduoti milisekundėmis*

**1 bandymas**

**Sąlygos:**

5 Namų darbų rezultatai
1000 įrašų

  **1 strategija**

  | Duomenų tipas | Nuskaitymas iš failo | Skirstymas į kategorijas |
|:-------------:|:--------------------:|:------------------------:|
|   Vektoriai   |          11          |             1            |
|      Deka     |          12          |            3            |
|    List'as    |          12          |            4           |

**2 strategija**

| Duomenų tipas | Nuskaitymas iš failo | Skirstymas į kategorijas |
|:-------------:|:--------------------:|:------------------------:|
|   Vektoriai   |          9          |           49           |
|      Deka     |          1          |           32           |
|    List'as    |          8          |            1           |


**2 bandymas**

**Sąlygos:**

10 Namų darbų rezultatų
10000 įrašų

  **1 strategija**

  | Duomenų tipas | Nuskaitymas iš failo | Skirstymas į kategorijas |
|:-------------:|:--------------------:|:------------------------:|
|   Vektoriai   |          93          |             10            |
|      Deka     |          99          |            34            |
|    List'as    |          91          |            446           |

**2 strategija**

| Duomenų tipas | Nuskaitymas iš failo | Skirstymas į kategorijas |
|:-------------:|:--------------------:|:------------------------:|
|   Vektoriai   |          86          |           4743           |
|      Deka     |          96          |           3390           |
|    List'as    |          87          |            307           |


## Naudojimosi instrukcija:
1. Atsidarę šį puslapį, spauskite "Clone or Download" mygtuką, kad parsisiųstumėte programą
2. Parsisiuntę Zip failą, išarchyvuokite jį sau patogiu įrankiu
3. Atsidarykite komandinės eilutės įrankį ir nueikite į išarchyvuotą aplanką
4. Išarchyvuotame aplanke naudokite vieną iš šių komandų, kad paruoštumėte programą naudojimui:
    * **make all** - sukompiliuoti visas programas
    * **make deque** - sukompiliuoti a ir b strategijų programas, naudojančias deką
    * **make list** - sukompiliuoti a ir b strategijų programas, naudojančias list'us
    * **make vector** - sukompiliuoti a ir b strategijų programas, naudojančias vektorius
5. Naudokite vieną šių komandų programos paleidimui:
    * **make run_deque_a** - paleisti a strategijos programą, naudojančią deką
    * **make run_deque_b** - paleisti b strategijos programą, naudojančią deką
    * **make run_list_a** - paleisti a strategijos programą, naudojančią listus
    * **make run_list_b** - paleisti b strategijos programą, naudojančią listus
    * **make run_vector_a** - paleisti a strategijos programą, naudojančią vektorius
    * **make run_vector_b** - paleisti b strategijos programą, naudojančią vektorius
6. Komanda skirta aplanko išvalymui:
    * **make clear** - išvalyti visus tekstinius ir paleidimo failus
