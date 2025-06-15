#include <stdio.h>
#include <stdlib.h>

int *buildArray(FILE *fp, int arrLen) {
    // create an array size based on arrLen
    int *data = calloc(arrLen, sizeof(int));
    int check = 0;
    int value = 0;
    int arrIndex = 0;
    /* Until EOF is encountered assign all integers to data[index]
     * return the starting address to calling function
     */
    while ((check = fscanf(fp, "%d", &value)) != EOF) {
        data[arrIndex++] = value;
    }
    return data;
}

void writeToFile(const char *fileName, int *arr, int arr_size, int max, double average) {
    FILE *fp = fopen(fileName, "w");
    if(fp == NULL)
        printf("fileName opening for write failed !\n");

    // used fprintf to write formatted strings to file
    fprintf(fp, "[Array]: ");
    for (int i = 0; i < arr_size; i++) {
        fprintf(fp, "%d ", arr[i]);
    }
    fprintf(fp, "\n");
    fprintf(fp, "Max element is : %d\n", max);
    fprintf(fp, "Average of all the elements is : %lf\n", average);

    fclose(fp);
}

void computeAvgAndMax(int *data, int arrLen) {
    /* compute max as int and average as double
     * as per requirement
     */
    int max = 0;
    double tot = 0;
    for(int i = 0; i < arrLen; i++) {
        if(data[i] > max)
            max = data[i] * 1;
        tot += data[i];
    }
    // print to stdout

    printf("[Array]: ");
    for (int i = 0; i < arrLen; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    printf("Max element is : %d\n", max);
    printf("Average of all the elements is : %lf\n", tot / arrLen);

    // call the function to write the output to a file
    writeToFile("answer-hw3.txt", data, arrLen, max, tot / arrLen);

}

int main(void) {

    /* open a file in read mode, assign the resulting pointer to a variable.
     * check for NULL to make sure the pointer points to valid file.
     */
    FILE *pFile = fopen("int_file.txt", "r");
    if(pFile == NULL)
        printf("int_file.txt does not exists\n");

    /* use fscanf to only read the first integer to get the array size
     * store the array size in a variable and send the file pointer 
     * to the function to build the array
     */
    int arrSize = 0;
    if(!(fscanf(pFile, "%d", &arrSize)))
        printf("reading from int_file.txt failed!\n");

    // build the array and get address to the start of the element
    int *arr = buildArray(pFile, arrSize);

    // call the function to compute average and max
    computeAvgAndMax(arr, arrSize);

    free(arr);
    fclose(pFile);

    return 0;
}
