#ifndef M_VARIABLE
#define M_VARIABLE
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>

//========================= Choix du premier element du tableau comme pivot ======================
int firstPivot(std::vector<double> &A, int first, int last) ; 
//======================== Choix du dernier element du tableau comme pivot =======================
int lastPivot(std::vector<double> &A, int first, int last)  ;
//======================== Choix de l'element median comme pivot==================================
double Mediane(std::vector<double> const& A, int N)         ;
//======================== Choix du pivot suivant une distribution aléatoire uniforme=============
int randomUniformePivot(std::vector<double> const& A, int first, int last);
//========================Choix de pseudo mediane comme pivot  ===================================
int medianOfThreePivot(std::vector<double> const& A, int first, int last) ;

#endif