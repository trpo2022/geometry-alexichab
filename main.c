#include <stdio.h>
#include <string.h>

int main()
{
  char input[64];
  printf("Введите фигуру\n");
  scanf("%s",&input);

  if (strcmp(input,"circle") == 0){
    printf("Вы ввели круг\n");
  }
  



  return 0;
}
