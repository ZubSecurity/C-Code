#include <iostream>

template <class T>
class CopyClass
{
public:
    T *autoptr;

    CopyClass(T *ptr = nullptr) : autoptr(ptr)
    {
    }

    ~CopyClass()
    {
        delete autoptr;
    }

    CopyClass(CopyClass const &copyclass)
    {
        this->autoptr = copyclass.autoptr;
        copyclass.autoptr = nullptr;
    }

    CopyClass& operator=(CopyClass &copyclass)
    {
        if (&copyclass == this)
        {
            return *this;
        }
        this->autoptr = copyclass.autoptr;
        copyclass.autoptr = nullptr;
        return *this;
    }

    bool isNull(){
        return this->autoptr == nullptr;
    }
};

class Data
{
public:
    Data()
    {
    }
    ~Data()
    {
    }
};

int main()
{
    CopyClass<Data> cc (new Data());
    CopyClass<Data> ss; // ptr to nullptr

    std::cout << "cc is " << (cc.isNull() ? "null\n" : "not null\n");
	std::cout << "ss is " << (ss.isNull() ? "null\n" : "not null\n");
 
	ss = cc; // res2 assumes ownership, res1 is set to null
 
	std::cout << "Ownership transferred\n";
 
	std::cout << "cc is " << (cc.isNull() ? "null\n" : "not null\n");
	std::cout << "ss is " << (ss.isNull() ? "null\n" : "not null\n");
}
