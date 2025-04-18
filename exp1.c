#include<stdio.h>
int main(){
    int marks[5];
    int total=0;
    int i;
    int passed=1;
    int valid=1;
    for(i=0;i<5;i++){
        valid=0;
        while(!valid){
            printf("Enter marks for subject %d(0to 100):",i+1);
            scanf("%d",&marks[i]);
            if(marks[i]>=0&&marks[i]<=100){
                valid=1;
                total+=marks[i];
                if(marks[i]<40){
                    passed=0;
                }
            }
            else{
                printf("Please enter a mark between 0 and 100\n");
            }
        }
    }
    double average = total/5.0;
    printf("%2f\n",average);
    if(passed){
        printf("passed\n");
    }else{
        printf("failed\n");
    }
    return 0;
}
        
   