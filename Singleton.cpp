#include "Singleton.h"
#include <cstdio>

Singleton *Singleton::instance = nullptr;

Singleton *Singleton::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Singleton();
    }
    return instance;
}

Singleton::Singleton()
{
}

void SingletonTest()
{
    Singleton *s = Singleton::getInstance();
    Singleton *r = Singleton::getInstance();

    printf("%d\n", s);
    printf("%d\n", r);
}