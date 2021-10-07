#include <stdio.h>

int add(int x, int y)
{
  return x+y;
}

int subtract(int x, int y)
{
  return x-y;
}

int multiply(int x, int y)
{
  int result;
  result = 0;
  while(y>0)
  {
  	result = add(result,x);
  	y = subtract(y,1);
  }
  return result;
}

int divide(int x, int y)
{
  int result;
  result = 0;
  
  while(multiply(result,y)<=x)
  {
  	result = add(result,1);
  }
  result = subtract(result,1);
  return result;
}

int squareroot(int x)
{
  int result;
  result = 0;
  while(x>multiply(result,result))
  {
  	result = add(result,1);
  }
  result = subtract(result ,1);
  return result;
}

int exponentiate(int x, int y)
{
  int result;
  result = 1;
  for(int i=0;i<y;i = add(i,1))
  {
  	result = multiply(result,x);
  }
  return result;
}


int main()
{
  int x,y,op;

  printf("Operations:\n");
  printf("1. Add \n");
  printf("2. Subtract \n");
  printf("3. Multiply\n");
  printf("4. Divide\n");
  printf("5. Square Root\n");
  printf("6. Exponentiate\n");

  printf("Enter the operation (1,2,..):\n");
  scanf("%d",&op);

  switch (op)
  {
    case 5:   printf("Enter positive integer\n");
              scanf("%d",&x);
              break;
    default:  printf("Enter first positive integer\n");
              scanf("%d",&x);
              printf("Enter second positive integer\n");
              scanf("%d",&y);
  }
  switch (op)
  {
    case 1: printf("Result = %d\n",add(x,y)); break;
    case 2: printf("Result = %d\n",subtract(x,y)); break;
    case 3: printf("Result = %d\n",multiply(x,y)); break;
    case 4: printf("Result = %d\n",divide(x,y)); break;
    case 5: printf("Result = %d\n",squareroot(x)); break;
    case 6: printf("Result = %d\n",exponentiate(x,y)); break;
  }
  return 0;
}