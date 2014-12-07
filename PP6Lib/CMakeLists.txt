
# - CMake script for pp6 library
# -----------------------------------------------------

add_library(pp6lib STATIC 
		   PP6Math.hpp 
		   PP6Math.cpp 
		   DAY1_MENU.hpp 
		   DAY1_MENU.cpp 
		   DAY2_MENU.hpp 
		   DAY2_MENU.cpp 
		   MUONANALYSIS.cpp 
		   MUONANALYSIS.hpp 
		   DAY3_MENU.hpp 
		   DAY3_MENU.cpp 
		   DAY4_MENU.hpp 
		   DAY4_MENU.cpp 
		   ThreeVector.cpp 
		   ThreeVector.hpp 
		   FourVector.cpp  
		   FourVector.hpp  		  
		   Particle.hpp
		   Particle.cpp
		   MuClassAnalysis.cpp
		   MuClassAnalysis.hpp)
