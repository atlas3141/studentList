#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>

using namespace std;

struct Student{
  char name;
  int id;
  float gpa;
};

int main(){
  vector<Student*> list;
  char input[20];
  bool running = true;
  while (running == true){
    cin.get(input,20);
    cin.ignore();
    if (!strcmp(input,"PRINT")){
      
    }
    else if (!strcmp(input, "ADD")){

    }
    else if (!strcmp(input, "DELETE")){

    }
    else if (!strcmp(input, "HELP")){
      cout << "Commands: \nPRINT\nADD\nDELETE" << endl;
    }
    else if (!strcmp(input, "EXIT")){
      running = false;
    }
    else{
      cout << "No such command: " <<  input << endl;
      cout << "Type HELP for a list of commands" << endl;
    }
  }
}
