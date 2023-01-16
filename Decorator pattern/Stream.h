//
// Created by Dell on 2023/1/16.
//

#ifndef DECORATOR_PATTERN_STREAM_H
#define DECORATOR_PATTERN_STREAM_H

#include <bits/stdc++.h>

class Stream {
public:
    virtual char Read(int number) = 0;
    virtual void Seek(int position) = 0;
    virtual void Write(size_t data) = 0;

    virtual ~Stream() = default;

    void Process();
};



#endif //DECORATOR_PATTERN_STREAM_H
