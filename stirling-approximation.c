#include<stdio.h>
#include<math.h>
#include<time.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

double factorial_manual(int n);
double stirling_approximation(int n);
int inputValidasi(int* var);

int main() {;

  int jumlahNumber;
  do{
    printf("masukkan jumlah test case: ");
    
  } while(inputValidasi(&jumlahNumber) != 1);
  
  
  int arr[jumlahNumber];

    for(int i = 0; i < jumlahNumber; i++){

      do {
  
        printf("Number %d: ", i+1);

      }while(inputValidasi(&arr[i]) != 1);
      
      #ifdef _WIN32
        system("cls");
      #else
        system("clear");
      #endif

      printf("nilai saat ini: \n");
      
      for(int j = 0; j < i + 1; j++) {
        
        printf("number %d: %d\n", j+1 ,arr[j]);
      }

      printf("\n");
    }

    #ifdef _WIN32
      system("cls");
    #else
      system("clear");
    #endif
    
    printf("\n\t\t\t\t\t\t\t\tFACTORIAL MANUAL VS STIRLING APPROXIMATION\n\n");
    printf("=============================================================================================================================================================\n");
    printf("| %-6s || %-70s | %-70s |\n", "number","manual factoring", "stirling approximation");
    printf("|===========================================================================================================================================================|\n");
    for(int i = 0; i < jumlahNumber; i++){
        int num = arr[i];
        clock_t start, end;
        double time_taken;

        //start = clock();i
        double fact_manual = factorial_manual(num);
        // end = clock();
        // time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        
        // start = clock();
        double fact_stirling = stirling_approximation(num);
        // end = clock();
        // double time_stirling = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("| %-6d || %-70.0f | %-70.6f |\n", 
            num, fact_manual, fact_stirling);
        if( i != jumlahNumber-1){
            printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
        }else{
          printf("|===========================================================================================================================================================|\n");
        }
    }

    return 0;
}

double factorial_manual(int n) {
    double result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

double stirling_approximation(int n) {
    if (n == 0) return 1;     

    return sqrt(2*M_PI*n)* pow(n/M_E,n);
}

int inputValidasi(int *var) {
    
  char buffer[256];

  if(fgets(buffer, 256, stdin) != NULL) {
  
     buffer[strcspn(buffer, "\n")] = '\0';
  
    if (!(strlen(buffer) < 4)) {
       printf("kelebihan mas\n\n");
      return 0;
    }

    int status = 0;

    for (int i = 0; i < strlen(buffer); i++) {

      if(!(isdigit(buffer[i]))) {
        status = 1;
        break;
      }  
    }

    if(status == 1) {
       printf("harus berbentuk integer\n\n");
      return 0;
    }

    *var = atoi(buffer);

     if(*var < 0) {
      printf("masukkan angka positive\n\n");
      return 0;
    }

    return 1;
  }

  printf("input tidak valid\n\n");
  clearerr(stdin);
  return 0;
}