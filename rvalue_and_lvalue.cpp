#include <iostream>

// lvalue have assigned memory address and rvalue not.

// int main(){
// int x{1};
// int &lref{x}; // l value reference which are modifiable.
// lref = 44; // modified value of lvalue.
// //int &llref{5}; lvalue intialize cannot accept rvalue.
// const int &llref{5}; // const lvalue accept rvalue.

// int &&ref{4};
// // int &&ref{x}; r value cannot accept lvalue.
// // const int &&rref{x}; const not accept lvalue.

// }
 
class Fraction
{
private:
	int m_numerator;
	int m_denominator;
 
public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator{ numerator }, m_denominator{ denominator }
	{
	}
 
	friend std::ostream& operator<<(std::ostream& out, const Fraction &f1)
	{
		out << f1.m_numerator << '/' << f1.m_denominator;
		return out;
	}
};
 
int main()
{
	auto &&rref{ Fraction{ 3, 5 } }; // r-value reference to temporary Fraction
	
    // f1 of operator<< binds to the temporary, no copies are created.
    std::cout << rref << '\n';
 
	return 0;
} // rref (and the temporary Fraction) goes out of scope here
