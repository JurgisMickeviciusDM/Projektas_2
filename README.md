# PROJEKTAS_2


# V0.1 Versija:

Pirminė programos versija, šioje versijoje vartotojas gali pats įvesti duomenis arba nuskaityti duomenis iš failo. Išveda vardą, pavardę, galutinį vidurkį/ galutinį medianą(jie skaičiuojami pagal atitinkamas formules: Galutinins= 0.4*vidurkis/mediana+0.6*egzaminas

# V0.2 Versija:

Porgrama atlieka tą patį, kaip ir # V0.1 versija, tačiau yra patobulinta. Šioje V0.2 versijoje studentai suskirstomi į dvi grupes: "Vargšiukai" ir "Kietiakai". Vargšiukai yra tie, kurių galutinis balas yra <5, kietiakai yra tie, kurių balas galutinis yra >=5. Taip pa t6ioje versijoje atsiranda laiko/spartos matavimas, kuris parodo kiek kiekviename etape užtrukto programa.

# V0.3 Versija:

Programoje išlieka tie patys pakeitimai, kaip ir senose versijose,  tačiau esminis pakeitimas yra tas, kad mes analizuojame programos spartos analizę, kaip ji priklauso, jeigu vietoj  vector naudojame list, kas pasikeičia, šiuo atveju pastebiu, kad su mano testavimo įrenginiu atsiranda atminties trūkumas ir tenka naudoti SSD su 10000000 studentų sąrašu, nes kitaip užlūžta programa.

# V1.0 Versija:
# Paleidimas

1. Parsisiunčiame reikalingus failus iš GitHub.(Generavimasv1.cpp ; Naudotojasv1.cpp; Projektasv10.cpp;RUNMEE; CMakeLists; Generavimasv1; Naudotojasv1; Skaičiavimasv1; Studentasv1)
2. Visus cpp sudedame į folderį ,,src'':(Generavimasv1.cpp ; Naudotojasv1.cpp; Projektasv10.cpp)
   Header tipo failus ir studentu sąrašus sudėti į ,,Include" folderį:( Generavimasv1; Naudotojasv1; Skaičiavimasv1; Studentasv1)
   Atskirai prie folderių įsidedame ,,RUNMEE'' ir CMakeLists. Bendrai turi būti 4 atskiri failai/folderiai
   ![image](https://github.com/JurgisMickeviciusDM/Projektas1/assets/144474535/d2eb11ec-951f-4b87-a9ab-7cea818ba07b)

3.Paleidžiame Windows PoweShell
![image](https://github.com/JurgisMickeviciusDM/Projektas1/assets/144474535/4ce6cab1-534f-4644-ae29-3a8ee9ae9a9c)

4.Rašome  cmake -S . -B .\build
5.Rašome  cmake --build .\build
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


# V1.1
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

![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/d877c01f-f2fd-4ca0-a6b2-367701b56e52)
![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/68ddb570-eb26-48cf-9c88-ad0e02710c86)


# Vektorius Naudojo DT strategija naudojant klase studentas 
|          Testavimas          	|      1000      	|     10000     	|     100000    	|     1000000     	|      10000000      	|
|:----------------------------:	|:--------------:	|:-------------:	|:-------------:	|:---------------:	|:------------------:	|
|    <br>Failo nuskaitymas     	|    <br>0,017   	|    <br>0,2541 	|    <br>2,754 	|    <br>28,7546 	|    <br>289,54    	|
|    <br>Rušiavimas            	|    <br>0,0024  	|    <br>0,0247	|    <br>0,2745	|    <br>3,456  	|    <br>190,5652     	|
|    <br>Sortinimas            	|    <br>0,0023  	|    <br>0,0145 	|    <br>0,1456	|    <br>1,387  	|    <br>13,5546    	|
|    <br>Įrašymas į vargšiukus 	|    <br>0,009   	|    <br>0,056 	|    <br>0,3784 	|    <br>4,512  	|    <br>40,3541   	|
|    <br>Sortinimas            	|    <br>0,0101 	|    <br>0,0,074	|    <br>0,487 	|    <br>3,7981 	|    <br>90,613    	|
|    <br>Įrašymas į kietiakus  	|    <br>0,0014   	|    <br>0,105 	|    <br>1,345	|    <br>11,2253  	|    <br>158,1132    	|
|    <br>Bendras               	|    <br>0,0422 	|    <br>0,4543	|    <br>5,3845 	|    <br>53,133	|    <br> 782,7401  	|

![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/6cc20ff5-5d87-4a8e-8129-597ef7ba2489)

![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/9d26fff2-98fa-4bcb-b7fe-e129f1204c2c)

# Išvada DT vektorius klasė ir struktūra
Atlikus testavimus su vektorius DT ir vektorius DT klasė studentas, buvo pastebėta, kad su klase vektorius DT žymiai paspartino rūšiavimą ir įrašymą į failus, greitis padidėjo beveik dvigubai, kaip pvz 100000 su vektorius DT 114,5434s, tuo tarpu vektorius DT klasė 53,133.


# Vektorius su  flag'ais O1, O2, O3:  
|          Testavimas          	|      o1_100000      	|     o2_100000     	|     o3_100000   	|      o1_1000000      	|     o2_1000000     	|     o3_1000000  |
|:----------------------------:	|:--------------:      	|:-------------:	   |:-------------:	   |:---------------:	   |:------------------:	|:------------------: |
|    <br>Failo nuskaitymas     	|    <br>2,4561 	      |    <br>2,3478 	   |    <br>2,3615 	   |    <br>22,941	   |    <br>21,9641   	| <br>22,6164  |
|    <br>Rušiavimas            	|    <br>0,3841 	      |    <br>0,3948	   |    <br>0,3415 	   |    <br>3,5441  	   |    <br>3,9145      |<br>3,2365   	|
|    <br>Sortinimas            	|    <br>0,2841 	      |    <br>0,2654 	   |    <br>0,2941	   |    <br>3,7512	   |    <br>3,9841    	|<br>3,6462    	|
|    <br>Įrašymas į vargšiukus 	|    <br>0,6465        	|    <br>0,6891	   |    <br>0,6156	   |    <br>6,9402  	   |    <br>6,9841   	|<br>6,8560   	|
|    <br>Sortinimas            	|    <br>0,4912      	|    <br>0,4648	   |    <br>0,4925  	   |    <br>8,1973 	   |    <br>5,9414   	|<br>5,7951    	|
|    <br>Įrašymas į kietiakus  	|    <br>1,0097 	      |    <br>0,9761	   |    <br>0,9364    	|    <br>14,3450	   |    <br>10,6910    	|<br>10,1057    	|
|    <br>Bendras               	|    <br>5,2717 	      |    <br>5,138 	   |    <br>5,0416 	   |    <br>59,7188 	   |    <br>49,5647    	|<br>49,0194  	|

|          Failas          	|      Failo dydis exe      	|   
|:----------------------------:	|:--------------:      	|
|    <br>Failo dydis "DEBUG" O1 	  |  <br> 504KB  |
|    <br>Failo dydis "DEBUG"  O2	  |  <br> 533KB  |
|    <br>Failo dydis "DEBUG"  O3	  |  <br> 533KB  |


# Su O1 100000 ir 1000000
![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/ed527970-5d7c-47fa-bdf8-30bbfaa72a58)

# Su O2 100000 ir 1000000
![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/1ce8a23d-6df2-4626-a223-08b5d8fe8777)

# Su O3 100000 ir 1000000
![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/9c73d51b-c2f1-493c-b853-4323a68bdf6e)
# Išvada O1, O2, O3
Atlikus matavimus su skirtingais flag'ais O1, O2, O3 ir paskaičiavus 5 paleidimų vidurkius gavome vidurkius. Galmie pastebėti, kad greičiausiai dirbo O3. Vertinannt greitį galime daryti išvadas, kad su vektoriumi vidutiniškai 1,48% greičiau O3 veikė negu O2 ir O1. 

# Vektorius su klase ir flag'ais O1, O2, O3: 
|          Testavimas          	|      o1_100000      	|     o2_100000     	|     o3_100000   	|      o1_1000000      	|     o2_1000000     	|     o3_1000000  |
|:----------------------------:	|:--------------:      	|:-------------:	   |:-------------:	   |:---------------:	   |:------------------:	|:------------------: |
|    <br>Failo nuskaitymas     	|    <br>2,6954   	      |    <br>2,7854 	   |    <br>2,6875 	   |    <br>24,745 	   |    <br>28,7843    	|   <br>26,0377  |
|    <br>Rušiavimas            	|    <br>0,2871 	      |    <br>0,2451	   |    <br>0,2015 	   |    <br>2,7884  	   |    <br>2,2874      |<br>2,2356   	|
|    <br>Sortinimas            	|    <br>0,1032  	      |    <br>0,0822 	   |    <br>0,0829	   |    <br>1,1407	   |    <br>0,899    	|<br>0,9497    	|
|    <br>Įrašymas į vargšiukus 	|    <br>0,3894         	|    <br>0,4587	   |    <br>0,3254	   |    <br>3,8991  	   |    <br>3,7810   	|<br>3,736   	|
|    <br>Sortinimas            	|    <br>0,3995       	|    <br>0,3874 	   |    <br>0,2971  	   |    <br>3,1045 	   |    <br>3,201   	|<br>3,1945    	|
|    <br>Įrašymas į kietiakus  	|    <br>1,087  	      |    <br>1,075 	   |    <br>1,0056    	|    <br>10,7451 	   |    <br>9,6933    	|<br>9,6641    	|
|    <br>Bendras               	|    <br>4,9616 	      |    <br>5,0338 	   |    <br>4,6 	   |    <br>46,4228 	   |    <br>46,3586    	|<br>43,582  	|

|          Failas          	|      Failo dydis exe      	|   
|:----------------------------:	|:--------------:      	|
|    <br>Failo dydis "DEBUG" O1 	  |  <br> 291KB  |
|    <br>Failo dydis "DEBUG"  O2	  |  <br> 309KB  |
|    <br>Failo dydis "DEBUG"  O3	  |  <br> 309KB  |


# Su O1 100000 ir 1000000
![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/6f2d1f49-c693-4d58-a311-ea028c0300f6)
# Su O2 100000 ir 1000000
![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/1324ecf9-2c17-40e6-95bd-57bf28d8f4d5)
# Su O3 100000 ir 1000000
![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/8d920694-cce9-4958-a3c1-59f0c2244686)
# Išvada O1, O2, O3
Atlikus 5 matavimus ir išvedus vidurkį matavimų su flag'ais klasėje pastebėta, kad O1 ir O2 laikas atlikimo yra lygiai tas pats, tačiau su O3 greitis padidėja apie 6.5%, o tai yra reikšmingas laiko sumažėjimas, nes kuo didesnis failas, duomenų kuo daugiau, tuo greičiua vyks darbas su duomenimis, failu.

# Apibendrinimas klasės ir struktūros O1, O2, O3
Atlikus matavimus ir išvedus vidurkius buvo pastebėta, kad su kalse programa veikia greičiausiai, skirtumas taikant O3 flag'ą skiriasi nedaug, bet vertinant didžiausią failą matavime 1000000, pastebime, kad sparta išauga 11,1%, o tai naudotojui yra svarbu, nes sutaupo laiko. 

# V1.2

Toliau yra tęsiama užduotis, šiuo atveju, aš sukuriu "Rule of three", taip pat įvesties ir išvesties operatorius(nuotraukos žemiau):
# klasė:
![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/a2a17a02-3d71-495d-a068-caa04cd10e5f)
# Operatorius įvesties: 
Įvesties operatoriuspanaudotas pagrindinai su rankiniu būdu, kadangi tai fiksuota ir pvz. duomenys esantis faile nereikalauja papildomo įvedimo, kaip vardas, pavardė ir kiti parametrai.
![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/841e3fb9-9c0b-4985-8eb7-ef9d37c9757f)
![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/c17c81c7-6497-4595-b94c-d223bc471dac)
# Operatorius išvesties:
![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/831f08a4-09f7-46b9-a01c-7c64ae359da0)
# Operatorių panaduojiams main'e ir savetofileV funkcijoje:
![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/3cad3c8f-26fd-4f9d-a422-2595c28727a4)
![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/3b1857ee-d162-4bf5-9dd6-5c580a4c0a2e)
![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/65f84372-88c4-48cc-b027-2b7be6e6ae39)
Taigi V1.2 sukuriame operatorius įvesties ir išvesties, juos pritaikome avo kode, jį patobuliname ir pakeičiame, kad viskas veiktų, taip pat galioja taisyklė "Rule of three", kuri reiškia, jog turi būti that kopijavimo konstruktorius,  copy assignment operatorius ir destruktorius.

# V1.5
Buvo sukurta vietoj turimos v1.2 versijos studento klasės dvi klasės, tai yra abstrakti klasė "Zmogus", kurioje yra pateikiama pagrindinė informacija vardas ir pavarde. Taip pat buvo suksurta išvestinė klasė Studentas. Programos esminės vietos išliko nepakitusios labai, toliau išliko "Rule of three", pagrindiniame kode "Projektasv25.cpp" išliko įvesties ir išvesties operatoriai, kaip ir v1.2 versijoje.
# Esminė kodo vieta abstrakti klasė "Zmogus" ir išvestinė klasė "Studentas"
![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/74507a8a-843e-434d-90c9-56a2d69e58a2)
![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/777525a0-5d96-433f-a589-9382e145ceeb)
# Kodo vieta, kuri demonstruoja, kad realizuotos abstrakčios klasė Zmogus(jos objektų kūrimas negalimas)
![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/b31f19da-db5d-422c-ab21-ac7230d1e789)
![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/9d242a05-141c-48f2-8384-93c17765fd65)
# Užkomentavus zmogus laikinas, programa veikia, kadangi nėra bandoma realizuoti abstrakčios klasės objektų
![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/9e4849e3-5b2f-46de-a197-6ceb22ade74b)  

# V3.0
Sukuriama galutinė versija, kurioje galima įsidiegti exe tipo failą į kompiuterį. Žemiau bus pateikta eiga.
1. Spaudžiate ant ,,Setupas" ir vykdome visus veiksmsu iš eilės.
![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/d22bad87-4ba4-4b26-97a9-c70686114ffe)
![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/dbe298ed-2ad3-43f0-ac4c-32c8f98d0738)
![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/35090d95-5f1e-45af-bbfa-ddc60ee8c08b)
![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/83ae7eb4-ac43-42cc-8e21-98dce5022ea4)
![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/3d09a5e2-2185-49b7-afa6-0f4a5717e7a7)


2. Atsiranda ikona:
   ![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/a034bbf4-e7da-467a-b886-1e872d07de8d)
![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/01ae0d3c-542f-434e-a7f0-9f914dd57a19)
3. Darbalaukyje
   ![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/caace696-c0d2-4b46-b6a2-ab090542cb40)
4. Jeigu norime galime pašalinti
![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/14a531d2-7758-4e47-9ba2-4e4a91165d29)
![Uploading image.png…]()
Kuriant vaizdas:
![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/03cd639a-9e5b-4811-80c4-47c01881c02f)
Po build 
![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/8512cbc9-695b-4b29-ac98-83b0c5c7fee6)
![image](https://github.com/JurgisMickeviciusDM/Projektas_2/assets/144474535/dfd75d58-af7e-4029-af66-aaf65519a50e)




