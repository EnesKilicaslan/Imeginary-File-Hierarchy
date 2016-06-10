/* 
 * File:   Directory.h
 * Author: eneskilicaslan
 *
 * Created on December 21, 2015, 2:15 PM
 */

#ifndef DIRECTORY_H
#define	DIRECTORY_H

#include "File.h"
#include <vector>

using namespace std;

namespace kilicaslanFiles
{
    class Directory : public File
    {
    public:
        Directory();
        Directory(const string& theName, const string& theOwner, 
                    const int theSize, const string& theTime,
                    const string& thePermission, const string& theCurrentPath);
                
        bool cp(File& other);
        virtual void ls(const string listType = " ");    
        File& cd(File& other); 
    
        bool isDir() const { return true;} //this is a directory
        
        //virtual output  functions for ls command
        virtual void output() const;
        virtual void outputLong() const;
        
    private:        
        vector<File *> files; 
        
    };
}

#endif	/* DIRECTORY_H */

