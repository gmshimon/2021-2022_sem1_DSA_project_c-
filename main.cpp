#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class Student{
    public:
        string name;
        string study;
        float cgpa;
        int age;
        int id;
        Student* next;

    Student(){
        name=" ";
        study=" ";
        cgpa=0.0;
        age=0;
        next=NULL;
    }
};

class Stack{

    public:
        Student* top;
        Stack(){
            top=NULL;
        }
        //checking the stack is empty or not
         bool isEmpty(){
            if(top==NULL){
                return true;
            }
            else{
                return false;
            }
        }
        
        //add to file
        void addToList(Student *s){
            ofstream file_out("Student.txt",ios::app);
            file_out<<s->id<<" "<<s->name<<" "<<s->study<<" "<<s->cgpa<<" "<<s->age<<endl;
    	}
        
        //delete the last line of the file 
        void kola(){
        	string line;   // To read each line from code
			int count=0;    // Variable to keep count of each line
	
			ifstream mFile ("Student.txt"); 
			//get the number of line in a file 
			if(mFile.is_open()) 
			{
				while(mFile.peek()!=EOF)
				{
					getline(mFile, line);
					count++;
				}
				mFile.close();
				cout<<"Number of lines in the file are: "<<count<<endl;
			}
			else
				cout<<"Couldn't open the file\n";
				
			
			//remove the last line of the line 
			string line2; 
			vector<string> lines;
			ifstream inputStream("Student.txt");
			
			while (getline(inputStream,line2)) {
			    lines.push_back(line2);
			}
			inputStream.close();
			
			fstream outputStream("example.txt", ios::out | ios::trunc);
			if (outputStream.is_open())
			{
			    for (int i=0; i < lines.size()-1; i++)
			    {
			        outputStream << lines[i] << "\n";
			    }
			    outputStream.close();
			}
			remove("Student.txt");
			rename("example.txt", "Student.txt");
		 
		}
        
        //check the node
        bool checkNode(Student* s){
            Student* temp=top;
            bool exist = false;
            while(temp!=NULL){
                if(temp->id==s->id){
                    exist=true;
                    break;
                }
                temp=temp->next;
            }
            return exist;
        }
        //push the node
        void push(Student *s) {
            // ofstream file_out("Student.txt",ios::app);
            if(top==NULL){
                // file_out<<s->id<<" "<<s->name<<" "<<s->study<<" "<<s->cgpa<<" "<<s->age<<endl;
                top=s;
            }
            else if(checkNode(s)){
                cout<<"Same key already exist in the stack"<<endl;
            }
            else{
                Student* temp=top;
                top=s;
                s->next=temp;
                // file_out<<s->id<<" "<<s->name<<" "<<s->study<<" "<<s->cgpa<<" "<<s->age<<endl;
                cout<<"Node pushed"<<endl;
            }
        }

        //pop operation 
        void pop(){
            Student *temp=NULL;
            if(isEmpty()){
                cout<<"Stack is empty"<<endl;
            }
            else{
            	kola();
                temp=top;
                top=top->next;
                delete temp;
                cout<<"Student data is deleted"<<endl;
            }
        }

        //print the all elements
        void display(){
            Student *temp;
            temp=top;
            if(isEmpty()){
                cout<<"Stack is empty"<<endl;
            }
            else{
                while(temp!=NULL){
                    cout<<"ID: "<<temp->id<<endl;
                    temp=temp->next;
                }
            }
        }
        
};

int main(){

    Stack s1;
    int option, position;
    string name;
    string study;
    float cgpa;
    int age;
    int id;

    do{
    	
        cout<<"What operation do you want to perform? Select Option number."<<endl<<"Enter 0 to exist"<<endl;
        cout<<"###############"<<endl;
        cout<<"1. Add Student"<<endl;
        cout<<"2. Delete Student file"<<endl;
        cout<<"3. isEmpty()"<<endl;
        cout<<"4. Display()"<<endl;
        cout<<"5. Clear Screen"<<endl;
        
        cout<<"(Enter Your Option): ";
        cin>>option;
        
        Student* s=new Student();
        

        switch(option){
            case 1: 
                cout<<"=======Enter Student Details======="<<endl;
                cout<<"Student id: ";cin>>id;
                cout<<"Student name: ";cin>>name;
                cout<<"Student study background: ";cin>>study;
                cout<<"Student CGPA: ";cin>>cgpa;
                cout<<"Student age: "; cin>>age;
                s->id=id;
                s->name=name;
                s->study=study;
                s->cgpa=cgpa;
                s->age=age;
                s1.push(s);
                s1.addToList(s);
                break;
            case 2:
                s1.pop();
//                s1.kola();
                break;
            case 3:
                if(s1.isEmpty()){
                    cout<<"Stack is empty"<<endl;
                }
                else{
                    cout<<"Stack is not empty"<<endl;
                }
                break;
            case 4:
                s1.display();
                break;
             case 5:
                system("cls");
                break;
            default:
                cout<<"Wrong operation number"<<endl;

        }
    }while(option!=0);
    
//    s1.addToList();
    
    return 0;
}
