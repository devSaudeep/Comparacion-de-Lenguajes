/*  Saulo Almeda Nieves
 *  841-13-0170
 *  11 / 2 /2015
 *  employee_payroll.c
 *  This program creates an array of at least five different kinds of employees
 *  and displays their data, including their weekly salary with the appropriate
 *  format.
 */

//Includes

//Defines
#define ID_SIZE 4
#define NAME_SIZE 20

//Defines Data Structures
typedef enum {HOURLY, SALES} EmployeeKind;

typedef struct {
   float pay_rate,
         hours_worked;
} HourlyEmployee;

typedef struct {
   float commission_rate,
         sales_amount;
} SalesEmployee;

typedef struct {
   EmployeeKind kind;
   char employee_id[ID_SIZE + 1],
        full_name[NAME_SIZE + 1];
   union {
      HourlyEmployee hourly;
      SalesEmployee sales;
   };
} Employee;

//Function Prototypes
void display_data(const Employee *emp);
char *kind_to_str(EmployeeKind kind);

//Main
int main(void) {
    Employee arr[] = {
        {HOURLY, "1234", "Saulo Almeda Nieves", .hourly = {5.0, 10}},
        {HOURLY, "2468", "Raquel Almeda Nieves", .hourly = {7.0, 20}},
        {HOURLY, "4812", "Rebeca Almeda Nieves", .hourly = {8.0, 50}},
        {SALES, "8162", "Judith Nieves Rivera", .sales = {.20, 100}},
        {SALES, "1621", "Saul Omar Almeda Cruz", .sales = {.40, 200}}};

    int arr_length = sizeof(arr) / sizeof(Employee);

    printf("These are the employees:\n\n");

    for(int idx = 0; idx < arr_length; idx++) {
        printf("Employee #%d\n\n", idx + 1);
        display_data(&arr[idx]);
    }
    return 0;
}//end of main

//Dispplay all the data of the given Employee
void display_data(const Employee *emp) {
    printf("Kind: %s\nID: %s\nFull Name: %s\n", kind_to_str(emp->kind),
           emp->employee_id, emp->full_name);
    switch (emp->kind) {
        case HOURLY:
            if(emp->hourly.hours_worked > 40) {
                printf("Weekly Salary: $%.2f\n\n", (emp->hourly.pay_rate + 1.5) * emp->hourly.hours_worked);
                break;
            }
            printf("Weekly Salary: $%.2f\n\n", emp->hourly.pay_rate *
                   emp->hourly.hours_worked);
            break;
        case SALES:
            printf("Weekly Salary: $%.2f\n\n", emp->sales.commission_rate * emp->sales.sales_amount);
            break;
    }
}

//Returns the equivalent enum value in a string
char *kind_to_str(EmployeeKind kind) {
    char *str[] = {"Hourly", "Sales"};
    return str[kind];
}
