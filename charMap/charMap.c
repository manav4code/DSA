#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define For(n) for(int i = 0; i < n; ++i)
#define STR_SIZE 1000


void printArray(int *arr,int size){
    For(size){
        printf("%d ",*(arr+i));
    }
    printf("\n");
    return;
}

char* tolower(char* str){
    for(int i = 0; str[i] != '\0'; ++i){
        if(str[i] <= 90){
            str[i] += 32;
        }
    }
    return str;
}

int* charMap(char* str){

    int* arr = (int*)calloc(sizeof(int),26);
    memset(arr,0,26);

    char* temp = (char*)calloc(sizeof(char),STR_SIZE);
    strcpy(temp,str);

    temp = tolower(temp);

    for(int i = 0; temp[i] != '\0'; ++i){
        int index = temp[i] - 'a';
        *(arr + index) += 1;
    }

    free(temp);
    return arr;
}

int main(){
    char* str= (char*)calloc(1,STR_SIZE);
    char* temp = (char*)calloc(1,STR_SIZE);

    printf("Enter String: ");gets(str);
    
    printf("Count of Characters:\n");
    int* count = charMap(str);

    for(int i = 0; i < 26; ++i){
        if(count[i]!=0){
            printf("%c : %d\n",('a' + i),count[i]);
        }
    }

    return 0;
}