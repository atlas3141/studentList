#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>

using namespace std;

struct Student{
  char* name;
  int id;
  float gpa;
};

void printStudents(vector<Student*>* list);
void newStudent(vector<Student*>* list);
void deleteStudent(vector<Student*>* list);

int main(){
  vector<Student*> list;
  char input[20];
  bool running = true;
  while (running == true){ //command line loop
    cin.get(input,20);
    cin.ignore();
    if (!strcmp(input,"PRINT")){
      printStudents(& list);
    }
    else if (!strcmp(input, "ADD")){
      newStudent(& list);
    }
    else if (!strcmp(input, "DELETE")){
      deleteStudent(& list);
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
void printStudents(vector<Student*>* list){ //go throught the list and print out thier info
  for(vector<Student*>::iterator it = list->begin(); it != list->end(); it++){
    cout << "Name: " << (*it)->name << ", ID: " << (*it)->id << ", GPA: " << setprecision(2)<<fixed << (*it)->gpa << endl;
  }
}
void newStudent(vector<Student*>* list){
  Student* s = new Student; //create the new student and put them on the heap
  int newId;
  char newName[30];
  float newGpa;
  cout << "New ID?" << endl; //get new students info
  cin >> newId;
  cin.ignore();
  cout << "New Name?" << endl;
  cin.get(newName,30);
  cin.ignore();
  cout << "New GPA?" << endl;
  cin >> newGpa;
  cin.ignore();
  s->id = newId;
  s->gpa = newGpa;
  s->name = strdup(newName);
  cout << "Added student with info" << endl;
  cout << "Name: " << s->name << ", ID: " << s->id << ", GPA: " << setprecision(2)\
       <<fixed << s->gpa << endl;
  list->push_back(s); //add them to the list
}
void deleteStudent(vector<Student*>* list){
  bool deleted = false;//ask witch student to delte
  int deleteId;
  cin >> deleteId;
  cin.ignore();
  for(vector<Student*>::iterator it = list->begin(); it != list-> end(); it++){ //look through the fector to find the person with that id
    if((*it)->id == deleteId){
      cout << "Removed " << (*it)->name << endl;
      delete (*it)->name;
      delete *it;
      list->erase(it);
      it = list->end();
      it--;
      deleted = true;
    }
  }
  if (deleted == false){
    cout << "No entries with Id " << deleteId << endl;
  }
} 
