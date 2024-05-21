#pragma once

#include "basic_hello/interface_definition.h"


void global_2_RelativePosition(LLA& refPos, double& refPosHeadingValue, LLA& targetPos, RelativePosition& targetRelativePos);

void global_2_RelativePosition_iso(LLA& refPos, double& refPosHeadingValue, LLA& targetPos,RelativePosition& targetRelativePos);

void global_2_RelativePosition_sae(LLA& refPos, double& refPosHeadingValue, LLA& targetPos,RelativePosition& targetRelativePos);

void global_2_RelativePosition_imu(LLA& refPos, double& refPosHeadingValue, LLA& targetPos,RelativePosition& targetRelativePos);

