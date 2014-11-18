#include <iostream>
#include <cmath>
#include "PP6Math.hpp"
#include <algorithm>
#include <limits>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <complex>

#include "MUONANALYSIS.hpp"

void muon_pairs(){
  std::string col2[1000], col6[1000];
  double col1[1000], col3[1000], col4[1000], col5[1000];
  double mupx[120], mupy[120], mupz[120], mu_event[120];
  double amupx[120], amupy[120], amupz[120], amu_event[120];
  double muE[120], amuE[120];
  double Inv_2D[120][120];
  double Inv[10000];
  double M = 0.1057;  //muon mass

  int P = 0; // counter for mu+
  int N = 0; // counter for mu-

  std::ifstream in("ObsPart.dat");
  while(!in.eof()){
    for (int i = 0; i < 1000; i++){
      in >> col1[i];
      in >> col2[i];
      in >> col3[i];
      in >> col4[i];
      in >> col5[i];
      in >> col6[i];
    }
  }

  for (int j = 0; j < 1000; j++){
    if(col2[j] == "mu-"){
      N++;
      mu_event[N-1] = col1[j];
      mupx[N-1] = col3[j];
      mupy[N-1] = col4[j];
      mupz[N-1] = col5[j];
      muE[N-1] = std::sqrt( (mupx[N-1]*mupx[N-1]) + (mupy[N-1]*mupy[N-1]) + (mupz[N-1]*mupz[N-1]) + (M*M) );
	  
    }

    if(col2[j] == "mu+"){
      P++;
      amu_event[P-1] = col1[j];
      amupx[P-1] = col3[j];
      amupy[P-1] = col4[j];
      amupz[P-1] = col5[j];
      amuE[P-1] = std::sqrt( (amupx[P-1]*amupx[P-1]) + (amupy[P-1]*amupy[P-1]) + (amupz[P-1]*amupz[P-1]) + (M*M) );
    }
  }

  for (int i = 0; i < N; i++){
    for (int j = 0; j < P; j++){
      Inv_2D[i][j] = std::sqrt( ((muE[i] + amuE[j])*(muE[i] + amuE[j]))
				- ((mupx[i] + amupx[j])*(mupx[i] + amupx[j]))
				- ((mupy[i] + amupy[j])*(mupy[i] + amupy[j]))
				- ((mupz[i] + amupz[j])* (mupz[i] + amupz[j]))) ;

      int D = N*i + j;
      Inv[D] =  std::sqrt( ((muE[i] + amuE[j])*(muE[i] + amuE[j]))
			   - ((mupx[i] + amupx[j])*(mupx[i] + amupx[j]))
			   - ((mupy[i] + amupy[j])*(mupy[i] + amupy[j]))
			   - ((mupz[i] + amupz[j])*(mupz[i] + amupz[j])));
    }
  }

  std::cout << " The program is now sorting those muon values " << std::endl;
  for(int f = 0; f < 9707;f++){
    std::sort(Inv,Inv+9707,std::greater<double>());
  }
  
  for(int f = 0; f < 11; f++){
    std::cout<< " the result of the sort is " << Inv[f] << std::endl;
    for(int k =0; k < N; k++){
      for(int i = 0; i < P; i++){
	if(Inv[f] == Inv_2D[k][i]){
	  std::cout << " muon at = " << mu_event[k] << " antimuon at = " << amu_event[i] << std::endl;
	}
      }
    }
  }

  std::cout << " number of muons = " << N << std::endl;
  std::cout << " number of antimuons = " << P << std::endl;
}
