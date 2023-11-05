# PROJEKTAS_1 

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
# Vektorius Naudojo S strategija  
Ekrano kopijos su visais laikais yra suagomos atskirame pdf faile, kuris yra patalpintas GitHub sistemoje prie failų ,,[Atminties matavimai su List Vektor ir S,D,DT strategijomis.pdf](https://github.com/JurgisMickeviciusDM/Projektas1/files/13259074/Atminties.matavimai.su.List.Vektor.ir.S.D.DT.strategijomis.pdf) "


| Testavimas             	| 1000      	| 10000  	| 100000 	| 1000000 	| 10000000 	|
|-----------------------	|-----------	|--------	|--------	|---------	        |----------  	|
| Failo nuskaitymas     	| 0,0283	| 0,1234 	| 1,9592 	| 22,5653   	| 266,2980 	|
| Rušiavimas            	| 0,0016    	| 0,0254	| 0,2232 	| 2,4963  	        | 24,0170 	|
| Įrašymas į vargšiukus 	| 0,0008    	| 0,0712 	| 0,6827 	| 6,9926    	| 65,4676  	|
| Įrašymas į kietiakus  	| 0,0028   	| 0,1769 	| 1,9491 	| 19,7519  	| 170,4570 	|
| Bendras               	        | 0,0335 	| 0,3966	| 4,8142 	| 45,5061 	        | 526,2396 	|



![Ekrano nuotrauka 2023-10-25 215531](https://github.com/JurgisMickeviciusDM/Projektas1/assets/144474535/c1b74400-7a5f-4fc1-b927-c3a219978b30)

# List
Su list labai prailgėjo 10milijonų failo veikimas, nes teko naudoti SSD, kadangi atminties neužteko RAM
![Ekrano nuotrauka 2023-10-26 005122](https://github.com/JurgisMickeviciusDM/Projektas1/assets/144474535/3e34be52-927a-497c-8719-9aa68a7ed374)
![Ekrano nuotrauka 2023-10-26 004900](https://github.com/JurgisMickeviciusDM/Projektas1/assets/144474535/8e88139f-bd12-4b84-b78e-925ebcd6b0b8)

| Testavimas             	| 1000      	| 10000  	| 100000 	| 1000000 	| 10000000 	|
|-----------------------	|-----------	|--------	|--------	|---------	        |----------  	|
| Failo nuskaitymas     	| 0,0425	| 0,3101 	| 3,2343	| 34,5764   	| 356,2980 	|
| Rušiavimas            	| 0,0016    	| 0,0485	| 0,5121 	| 6,2363  	        | 434,0254	|
| Įrašymas į vargšiukus 	| 0,0084    	| 0,0512 	| 0,5332 	| 4,6426    	| 56,4176  	|
| Įrašymas į kietiakus  	| 0,0094   	| 0,0799 	| 0,6732 	| 7,6319  	| 70,4570 	|
| Bendras               	        | 0,0619 	| 0,4897	| 4,9528 	| 52,0872 	        | 917,1971 	|
