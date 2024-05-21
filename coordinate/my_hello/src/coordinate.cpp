#include "basic_hello/coordinate.h"
#include <math.h>
#include <iostream>


void global_2_RelativePosition(LLA& refPos, double& refPosHeadingValue, LLA& targetPos, RelativePosition& targetRelativePos)
{
    double ref_pos_lon_degree = refPos.longitude * 0.0000001;
    double ref_pos_lat_degree = refPos.latitude * 0.0000001;
    double target_pos_lon_degree = targetPos.longitude * 0.0000001;
    double target_pos_lat_degree = targetPos.latitude * 0.0000001;

    double delt_lon = target_pos_lon_degree - ref_pos_lon_degree;
    double delt_lat = target_pos_lat_degree - ref_pos_lat_degree;
    double x = delt_lon * cos(ref_pos_lat_degree * M_PI / 180) * 111199;
    double y = delt_lat * 111199;

    double angle = (90-refPosHeadingValue) * M_PI / 180.0;
    double rotated_x = cos(angle) * x + y * sin(angle);
    double rotated_y = -sin(angle) * x + cos(angle) * y;

    targetRelativePos.x = rotated_x;
    targetRelativePos.y = rotated_y;
}