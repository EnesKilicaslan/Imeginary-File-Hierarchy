#include "Executable.h"

using namespace std;

namespace kilicaslanFiles
{
    Executable :: Executable() : File()
    {
        setCompiler("gcc default");        
    }
    
    Executable :: Executable(const string& theName, const string& theOwner,
        const int theSize, const string& theTime,
        const string& thePermission, const string& theCurrentPath,
        const string& theCompiler)
            : File(theName, theOwner, theSize, theTime, thePermission,  theCurrentPath)
    {
        setPermission("-x");
        setCompiler(theCompiler);
    }
    
    void Executable :: setCompiler(const string& theCompiler)
    {
        compiler = theCompiler;
    }
    
    string Executable :: getCompiler() const
    {
        return compiler;
    }
    
    //Executable is not a directory
    bool Executable :: isDir() const
    {
        return false;
    } 
    
    void Executable :: output() const
    {
        cout << getName() + ".o" << endl; 
    }
    
    //print permission, name, owner, size and last modification time 
    void Executable :: outputLong() const
    {
        cout << getPermission() + " " + getName() + ".o "  + 
                getOwner() + " " <<  getSize() <<  " "  + getTime() << " "  + getCompiler() << endl;
    }
    
}

