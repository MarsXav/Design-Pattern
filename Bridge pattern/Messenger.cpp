//
// Created by Dell on 2023/1/17.
//

#include "Messenger.h"

class PCMessengerImp : public MessengerImp{
public:
    virtual void PlaySound(){}
    virtual void DrawShape(){}
    virtual void WriteText(){};
    virtual void Connect(){};

};

class MessengerLite : public Messenger{
//    MessengerImp* messengerImp; // declare as pointer to realise polymorphism
public:
    virtual void Login(string username, string password){
        messengerImp->Connect();
    }
    virtual void SendMessage(string message){
        messengerImp->WriteText();
    }
};

class MobileMessengerImp : public MessengerImp{
public:
    virtual void PlaySound(){}
    virtual void DrawShape(){}
    virtual void WriteText(){};
    virtual void Connect(){};
};

class MobileMessenger : public Messenger{
//    MessengerImp* messengerImp; // declare as pointer to realise polymorphism
public:
    MobileMessenger(MessengerImp* messengerImp) : Messenger(messengerImp){}
    virtual void Login(string username, string password){
        messengerImp->Connect();
    }
    virtual void SendMessage(string message){
        messengerImp->WriteText();
    }
};

void MessengerImp::Process() {
    MessengerImp* Imp = new MobileMessengerImp();
    Messenger* m = new Messenger(Imp);
    m->SendMessage("Hello");
    m->Login("abc", "abc");
}


