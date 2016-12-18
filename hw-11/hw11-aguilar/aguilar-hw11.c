/* Graciela Aguilar 
   April 18, 2016
   HW-11 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw11-lib.h"

int main (int argc, char* argv[]){
    
    char *filename1 = (argv[1]);
    char *filename2 = (argv[2]);
    struct curriculum *rqmts;
    char ** courseArray;
    int rqmtsCount = 0, courseCount = 0;
 
    
    if(argc != 3)
    {
        printf("example:  ./aguilar-hw11  bscs.csv  myCourses.txt\n");
        exit(1);
    }

    courseArray = createCourseWorkArr(filename2, &courseCount);
    
    rqmts = createRqmtList(filename1, &rqmtsCount);
    
    printOutput(rqmts, courseArray, rqmtsCount, courseCount);
    
    freeStruct(rqmts, rqmtsCount);
    
    freeArray(courseArray, courseCount);
}
