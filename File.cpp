#include "File.h"
#include <iostream>
#include <string>


using namespace std;

namespace kilicaslanFiles
{   
    
 
    File :: File()
    {
        setName("name");
        setOwner("owner");
        setSize(0);
        setTime("00:00");
        setPermission("-r");
        setPath("root/");
    }


    File :: File(const string& theName, const string& theOwner,
            const int theSize, const string& theTime,
            const string& thePermission, const string& theCurrentPath)
    {
        name = theName;
        owner = theOwner;
        size = theSize;
        lastMTime = theTime;
        permission = thePermission;
        currentPath = theCurrentPath;            
    }


    /***************** SEETER AND GETTER FUNCTIONS ************************/        
    void File :: setName(const string& newName)
    {
        name = newName;
    }

    string File :: getName() const
    {
        return name;
    }

    void File :: setOwner(const string& newOwner)
    {
        owner = newOwner;
    }

    string File ::getOwner() const
    {
        return owner;
    }

    void File ::setSize(const int newSize)
    {
        size = newSize;
    }

    int File :: getSize() const
    {
        return size;
    }

    void File :: setTime(const string& newTime)
    {
        lastMTime = newTime;
    }

    string File :: getTime() const
    {
        return lastMTime;
    }   

    void File :: setPermission(const string& newPermission)
    {
        permission = newPermission;
    }

    string File :: getPermission() const
    {
        return permission;
    }       

    void File :: setPath(const string& newPath)
    {
        currentPath = newPath;
    }
    /***************** END OF SETTERS AND GETTERS **************************/


    string File :: path() const
    {
        return currentPath;
    }

    void File :: ls(const string listType )
    {
        cerr << "-bash.... This is not a directory" << endl;
    }        

    File& File ::cd(const File& other)
    {
        cerr << "-bash.... This is not a directory" << endl;
        return *this;
    }

    bool File :: cp(File& other)
    {
        cerr << "-bash.... This is not a directory" << endl;
        return false;
    }

    void File :: addToPath(const string& addString)
    {           
        setPath(path() + addString);
    }
    
    //Actually we can not create an object of this class 
    //But in either way, this is not a directory
    bool File :: isDir() const
    {
        return false;
    }      
    
    //print name
    void File :: output() const
    {
        cout << getName() << endl; 
    }
    
    //print permission, name, owner, size and last modification time 
    void File :: outputLong() const
    {
        cout << getPermission() + " " + getName() + " "  + 
                getOwner() + " " <<  getSize() <<  " "  + getTime() << endl;
    }
    
}

