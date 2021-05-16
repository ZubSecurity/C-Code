#include <iostream>

int main()
{
    try
    {
        throw "abc";
    }
    catch (const int e)
    {
        std::cout << "--i am an integer " << e << std::endl;
    }

    catch (const float e)
    {
        std::cout << "---i am a float " << e << std::endl;
    }

    catch (const char *exception)
    {
        std::cerr << "---i am a string " << exception << std::endl;
    }
    catch (double e)
    {
        std::cout << "---i am a double " << e << std::endl;
    }
    catch (const char e)
    {
        std::cout << "---i am a char " << e << std::endl;
    }


    try
	{
		throw 5; // throw an int exception
	}
	catch (double x)
	{
		std::cout << "We caught an exception of type double: " << x << '\n';
	}
	catch (...) // catch-all handler
	{
		std::cout << "We caught an exception of an undetermined type\n";
	}
    
}

 
