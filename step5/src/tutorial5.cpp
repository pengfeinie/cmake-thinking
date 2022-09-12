#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include "TutorialConfig.h"
#include "basic_hello/basic_hello_function.h"
#ifdef USE_MYMATH
  #include "basic_math/basic_math_function.h"
  #include "complex_math/complex_math_function.h"
#endif

int main(int argc, char* argv[])
{
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }
  std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."<< Tutorial_VERSION_MINOR << std::endl;

  #ifdef USE_MYMATH
    const double sum = myadd(1,2);
    std::cout << " x + y  = 1 + 2" << sum << std::endl;

    const double sub = mysub(5,4);
    std::cout << " a - b  = 5 - 4" << sub << std::endl;

    const double inputValue = atof(argv[1]);
    const double outputValue = mysqrt(inputValue);
    std::cout << "Custom math function - mysqrt: The square root of " << inputValue << " is " << outputValue << std::endl;
  #else 
    const double inputValue_system = atof(argv[1]);
    const double outputValue_system = sqrt(inputValue_system);
    std::cout << "System math function - sqrt: The square root of " << inputValue_system << " is " << outputValue_system << std::endl;
  #endif
  
  std::string something = say();
  std::cout << something << std::endl;
  return 0;
}
