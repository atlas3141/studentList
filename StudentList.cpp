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
void printStudents(vector<Student*>* list){
  for(vector<Student*>::iterator it = list->begin(); it != list->end(); it++){
    cout << "Name: " << (*it)->name << ", ID: " << (*it)->id << ", GPA: " << setprecision(2)<<fixed << (*it)->gpa << endl;
  }
}
void newStudent(vector<Student*>* list){
  Student* s = new Student;
  int newId;
  char newName[30];
  float newGpa;
  cout << "New ID?" << endl;
  cin >> newId;
  cin.ignore();
  cout << "New Name?" << endl;
  cin >> newName;
  cin.ignore();
  cout << "New GPA?" << endl;
  cin >> newGpa;
  cin.ignore();
  s->id = newId;
  s->gpa = newGpa;
  s->name = strdup(newName);
  list->push_back(s);
}
void deleteStudent(vector<Student*>* list){
  bool deleted = true;
  int deleteId;
  cin >> deleteId;
  cin.ignore();
  for(vector<Student*>::iterator it = list->begin(); it != list-> end(); it++){
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
  if (deleted == true){
    cout << "No entries wit Id " << deleteId << endl;
  }
} 
