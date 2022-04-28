#include "library/point.h"
#include "inputread.h"
#include "library/triangle.h"
#include "library/circle.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
  char* input = malloc(sizeof(char) * 32);//ввод данных
    initInput(input);

    char delims[] = "( ,)";
    char* token = strtok(input, delims);

    if (strcmp(token, "circle") == 0) {//если круг
        printf("\n%s:\n", token);
        struct Point p;

        p.x = atof(strtok(NULL, delims));
        p.y = atof(strtok(NULL, delims));
        float radius = atof(strtok(NULL, delims));

        float perimeter = calculateCirclePerimeter(radius);//вычисляем периметр круга
        float area = calculateCircleArea(radius);//вычисляем площадь круга

       
        CircleInfo(p.x, p.y, radius, perimeter, area);// дополняем вывод периметром и площадью

    } else if (strcmp(token, "triangle") == 0) {//если треугольник
        printf("\n%s:\n", token);
        struct Point points[4];

        for (int i = 0; i < 4; i++) {
            points[i].x = atof(strtok(NULL, delims));
            points[i].y = atof(strtok(NULL, delims));
        }

        if (points[3].x != points[0].x || points[3].y != points[0].y) {
            printf("Ошибка обработки первой/последней точки в треугольнике.\nПроверьте ввод данных.\n");
        }

        float perimeter = calculateTrianglePerimeter(points);//периметр треугольника
        float area = calculateTriangleArea(points);//площадь треугольника

        TriangleInfo(points, perimeter, area);//дополняем вывод!

    } else if (strcmp(token, "q") == 0) {
        return 0;

    } else {
        printf("Неправильный ввод данных.\n");
    }
    free(input);
  return 0;
}
