@ECHO OFF
BREAK>> RUNMEE.txt
ECHO cmake CMakeLists.txt >> RUNMEE.txt
ECHO cmake --install . >> RUNMEE.txt
ECHO cmake --build . >> RUNMEE.txt
ECHO copy src\studentai1000.txt Debug\studentai.txt >> RUNMEE.txt
ECHO Debug\Projektas_2_0.exe >> RUNMEE.txt