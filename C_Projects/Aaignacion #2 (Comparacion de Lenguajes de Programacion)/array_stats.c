/*  Saulo Almeda Nieves
 *  841-13-0170
 *  10/12/2015
 *  array_stats.c
 *  Este programa pidelos elementos para un arreglo de 10 números enteros y que
 *  determine el elemento mínimo, el promedio de los elementos y la cantidad de
 *  elementos impares.
 */

 #include <stdio.h> //for scanf & printf

 #define LENGTH 10

 //Prototipos de las funciones
 void read_array(int arr[], int len);
 void show_array(const int arr[], int len);
 int minimumElement(int arr[], int len);
 double average(int arr[], int len);
 int oddCalc(int arr[], int len);

 //Ejecuccion del programa(main)
 int main(void) {
     int minimum, odd;
     double ave;
     int array[LENGTH];

     printf("Enter the %d elements: ", LENGTH);
     read_array(array, LENGTH);
     printf("\n");

     minimum = minimumElement(array, LENGTH);
     printf("The minimum element is: %d", minimum);
     printf("\n");

     ave = average(array, LENGTH);
     printf("The average of the elements is %.1f", ave);
     printf("\n");

     odd = oddCalc(array, LENGTH);
     printf("There are %d odd elements", odd);
     printf("\n");

     printf("Thanks for using this program");
     return 0;
 }

 //Calcula la cantidad de numeros impares en todo el arreglo recibido.
 int oddCalc(int arr[], int len) {
     int oddCount = 0, residuo;
     for(int idx = 0; idx < len; idx++) {
         residuo = arr[idx] % 2;
         if(residuo != 0)
            oddCount++;
     }
     return oddCount;
 }

 //Calcula el promedio de todos los elementos del arreglo recibido.
 double average(int arr[], int len) {
     int sum = 0;
     for(int idx = 0; idx < len; idx++)
        sum += arr[idx];
     return (double) sum / len;
 }

 //Calcula el minimo elemento del arreglo recibido.
 int minimumElement(int arr[], int len) {
     int min = arr[0];
     for(int idx = 0; idx < len; idx++)
        if(arr[idx] < min)
                min = arr[idx];
     return min;
 }

 // Reads the contents of the given array.
 void read_array(int arr[], int len) {
    for (int idx = 0; idx < len; idx++)
        scanf("%d", &arr[idx]);
}

 // Displays the contents of the given array.
 void show_array(const int arr[], int len) {
    for (int idx = 0; idx < len; idx++)
        printf("%d ", arr[idx]);
    printf("\n");
}
