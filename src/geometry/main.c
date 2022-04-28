#include "library/point.h"
#include "library/objects.h"
#include "inputread.h"
#include "library/triangle.h"
#include "library/circle.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void getObject(int i, object* obj)
{
    char* input = malloc(sizeof(char) * 32);
    char* token = NULL;
    initInput(input);
    char* delims = "( ,)";
    switch (check_object(input, &token)) {
    case 0:
        printf("\n%d. %s:\n", i, token);
        struct Circle circle;

        circle.center.x = atof(strtok(NULL, delims));
        circle.center.y = atof(strtok(NULL, delims));
        circle.radius = atof(strtok(NULL, delims));

        obj->circle = circle;
        obj->type = CIRCLE;
        CircleInfo(circle);
        break;

    case 1:
        printf("\n%d. %s:\n", i, token);
        struct Triangle triangle;

        for (int i = 0; i < 4; i++) {
            triangle.points[i].x = atof(strtok(NULL, delims));
            triangle.points[i].y = atof(strtok(NULL, delims));
        }

        if (triangle.points[3].x != triangle.points[0].x
            || triangle.points[3].y != triangle.points[0].y) {
            printf("Error with handling the first/last point of the "
                   "triangle.\nCheck if your data is correct.\n");
        }

        obj->triangle = triangle;
        obj->type = TRIANGLE;
        TriangleInfo(triangle);
        break;

    default:
        printf("Incorrect input.\n");
    }
    free(input);
}


int main()
{
    object objects[3];
    for (int i = 0; i < 3; i++) {
        getObject(i + 1, &objects[i]);
    }
    
//   char* input = malloc(sizeof(char) * 32);//ввод данных
//     initInput(input);

//     char delims[] = "( ,)";
//     char* token = strtok(input, delims);

//     if (strcmp(token, "circle") == 0) {//если круг
//         printf("\n%s:\n", token);
//         struct Point p;

//         p.x = atof(strtok(NULL, delims));
//         p.y = atof(strtok(NULL, delims));
//         float radius = atof(strtok(NULL, delims));

//         float perimeter = calculateCirclePerimeter(radius);//вычисляем периметр круга
//         float area = calculateCircleArea(radius);//вычисляем площадь круга

       
//         CircleInfo(p.x, p.y, radius, perimeter, area);// дополняем вывод периметром и площадью

//     } else if (strcmp(token, "triangle") == 0) {//если треугольник
//         printf("\n%s:\n", token);
//         struct Point points[4];

//         for (int i = 0; i < 4; i++) {
//             points[i].x = atof(strtok(NULL, delims));
//             points[i].y = atof(strtok(NULL, delims));
//         }

//         if (points[3].x != points[0].x || points[3].y != points[0].y) {
//             printf("Ошибка обработки первой/последней точки в треугольнике.\nПроверьте ввод данных.\n");
//         }

//         float perimeter = calculateTrianglePerimeter(points);//периметр треугольника
//         float area = calculateTriangleArea(points);//площадь треугольника

//         TriangleInfo(points, perimeter, area);//дополняем вывод!

//     } else if (strcmp(token, "q") == 0) {
//         return 0;

//     } else {
//         printf("Неправильный ввод данных.\n");
//     }
//     free(input);
  return 0;
}
