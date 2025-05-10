#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
 
int main(int ac, char **av)
{
   if(ac != 4)
   {
      std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
      return(1);
   }
   std::string filename = av[1];
   std::string s1 = av[2];
   std::string s2 = av[3];

   if (s1.empty()) 
   {
      std::cerr << "Error: s1 cannot be empty." << std::endl;
      return 1;
   }
   std::ifstream infile (filename);
   if (!infile)
   {
      std::cerr << "Error: cannot open input file " << filename << std::endl;
      return 1;
   }
   std::ofstream outfile(filename + ".replace");
   if (!outfile) 
   {
      std::cerr << "Error: cannot create output file " << filename << ".replace" << std::endl;
      return 1;
   }
   std::stringstream buffer;
   buffer << infile.rdbuf();
   std::string content = buffer.str();
   std::string result;
   size_t pos = 0;
   size_t found;
   while ((found = content.find(s1, pos)) != std::string::npos)
   {
      result += content.substr(pos, found - pos); 
      result += s2;                               
      pos = found + s1.length();                
   }
   result += content.substr(pos);
   outfile << result;
   std::cout << "Replacement done. Output written to " << filename << ".replace" << std::endl;
   return 0;
  
}