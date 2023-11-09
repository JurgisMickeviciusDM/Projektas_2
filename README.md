# PROJEKTAS_1 
# Paleidimas

-----
-----

# Reikalavimai

# Parametrai 

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
S-
D-
DT-
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
|          Testavimas          	|      1000     	|     10000     	|     100000     	|     1000000     	|      10000000      	|
|:----------------------------:	|:-------------:	|:-------------:	|:--------------:	|:---------------:	|:------------------:	|
Failo nuskaitymas	0,0311	0,241	2,489	25,4014	278,5874
					
Rušiavimas	0,0017	0,0117	0,1174	1,212	194,5896
					
Sortinimas	0,002	0,0295	0,3465	4,7321	60,551
					
Įrašymas į vargšiukus	0,0085	0,0623	0,7741	7,9542	105,8452
					
Sortinimas	0,0034	0,0432	0,6512	7,14	129,5645
					
Įrašymas į kietiakus	0,0103	0,094	1,084	11,7552	176,2552
					
Bendras	0,057	0,4817	5,4622	58,1949	945,3929
					
![image](https://github.com/JurgisMickeviciusDM/Projektas1/assets/144474535/a009d977-f0b0-4ce9-a8a9-55dd215fd785)


# List Naudojo DT strategiją 
|          Testavimas          	|      1000     	|     10000     	|     100000     	|     1000000     	|      10000000      	|
|:----------------------------:	|:-------------:	|:-------------:	|:--------------:	|:---------------:	|:------------------:	|
|    <br>Failo nuskaitymas     	|    <br>0,001  	|    <br>0,1634 	|    <br>2,1478  	|    <br>22,5653  	|    <br>235,5489    	|
|    <br>Rušiavimas            	|    <br>0,0016 	|    <br>0,0254 	|    <br>0,2232  	|    <br>2,4963   	|    <br>105,8744    	|
|    <br>Sortinimas            	|    <br>0,005  	|    <br>0,08   	|    <br>1,254   	|    <br>16,8954  	|    <br>210,594     	|
|    <br>Įrašymas į vargšiukus 	|    <br>0,0115 	|    <br>0,1014 	|    <br>1,745   	|    <br>22,9546  	|    <br>248,6545    	|
|    <br>Sortinimas            	|    <br>0,0174 	|    <br>0,1345 	|    <br>2,4579  	|    <br>30,8746  	|    <br>289,5456    	|
|    <br>Įrašymas į kietiakus  	|    <br>0,017  	|    <br>0,2454 	|    <br>3,2478  	|    <br>32,5475  	|    <br>338,5616    	|
|    <br>Bendras               	|    <br>0,0535 	|    <br>0,7501 	|    <br>11,0757 	|    <br>128,3337 	|    <br>1428,779    	|

