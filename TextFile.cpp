#include "TextFile.h"

using namespace std;

namespace kilicaslanFiles
{
    TextFile :: TextFile() : File()
    {
        setText("This text file is really important");// some text here        
    }
    
    TextFile :: TextFile(const string& theName, const string& theOwner,
        const int theSize, const string& theTime,
        const string& thePermission, const string& theCurrentPath,
        const string& theText)
            : File(theName, theOwner, theSize, theTime, thePermission,  theCurrentPath)
    {
        setText(theText);
    }
    
    void TextFile :: setText(const string& theText)
    {
        text = theText;
    }
    
    string TextFile :: getText() const
    {
        return text;
    }
    
    //Text file is not a directory
    bool TextFile :: isDir() const
    {
        return false;
    } 
    
    void TextFile :: output() const
    {
        cout << getName() << endl; 
    }
    
    //print permission, name, owner, size and last modification time 
    void TextFile :: outputLong() const
    {
        cout << getPermission() + " " + getName() + ".txt "  + 
                getOwner() + " " <<  getSize() <<  " "  + getTime() << endl;
    }
    
}


