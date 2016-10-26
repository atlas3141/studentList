# include <iostream>
# include <vector>
# include <cstring>
# include <iomanip>

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
  char inputstr[20];
  bool running = true;
  while (running == true){
    cin.get(inputstr,20);
    cin.ignore();
    if (strcmp(inputstr, "ADD")==0){
	newStudent(& list);
      }
    else if (strcmp(inputstr, "DELETE")==0){
      deleteStudent(& list);
      }
    else if (strcmp(inputstr, "PRINT")==0){
      printStudents(& list);
      }
    else if (strcmp(inputstr, "EXIT")==0){
      running = false;
      for (vector<Student*>::iterator it = list.begin(); it != list.end(); it++){
	delete (*it)->name;
	delete *it;
	list.erase(it);
      }
    }
    else if (strcmp(inputstr, "HELP")==0){
      cout << "Commands:\nADD\nDELETE\nPRINT\nEXIT\n" << endl;
    }
    else {
      cout << "No such command " << inputstr << endl;
      cout << "Type HELP for list of comands" << endl;
    }
  }
}
void newStudent(vector<Student*>* list){
  Student* s = new Student;
  int newId;
  float newGpa;
  char newName[20];
  cout << "Enter Info" << endl;
  cout<< "Name?" << endl;
  cin.get(newName, 20);
  cin.ignore();
  cout << "ID?" << endl;
  cin >> newId;
  cout << "GPA?" << endl;
  cin >> newGpa;
  cin.ignore();
  s->id = newId;
  s->gpa = newGpa;
  s->name = strdup(newName);
  list->push_back(s);
}
void printStudents(vector<Student*>* list){
  for (vector<Student*>::iterator it = list->begin(); it != list->end(); it++){
    cout << "Name: " << (*it)->name << ", ID: " << (*it)->id << ", GPA: " << setprecision(2) <<fixed << (*it)->gpa << endl;
  }
}
void deleteStudent(vector<Student*>* list){
  int deleteId;
  bool deleted = false;
  cout << "ID?" << endl;
  cin >> deleteId;
  cin.ignore();
  for (vector<Student*>::iterator it = list->begin(); it != list->end(); it++){
    if ((*it)->id == deleteId){
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
    cout << "No entries with ID "<< deleteId << endl; 
  }
}

