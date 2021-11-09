#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main()
{
  setlocale(LC_ALL, "Rus");
  int n = 0, i = 0, k = 0, j = 0;
  double max1 = 0.0, min1 = 0.0, sum3 = 0.0;
  int* mas2;
  double* mas1;

  printf("����� ���������� ���������:\t");
  scanf_s("%d", &n);
  if (n <= 0)
  {
    printf("������! ���������� ���������� ������ ����\n");
    return 0;
  }
  printf("����� �������:\t");
  scanf_s("%lf", &min1);
  printf("����� ��������:\t");
  scanf_s("%lf", &max1);
  if (max1 < min1)
  {
    printf("������! �������� ��������� ������ ��������\n");
    return 0;
  }

  mas1 = (double*)malloc(n * sizeof(double));
  mas2 = (int*)malloc(n * sizeof(int));
  if (mas1 == 0 || mas2 == 0)
  {
    printf("������! ��������� ������� ������\n");
    return 0;
  }
  for (i = 0; i < n; i++)
    mas1[i] = (((double)rand()) / RAND_MAX) * (max1 - min1) + min1;
  //for (i = 0; i < n; i++)
    //printf("mas1[%d]=%lf\n", i, mas1[i]);
  for (int i = 0; i < n; i++)
    mas2[i] = ((mas1[i] - (int)mas1[i]) * 1000000);
  while (mas2[i] % 10 == 0)
    mas2[i] = mas2[i] / 10;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == mas2[j])
        {
          sum3 = sum3 - mas1[i];
          mas1[i] = 0.0;
        }
    }
  }
  for (int i = 0; i < n; i++)
  {
    sum3 = sum3 + mas1[i];
  }
  printf("����� �������� = %lf", sum3);
  free(mas1);
  free(mas2);
  return 0;
}