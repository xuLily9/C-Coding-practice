/*
* Student ID: 201377026
* Student Name: Yifan Xu
* Email: Y.Xu108@student.liverpool.ac.uk *
* User: sgyxu27 *
* Problem ID: 1081
* RunID: 39589
* Result: Accepted 
*/
#include <stdio.h>
#include <stdlib.h>
/* constant alive cell as 'X', dead cell as '.' */
#define ALIVE 'X'
#define DEAD '.'
/*initialise the table of cells*/
void ask_table(int max_row, int max_col, char **table) {
    char cells;
    for (int i = 0; i < max_row; i++) {
        for (int j = 0; j < max_col; j++) {
            scanf(" %c", &cells);
            /* user enter where organism is living or dead */
            if (cells == ALIVE || cells == DEAD) {
                table[i][j] = cells;
            } else {
                printf("Error. Board value must be '%c' or '%c'.\n", ALIVE, DEAD);
                exit(1);
            }
        }
    }
}
/* print out the table*/
void print_Table(int max_row, int max_col, char **table) {
    for (int i = 0; i < max_row; i++) {
        for (int j = 0; j < max_col; j++) {
            printf("%c", table[i][j]);
        }
        printf("\n");
    }
}
/*get the value of neighbors, prepare for count the number of neighbors*/
int getValue(int row, int col, int max_row, int max_col, char **table) {
	/*if the cell is dead or out of bounds*/
    if (row < 0 || col < 0 || col >= max_col ||row >= max_row || table[row][col] != ALIVE) return 0;
   /*if the cell is alive*/
    else return 1;
}

/*counts the number of neighbour cells which is aliving */
int count_Value(int row, int col, int max_row, int max_col, char **table) {
    int count = 0;
    /* check and count the surrounding cells */
    count += getValue(row - 1, col - 1, max_row, max_col, &*table)+ getValue(row - 1, col, max_row, max_col, &*table)
   			+ getValue(row - 1, col + 1, max_row, max_col, &*table) + getValue(row, col - 1, max_row, max_col, &*table)
    		+ getValue(row, col + 1, max_row, max_col, &*table) + getValue(row + 1, col - 1, max_row, max_col, &*table)
    		+ getValue(row + 1, col, max_row, max_col, &*table) + getValue(row + 1, col + 1, max_row, max_col, &*table);
    return count;
}

/*deal with the neighbors, get the cells distribution after several generations*/
void neighbors(int max_row, int max_col, char **table,char **newtable) {
    
	for(int r = 0; r < max_row; r++) {
	    for(int c = 0; c < max_col; c++) {
	        /* count the total number of alive neighbours */
	        int count = count_Value(r, c, max_row, max_col, &*table);  
	        /* get the cell state*/
	        if(count == 3) 
	            newtable[r][c] = ALIVE;
	        else if(count == 2 && table[r][c] == ALIVE) 
	            newtable[r][c] = ALIVE;
	        else 
	            newtable[r][c] = DEAD;             
	    }
	}
	/* After a generation,update the table state */
	for (int row = 0; row < max_row; row++) {
	    for (int col = 0; col < max_col; col++) {
	        table[row][col] = newtable[row][col];
	    }
	}   
}

int main() {
    /* Taking the initial input line */
    int max_row, max_col, generations;
    scanf("%d %d %d", &max_row, &max_col, &generations);
    if (max_row <= 0 || max_col <= 0 || generations <= 0) {
        printf("Warning, please enter numbers greater than zero!\n");
        exit(1);
    }
    
    /* create cells table */
    char **table;
    /* create new table for new generations*/
    char **newtable;
    table = (char **)malloc(max_row * sizeof(char *));
    newtable = (char **)malloc(max_row * sizeof(char *));
    for (int i = 0; i < max_row; i++) {
        table[i] = (char *)malloc(max_col * sizeof(char));
        newtable[i] = (char *)malloc(max_col * sizeof(char));
    }
    if (newtable == NULL||table == NULL) {
        printf("Sorry, not available space.\n");
        exit(1);
    }

    /* user enter where organism is living or dead */
    ask_table(max_row, max_col, &*table);
	/*get the cells distribution after several generations*/
    for(int gen = 0; gen < generations; gen++) {
    	neighbors(max_row, max_col, &*table,&*newtable);
    }
    /*print out the cell table*/
    print_Table(max_row, max_col, &*table);
    /* Free the memory */
    free(table);
    free(newtable);
    return 0;
}



























