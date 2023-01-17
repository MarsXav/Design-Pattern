//
// Created by Dell on 2023/1/17.
//

#ifndef BRIDGE_PATTERN_MESSENGER_H
#define BRIDGE_PATTERN_MESSENGER_H

#include <bits/stdc++.h>
using namespace std;

class MessengerImp;

class Messenger {
protected:
    MessengerImp* messengerImp;
public:
    explicit Messenger(MessengerImp* Imp) : messengerImp(Imp){}
    virtual void Login(string username, string password) = 0;
    virtual void SendMessage(string message) = 0;
    virtual ~Messenger()= default;
};

class MessengerImp{
public:
    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriteText() = 0;
    virtual void Connect() = 0;
    virtual void Process();

    virtual ~MessengerImp()= default;
};






#endif //BRIDGE_PATTERN_MESSENGER_H
