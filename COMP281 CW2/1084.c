/*
* Student ID: 201377026
* Student Name: Yifan Xu
* Email: Y.Xu108@student.liverpool.ac.uk *
* User: sgyxu27 *
* Problem ID: 1084
* RunID: 39531
* Result: Accepted 
*/
#include <stdio.h>
#include <stdlib.h>
/* constant empty space is '.' a vehicle is '1' */
#define SPACE '.'
#define CAR '1'
/*the time of the car entering the highway and the time of the car moving beyond the last column */
int car_Entering(int time, int highway, int **Enter, int cars) {
    /*count the number of cars that entering the highway*/
    for(int a = 0; a < cars; a++) {
        /*Which highway the vehicle entered*/
        if(Enter[a][1] == highway) {
            /* check the time at that car entering the highway*/
            if(Enter[a][0] == time) {
                /*if a car has entered the highway*/
                return 1;
            }
        }
    }
    /*if the car is not entering or is moving beyond the last column of the highway */
    return 0;
}

void highway_situation(int max_row, int max_col, int period, char **table) {
    int highway, time;
    int **Enter = 0;
    int cars = 0;
    /*users input the car in which highway and its entering time */
    while (scanf("%d %d", &highway, &time) != -1) {
        /* Reallocates the size of the array to allow for more inputs */
        Enter= (int **) realloc(Enter, (cars + 1) * sizeof(int *));
        /* check the memory space */
        if (Enter == NULL) {
            printf("Sorry, not available space.\n");
            exit(1);
        }
        /* Allocating the column */
        Enter[cars] = (int *) malloc(2 * sizeof(int));
        if (Enter[cars] == 0) exit(1);
        Enter[cars][0] = highway;
        /* the 1 column means the time of car entering */
        Enter[cars][1] = time;
        /*add car numbers*/
        cars++;
    }
    /*count the number of timesteps that car entering the highway*/
    for(int time = 0; time < period; time++) {
        /*at the differnt highways*/
        for(int highway = 0; highway < max_row; highway++) {
             /*Move the highway table to right */
            move_Table(highway, max_col, &*table);
            /*if a car has entered the highway*/
            if(car_Entering(time, highway, &*Enter, cars)) 
                 table[highway][0] = CAR;
            else  /*if not, print empty space on the table*/
                table[highway][0] = SPACE;  
        }
    }
    /* Free the memory */
    free(Enter); 
}
/*initialise the table of highway */
void init_Table(int max_row, int max_col, char **table) {
    int row, col;
    for (row = 0; row < max_row; row++) {
        for (col = 0; col < max_col; col++) {
            table[row][col] = SPACE;
        }
    }
}
/*Move the highway table to right */
void move_Table(int highway, int max_col, char **table) {
    int col;
    for(col = max_col; col > 0; col--) {
        table[highway][col] = table[highway][col - 1];
    }
}
/*print out the table*/
void print_Table(int max_row, int max_col, char **table) {
    int row, col;
    for (row = 0; row < max_row; row++) {
        for (col = 0; col < max_col; col++) {
            printf("%c", table[row][col]);
        }
        printf("\n");
    }
}

int main() {
    int max_row, max_col, period;
    /*users input the number_of_rows,number_of_colums,number_of_timesteps*/
    scanf("%d %d %d", &max_row, &max_col, &period);
    if (max_row <= 0 || max_col <= 0 || period <= 0) {
        /*Warning, if users enter the row and column smaller than zero*/
        printf("Warning, please enter numbers greater than zero!\n");
        exit(1);
    }  
    /* create the pointers to pointers of highway table via Dynamically allocation*/
    char **table;
    /* Allocating the column */
    table = (char **)malloc(max_row * sizeof(char *));
    for (int b = 0; b < max_row; b++) {
         /* Allocating the row */
        table[b] = (char *)malloc(max_col * sizeof(char));
    }
     /* check the memory space */
    if (table == NULL) {
        printf("Sorry, not available space.\n");
        exit(1);
    }
    
    /* call the methods and print the results */
    init_Table(max_row, max_col, &*table);
    highway_situation(max_row, max_col, period, &*table);
    print_Table(max_row, max_col, &*table);
    /* Free the memory */
    free(table);
    return 0;
}