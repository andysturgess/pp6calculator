#include <iostream>
#include <cmath>
#include <climits>


int main()
{

  int var;
  std::cout << "What would you like to do?" << std::endl;
  std::cout << "1. Multiplication" << std::endl;
  std::cout << "2. Division" << std::endl;
  std::cout << "3. Addition" << std::endl;
  std::cout << "4. Subtraction" << std::endl;

  std::cin >> var;
  

  if(var < 1){
      std::cout << "Hey man, take this more seriously"<< std::endl;
      //return 0;
    }
  if(var > 4){
    std::cout << "Hey man, take this more seriously"<< std::endl;
    //return 0;
    }


  if(var ==1){
    std::cout << "Please enter two numbers that you wanna multiply" << std::endl;
  
    double a,b,c;
    std::cin>>a;
    std::cin>>b;
    c = a * b;

    std::cout << "The product of the numbers " << a << " and " << b << " is: " << c <<std::endl;
  }

   if(var ==2){
    std::cout << "Please enter two numbers that you wanna divide" << std::endl;
  
    double a,b,c;
    std::cin>>a;
    std::cin>>b;  
    c = a / b;
    if(b == 0) std::cout << "dont divide by 0!" << std::endl;
    if(fabs(b) > 0){
      std::cout << "The division of the numbers " << a << " and " << b << " is: " << c <<std::endl;
    }
  }

   if(var ==3){
     std::cout << "Please enter two numbers that you wanna add" << std::endl;
     
     double a,b,c;
     std::cin>>a;
     std::cin>>b;
     c = a + b;

     std::cout << "The addition of the numbers " << a << " and " << b << " is: " << c <<std::endl;
   }
   
   if(var == 4){
     std::cout << "Please enter two numbers that you wanna subtract" << std::endl;
     
     double a,b,c;
     std::cin>>a;
     std::cin>>b;   
     c = a - b;

     std::cout << "The subtraction of the numbers " << a << " and " << b << " is: " << c <<std::endl;
   }
  
  
  
  

  
  return 0;
  
}
