#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <regex>

std::vector<std::array<std::string, 3>> nodes; 
std::vector<std::array<int, 3>> triangs; 

void writeOutput() {
   std::ofstream  output;
   int numel = triangs.size();
   int numnp = nodes.size();
   int nmat = 1;
   int nmode = 0;
   int psf = 0;
   output.open("output");
   output << "numel numnp nmat nmode plane_stress_flag\n";
   output << numel << " " << numnp << " " << nmat << " " << nmode << " " << psf << "\n";
   output << "matl no., E modulus, Poisson Ratio, density\n";
   output << "0  10000000.0000    0.3000 2238.3000\n";
   output << "el no., connectivity, matl no\n";
   for(int i = 0; i < numel; i++) {
      output << i << "   " << triangs[i][0] << "   " << triangs[i][1] << "   " << triangs[i][2] << "   " << "0" << "\n";
   }
   output << "node no., coordinates\n";
   for(int i = 0; i < numnp; i++) {
      output << i << "   " << nodes[i][0] << "   " << nodes[i][1] << "   " << nodes[i][2] << "\n";
   }
   output << "prescribed displacement x: node  disp value\n";
   output << "-10\n";
   output << "prescribed displacement y: node  disp value\n";
   output << "-10\n";
   output << "prescribed displacement z: node  disp value\n";
   output << "-10\n";
   output << "node with point load and load vector in x,y,z\n";
   output << "-10\n";
   output << "node no. with stress and stress vector in xx,yy,zz,xy,xz,yz\n";
   output << "-10\n";
   output << "\n\nThis mesh was generated from " << "whatever" << ".";
   output.close();
}

void readFile(std::string path) {

   std::ifstream  stlf2(path);
   std::ifstream  stlf;
   std::string path2=path;
   char * start= new char [5];
   stlf2.read(start,5);
   if(strcmp(start,"solid") != 0) {
      char * command= new char [100];
      strcpy(command,"./convertSTL.rb ");
      strcat(command,path.c_str());
      system(command);
      path2=path.substr(0,path.size()-4)+"-ascii.stl";
   }
   stlf.open(path2);
   std::string sline;
   std::regex floatstr("([-+]?[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?)");
   std::smatch m;
   bool unique;
   int tric=0;

   std::cout << "Reading data..." << std::endl;

   while(std::getline(stlf,sline)) {
     if ( sline.find("vertex")==std::string::npos) {
      
      } else {
	  std::array<std::string, 3> vec={"","",""};  
	  int c=0;
	  unique=1;
	  while (std::regex_search (sline,m,floatstr)) {
	    vec[c]=m[0];
            sline = m.suffix().str();
	    c++;
          }

         int j=0;
         for (int i=0;i<nodes.size();i++) {
            if (nodes[i][0]==vec[0] && nodes[i][1]==vec[1] && nodes[i][2]==vec[2]) {
	      unique=0;
	      j=i;
	    }
         }

         if (tric % 3 == 0) {
	   triangs.push_back({0,0,0});
	 }
	
	 if (unique) {
           nodes.push_back(vec);
           triangs.back()[tric % 3]=nodes.size()-1;

         } else {
           triangs.back()[tric % 3]=j;
         }
         
         
         tric++;
      }
   }

}

int main(int argc, char ** argv)
{
   readFile(argv[1]);
   std::cout << "Writing output..." << std::endl;
   writeOutput();
   return 0;
}	
