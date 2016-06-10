/* 
 * File:   main.cpp
 * Author: eneskilicaslan
 *         141044088
 *
 * Created on December 21, 2015, 1:43 PM
 */

#include <cstdlib>
#include "Directory.h"
#include "File.h"
#include "Executable.h"
#include "TextFile.h"


using namespace std;
using namespace kilicaslanFiles;

int main(int argc, char** argv) 
{
    //Creating directories
    Directory Root("root", "computer", 22000, "00:00", "-wrx", "/" );
    Directory A("A", "eneskilicaslan", 10, "01:20", "-wrx", "/" );
    Directory C("C", "eneskilicaslan", 50, "12:55", "-wrx", "/" );
    Directory B("B", "eneskilicaslan", 50, "05:50", "-rx", "/" );
    
    
    Executable exe1("Exe1", "enes", 5400, "12.30", "-x", "/", "g++");
    TextFile note1("Mynote1", "enes", 21000, "10:45", "-wrx", "/", "some text inside of the text file");
    
    Executable exe2("Exe2", "enes", 3330, "01.30", "-x", "/", "gcc");
    TextFile note2("Mynote2", "enes", 100, "20:45", "-wr", "/", "again some text inside of the text file");
        
    //copying exe and note to the directory A
    A.cp(note1);
    A.cp(exe1);
    
    cout << endl << "Now A.ls is working" << endl << endl;
    
    A.ls(); //this is short form of ls
    
    B.cp(A);
    C.cp(B);
    
    C.cp(exe2);
    C.cp(note2);
    
    
    cout << endl << endl << "Now C.ls  is working" << endl << endl;
    
    //C includes:
    //directory A which includes note1 and exe1
    //directory B which includes directory A
    //exe2
    //note2
    C.ls("Rl"); //long and recursive form of output
    
    
    
    cout << endl << endl << "Changing directory" << endl << endl;
    //now C is directory A
    C.cd(A);
    C.ls("l"); //long form of ls
    
    
    
    
    return 0;
}

