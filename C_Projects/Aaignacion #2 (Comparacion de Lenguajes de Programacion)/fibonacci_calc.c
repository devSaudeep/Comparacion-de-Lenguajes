/*  Saulo Almeda Nieves
 *  841-13-0170
 *  10/11/2015
 *  fibonacci_calc.c
 *  Este programa calcula la enesima posicion de la susecion de fibonacci
 *  tanto recursivamente como iterativamente.
 */

 //Includes
 #include <stdio.h> //for scanf & printf

 //Prototipos de las funciones
 int iterativeFibo(int len);

 //Ejecuccion del programa (main)
 int main(void) {
     int arrLen, enesimo, result;

     printf("Enter a non-negative integer: ");
     scanf("%d", &enesimo);
     arrLen = enesimo + 1;

     result = iterativeFibo(arrLen);

     printf("Using iteration, the %d-th number in the Fibonacci sequence is %d.\n", enesimo, result);

     result = iterativeFibo(enesimo + 1);
     printf("Using recursion, the %d-th number in the Fibonacci sequence is %d.", enesimo, result);
     return 0;
 }

 //Calcula el enesimo termino de la secuencia de fibonacci y devuelve el mismo.
 int recursiveFibo(int n) {
     if(n == 0)
        return 0;
     else if(n == 1)
        return 1;
     else
        return recursiveFibo(n - 1) + recursiveFibo(n - 2);
 }

 //Calcula la secuencia de fibonacci hasta el enesimo termino y devuelve el mismo.
 int iterativeFibo(int len) {
     int arrFibo[len];
     int idx;

     arrFibo[0] = 0;
     arrFibo[1] = 1;

     for(idx = 2; idx <= len - 1; idx++) {
            arrFibo[idx] = arrFibo[idx - 1] + arrFibo[idx - 2];
     }
     return arrFibo[len - 1];
 }
