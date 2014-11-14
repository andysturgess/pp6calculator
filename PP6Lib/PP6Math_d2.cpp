#include "PP6Math_d2.hpp"

// Standard Library

#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <utility>
#include <complex>

//---------------------------------------------------------------------
// Function Definitions

double swap(double& a, double&b){
  a = a + b;
  b = a - b;
  a = a - b;
  return(1);
}

double Bubble(double array[]){
 
  int i,j;
  for(i = 0; i < 5; i++){
    for(j = 0; j < 4 - i; j++){
      if(array[j] < array[j+1]){                          
	swap(array[j],array[j+1]);
      }
    }
  }
  return(1);
}
