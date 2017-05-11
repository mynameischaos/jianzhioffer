#include <iostream>

using namespace std;

class Singleton1 {
private:
    Singleton1() {

    };
    static Singleton1* instance = new Singleton1();
public:
    static Singleton1* GetInstance() {
        return instance;
    };
};

int main() {
    Singleton1* single = Singleton1::GetInstance();
    return 0;
}