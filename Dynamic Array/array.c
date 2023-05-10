#include<stdio.h>
#include<stdlib.h>

/*
#define For(n) for(int i = 0; i < n; ++i)
int** initMatrix(int size){
    int **temp = (int **)calloc(sizeof(int*),size);

    For(size){
        *(temp+i) = (int *)calloc(sizeof(int),size);
    }

    return temp;
}

int** createMatrix(int size){

    int **arr = initMatrix(size);

    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            scanf("%d",(*(arr+i)+j));
        }
    }

    return arr;
}

int** matrixMultiplication(int **arr1,int **arr2,int size){
    int **sum = initMatrix(size);

    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            *(*(sum + i) + j) = 0;
            for(int k = 0; k < size ; ++k){
                (*(*(sum + i) + j)) += *(*(arr1 + i) + k) * (*(*(arr2 + k) + j));
            }
        }
    }

    return sum;
}

void printMatrix(int **arr,int size){
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            printf("%d ",*(*(arr+i)+j));
        }
        printf("\n");
    }
    return;
}

int main(){
    int size;

    printf("Size: ");
    scanf("%d",&size);getchar();

    int **arr1 = createMatrix(size);
    int **arr2 = createMatrix(size);

    int **matMul = matrixMultiplication(arr1,arr2,size);
    printMatrix(matMul,size);
    // printMatrix(arr1,size);printf("\n");
    // printMatrix(arr2,size);printf("\nFINISH");
    return 0;
}

*/


// #include<stdio.h>
// #include<stdlib.h>


// // Print Array
// void printArray(int* arr,int* size){
//     for(int i = 0; i < *size; ++i){
//         printf("Address: %d Value: %d\n",(arr+i),*(arr+i));
//     }
//     return;
// }

// void* readArray(int* size){
//     int* arr = (int*)calloc(sizeof(int),(*size));

//     for(int i = 0; i < *size; ++i){
//         scanf("%d",arr + i);
//     }

//     return (void *)arr;
// }

// int main(){
    
//     int* size = (int*)malloc(sizeof(int));

//     printf("Enter Size: ");
//     scanf("%d",size);getchar();

    
//     int* arr = (int *)readArray(size);
//     printArray(arr,size);

//     system("pause");
//     return 0;
// }