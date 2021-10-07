#include <iostream>
#include <thread>

void print(int x)
{
     std::cout<< "Hello! I am minion "<< x <<std::endl;
 }
int main (int argc, char** argv) {
  if (argc < 2) {
    std::cerr<<"usage: "<<argv[0]<<" <nbminions>\n";
    return -1;
  }
  //Your code goes here
  int x = atoi(argv[1]); // Converts string to integer
    std::thread thread[x];
    for (int i = 0; i < x; i++)
    {
      thread[i] = std::thread(print, i + 1);
	// std::cout<< "Hello! I am minion "<< i <<std::endl;
    }
    for (int j = 0; j < x; j++)
    {
        thread[j].join();
    }
    std::cout<< "Hello minions! I am the Overlord!"<<std::endl;
    return -1;
}
