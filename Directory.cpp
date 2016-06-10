#include "Directory.h"
#include "File.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace kilicaslanFiles
{
    Directory :: Directory() : File()
    {
        //Body intentionally empty
    }
    
    Directory :: Directory(const string& theName, const string& theOwner,
        const int theSize, const string& theTime, 
        const string& thePermission, const string& theCurrentPath) 
            : File(theName, theOwner, theSize, theTime, thePermission, theCurrentPath)
    {
        //Body intentionally empty
    }
    
    bool Directory :: cp( File& other)
    {
        for(int i=0; i<files.size(); i++)
            if(files[i]->getName() == other.getName())//check if the same file name already exist
                return false;
            
        
        files.push_back(&other);
        other.addToPath((*this).getName());
        
        return true;
    }
    
    void Directory :: ls(const string listType) 
    {
        if(files.size() < 1)//if the directory is empty don't go to loop
            return;
                                     
        for(int i=0; i<files.size(); i++)
        {
            
            if(listType == " ")//just name of the file
                files[i]->output();
            
            else if(listType == "l")//long form of the file output
                files[i]->outputLong();
            
            else if(listType == "R") //recursive function 
            {               
                if(files[i]->isDir())
                {
                    files[i]->output(); //just name
                    files[i]->ls("R");                   
                }
                else
                    files[i]->output();
            }
            
            else if(listType == "Rl" || listType == "lR") //recursive function 
            {               
                if(files[i]->isDir())
                {
                    files[i]->outputLong(); //long output because of "l" in "lR"
                    files[i]->ls("Rl");                   
                }
                else
                    files[i]->outputLong();
            }
            else
            {
                cout << "Error!... Wrong usage of ls parameters " << endl;
                return;
            }
        }
        
    }
    
    File& Directory :: cd( File& other )
    {               
        //if this is not a directory
        if(other.isDir() == false)
            cerr << "This is not a directory" << endl;     
        
        //change the directory
        else
        {
            Directory * temp;
            temp = dynamic_cast<Directory *> (&other);
            
            setName(other.getName());
            setOwner(other.getOwner());
            setSize(other.getSize());
            setTime(other.getTime());
            
            files = temp->files;                       
        } 
        
        return *this;
    }
    
    void Directory :: output() const
    {
        cout << getName() << endl; 
    }
    
    //print permission, name, owner, size and last modification time 
    void Directory :: outputLong() const
    {
        cout << getPermission() + " " + getName() + " "  + 
                getOwner() + " " <<  getSize() <<  " "  + getTime() << endl;
    }
}


