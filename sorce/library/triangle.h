#pragma once
#include "point.h"

void TriangleInfo(struct Point points[4], float perimeter, float area);
float calculateSide(struct Point point1, struct Point point2);
float calculateTrianglePerimeter(struct Point points[4]);
float calculateTriangleArea(struct Point points[4]);