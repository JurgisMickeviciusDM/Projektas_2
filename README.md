# PROJEKTAS_1 
# Paleidimas

1. Parsisiunčiame reikalingus failus iš GitHub.(Generavimasv1.cpp ; Naudotojasv1.cpp; Projektasv10.cpp;RUNMEE; CMakeLists; Generavimasv1; Naudotojasv1; Skaičiavimasv1; Studentasv1)
2. Visus cpp sudedame į folderį ,,src'':(Generavimasv1.cpp ; Naudotojasv1.cpp; Projektasv10.cpp)
   Header tipo failus ir studentu sąrašus sudėti į ,,Include" folderį:( Generavimasv1; Naudotojasv1; Skaičiavimasv1; Studentasv1)
   Atskirai prie folderių įsidedame ,,RUNMEE'' ir CMakeLists. Bendrai turi būti 4 atskiri failai/folderiai
   ![image](https://github.com/JurgisMickeviciusDM/Projektas1/assets/144474535/d2eb11ec-951f-4b87-a9ab-7cea818ba07b)

3.Paleidžiame Windows PoweShell
![image](https://github.com/JurgisMickeviciusDM/Projektas1/assets/144474535/4ce6cab1-534f-4644-ae29-3a8ee9ae9a9c)

4.RaŠome  cmake -S . -B .\build
5.RaŠome  cmake --build .\build
![image](https://github.com/JurgisMickeviciusDM/Projektas1/assets/144474535/bf0443a5-828e-4dac-a948-0b23c2252f8c)
5.1 SVarbu nepamiršti į Debug folderį įsikelti studentų failų, kad nereikėtų laukti, kol sugeneruos, kadangi, tai gali atimti daug laiko.
![image](https://github.com/JurgisMickeviciusDM/Projektas1/assets/144474535/989b341f-174e-4e42-ac34-2bf1fafc6af3)

6. Atsidarome nauja folderį build. Jame saugomas exe failas, reikalingas paleisti programą
![image](https://github.com/JurgisMickeviciusDM/Projektas1/assets/144474535/a8511df2-958c-4d5a-876f-e2a11ffdf4b1)

7. Einame į Build folderį, spaudžiame Debuf, tada projektasv10.exe
8. ![image](https://github.com/JurgisMickeviciusDM/Projektas1/assets/144474535/82ccb74c-05cf-46e6-ab16-ba30649d9d9d)

9. Programa pradeda darbą

# Parametrai įrenginio, su kuriuo buvo testuojamas laikas 

| CPU                                                       	| RAM                          	| SSD                  	|
|-----------------------------------------------------------	|------------------------------	|----------------------	|
| 11th Gen Intel(R) Core(TM) i5-1135G7 @ 2.40GHz   2.42 GHz 	| 8,00 GB (naudotina: 7,70 GB) 	| 475GB (laisva 195GB) 	|

# V0.1 Versija:

Pirminė programos versija, šioje versijoje vartotojas gali pats įvesti duomenis arba nuskaityti duomenis iš failo. Išveda vardą, pavardę, galutinį vidurkį/ galutinį medianą(jie skaičiuojami pagal atitinkamas formules: Galutinins= 0.4*vidurkis/mediana+0.6*egzaminas

# V0.2 Versija:

Porgrama atlieka tą patį, kaip ir # V0.1 versija, tačiau yra patobulinta. Šioje V0.2 versijoje studentai suskirstomi į dvi grupes: "Vargšiukai" ir "Kietiakai". Vargšiukai yra tie, kurių galutinis balas yra <5, kietiakai yra tie, kurių balas galutinis yra >=5. Taip pa t6ioje versijoje atsiranda laiko/spartos matavimas, kuris parodo kiek kiekviename etape užtrukto programa.

# V0.3 Versija:

Programoje išlieka tie patys pakeitimai, kaip ir senose versijose,  tačiau esminis pakeitimas yra tas, kad mes analizuojame programos spartos analizę, kaip ji priklauso, jeigu vietoj  vector naudojame list, kas pasikeičia, šiuo atveju pastebiu, kad su mano testavimo įrenginiu atsiranda atminties trūkumas ir tenka naudoti SSD su 10000000 studentų sąrašu, nes kitaip užlūžta programa.

# V1.0 Versija:
Naujausioje versijoje vyksta testavimas skirtingų strategijų. Jos yra 3. 1-Strategija duomenų rūšiavimui naudoja tokį pat rūšiavimo principą, kaip ir senosiose versijose. 2-Strategija naudoja rūšiavimui, tik vieną konteinerį, tiesiog vargšiukus ištrina iš bendro, juos perkelia į vargšiukų konteinerį, o kietiakai lieka senąjame ir nėra perkeliami į naują konteinerį. 3-Strategija yra patobulinta (2-strategija), kadangi buvo pastebėta atliekant spartos matavimus, jog ši strategija yra spartesnė, negu 1-strategija. 3-Strategijoje naudojamas stable_partition rūšiavimo metu, jis pertvarko elementus diapazone [first,last)taip, kad visi elementai, kuriems grąžina pred true, būtų pirmesni už visus tuos, kuriems jis grąžina false.
# Strategijų tipai S D DT
S-Bendro studentai konteinerio (vector ir list tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų". 
D-Bendro studentų konteinerio (vector ir list) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai". Tokiu būdu, jei studentas yra vargšiukas, jį turime įkelti į naująjį "vargšiukų" konteinerį ir ištrinti iš bendro studentai konteinerio
DT-Patobulinta D versija 
# Vektorius Naudojo S strategija  
Ekrano kopijos su visais laikais yra suagomos atskirame pdf faile, kuris yra patalpintas GitHub sistemoje prie failų ,,[Atminties matavimai su List Vektor ir S,D,DT strategijomis.pdf](https://github.com/JurgisMickeviciusDM/Projektas1/files/13259074/Atminties.matavimai.su.List.Vektor.ir.S.D.DT.strategijomis.pdf) "
Atlikus pakartotinius galutinius matavimus ir išvedus matavimų vidurkį gauti rezultatai ,,pablogėo", kadangi prieš tai matavau Vector viską tik su RAM, o List iškilus problemoms, kad nulužinėja programa, nes neužtenka atminties, pradėjau naudoti SSD, talpos nekeičiau ir permatuojant Vector, kadangi yra, tik 8GB RAM, o Windows sistema vien paleidus ir kitos porgramos iš kart ,,suvalgo'' 5GB RAM, tad laisvų lieka geriausiu atveju, tik 3GB. Tad sistema automatiškai dalį atminties pradėjo imti iš SSD, kai suteikiau tokią galimybę, tai yra atlaisvinau, leidau sistemai naudoti 40GB SSD. 

|          Testavimas          	|      1000     	|     10000     	|     100000     	|     1000000     	|      10000000      	|
|:----------------------------:	|:-------------:	|:-------------:	|:--------------:	|:---------------:	|:------------------:	|
|    <br>Failo nuskaitymas     	|    <br>0,001  	|    <br>0,1634 	|    <br>2,1478  	|    <br>22,5653  	|    <br>235,5489    	|
|    <br>Rušiavimas            	|    <br>0,0016 	|    <br>0,0254 	|    <br>0,2232  	|    <br>2,4963   	|    <br>105,8744    	|
|    <br>Sortinimas            	|    <br>0,005  	|    <br>0,08   	|    <br>1,254   	|    <br>16,8954  	|    <br>210,594     	|
|    <br>Įrašymas į vargšiukus 	|    <br>0,0115 	|    <br>0,1014 	|    <br>1,745   	|    <br>22,9546  	|    <br>248,6545    	|
|    <br>Sortinimas            	|    <br>0,0174 	|    <br>0,1345 	|    <br>2,4579  	|    <br>30,8746  	|    <br>289,5456    	|
|    <br>Įrašymas į kietiakus  	|    <br>0,017  	|    <br>0,2454 	|    <br>3,2478  	|    <br>32,5475  	|    <br>338,5616    	|
|    <br>Bendras               	|    <br>0,0535 	|    <br>0,7501 	|    <br>11,0757 	|    <br>128,3337 	|    <br>1428,779    	|

# Vektorius Naudojo D strategija  

|          Testavimas          	|      1000     	|     10000     	|     100000    	|     1000000     	|      10000000      	|
|:----------------------------:	|:-------------:	|:-------------:	|:-------------:	|:---------------:	|:------------------:	|
|    <br>Failo nuskaitymas     	|    <br>0,014  	|    <br>0,284  	|    <br>2,1845 	|    <br>22,7653  	|    <br>227,6789    	|
|    <br>Rušiavimas            	|    <br>0,0013 	|    <br>0,0287 	|    <br>0,3548 	|    <br>3,4963   	|    <br>324,2243    	|
|    <br>Sortinimas            	|    <br>0,004  	|    <br>0,0754 	|    <br>1,4587 	|    <br>17,4554  	|    <br>215,9591    	|
|    <br>Įrašymas į vargšiukus 	|    <br>0,0091 	|    <br>0,1178 	|    <br>1,645  	|    <br>19,6478  	|    <br>255,1248    	|
|    <br>Sortinimas            	|    <br>0,0121 	|    <br>0,1145 	|    <br>1,894  	|    <br>23,9946  	|    <br>294,7841    	|
|    <br>Įrašymas į kietiakus  	|    <br>0,014  	|    <br>0,1785 	|    <br>2,3478 	|    <br>29,1275  	|    <br>321,4116    	|
|    <br>Bendras               	|    <br>0,0545 	|    <br>0,7989 	|    <br>9,8848 	|    <br>116,4869 	|    <br>1639,183    	|

# Vektorius Naudojo DT strategija  
|          Testavimas          	|      1000      	|     10000     	|     100000    	|     1000000     	|      10000000      	|
|:----------------------------:	|:--------------:	|:-------------:	|:-------------:	|:---------------:	|:------------------:	|
|    <br>Failo nuskaitymas     	|    <br>0,017   	|    <br>0,2237 	|    <br>2,1475 	|    <br>21,8651  	|    <br>232,7451    	|
|    <br>Rušiavimas            	|    <br>0,0024  	|    <br>0,0296 	|    <br>0,3358 	|    <br>3,7863   	|    <br>329,102     	|
|    <br>Sortinimas            	|    <br>0,0023  	|    <br>0,0831 	|    <br>1,2972 	|    <br>16,3789  	|    <br>219,1107    	|
|    <br>Įrašymas į vargšiukus 	|    <br>0,009   	|    <br>0,1478 	|    <br>1,6258 	|    <br>19,5587  	|    <br>252,1138    	|
|    <br>Sortinimas            	|    <br>0,01035 	|    <br>0,1145 	|    <br>1,941  	|    <br>24,1078  	|    <br>294,7841    	|
|    <br>Įrašymas į kietiakus  	|    <br>0,014   	|    <br>0,1675 	|    <br>2,2178 	|    <br>28,8466  	|    <br>348,1716    	|
|    <br>Bendras               	|    <br>0,05505 	|    <br>0,7662 	|    <br>9,5651 	|    <br>114,5434 	|    <br>1676,027    	|
# List Naudojo S strategiją 
|          Testavimas          	|      1000      	|     10000     	|     100000    	|     1000000    	|      10000000      	|
|:----------------------------:	|:--------------:	|:-------------:	|:-------------:	|:--------------:	|:------------------:	|
|    <br>Failo nuskaitymas     	|    <br>0,0354  	|    <br>0,2877 	|    <br>2,7412 	|    <br>25,7865 	|    <br>289,5452    	|
|    <br>Rušiavimas            	|    <br>0,00298 	|    <br>0,0342 	|    <br>0,3488 	|    <br>3,4578  	|    <br>510,952     	|
|    <br>Sortinimas            	|    <br>0,0021  	|    <br>0,0347 	|    <br>0,5485 	|    <br>0,8942  	|    <br>79,5685     	|
|    <br>Įrašymas į vargšiukus 	|    <br>0,0074  	|    <br>0,0687 	|    <br>0,9745 	|    <br>3,9846  	|    <br>103,8422    	|
|    <br>Sortinimas            	|    <br>0,0038  	|    <br>0,0489 	|    <br>0,854  	|    <br>1,2478  	|    <br>96,7914     	|
|    <br>Įrašymas į kietiakus  	|    <br>0,0108  	|    <br>0,1274 	|    <br>1,2118 	|    <br>5,8756  	|    <br>155,2434    	|
|    <br>Bendras               	|    <br>0,06248 	|    <br>0,6016 	|    <br>6,6788 	|    <br>41,2465 	|    <br>1235,943    	|

# List Naudojo D strategiją 
|          Testavimas          	|      1000     	|     10000     	|     100000    	|     1000000    	|      10000000      	|
|:----------------------------:	|:-------------:	|:-------------:	|:-------------:	|:--------------:	|:------------------:	|
|    <br>Failo nuskaitymas     	|    <br>0,0311 	|    <br>0,241  	|    <br>2,489  	|    <br>25,4014 	|    <br>278,5874    	|
|    <br>Rušiavimas            	|    <br>0,0017 	|    <br>0,0117 	|    <br>0,1174 	|    <br>1,212   	|    <br>194,5896    	|
|    <br>Sortinimas            	|    <br>0,002  	|    <br>0,0295 	|    <br>0,3465 	|    <br>4,7321  	|    <br>60,551      	|
|    <br>Įrašymas į vargšiukus 	|    <br>0,0085 	|    <br>0,0623 	|    <br>0,7741 	|    <br>7,9542  	|    <br>105,8452    	|
|    <br>Sortinimas            	|    <br>0,0034 	|    <br>0,0432 	|    <br>0,6512 	|    <br>7,14    	|    <br>129,5645    	|
|    <br>Įrašymas į kietiakus  	|    <br>0,0103 	|    <br>0,094  	|    <br>1,084  	|    <br>11,7552 	|    <br>176,2552    	|
|    <br>Bendras               	|    <br>0,057  	|    <br>0,4817 	|    <br>5,4622 	|    <br>58,1949 	|    <br>945,3929    	|

# List Naudojo DT strategiją 
|          Testavimas          	|      1000     	|     10000     	|     100000    	|     1000000    	|      10000000      	|
|:----------------------------:	|:-------------:	|:-------------:	|:-------------:	|:--------------:	|:------------------:	|
|    <br>Failo nuskaitymas     	|    <br>0,0221 	|    <br>0,2454 	|    <br>2,454  	|    <br>26,8954 	|    <br>258,7851    	|
|    <br>Rušiavimas            	|    <br>0,0011 	|    <br>0,0103 	|    <br>0,1021 	|    <br>1,4678  	|    <br>208,6141    	|
|    <br>Sortinimas            	|    <br>0,001  	|    <br>0,0274 	|    <br>0,3867 	|    <br>5,2321  	|    <br>78,9612     	|
|    <br>Įrašymas į vargšiukus 	|    <br>0,0068 	|    <br>0,0594 	|    <br>0,6451 	|    <br>9,5751  	|    <br>112,1145    	|
|    <br>Sortinimas            	|    <br>0,0038 	|    <br>0,0467 	|    <br>0,5879 	|    <br>9,1574  	|    <br>97,8964     	|
|    <br>Įrašymas į kietiakus  	|    <br>0,0101 	|    <br>0,0894 	|    <br>1,05   	|    <br>14,712  	|    <br>141,7864    	|
|    <br>Bendras               	|    <br>0,0449 	|    <br>0,4786 	|    <br>5,2258 	|    <br>67,0398 	|    <br>898,1577    	|

