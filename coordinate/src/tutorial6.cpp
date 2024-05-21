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
#include "basic_hello/coordinate.h"

int main(int argc, char* argv[])
{
  // if (argc < 2) {
  //   std::cout << "Usage: " << argv[0] << " number" << std::endl;
  //   return 1;
  // }
  // std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."<< Tutorial_VERSION_MINOR << std::endl;

  // #ifdef USE_MYMATH
  //   const double sum = myadd(1,2);
  //   std::cout << " x + y  = 1 + 2" << sum << std::endl;

  //   const double sub = mysub(5,4);
  //   std::cout << " a - b  = 5 - 4" << sub << std::endl;

  //   const double inputValue = atof(argv[1]);
  //   const double outputValue = mysqrt(inputValue);
  //   std::cout << "Custom math function - mysqrt: The square root of " << inputValue << " is " << outputValue << std::endl;
  // #else 
  //   const double inputValue_system = atof(argv[1]);
  //   const double outputValue_system = sqrt(inputValue_system);
  //   std::cout << "System math function - sqrt: The square root of " << inputValue_system << " is " << outputValue_system << std::endl;
  // #endif
  
  // std::string something = say();
  // std::cout << something << std::endl;

  GlobalLLA refPos;
  refPos.latitude = 499852888;
  refPos.longitude = 1164959876;
  double refPositionHeadingValue = 64.2234;


  GlobalLLA targetPos;
  targetPos.latitude = 499852560;
  targetPos.longitude = 1164954786;

  RelativePosition relativePosISO;
  global_2_RelativePosition_iso(refPos, refPositionHeadingValue, targetPos,relativePosISO);
  std::cout << "relativePosISO.x = " << relativePosISO.x << std::endl;
  std::cout << "relativePosISO.y = " << relativePosISO.y << std::endl;

  RelativePosition relativePosSAE;
  global_2_RelativePosition_sae(refPos, refPositionHeadingValue, targetPos,relativePosSAE);
  std::cout << "relativePosSAE.x = " << relativePosSAE.x << std::endl;
  std::cout << "relativePosSAE.y = " << relativePosSAE.y << std::endl;

  RelativePosition relativePosIMU;
  global_2_RelativePosition_imu(refPos, refPositionHeadingValue, targetPos,relativePosIMU);
  std::cout << "relativePosIMU.x = " << relativePosIMU.x << std::endl;
  std::cout << "relativePosIMU.y = " << relativePosIMU.y << std::endl;

  return 0;
}
