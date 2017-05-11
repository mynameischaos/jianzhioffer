#include <iostream>

using namespace std;

// 赋值运算符重载

class CMyString {
public:
    CMyString(char* pData = nullptr) {
        if(pData == nullptr)
        {
            m_pData = new char[1];
            m_pData[0] = '\0';
        }
        else
        {
            int length = strlen(pData);
            m_pData = new char[length + 1];
            strcpy(m_pData, pData);
        }
    }
    CMyString(const CMyString& str) {
        int length = strlen(str.m_pData);
        m_pData = new char[length + 1];
        strcpy(m_pData, str.m_pData);
    }
    ~CMyString(void) {
        delete[] m_pData;
    }

    CMyString& operator=(const CMyString& str) {
        if (this == &str) {
            return *this;
        }
        delete[] m_pData;
        m_pData = nullptr;

        m_pData = new char[strlen(str.m_pData) + 1];
        strcpy(m_pData, str.m_pData);
        return *this;
    }
    void my_print() {
        cout << m_pData << endl;
    }


private:
    char* m_pData;
};

int main() {
    char f1 [] = "apple";
    CMyString cms(f1);
    CMyString cms1;
    CMyString cms2;
    cms = cms;
    cms1 = cms2 = cms;
    cms2.my_print();
    return 0;
}