#include <string>
#include <fstream>
#include <iostream>
#include<stdbool.h>
#include <dirent.h>
#include <sys/types.h>

using namespace std;

class Createfile{
public:
  void c(string a){
    string filename = a.c_str();
    string data;
    cout<<"Enter data for file"<<endl;
    //cin >> data;
    cin >> data;
    ofstream f;
    f.open(filename.c_str());
    f << data;
    f.close();
  }
};

class Openfile{
public:
  void o(string y){

    string x = y.c_str();
    char data[100];

     ifstream infile;
     infile.open(x);

     cout << "Reading from the file" << endl;
     infile.getline(data,100);

     cout << data << endl;

     infile.close();
   }
};

class Readfile{
  public :

  void r(string x){
      char ch;
      const char *fileName=x.c_str();

      ifstream file;

      file.open(fileName,ios::in);
      if(!file)
      {
        cout<<"Error in opening file!!!"<<endl;
        //return -1;
      }

      //read and print file content
      while (!file.eof())
      {
        file >> noskipws >> ch;	//reading from file
        cout << ch;	//printing
      }
      cout<<endl<<"---------------End of File----------------"<<endl;
      file.close();

      //return 0;
  }
};

void list_dir(const char *path) {
   struct dirent *entry;
   DIR *dir = opendir(path);

   if (dir == NULL) {
      return;
   }
   while ((entry = readdir(dir)) != NULL) {
   cout << entry->d_name << endl;
   }
   closedir(dir);
}

string FileSelection(string c_mode){

  if(c_mode == "c"){
    string filename;
    cout << "Enter FileName: ";
    cin >> filename;
    return filename.c_str();
  }

  else if(c_mode == "r"){
    cout << "The files available to Read : "<<endl;
    list_dir("E:/programs/C++ project");

    string filename;
    cout << "Enter FileName to read: ";
    cin >> filename;
    return filename.c_str();
  }
}

int main(){

    Createfile cf;
    Readfile rf;
    Openfile op;
    int option,condition;
    string x ,y , mode;
    bool flag = true;

        while(flag != false){

              cout << "Enter Function :"<<endl<<"1.) Create"<<endl<<"2.) Read"<<endl;
              cin >> option;

              if(option == 1){
                mode = "c";
                x = FileSelection(mode);
                cf.c(x);

              }
              else if(option == 2){
                mode = "r";
                x = FileSelection(mode);
                rf.r(x);

              }
              else {
                exit(0);
              }

              cout << "Press 0 to exit" <<endl;
              cin >> condition;
              if(condition == 0){ flag = false; }
              else{ flag = true; }
      }
}
