#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include "TutorialConfig.h"



double myadd(double x, double y);

double mysub(double a , double b);

double mysqrt(double x);

std::string say();


int main(int argc, char* argv[])
{
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }
  std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."<< Tutorial_VERSION_MINOR << std::endl;

  const double sum = myadd(1,2);
  std::cout << " x + y  = 1 + 2" << sum << std::endl;

  const double sub = mysub(5,4);
  std::cout << " a - b  = 5 - 4" << sub << std::endl;

  const double inputValue = atof(argv[1]);
  const double outputValue = mysqrt(inputValue);
  std::cout << "Custom math function - mysqrt: The square root of " << inputValue << " is " << outputValue << std::endl;

  const double inputValue_system = atof(argv[1]);
  const double outputValue_system = sqrt(inputValue_system);
  std::cout << "System math function - sqrt: The square root of " << inputValue_system << " is " << outputValue_system << std::endl;

  std::string something = say();
  std::cout << something << std::endl;
  return 0;
}
