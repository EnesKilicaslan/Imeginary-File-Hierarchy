/* 
 * File:   TextFile.h
 * Author: eneskilicaslan
 *
 * Created on December 21, 2015, 4:42 PM
 */

#ifndef TEXTFILE_H
#define	TEXTFILE_H

#include "File.h"

namespace kilicaslanFiles
{
    class TextFile : public File
    {
    public:
        TextFile();
        TextFile(const string& theName, const string& theOwner,
                        const int theSize, const string& theTime,
                        const string& thePermission, const string& theCurrentPath,
                        const string& someText);
        
        /***************** SEETER AND GETTER ************************/         
        void setText(const string& theCompiler);
        string getText() const;
        /************** END OF SEETER AND GETTER *********************/ 
        
        
        bool isDir() const;
        
        
        //virtual output  functions for ls command
        virtual void output() const;
        virtual void outputLong() const;
        
    private:
        string text;
    };
}


#endif	/* TEXTFILE_H */

