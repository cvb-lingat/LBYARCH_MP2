#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void DAXPY_ASM(int n, double A, double* vector_X, double* vector_Y, double* vector_Z);

void DAXPY_C()
{
    FILE *fp = fopen("data.txt", "r");
    
    int size;
    int i;
    double A;

    fscanf(fp, "%d", &size);
    fscanf(fp, "%lf", &A);
    double* vector_Z = malloc(size * sizeof(double));
    double* vector_X = malloc(size * sizeof(double));
    double* vector_Y = malloc(size * sizeof(double));

    clock_t start_time, end_time;
    double run_time;

    for(i = 0; i < size; i++)
    {
        fscanf(fp, "%lf", &vector_X[i]);
    }

    for(i = 0; i < size; i++)
    {
        fscanf(fp, "%lf", &vector_Y[i]);
    }

    fclose(fp);

    system("cls");

    // ACTUAL DAXPY:

    start_time = clock();

    for(i = 0; i < size; i++)
    {
        vector_Z[i] = A*vector_X[i] + vector_Y[i];
    }

    end_time = clock();

    printf("First 10 Elements of Z:\n\n");

    for(i = 0; i < 10; i++)
    {
        printf("Z[%d] = %lf \n", i, vector_Z[i]);
    }
    
    run_time = (double)(end_time - start_time) * 1000.0 / CLOCKS_PER_SEC;
    printf("Execution Time: %.2f milliseconds\n", run_time);

    free(vector_X);
    free(vector_Y);
    free(vector_Z);

    system("pause");
}

void call_ASM()
{
    FILE *fp = fopen("data.txt", "r");
    
    int size;
    int i;
    double A;

    fscanf(fp, "%d", &size);
    fscanf(fp, "%lf", &A);
    double* vector_Z = malloc(size * sizeof(double));
    double* vector_X = malloc(size * sizeof(double));
    double* vector_Y = malloc(size * sizeof(double));

    clock_t start_time, end_time;
    double run_time;

    for(i = 0; i < size; i++)
    {
        fscanf(fp, "%lf", &vector_X[i]);
    }

    for(i = 0; i < size; i++)
    {
        fscanf(fp, "%lf", &vector_Y[i]);
    }

    fclose(fp);

    system("cls");

    start_time = clock();

    // ACTUAL DAXPY:
    DAXPY_ASM(size, A, vector_X, vector_Y, vector_Z);

    end_time = clock();

    printf("First 10 Elements of Z:\n\n");

    for(i = 0; i < 10; i++)
    {
        printf("Z[%d] = %lf \n", i, vector_Z[i]);
    }

    run_time = (double)(end_time - start_time) * 1000.0 / CLOCKS_PER_SEC;
    printf("Execution Time: %.2f milliseconds\n", run_time);   
 
    free(vector_X);
    free(vector_Y);
    free(vector_Z);

    system("pause");    
}

void Run_Both()
{
    FILE *fp = fopen("data.txt", "r");
    
    int size;
    int i;
    int flag = 1;
    double A;

    fscanf(fp, "%d", &size);
    fscanf(fp, "%lf", &A);
    double* vector_Z_C = malloc(size * sizeof(double));
    double* vector_Z_ASM = malloc(size * sizeof(double));
    double* vector_X = malloc(size * sizeof(double));
    double* vector_Y = malloc(size * sizeof(double));

    clock_t start_time, end_time;
    double run_time_C, run_time_ASM;

    for(i = 0; i < size; i++)
    {
        fscanf(fp, "%lf", &vector_X[i]);
    }

    for(i = 0; i < size; i++)
    {
        fscanf(fp, "%lf", &vector_Y[i]);
    }

    fclose(fp);

    system("cls");

    start_time = clock();
    for(i = 0; i < size; i++)
    {
        vector_Z_C[i] = A*vector_X[i] + vector_Y[i];
    }
    end_time = clock();
    run_time_C = (double)(end_time - start_time) * 1000.0 / CLOCKS_PER_SEC;
    
    start_time = clock();
    DAXPY_ASM(size, A, vector_X, vector_Y, vector_Z_ASM);
    end_time = clock();
    run_time_ASM = (double)(end_time - start_time) * 1000.0 / CLOCKS_PER_SEC;

    // sanity check:
    for(i = 0; i < size; i++)
    {
        if(vector_Z_ASM[i] != vector_Z_C[i])
        {
            flag = 0;
        }
    }

    printf("Sanity Check: First 10 Elements of Z by Assembly and Z by C\n");
    printf("Note: All Elements Have Been Checked by the Program.\n\n");

    for(i = 0; i < 10; i++)
    {
        printf("ASM [%d] = %lf \n", i, vector_Z_ASM[i]);
        printf("C [%d] = %lf \n\n", i, vector_Z_C[i]);
    }

    if (flag)
    {
        printf("\nSanity Check Passed!\n\n");
        printf("C Execution Time: %.2f milliseconds\n", run_time_C);
        printf("ASM Execution Time: %.2f milliseconds\n\n", run_time_ASM);
    }

    else if (flag == 0)
    {
        printf("\nC and ASM not same for some reason!\n");
    }

    free(vector_X);
    free(vector_Y);
    free(vector_Z_ASM);
    free(vector_Z_C);
    system("pause");
}

int main ()
{
    int flag = 1;
    int input;

    do
    {
        system("cls");
        
        printf("[1] = C Version of DAXBY\n");
        printf("[2] = x86-64 Assembly Version of DAXBY\n");
        printf("[3] = Run Both\n");
        printf("[4] = Exit\n");

        scanf("%d", &input);

        if(input == 1)
        {
            system("cls");
            DAXPY_C();
        }

        else if(input == 2)
        {
           system("cls");
           call_ASM();
        }

        else if(input == 3)
        {
            system("cls");
            Run_Both();
        }

        else if(input == 4)
        {
            flag = 0;
        }

    } while (flag == 1);
    
    return 0;
}