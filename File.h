/* 
 * File:   File.h
 * Author: eneskilicaslan
 *
 * Created on December 21, 2015, 1:44 PM
 */
#ifndef FILE_H
#define	FILE_H

#include <iostream>
#include <string>

using namespace std;

namespace kilicaslanFiles
{   
    //this class is an abstract class
    //Copy constructor, assignment operator, destructor are OK!
    class File 
    {
    public:           
        File();
        
        File(const string& theName, const string& theOwner,
                const int theSize, const string& theTime,
                const string& thePermission, const string& theCurrentPath);

        
        /***************** SEETER AND GETTER FUNCTIONS ************************/         
        void setName(const string& newName);
        string getName() const;
        
        void setOwner(const string& newOwner);
        string getOwner() const;
        
        void setSize(const int newSize);
        int getSize() const;
        
        void setTime(const string& newTime);
        string getTime() const;       
        
        void setPermission(const string& newTime);
        string getPermission() const;   
        
        void setPath(const string& newPath);
        /***************** END OF SETTERS AND GETTERS **************************/
                
        string path() const; 
        virtual void ls(const string listType = " ");        
        virtual File& cd(const File& other);
        bool cp(File& other);
                
        void addToPath(const string& addString);
        virtual bool isDir() const;
        
        //virtual output  functions for ls command
        virtual void output() const = 0;
        virtual void outputLong() const = 0;
        
    private:        
        string name;
        string owner;
        int size;       
        string lastMTime; // may be d time library
        
        string permission; //w, x, r permission
        string currentPath;   
    };
}



#endif	/* FILE_H */

