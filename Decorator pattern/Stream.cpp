//
// Created by Dell on 2023/1/16.
//

#include "Stream.h"

class FileStream : public Stream{
public:
    virtual char Read(int number){return '0';} //read file stream
    virtual void Seek(int position) {return;} //seek file stream
    virtual void Write(size_t data) {return;} //write file stream
};

// expansion operation
class DecoratorStream : public Stream{
public:
    DecoratorStream(Stream* stm) : stream(stm){}
protected:
    Stream* stream;
};

class CryptoStream : public DecoratorStream{ // inherit to complete virtual functions
public:
    CryptoStream(Stream* stm) : DecoratorStream(stm){}
    virtual char Read(int number) {
        /*
         * Additional encryption
         */
        stream -> Read(number); // read file stream
    }
    virtual void Seek(int position){
        /*
         * Additional encryption
         */
        stream -> Seek(position);
    }
    virtual void Write(size_t data) {
        /*
        * Additional encryption
        */
        stream ->Write(data);
    }
};

class BufferStream : public DecoratorStream{
public:
    BufferStream(Stream* stm) : DecoratorStream(stm){}
    virtual char Read(int number) {
        /*
         * Additional encryption
         */
        stream -> Read(number); // read file stream
    }
    virtual void Seek(int position){
        /*
         * Additional encryption
         */
        stream -> Seek(position);
    }
    virtual void Write(size_t data) {
        /*
        * Additional encryption
        */
        stream ->Write(data);
    }
};

void Stream::Process(){
    FileStream* fs = new FileStream();
    CryptoStream* cs = new CryptoStream(fs);
    BufferStream* bs = new BufferStream(cs);
}


