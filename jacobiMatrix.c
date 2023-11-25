#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 3 // Number of variables
double A[N][N] = {
        {4,1,1},
        {2,5,2},
        {1,2,4},
        
      };
double b[N] = {8, 3, 11}; 
double x[N] = {0}; 
double x_n[N]; 
int max_iterations = 100;
double tolerance = 10e-6;
int iteration, i, j,k;

void jacob(){
     for (iteration = 0; iteration < max_iterations; iteration++) {
        for ( i = 0; i < N; i++) {
            double sum = b[i];
            for ( j = 0; j < N; j++) {
                if (j != i) {
                    sum -= A[i][j] * x[j];
                }
            }
            x_n[i] = sum / A[i][i];
        }
        
    
        
        double max_diff = 0;
        for (i = 0; i < N; i++) {
            double diff = fabs(x_n[i] - x[i]);
            if (diff > max_diff) {
                max_diff = diff;
            }
        }

        
        for (i = 0; i < N; i++) {
            x[i] = x_n[i];
        }

        if (max_diff < tolerance) {
            break; 
        }
        
    }
    
    printf("Total iteration: %d\n", iteration);
   
    printf("Solution:\n");
    for ( i = 0; i < N; i++) {
        printf("x%d = %.6f\n", i + 1, x[i]);
    }


}

int main() {
   int flag = 0;
   double sum =0;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(i != j){
                sum = sum + abs(A[i][j]);
            }
        }
        
        if(abs(A[i][i]) <= sum){
            flag = 1;
        }
        sum = 0;
        
    }
    if(flag == 1){
        printf("It is not diagonally dominated.\n");
        return 0;
    }
    else{
        jacob();
    }

    

    return 0;
}




