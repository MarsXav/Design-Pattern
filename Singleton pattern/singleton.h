//
// Created by Dell on 2023/1/23.
//

#ifndef SINGLETON_PATTERN_SINGLETON_H
#define SINGLETON_PATTERN_SINGLETON_H

#include <bits/stdc++.h>
#include <mutex>
#include <thread>

class Singleton{
private:
    Singleton();
    Singleton(const Singleton& S);

public:
    static Singleton* getInstance();
    static std::atomic<Singleton*> m_instance;
    static std::mutex m_mutex;
};

// to prevent REORDER during compiling when using double-check lock, the following actions are suggested
Singleton* Singleton::getInstance() { // unsafe under multi thread scenario
    Singleton* tmp = m_instance.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire); // obtain memory fence
    if (tmp == nullptr){
        std::lock_guard<std::mutex> lock(m_mutex);
        tmp = m_instance.load(std::memory_order_relaxed);
        if (tmp == nullptr){
            // Order: Allocate memory -> Constructor -> Assign variable
            tmp = new Singleton();
            std::atomic_thread_fence(std::memory_order_release); // release memory fence
            m_instance.store(tmp, std::memory_order_relaxed);
        }
    }
    return tmp;
}


#endif //SINGLETON_PATTERN_SINGLETON_H
