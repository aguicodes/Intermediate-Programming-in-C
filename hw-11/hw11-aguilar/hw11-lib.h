struct curriculum{
    char *courseName;
    char *category;
    char *preQ;
    char *notes;
};
struct curriculum *createRqmtList (char *file, int *counter);
void expandStruct ( struct curriculum **s, int *size);
char** createCourseWorkArr(char *file, int *counter);
void freeStruct(struct curriculum *s, int counter);
void freeArray(char **s, int count);
void printOutput(struct curriculum *s1, char **s2, int s1Count, int s2Count);
int preReqs(char **s1, char *s2, int count);
