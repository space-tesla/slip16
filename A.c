//Q.1)Display all the files from the current directory which are created in a particular month.
#include <stdio.h>
#include <stdlib.h>

int main() {
    char month[10];
    printf("Enter the month (e.g., Jan, Feb, Mar): ");
    scanf("%s", month);

    char command[50];
    sprintf(command, "ls -l --time-style=+%%b | grep ' %s '", month);
    system(command);

    return 0;
}








/*Enter the month (e.g., Jan, Feb, Mar): Jan
-rw-r--r-- 1 user user 1024 Jan 15 10:00 example.txt
-rw-r--r-- 1 user user 2048 Jan 20 12:30 data.csv
*/