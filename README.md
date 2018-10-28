# C-code-Statistics
This is a project done for Compiler Construction course (in 2018) at Computer Science Department of Faculty of Mathematics, University of Belgrade in Serbia. 

Its general purpose is to preview some basic statistics of arbitrary C code. It is written in C++ in a day, contains ~850 lines of code.

## Description of Implementation
First, what we needed was a way to analyze and parse the input code. For that purpose, we used _flex_ and _bison_, respectively. What lexical analyzator (flex) generates, it passes it to parser generator (bison), which produces a parse tree. Using bison's grammar recognition and actions written in C++, we were able to create abstract synthax tree which knew when a variable was created, how many loops and branches were used in code and was the function declared before its definition. The output shows stats for every function, as well as information whether the function is recursive or not.

#### Note
This program does not recognize _every_ form of C code. The parser was written by hand in a few hours, so it goes without saying that it was impossible to write complete grammar; for example - structures, enumerators and the like. If you would like to test this program on your C file, chances are, you will be required to help our parser a bit by commenting out some 'problematic' lines of code.

## Requirements
* **g++** - Compiler system used for this project.  **clang++** works as well.
* **bison** / **yacc** - Parser generator used. bison recommended.
* **flex** / **lex** - Lexical analyzer generator used. Either one will work.
* **make** - Build automation tool

**To install _g++_ and _make_, run:**

```$ sudo apt-get install build-essential```


**To install _bison_ and _flex_, run:**

```$ sudo apt-get update ```

```$ sudo apt-get upgrade```

```$ sudo apt-get install flex bison```

## Usage
You can clone this project by executing this command:

```$ git clone https://github.com/ajvazz/C-code-Statistics.git```.

Navigate to newly created folder, then run _make_: 

`$ make`

To start the program, decide which C file to enter as input stream, and then run:

```$ ./parser < file.c```.

We have provided some random C code for a user as a quick demonstration on how this program works.

## Output

If there is a synthax error in the input stream, the user will be provided a short message to what was the problem and where the error occured. Either the C code intentionally had a synthax error or our parser was unable to recognize its grammar.
First things displayed are some basic stats about the code, and then info about each function used.

## Previous Version
This is a second version of this project. First one could recognize almost **every** form of C code, but since its grammar recognition was way too complex and was the same size of the complete second version, we had to sacrifice 'functionality' to compactness and readability.
It is worth saying that the second version works better and looks like the way we wanted it to look in the end. In the first one, it was almost impossible to add and calculate new stats, while in the second one, it can be easily added. Deadline stopped us from enriching it further.
