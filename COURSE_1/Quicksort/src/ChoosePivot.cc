#include "ChoosePivot.hpp"
#include<random>

static std::mt19937 gen(std::random_device()); // Standard mersenne_twister_engine seeded with rd()

//==========================choose the first element as pivot====================
int firstPivot(std::vector<double> &A, int first, int last)
{
    return first;
}

//=========================choose the last element as pivot=======================
int lastPivot(std::vector<double> &A, int first, int last)
{
    return last;
}

//=============================Mediane ==========================================

double Mediane(std::vector<double> const &A, int N)
{
    // si N est pair
    if (N % 2 == 0)
    {

        std::nth_element(A.begin(), A.begin() + N / 2, A.end());

        std::nth_element(A.begin(), A.begin() + (N - 1) / 2, A.end());

        return round(A[((N - 1) / 2 + N / 2) / 2]); // round pour nous assurer que l'élément envoyer sera dans le tableau passé en argument
    }

    // si N est impair
    else
    {
        std::nth_element(A.begin(), A.begin() + N / 2, A.end());

        return round(A[N / 2]);
    }
}

//============================Choix du pivot suivant une distribution de probabilité uniforme==========
int randomUniformePivot(int first, int last)
{
    srand((unsigned)time(0));
    int randIndex = (rand() % last) + first;

    return randIndex;
}

int randomUniform(int first, int last)
{
    std::uniform_int_distribution<int> distribution(first, last);
    return distribution(gen);
}

//========================choix de pseudo-médiane : prendre la médiane de l'ensemble formé par le premier, le dernier et l'élément au milieu comme médiane
int medianOfThreePivot(std::vector<double> const &A, int first, int last)
{
    int middle = round(last - first + 1) / 2;
    double const x1 = A[first], x2 = A[last], x3 = A[middle];
    std::vector<double> tmp = {x1, x2, x3};

    if (Mediane(tmp, 3) == x1)
        return first;
    else if (Mediane(tmp, 3) == x2)
        return last;
    else
        return middle;
}
