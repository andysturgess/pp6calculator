#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <utility>
#include <complex>

//=======================================
//This is where the functions are defined
//=======================================

double add(double a,double b){
  return a + b;
}
double subtract(double a, double b){
  return a - b;
}
double multiply(double a,double b){
  return a * b;
}
double divide(double a, double b){
  return a / b;
}
double intercept(double a, double b, double c, double d){
  double gradient = (d-b)/(c-a);
  double x_intercept = b - gradient*a;
  return x_intercept;
}

std::pair<std::complex<double>,std::complex<double> > quadratic(std::complex<double> m,std::complex<double> n, std::complex<double> o, bool& pos, bool& neg){
  std::complex<double> discriminant = n * n - 4.0*m*o;
  if (std::real(discriminant) >= 0.){ 
    pos = true;
  }
  else{
    neg = true;
  }
  std::pair<std::complex<double>,std::complex<double> > solutions;
  std::complex<double> x1 = (-n + std::sqrt(discriminant))/(2.*m);
  std::complex<double> x2 = (-n - std::sqrt(discriminant))/(2.*m);
  solutions.first = x1;
  solutions.second = x2; 
  return solutions;
}

double vectorlength3(double a, double b, double c){
  double length_3 =std::sqrt( a*a + b*b +  c*c);
  return length_3;
    }

double vectorlength4(double a, double b, double c, double d){
  double length_4 = d*d - a*a - b*b -c*c ;
  return length_4;
}

double invmass(double a, double b, double c, double d, double theta){
  double ConvertDegtoRad = theta * (3.14159/180);
  double squared_terms = a*a + c*c -b*b - d*d;
  double cross_terms = 2*a*c - 2*b*d*ConvertDegtoRad;
  double inv_mass_sq = squared_terms + cross_terms;
  double inv_mass = sqrt(inv_mass_sq);
  return inv_mass;
}

double swap(double& a, double&b){
  a = a + b;
  b = a - b;
  a = a - b;
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
  
}


int main(){

  double a(0), b(0), res(0), res2(0), c(0), d(0), check(0), theta(0);
  double bubble_array[5];
  std::pair<std::complex<double>,std::complex<double> > ReturnQuadSols;
  std::pair<double,double> vlength;
  char op('\0');

  // =======================================
  // Variables used in the program - defined.
  // =======================================
  
  while(true){
    std::cout << "What would you like to do? (q = quit) "<< std::endl;
    std::cout << "*  = multiplication." << std::endl;
    std::cout << "/  = division." << std::endl;
    std::cout << "-  = subtraction." << std::endl;
    std::cout << "*  = addition" << std::endl;
    std::cout << "i  = x intercept." << std::endl;
    std::cout << "x  = solve a quadratic." << std::endl;
    std::cout << "t  = length of a 3 vector." << std::endl;
    std::cout << "f  = length of a 4 vector." << std::endl;
    std::cout << "m  = invariant mass of two particles " << std::endl;
    std::cout << "s  = swap variables" << std::endl;
    std::cout << "b  = bubble sort variables" << std::endl;
    
    std:: cin >> op;
    if(op == 'q') break;

    if(op == '+'){
      std::cout << "Please enter your first number" << std::endl;
      std::cin >> a;
      if(!std::cin){
	std::cerr<<"[ERR] Please enter a valid number" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	continue;
      }
      
      std::cout << "Please enter your second number" << std::endl;
      std::cin >> b;
      if(!std::cin){
	std::cerr<<"[ERR] Please enter a valid number" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	continue;
      }
      
      res = add(a,b);
      std::cout << " The result of adding " << a << " and " << b << " is " << res << std::endl;
    }
    
    // ==================================================
    // calculating the addition function for two numbers;
    // =================================================
    
    if(op == '-'){
      std::cout << "Please enter your first number" << std::endl;
      std::cin >> a;
      if(!std::cin){
	std::cerr<<"[ERR] Please enter a valid number" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	continue;
      }

      std::cout << "Please enter your second number" << std::endl;
      std::cin >> b;
      if(!std::cin){
	std::cerr<<"[ERR] Please enter a valid number" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      	continue;
      }	
      
      res = subtract(a,b);
      std::cout << " The result of subtracting " << a << " and " << b << " is " << res << std::endl;
    }
    
    // ====================================================
    // calculating the subtraction function for two numbers;
    // ====================================================
    
    if(op == '*'){
      std::cout << "Please enter your first number" << std::endl;
      std::cin >> a;
      if(!std::cin){
	std::cerr<<"[ERR] Please enter a valid number" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      	continue;
      }	
      
      std::cout << "Please enter your second number" << std::endl;
      std::cin >> b;
      if(!std::cin){
	std::cerr<<"[ERR] Please enter a valid number" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      	continue;
      }	
      
      res = multiply(a,b);
      std::cout << " The result of multiplying " << a << " and " << b << " is " << res << std::endl;
    }

    // =======================================================
    // calculating the multiplication function for two numbers;
    // =======================================================
    

    if(op == '/'){
      std::cout << "Please enter your first number" << std::endl;
      std::cin >> a;
      if(!std::cin){
	std::cerr<<"[ERR] Please enter a valid number" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      	continue;
	 }	
      
      std::cout << "Please enter your second number" << std::endl;
      std::cin >> b;
      if(!std::cin){
	std::cerr<<"[ERR] Please enter a valid number" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      continue;
      }
     
      res = divide(a,b);
      std::cout << " The result of dividing " << a << " and " << b << " is " << res << std::endl;
    }
  
    // =================================================
    // calculating the division function for two numbers;
    // =================================================
      
    if(op == 'i'){
      std::cout << "Please enter x of point 1" << std::endl;
      std::cin >> a;
      if(!std::cin){
	std::cerr<<"[ERR] Please enter a valid number" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      continue;
      }
      
      std::cout << "Please enter y of point 1" << std::endl;
      std::cin >> b;
      if(!std::cin){
	std::cerr<<"[ERR] Please enter a valid number" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	continue;
      }

      std::cout << "Please enter x of point 2" << std::endl;
      std::cin >> c;
      if(!std::cin){
	std::cerr<<"[ERR] Please enter a valid number" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	continue;
      }

      std::cout << "Please enter y of point 2" << std::endl;
      std::cin >> d;
       if(!std::cin){
	std::cerr<<"[ERR] Please enter a valid number" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	continue;
      }
      
       else{
	 std::cout << "intercept of x for a line connecting coords ("
		 << a << ","<< b
		 << ") and (" << c << ","<< d
		 << ") is " << res << "\n" << std::endl;
       }
    }
  
    // =======================================================================
    // Input/output to calculate the intercept of a straight line (y = mx + c)
    // ======================================================================
   
    if(op == 'x'){
      std::cout << "the standard form of quadratic equation is ax^2 + bx + c)" << std::endl;

      bool pos = false; 
      bool neg = false;

      // The two variables which are used for passing by reference
      // Not really important; just another way of telling us if  
      // we are dealing with imaginary solutions or not.

      std::cout << "Please enter a" << std::endl;
      std::complex<double> m;
      std::cin >> m;
      if(!std::cin){
	std::cerr<<"[ERR] Please enter a valid number" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	continue;
      }
      
      std::cout << "Please enter b" << std::endl;
      std::complex<double> n;
      std::cin >> n;
      if(!std::cin){
	std::cerr<<"[ERR] Please enter a valid number" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	continue;
      }
      
      std::cout << "Please enter c" << std::endl;
      std::complex<double> o;
      std::cin >> o;
      if(!std::cin){
	std::cerr<<"[ERR] Please enter a valid number" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	continue;
      }
      
      
      ReturnQuadSols = quadratic(m,n,o,pos,neg);
      
      if (pos == true) std::cout << " valid discriminant = non-imaginary solutions"
				 << std::endl;
      if (neg == true) std::cout << " invalid discriminant = imaginary solutions"
				 << std::endl;
      std::cout << " The form of the solution is (real,imaginary)" << std::endl;
      std::cout << " for example, a solution like (-3 + 2i) & (-3 - 2i)" << std::endl;
      std::cout << " Would appear as (-3,2) and (-3,-2)" << std::endl;
      std::cout << " The two solutions for this quadratic equation are "
		<< ReturnQuadSols.first << " and " << ReturnQuadSols.second << "\n" << std::endl;
    }

    // =========================================================
    // Input/out to obtain the solutions of a quadratic equation
    // ========================================================
    
    if(op == 't'){
      std::cout << " Please enter the value of the 'x' coordinate" << std::endl;
      std::cin >> a;
      if(!std::cin){
	std::cerr<<"[ERR] Please enter a valid number" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	continue;
      }
      
      std::cout << " Please enter the value of the 'y' coordinate" << std::endl;
      std::cin >> b;
      if(!std::cin){
	std::cerr<<"[ERR] Please enter a valid number" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	continue;
      }
      
      std::cout << " Please enter the value of the 'Z' coordinate" << std::endl;
      std::cin >> c;
      if(!std::cin){
	std::cerr<<"[ERR] Please enter a valid number" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	continue;
      }

      res = vectorlength3(a,b,c);
      std::cout << " The length of this three-vector is " << res << std::endl;
    }
    
    // ====================================================
    // Input/output for calculating a length of a 3 vector
    // ====================================================

  if(op == 'f'){
      std::cout << " Please enter the value of the 'x' coordinate" << std::endl;
      std::cin >> a;
      if(!std::cin){
	std::cerr<<"[ERR] Please enter a valid number" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	continue;
      }
      
      std::cout << " Please enter the value of the 'y' coordinate" << std::endl;
      std::cin >> b;
      if(!std::cin){
	std::cerr<<"[ERR] Please enter a valid number" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	continue;
      }
      
      std::cout << " Please enter the value of the 'Z' coordinate" << std::endl;
      std::cin >> c;
      if(!std::cin){
	std::cerr<<"[ERR] Please enter a valid number" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	continue;
      }

      std::cout << " Please enter the value of the 't' coordinate" << std::endl;
      std::cin >> d;
      if(!std::cin){
	std::cerr<<"[ERR] Please enter a valid number" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	continue;
      }
      
      res = vectorlength4(a,b,c,d);
      std::cout << " The length of this four-vector is " << res << std::endl;
    }
    
    // ===================================================
    // Input/output for calculating a length of a 4 vector
    // ===================================================
    
  if(op == 'm'){
    std::cout << " Please enter the energy of particle 1 (GeV)" << std::endl;
    std::cin >> a;
    if(!std::cin){
      std::cerr<<"[ERR] Please enter a valid number" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      continue;
    }
      
    std::cout << " Please enter the momentum of particle 1 (GeV)" << std::endl;
    std::cin >> b;
    if(!std::cin){
      std::cerr<<"[ERR] Please enter a valid number" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      continue;
    }
	
    if(b > a){
      std::cout << "Momentum > Energy; not possible!" << std::endl;
      continue;
    }
       
    std::cout << " Please enter the energy of particle 2 (GeV)" << std::endl;
    std::cin >> c;
    if(!std::cin){
      std::cerr<<"[ERR] Please enter a valid number" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      continue;
    }

    std::cout << "Please enter the momentum of particle 2 (GeV)" << std::endl;
    std::cin >> d;
    if(!std::cin){
      std::cerr<<"[ERR] Please enter a valid number" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      continue;
    }

    if(d > c){
      std::cout << "Momentum > Energy; not possible!" << std::endl;
      continue;
    }

    std::cout << "Please enter the angle between the collision (180 degrees is head on!)" << std::endl;
    std::cin >> theta;
    if(!std::cin){
      std::cerr<<"[ERR] Please enter a valid number" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      continue;
    }

    res = invmass(a,b,c,d,theta);
    std::cout << "The Invariant mass of the system is " << res << std::endl;
  }

  // =============================================================
  // input/output to calculate the invariant mass of two particles
  // =============================================================
      
  if(op == 's'){
    std::cout << "Please enter your first number" << std::endl;
    std::cin >> a;
    
    if(!std::cin){
      std::cerr<<"[ERR] Please enter a valid number" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      continue;
    }
    
    std::cout << "Please enter your second number" << std::endl;
    std::cin >> b;
    if(!std::cin){
      std::cerr<<"[ERR] Please enter a valid number" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      	continue;
    }	
    std::cout << " the result of swapping " << a << " and " << b << std::endl;
    res = swap(a,b);
    std::cout << " means that a is now " << a << " and b is now " << b << std::endl;
  }

  // ======================================================
  // this inputs and outputs the swap of two numbers a and b
  // ======================================================
  
  if(op == 'b'){
    std::cout << "Please enter five numbers" << std::endl;
    for (int j = 0; j < 5; j++){
      std::cin >> bubble_array[j];
    }	

    if(!std::cin){
      std::cerr<<"[ERR] Please enter a valid number" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      continue;
    }
    std::cout << " The array has now been bubble sorted.." << std::endl;
    Bubble(bubble_array);
    for(int i = 0; i < 5; i++){
      std::cout << bubble_array[i] << std::endl;
    }
  }

  // =======================================================
  // this inputs and outputs the bubble sort of five numbers
  // =======================================================
  
  }
  
  std::cout << "Please use me again sometime in the future?" << std::endl;
  return 0;
  
}
