/*************************QuickSort**********************************************
 * Input : Tableau de N éléments distinct, premier et dernier élément du tableau
 * Postcondition : Eléments du tableau mais ordonner du plus petit au plus grand.*/ 

#include<iostream>
#include"QuickSort.hpp"
#include"ChoosePivot.hpp"
#include"Partition.hpp"

/*===============================Choix du pivot à traver un menu pivot =======================
                1 -> Premier element du tableau
                2 -> Dernier element du tableau
                3 -> Mediane du tableau     
                4 -> Choix aléatoire et uniforme d'un element du tableau
                5 -> Choix de la mediane des trois (premier, dernier et mediane du tableau) 

*==============================================================================================*/   



void QSort(std::vector<double> &A, int first, int last,int choice)
{
    int N = last - first + 1;
    std::vector<int> index;
    for(int i = 0; i < N; i++)
        index.push_back(i);
   
    
    if (first >= last)
        return;
    
    int i = 0;
    switch (choice)
    {
    case 1:
         i = firstPivot(A, first, last);
        break;
    case 2:
         i = lastPivot(A,first, last);
        break;
    case 3:
         i = Mediane(A, N);
        break;
    case 4:
         i = randomUniformePivot(A, first, last);
        break;

    default:
         i =  medianOfThreePivot(A, first, last);
        break;
    }

    int tmp = A[i];
    A[i] = A[first];
    A[first] = tmp;

    int j = partition(A, first, last);              // j devient la position du nouveau pivot

    QSort(A, first, j-1,choice);                    // recursion sur la première partie 
    QSort(A, j+1, last,choice) ;                    // reucrsion sur la dernière partie                   
}



void print(std::vector<double> &A, int first, int last)
{
    for(int i = first; i <= last; i++)
        std::cout << i << " ";
    std::cout << "\n";
}


int main()
{
    std::vector<double> A = {3,8,2,5,1,4,7,6} ;
    QSort(A,0,7,1);
    print(A,0,7);

    return 0; 
}
