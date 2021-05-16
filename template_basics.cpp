#include <iostream>
using namespace std;

class Emp
{
private:
    int myvar;

public:
    Emp(int var) : myvar(var)
    {
    }

    friend bool operator>(const Emp &c1, const Emp &c2)
    {
        return (c1.myvar > c2.myvar);
    }

    friend std::ostream &operator<<(std::ostream &out, const Emp &cents)
    {
        out << cents.myvar << " cents ";
        return out;
    }

    Emp &operator+=(const Emp &myemp)
    {
        myvar += myemp.myvar;
        return *this;
    }

    Emp &operator/=(int length)
    {
        myvar /= length;
        return *this;
    }
};

template <typename T>
T myMax(T x, T y)
{
    std::cout << "-------1------\n"
              << std::endl;
    return (x > y) ? x : y;
}

template <typename T>
T average(T *array, int length)
{
    T sum(0);
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    sum /= length;
    return sum;
}

int main()
{
    Emp one(1);
    Emp two(2);

    Emp bigger(myMax(one, two));

    Emp array3[]{Emp(5), Emp(10), Emp(15), Emp(14)};
    std::cout << average(array3, 4) << '\n';

    return 0;
}
