//Standard Library
#include <iostream>
#include <limits>

#include "DAY1_MENU.hpp"
#include "DAY2_MENU.hpp"
#include "DAY3_MENU.hpp"

int main(){

  char day('\0');

  while(true)
    {

      std::cout << "PP6 CALCULATOR - Main Menu" << std::endl;
      std::cout << "===============================" << std::endl;
      std::cout << "Which day would you like to access?" << std::endl;
      std::cout << "1) - Basic Mathematics" << std::endl;
      std::cout << "2) - Arrays etc." << std::endl;
      std::cout << "3) - structs etc. (hopefully!)" << std::endl;
      std::cout << "q) - Quit" << std::endl;
      std::cout << "===============================" << std::endl;
      

      std::cin >> day;
      if(!std::cin)
	{
	  std::cerr << "Please enter a valid operation" << std::endl;
	  std::cin.clear();
	  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	  continue;
	}
      
      if(day == 'q') break;
      else if (day == '1'){
	day1_menu();
      }
      else if (day == '2'){
	day2_menu();
      }
       else if (day == '3'){
	day3_menu();
       }
      else{
	std::cerr << "[ERR]" << day << " not recognised" << std::endl;
	continue;
      }

      std::cout<< "Thanks for using PP6 calculator!" << std::endl;
      return 0;

    }
}
