#include "circle.h"
#include "point.h"
#include <math.h>
#include <stdio.h>

void CircleInfo(
        float x, float y, float radius)
{
    printf("\tcenter = (%.3f %.3f)\n\tradius = %.3f\n",
           x,
           y,
           radius
           );
}