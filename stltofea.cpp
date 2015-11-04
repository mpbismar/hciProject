#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

struct obj {
   int nNodes;
};

struct obj readFile(char * path) {
   std::ifstream  stlf("sample1.stl");
   struct obj stlObj;
   int n = 0;
   std::vector<int>  *nodes;
   int nodecount=0;  
   std::string sline;


   while(std::getline(stlf,sline)) {
     if ( sline.find("vertex")!=std::string::npos) {
      
      } else {
	 
	 std::cout<<sline.substr(4,64).c_str();
         for (int i=0;i<=nodecount;i++) {
             
	   
	   
         }
      }
   }

   
   stlObj.nNodes = n;
   return stlObj;
}

int main(int argc, char ** argv)
{
   obj neu = readFile(argv[1]);
   return 0;
}	
