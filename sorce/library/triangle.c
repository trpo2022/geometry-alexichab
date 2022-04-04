#include "triangle.h"
#include "point.h"
#include <math.h>
#include <stdio.h>

void TriangleInfo(struct Point points[4])
{
    printf("\tpoints:\n");
    for (int i = 0; i < 3; i++) {
        printf("\t\t%d: (%.3f, %.3f)\n", i + 1, points[i].x, points[i].y);
    }
}
