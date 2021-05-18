#include<stdio.h>
#include<stdlib.h>
#include "rdtsc.h"

#define N 2

double **saisie_matrice(double **mat,int n){
    int i,j;

    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            printf("[%d][%d]= ", i, j);
            scanf("%lf", &mat[i][j]);
            printf("\n");
        }
    }
   
  return mat;

     
}


double **allocation_matrice(int n){
     int i;
     double **mat= malloc(n*sizeof(double*));
        for(i=0;i<n;i++)
        {
            mat[i] = malloc(n*sizeof(double));
        }
    return mat;

}

void afficher_matrice(double **M,int  n)
{
  int i,j;
  	for(i=0;i<n;i++){
               printf("\n");
		for(j=0;j<n;j++){ 
                  printf(" %lf",*(*(M+i)+j));}
                        }
        printf("\n");
}

void liberer_matrice(double **m, int n)
   {
    int i;
    for (i=0; i<n; i++){
       free(m[i]);
       free(m);
       }
    }


int main(void)
 {
      
   double **A,**B,**C;
   double a1,b1;
   int  i,j,k;
   
    
   // Matrice A
   A=allocation_matrice(N);
   A=saisie_matrice(A,N);
   printf("\n Matrice A=\n");
   afficher_matrice(A,N);

   //Matrice B
   B=allocation_matrice(N);
   B=saisie_matrice(B,N);
   printf("\n Matrice B=\n");
   afficher_matrice(B,N);
   
   //Matrice C
   C=allocation_matrice(N);
 
   

 
   //Question 1
   a1= rdtsc();
   for(i=0;i<N;i++)
   {	for(j=0;j<N;j++)
	{	for(k=0;k<N;k++)
                {
                 C[i][j]+=A[i][k]*B[k][j];
                   
                }
        }

   }
   //Question 3
   /* for(i=0;i<N;i++)
   {	for(k=0;k<N;k++)
	{	for(j=0;j<N;j++)
                {
                 C[i][j]+=A[i][k]*B[k][j];
                   
                }
        }

   }
   */


   b1=rdtsc(); 
   double t1 = (b1 - a1); 
   printf("\n Cycles :%lf\n ",t1);
   printf("\n la matrice C=\n");
   afficher_matrice(C,N);
  
   liberer_matrice(A,N);
   liberer_matrice(B,N);
   liberer_matrice(C,N);
  
   
  

   
 return 0;
 }






