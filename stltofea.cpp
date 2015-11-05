#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <regex>

std::vector<std::array<std::string, 3>> nodes; 
std::vector<std::array<int, 3>> triangs; 

void readFile(char * path) {

   std::ifstream  stlf("sample1.stl");

   std::string sline;
   std::regex floatstr("([-+]?[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?)");
   std::smatch m;
   bool unique;
   int tric=0;

   while(std::getline(stlf,sline)) {
     if ( sline.find("vertex")==std::string::npos) {
      
      } else {
          //std::cout << sline << "\n";
	  std::array<std::string, 3> vec={"","",""};  
	  int c=0;
	  unique=1;
	  while (std::regex_search (sline,m,floatstr)) {
	    vec[c]=m[0];
            //std::cout << m[0] << " ";
            sline = m.suffix().str();
	    c++;
          }
          //std::cout << std::endl;

         int j=0;
         for (int i=0;i<nodes.size();i++) {
            if (nodes[i][0]==vec[0] && nodes[i][1]==vec[1] && nodes[i][2]==vec[2]) {
	      unique=0;
	      j=i;
	      //std::cout<<j<<std::endl;
	    }
         }

         if (tric % 3 == 0) {
	   triangs.push_back({0,0,0});
           std::cout<<std::endl;
	 }
	
	 if (unique) {
           nodes.push_back(vec);
	   //std::cout<<vec[0]<<"%"<<vec[1]<<"%"<<vec[2]<<std::endl;  

           triangs.back()[tric % 3]=nodes.size()-1;
	   std::cout<<nodes.size()-1<<" ";


         } else {
           triangs.back()[tric % 3]=j;
	   std::cout<<j<<" "; 
         }
         
         
         tric++;
      }
   }

}

int main(int argc, char ** argv)
{
   readFile(argv[1]);
   return 0;
   for (int i=0; i<triangs.size();i++) {
     std::cout<<i<<" "<<triangs[i][0]<<" "<<triangs[i][1]<<" "<<triangs[i][2]<<" "<<std::endl;
   }
}	
