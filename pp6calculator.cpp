#include <iostream>
#include <cmath>
#include <limits>

//Now we define the functions!

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

int main(){
  
  double a(0), b(0), c(0);
  char op('\0');
  
  while(true){
    
    
    std::cout << "What would you like to do? (*,/,-,+).. (q = quit) "<< std::endl;
    std:: cin >> op;
    if (!std::cin){
      std::cerr<<" [ERR] Please enter a valid operation"<< std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      continue;
    }

    if(op == 'q') break;

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
    
    if(op == '+'){
      c = add(a,b);
    }
    else if(op == '-'){
      c = subtract(a,b);
    }
    else if (op == '*'){
      c = multiply(a,b);
    }
    else if (op == '/'){
      if(fabs(b) > 0){
	c = divide(a,b);
      }
      if(fabs(b) == 0){
	std::cerr<<"[ERR] Can't divide by zero!" << std::endl;
	continue;
      }
    }
    else
      {
	std::cerr<<"[ERR] we need a valid operation"<<std::endl;
	continue;
      }

    std::cout << "the result of the operation '" << op 
	      << "' for numbers " << a << " and " << b 
	      << " is " << c << std::endl; 
  }

  std::cout << "Hope you enjoyed using the calculator" << std::endl;
  return 0;
}
    
