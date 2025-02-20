 *  Executing task: C/C++: g++ build active file 

Starting build...
/usr/bin/g++ -fdiagnostics-color=always -std=c++11 -g '/home/ojimenbl7.alumnes/Escriptori/Estructura-de-Dades/Pràctica 1/Excercici3/mainExercici3.cpp' -o '/home/ojimenbl7.alumnes/Escriptori/Estructura-de-Dades/Pràctica 1/Excercici3/mainExercici3'
/usr/bin/ld: /tmp/ccfiPbDs.o: en la función `informarEstudiant(std::vector<Estudiant, std::allocator<Estudiant> >&)':
/home/ojimenbl7.alumnes/Escriptori/Estructura-de-Dades/Pràctica 1/Excercici3/mainExercici3.cpp:19: referencia a `Estudiant::Estudiant(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, int, int)' sin definir
/usr/bin/ld: /home/ojimenbl7.alumnes/Escriptori/Estructura-de-Dades/Pràctica 1/Excercici3/mainExercici3.cpp:21: referencia a `Estudiant::print()' sin definir
/usr/bin/ld: /tmp/ccfiPbDs.o: en la función `void std::_Construct<Estudiant>(Estudiant*)':
/usr/include/c++/12/bits/stl_construct.h:119: referencia a `Estudiant::Estudiant()' sin definir
collect2: error: ld returned 1 exit status

Build finished with error(s).

 *  The terminal process failed to launch (exit code: -1). 
 *  Terminal will be reused by tasks, press any key to close it. 
