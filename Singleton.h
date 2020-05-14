#ifndef SINGLETON_H_
#define SINGLETON_H_

class Singleton
{
  public:
    static Singleton *getInstance();

  private:
    static Singleton *instance;
    Singleton();
};

void SingletonTest();

#endif // SINGLETON_H
