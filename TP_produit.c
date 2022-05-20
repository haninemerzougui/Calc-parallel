#include "omp.h"
#include <stdio.h>
#define N 100
#define N 100

int main(){
    int Matrice[N][N];
    int Matrice1[N][N];
    int Resultat[N][N];
    int i,j,m;
    double t1,t2;
    

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            Matrice[i][j]=i;
            }
            
        }
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            Matrice1[i][j]=j;
            }
            
        }

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            Resultat[i][j]=0;
            for(m=0;m<N;m++){
            //Resultat[i][j]=Matrice[i][m]*Matrice1[m][j];
            //Resu[i][j]=Resu[i][j]+Resultat[i][j];  
            //m++;        
                Resultat[i][j]+=Matrice[i][m]*Matrice1[m][j];

            }

        }

    }

    





    
    /*#pragma omp parallel for private(j)
        for(i=0;i<N;i++){
            Resultat[i][j]=0;
            for(j=0;j<N;j++){
                Resultat[i][j]=Resultat[i][j]+(Matrice[i][j]*Matrice1[i][j]);
            }
        }*/

    t1= omp_get_wtime();

    printf("Le resultat du produit \n");
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf ("%d \t",Resultat[i][j]);
            } 
        }
    t2= omp_get_wtime();   
    printf("time= %f  \n",t2-t1);


    
}