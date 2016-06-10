/* 
 * File:   Executable.h
 * Author: eneskilicaslan
 *
 * Created on December 21, 2015, 4:10 PM
 */

#ifndef EXECUTABLE_H
#define	EXECUTABLE_H


#include "File.h"

namespace kilicaslanFiles
{
    class Executable : public File
    {
    public:
        Executable();
        Executable(const string& theName, const string& theOwner,
                        const int theSize, const string& theTime,
                        const string& thePermission, const string& theCurrentPath,
                        const string& theCompiler);
        
        /***************** SEETER AND GETTER ************************/         
        void setCompiler(const string& theCompiler);
        string getCompiler() const;
        
        bool isDir() const;
       
        
        //virtual output  functions for ls command
        virtual void output() const;
        virtual void outputLong() const;
        
    private:
        string compiler;
    };
}

#endif	/* EXECUTABLE_H */

