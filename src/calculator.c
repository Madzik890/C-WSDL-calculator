#include <stdlib.h>
#include <string.h>
#include "calculatorAPI.h"

typedef enum argvNumbersError argvNumbersError;
enum argvNumbersError
{
  noNumbers,
  successful
};

struct argvNumbers
{
  int u_firstNumber;
  int u_secondNumber;

  enum argvNumbersError e_error;
};

void getNumbersFromArgv(int reference, char ** argv, struct argvNumbers * argvNumbers);
void helpArgv();

int main(int argc, char ** argv)
{
/// <help>
    if(argc == 1)//zero arguments
    {
       helpArgv();
       exit(1);//to not to start the api
    }
    if(argc == 2 && (!strcmp( argv[ 1 ], "-h") || !strcmp( argv[ 1 ], "-help" ) || !strcmp( argv[ 1 ], "--help" )))
    {
        helpArgv();
        exit(1);//to not to start the api
    }
/// </help>

startCalculatorAPI();
  for(int i = 1; i<= argc - 1;i++)
  {
    if(!strcmp( argv[ i ], "+" ))//all
    {
      struct argvNumbers numbers;
      getNumbersFromArgv(i, argv, &numbers);
      if(numbers.e_error = successful)
      {
        int u_result = additionOperation(numbers.u_firstNumber,numbers.u_secondNumber);
        printf("%d + %d = %d \n",numbers.u_firstNumber, numbers.u_secondNumber, u_result);
      }
    }

    if(!strcmp( argv[ i ], "-" ))//all
    {
      struct argvNumbers numbers;
      getNumbersFromArgv(i, argv, &numbers);
      if(numbers.e_error = successful)
      {
        int u_result =  subtractionOperation(numbers.u_firstNumber,numbers.u_secondNumber);
        printf("%d - %d = %d \n",numbers.u_firstNumber, numbers.u_secondNumber, u_result);
      }
    }

    if(!strcmp( argv[ i ], "x" ))//all
    {
      struct argvNumbers numbers;
      getNumbersFromArgv(i, argv, &numbers);
      if(numbers.e_error = successful)
      {
        int u_result = multiplyOperation(numbers.u_firstNumber,numbers.u_secondNumber);
        printf("%d * %d = %d \n",numbers.u_firstNumber, numbers.u_secondNumber, u_result);
      }
    }

    if(!strcmp( argv[ i ], "/" ))//all
    {
      struct argvNumbers numbers;
      getNumbersFromArgv(i, argv, &numbers);
      if(numbers.e_error = successful)
      {
        int u_result = divideOperation(numbers.u_firstNumber,numbers.u_secondNumber);
        printf("%d / %d = %d \n",numbers.u_firstNumber, numbers.u_secondNumber, u_result);
      }
    }
  }

  closeCalculatorAPI();

  return 0;
}

void getNumbersFromArgv(int reference, char ** argv, struct argvNumbers * argvNumbers)
{
  unsigned int u_sizeOfArgv = sizeof(argv) / sizeof(char);
  if(reference < u_sizeOfArgv)
  {
    argvNumbers->u_firstNumber =   atoi(argv[reference + 1]);
    argvNumbers->u_secondNumber = atoi(argv[reference + 2]);
    argvNumbers->e_error = successful;
  }
  else
    argvNumbers->e_error = noNumbers;
}

void helpArgv()
{
  printf("Usage calculator [+ firstNumber secondNumber] [- firstNumber secondNumber] [x firstNumber secondNumber] [/ firstNumber secondNumber]  \n");
  printf("\nOptions: \n");
  printf("    +               firstNumber + secondNumber = result \n");
  printf("    -               firstNumber - secondNumber = result \n");
  printf("    x               firstNumber x secondNumber = result \n");
  printf("    /               firstNumber / secondNumber = result \n");
}
