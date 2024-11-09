TOY ROBOT PROGRAM

DIRECTORY STRUCTURE AND BUILD INSTRUCTIONS

The Code is compiled and build using g++ on MacOS (Apple clang version 16.0.0 (clang-1600.0.26.3))
C++ version 17.
All the include files are in "inc" folder and all the source files are in "src".
A simple Makefile is used and included to build the code.
Make version used is GNU Make 3.81.
When built successfully, binary name "Main" will be created in "bin" folder.
To build the code "make all" should be run in the top most directory (where README.txt is located).
The program has to be run from top most directory as the path for the input command file is hardcoded.
From the top most directory execute ./bin/Main to run the program.
The code is tested using a input Text file and from the command prompt.
The input text file is CommandFile.txt, present in the top most directory (where README.txt is located).
Main.cpp in the src folder is the entry point for the program.
Program can be made to take the input from console by
uncommenting line number 13 in the Main.cpp 
	"//pCmdReader = std::move(std::make_unique<ConsoleCommandReader>());"
and commenting line number 14 
	"pCmdReader = std::move(std::make_unique<FileCommandReader>(“CommandFile.txt"));"
The program keeps on reading a line from the input stream using getline function. So if the program is
made to read input from the console then either Ctrl+D or Ctrl+C should be pressed to stop it.
Ctrl+D signifies EOF for the input stream established using std::cin (standard input). The program logic
keeps on reading from the stream unless the EOF is reached.

DESIGN

Flexibility and Extendability were the main considerations while designing the overall application. Efforts are made to 
avoid tight coupling of as many classes and modules as possible. The composite pattern is used to capture behaviour of TableTop,
Canvas and Robot. Classes Table, Canvas and Robot are used to represent. The Table class carries instance of Canvas and 
acts as a container for all the components placed on top of the table. Robot is derived from the interface IObject to handle case
where there may arise a need to place more than one Robots on the Table or may be a Robot and a Toy Car. Also, the Canvas, 
which represents actual quadrant is introduced to make the design flexible allowing a possibility of placing more than one 
Canvas on the table, may be one for each of the 4 quadrants of the two dimensional geometric system. Reference of Canvas is
injected to Robot considering the fact that if more than one Robots are place then they can share the Canvas.
Things may become simpler if more restrictions/requirements are added regarding movement of the Robot. For eg, if more than one 
Robot are present then a Robot can not move to a position which is occupied by another Robot. 
Or some locations on the Canvas are not accessible to a Robot. Reference of the Canvas to Robot makes all the validations 
possible if required. Table class holding Robot and Canvas can in the future use Observer pattern if a there comes a need to 
handle more than once Canvases and Robots or other objects like a Toy Car.

To represent direction of the Robot, state pattern is used representing each of the 4 directions. Again, if there comes a need 
where Robot can move diagonally the State pattern can be extended to represent remaining 4 directions like 
“NORTH-EAST, NORTH-WEST” etc.

Command pattern is used to represent and handle commands. Which raised a need to implement hierarchy of CommandArgs class 
representing arguments for each command. 

To handle creating instances of Directions, Commands and CommandArgs, Factory Classes are implemented.

SysIO file contains helper classes which can be used to toggle between input streams (file and console).

Error handling is implemented using C++ exceptions.

A lot of comments are added to the code to explain the design idea and to explain the flow just to make it easy
to understand.

IMPROVEMENTS

There are a lot of things that can be improved to make the design better, like Error Handling in the code is very basic. 
Introduction of Logging can improve the error handling and even exception handling can be made better. Reporting bad 
commands, both in terms of invalid inputs and invalid flow can be reported. 
Factory patterns implemented can be improved by introducing a global or a singleton instance of Table, which will eliminate need of complex logic to pass input to commands, and hence improving Facotries. Program can 
be further modified to take input from both file and console and outputting to both file and console. 

CONCLUSION

Although, there is a scope of improvement in the design, but the current design does permit and allow a lot of flexibility and 
Extendability in terms of further requirements and improvements.

