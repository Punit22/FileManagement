#include <string>
#include <fstream>
#include <iostream>
#include<stdbool.h>
#include <dirent.h>
#include <string>
#include <sys/types.h>

using namespace std;

class Createfile{
  public:
  void c(string x){

    ofstream textfile;
    textfile.open (x.c_str());

    cout<<"Enter data : ";
    string str;
  	int t = 2;
  	while (t--)
  	{
  		// Read a line from standard input in str
  		getline(cin, str);
  	}
    textfile << str;
    textfile.close();
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

      }
      //read and print file content
      cout << endl << "File Content: "<<endl<<endl;
      while (!file.eof())
      {
        file >> noskipws >> ch;	//reading from file
        cout << ch;	//printing
      }
      cout<<endl;
      file.close();

  }
};

class Deletefile{
public:
  void d(string x){
    if( remove( x.c_str() ) != 0 )
      perror( "Error deleting file" );
    else
      puts( "File successfully deleted" );
    }
};

class Appendfile{
public:
  void a(string x){
    std::ofstream outfile;

    outfile.open(x.c_str(), std::ios_base::app);
    cout<<"Enter data to append in the file :";
    string str;
    int t = 2;
    while (t--)
    {
      // Read a line from standard input in str
      getline(cin, str);
    }
    outfile <<endl<< str;
    outfile.close();
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
    cout << "|------------------";
    list_dir("E:/programs/C++ project");
    cout << "-------------------|";
    string filename;
    cout <<endl<< "Enter filename to read: ";
    cin >> filename;
    return filename.c_str();
  }

  else if(c_mode == "a"){
    cout << "The files available to Append : "<<endl;
    cout << "|------------------";
    list_dir("E:/programs/C++ project");
    cout << "-------------------|";
    string filename;
    cout <<endl<< "Enter FileName to append: ";
    cin >> filename;
    return filename.c_str();
  }

  else if(c_mode == "d"){
    cout << "The files available to Delete : "<<endl;
    cout << "|------------------";
    list_dir("E:/programs/C++ project");
    cout << "-------------------|";;
    string filename;
    cout <<endl<< "Enter FileName to delete: ";
    cin >> filename;
    return filename.c_str();
  }

}

int main(){

    Createfile cf;
    Readfile rf;
    Deletefile df;
    Appendfile af;

    int option;
    string x, mode;
    bool flag = true;

        while(flag != false){

              cout << "|---------------[ Choose Option ]------------------------|"<<endl;
              cout << "|              (1)Create File                            |"<<endl;
              cout << "|              (2)Read File                              |"<<endl;
              cout << "|              (3)Append File                            |"<<endl;
              cout << "|              (4)Delete File                            |"<<endl;
              cout << "|              (5)Exit                                   |"<<endl;
              cout << "|--------------------------------------------------------|"<<endl;

              cout <<endl<< "Enter Option : ";
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
              else if(option == 3){
                mode = "a";
                x = FileSelection(mode);
                af.a(x);
              }
              else if(option == 4){
                mode = "d";
                x = FileSelection(mode);
                df.d(x);
              }
              else if(option == 5){
                exit(0);
              }
              else{
                flag = false;
              }
      }
      cout << "End of Program";
}
