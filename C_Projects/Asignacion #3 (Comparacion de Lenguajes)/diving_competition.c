/*  Saulo Almeda Nieves
 *  841-13-0170
 *  October / 27 /2015
 *  diving_competition.c
 *  This program reads a file with the data of a diving competition and
 *  displays a report of the results.
 */

//Includes
#include <stdio.h>  //for scanf, printf
#include <stddef.h>  // for NULL
#include <stdlib.h>  // for exit

//Defines
#define ID_SIZE 4
#define NAME_SIZE 10
#define NUM_SCORES 10

//Defines Data Structures
typedef struct {
    char diver_id[ID_SIZE + 1],
    first_name[NAME_SIZE + 1],
    last_name[NAME_SIZE + 1];
    float scores[NUM_SCORES];
} Diver;

//Function Prototypes
Diver read_record(FILE *in);
float average(const Diver *d);
void write_data(FILE *out, const Diver *dv);

//Main
int main(void) {
    FILE *fileToRead;
    char *filename = "competition.txt";

    fileToRead = fopen(filename, "r");

    if(fileToRead == NULL) {
        printf("The file %s was not found!", filename);
        return 1;
    }
    char *title = "Diving Competition Results";
    printf("        Diving Competition Results\n");
    printf("\n");
    printf("ID      Name                 Trunc. Average\n");
    printf("--      ----                 --------------\n");

    FILE *report_file = fopen("report.txt", "w");
    fprintf(report_file, "        Diving Competition Results\n");
    fprintf(report_file, "\n");
    fprintf(report_file, "ID      Name                 Trunc. Average\n");
    fprintf(report_file, "--      ----                 --------------\n");

    Diver diver = read_record(fileToRead);
    while (! feof(fileToRead)) {
        write_data(report_file, &diver);
        diver = read_record(fileToRead);
        printf("%-4s    %-6s, %s%14.3f\n", diver.diver_id,
               diver.last_name, diver.first_name, average(&diver));
    }

    fclose(fileToRead);
    fclose(report_file);
    fprintf(stdout, "Files have been processed.\n");
    return 0;	//Exit code of main
}//End of main

void write_data(FILE *out, const Diver *dv) {
    fprintf(out, "%s    %s, %s            %.3f\n", dv->diver_id,
               dv->last_name, dv->first_name, average(dv));
}

float average(const Diver *d) {
    int sum = 0, min = 0, max = 0;
    for (int idx = 0; idx < NUM_SCORES; idx++) {
        min = d->scores[0];
        max = d->scores[0];
        if(min > d->scores[idx])
            min = d->scores[idx];
        if(max < d->scores[idx])
            max = d->scores[idx];
        sum += d->scores[idx];
    }
    sum -= min;
    sum -= max;
    return (float)sum / (NUM_SCORES - 2);
}

Diver read_record(FILE *in) {
    Diver d;
    fscanf(in, "%s %s %s", d.diver_id, d.first_name, d.last_name);
    for(int idx = 0; idx < NUM_SCORES; idx++)
        fscanf(in, "%f", &d.scores[idx]);
    return d;
}
