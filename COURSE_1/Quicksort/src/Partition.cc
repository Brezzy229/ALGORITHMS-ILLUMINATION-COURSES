#include <iostream>
#include "Partition.hpp"

int partition(std::vector<double> &A, int first, int last)
{
    int p = first;     // choix du premier élément comme pivot
    int i = first + 1; // incrément délimitant la les éléments qui sont plus petit que le pivot et le pivot

    for (int j = first + 1; j < p; j++)
    {
        if (A[j] < p) // Pour restaurer l'invariant
        {
            double tmp = A[j];
            A[j] = A[i];
            A[i] = tmp;
            i++;
        }
    }
    double tmp = A[first];
    A[first] = A[i - 1];
    A[i - 1] = tmp; // placer le pivot correctement
    return i - 1;   // renvoyer la position du pivot.
}


