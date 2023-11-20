/* FIRST RULE OF PROGRAMMING-
   IF IT WORKS DONT TOUCH IT */
#include <stdio.h>
void countdupe() //   WAP COUNT DUPLICATE DIGITS IN ARRAY
{
   int n;
   printf("enter size");
   scanf("%d", &n);
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      scanf("%d", &arr[i]);
   }
   int count = 0;
   for (int i = 0; i < n; i++)
   {
      for (int j = i; j < n; ++j)
      {
         if (arr[i] == arr[j] && i != j)
         {
            count++;
         }
         if (arr[i] == arr[j] && i != j)
            break;
      }
   }
   printf("%d", count);
}
void countuniq() // WAP COUNT ONLY UNIQUE VALUE IN A ARRAY
{
   int n;
   printf("enter size");
   scanf("%d", &n);
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      scanf("%d", &arr[i]);
   }
   for (int i = 0; i < n; i++)
   {
      int count = 0;
      for (int j = 0; j < n; ++j)
      {
         if (arr[i] == arr[j] && i != j)
         {
            count++;
         }
         if (arr[i] == arr[j] && i != j)
            break;
      }
      if (count == 0)
      {
         printf("%d", arr[i]);
      }
      printf("\n");
   }
}
void frequniq() //  WAP FREQUENCY OF unique ELEMNTS IN ARRAY
{
   int n;
   printf("enter size");
   scanf("%d", &n);
   int arr[n];
   int c[n];
   for (int i = 0; i < n; i++)
   {
      scanf("%d", &arr[i]);
      c[i] = 1;
   }
   for (int i = 0; i < n; i++)
   {
      int count = 1;
      for (int j = i + 1; j < n; ++j)
      {
         if (arr[i] == arr[j])
         {
            count++;
            c[j] = 0;
         }
      }
      if (c[i] != 0)
         printf("%d = %d", arr[i], count);
      printf("\n");
   }
}
void removedup() // WAP TO REMOVE DUPLICATE ELEMENTS FROM AN ARRAY
{
   int n;
   printf("Enter size:");
   scanf("%d", &n);
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      printf("Enter index %d: ", i);
      scanf("%d", &arr[i]);
   }
   int c = 0;
   int check[n];
   for (int i = 0; i < n; i++)
   {
      check[i] = 1;
   }
   for (int i = 0; i < n; i++)
   {
      for (int j = i + 1; j < n; j++)
      {
         if (arr[i] == arr[j])
         {
            check[j] = 0;
         }
      }
   }
   for (int i = 0; i < n; i++)
   {
      if (check[i] != 0)
         c++;
   }
   int new[c];

   for (int i = 0, j = 0; i < n; i++)
   {
      if (check[i] != 0)
      {
         new[j] = arr[i];
         j++;
      }
   }
   for (int i = 0; i < c; i++)
   {
      printf("%d", new[i]);
   }
}
void reverse() // WAP TO reverse an array
{
   int n;
   printf("Enter size:");
   scanf("%d", &n);
   int arr[n];
   int l = n / 2;
   int tmp;
   for (int i = 0; i < n; i++)
   {
      printf("Enter index %d: ", i);
      scanf("%d", &arr[i]);
   }
   for (int i = 0, j = n - 1; i < l; i++, j--)
   {
      tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;
   }
   for (int i = 0; i < n; i++)
   {
      printf(" index %d: ", i);
      printf("%d", arr[i]);
   }
}
void bubble() // WAP  BUBBLE SORT
{
   int n;
   printf("Enter size:");
   scanf("%d", &n);
   int arr[n];
   int tmp;
   for (int i = 0; i < n; i++)
   {
      printf("Enter index %d: ", i);
      scanf("%d", &arr[i]);
   }
   for (int i = 0; i < n; i++)
   {
      for (int j = i + 1; j < n; j++)
      {
         if (arr[j] < arr[i])
         {
            tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
         }
      }
   }
   for (int i = 0; i < n; i++)
   {
      printf("Enter index %d: ", i);
      printf("%d \n", arr[i]);
   }
}
void selection() // WAP SELECTION SORT
{
   int n;
   printf("Enter size:");
   scanf("%d", &n);
   int arr[n], min, mi = 0, temp;
   for (int i = 0; i < n; i++)
   {
      printf("Enter index %d: ", i);
      scanf("%d", &arr[i]);
   }
   for (int i = 0; i < n; i++)
   {
      min = arr[i];
      mi = i;
      for (int j = i; j < n; j++)
      {
         if (arr[j + 1] < min)
         {
            min = arr[j + 1];
            mi = j + 1;
         }
      }
      if (arr[mi] != arr[i])
      {
         temp = arr[i];
         arr[i] = arr[mi];
         arr[mi] = temp;
      }
   }
   for (int i = 0; i < n; i++)
   {
      printf("%d\n", arr[i]);
   }
}
void maxmin() // WAP TO FIND MAXIMUM AND MINIMUN VALUE IN AN ARRAY
{
   int n;
   printf("Enter size of array: ");
   scanf("%d", &n);
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      printf("emter element \n");
      scanf("%d", &arr[i]);
   }
   int max = arr[0], min = arr[0];
   for (int j = 0; j < n; j++)
   {
      if (max < arr[j])
      {
         max = arr[j];
      }

      if (min > arr[j])
      {
         min = arr[j];
      }
   }
   printf("max= %d", max);
   printf("min= %d", min);
}
void merge()
{
}
void main()
{
   void countdupe();
   void maxmin();
   void selection();
   void bubble();
   void frequniq();
   void countuniq();
   void removedup();
   void reverse();
   void merge();
}