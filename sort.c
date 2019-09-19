#include <stdio.h>
#include <string.h>

void DisplayStr(char** x, int nums, char* message){
    int i;
    puts(message);

    for(i = 0; i < nums; i++){
        printf(" [%d]번째 이름 --> %s \n", i, *(x+i));
    }
}

void BubbleSort(char** x, int nums){
    int i, j;
    char* tmp;

    for(i=0; i < nums-1; i++){
        for (j=0; j < nums-1-i; j++)
        {
            if(strcmp(*(x+j), *(x+j+1)) > 0){
                tmp = *(x+j);
                *(x+j) = *(x+j+1);
                *(x+j+1) = tmp;
            }
        }
        
    }
    DisplayStr(x, nums, "\n 정열 후");

}

int main(){
    char* strs[5] = {"apple", "grape", "mellon", "banana", "kiwi"};
    int n = sizeof(strs)/sizeof(char*);

    DisplayStr(strs, n, "원본");
    BubbleSort(strs, n);

    return 0;
}
