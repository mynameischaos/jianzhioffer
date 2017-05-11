#include <iostream>

using namespace std;

class Singleton1 {
private:
    Singleton1() {

    };
    static Singleton1* m_pInstance;
public:
    static Singleton1* GetInstance();
};
Singleton1* Singleton1::m_pInstance = NULL;
Singleton1* Singleton1::GetInstance() {
    if (m_pInstance == NULL) {
        m_pInstance = new Singleton1();
    }
    return m_pInstance;
}

int main() {
    Singleton1* single = Singleton1::GetInstance();
    Singleton1* single2 = single->GetInstance();
    Singleton1& ref = * Singleton1::GetInstance();
    return 0;
}