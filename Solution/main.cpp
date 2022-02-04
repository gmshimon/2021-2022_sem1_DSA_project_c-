// MINI PROJECT : "E-RECRUITMENT SYSTEM" //
// SECJ2013 DATA STRUCTURE AND ALGORITHM //
// SESSION 2021/2022/1 //
// SECTION - 09, LECTURER: DR. SIM HIEW MOI //
// GROUP - 05 //
/* MEMBERS:  

   G M SHAHEEN SHAH SHIMON (A20EC0266)
   TOYA LAZMIN KHAN (A20EC0284)
   RAHIM REHNUMA TAHSIN	(A20EC5001)   */

#include<iostream> 
#include<fstream> 
#include<vector> 
using namespace std; 
 
class Applicant{ 
    public: 
        string name; 
        string study; 
        float cgpa; 
        int age; 
        int id; 
        Applicant* next; 
 
    Applicant(){ 
        name=" "; 
        study=" "; 
        cgpa=0.0; 
        age=0; 
        next=NULL; 
    } 
    void setInfo(int ID,string n,string s,float c, int a){ 
     name=n; 
     study=s; 
     cgpa=c; 
     age=a; 
     id=ID; 
 } 
}; 
 
class Stack{ 
 
    public: 
        Applicant* top; 
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
        void addToList(Applicant *s){ 
            ofstream file_out("Applicant.txt",ios::app); 
            file_out<<s->id<<" "<<s->name<<" "<<s->study<<" "<<s->cgpa<<" "<<s->age<<endl; 
     } 
         
        //delete the last line of the file  
        void deleteLastLine(){ 
         string line;   // To read each line from code 
   int count=0;    // Variable to keep count of each line 
  
   ifstream mFile ("Applicant.txt");  
   //get the number of line in a file  
   if(mFile.is_open())  
   { 
    while(mFile.peek()!=EOF) 
    { 
     getline(mFile, line); 
     count++; 
    } 
    mFile.close(); 
    // cout<<"Number of lines in the file are: "<<count<<endl; 
   } 
   else 
    cout<<"Couldn't open the file\n"; 
     
    
   //remove the last line of the line  
   string line2;  
   vector<string> lines; 
   ifstream inputStream("Applicant.txt"); 
    
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
   remove("Applicant.txt"); 
   rename("example.txt", "Applicant.txt"); 
  } 
         
        //check the node 
        bool checkNode(Applicant* s){ 
            Applicant* temp=top; 
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
 
  //Search an applicant 
        void searchApplicant(int searchID){ 
 
   string name; 
   string study; 
   float cgpa; 
   int age; 
   int id; 
 
   int found=0; 
 
   fstream infile("Applicant.txt",ios::in); 
   infile>>id>>name>>study>>cgpa>>age; 
   while(!infile.eof()){ 
    if(id==searchID){ 
     cout<<endl<<"|||||||||||||Applicant Details|||||||||||||"<<endl; 
     cout<<"Applicant ID: "<<id<<endl; 
     cout<<"Applicant name: "<<name<<endl; 
     cout<<"Applicant cgpa: "<<cgpa<<endl; 
     cout<<"Applicant age: "<<age<<endl; 
     cout<<endl; 
     found=1; 
    } 
    infile>>id>>name>>study>>cgpa>>age;     
   } 
   if(found==0){ 
             cout<<"Applicant not found"<<endl<<endl; 
   } 
        } 
 
        //push the node 
        void addApplicant(Applicant *s) { 
             
            if(top==NULL){ 
             addToList(s); 
                top=s; 
            } 
            else if(checkNode(s)){ 
                cout<<"xxxxxxx(ERROR : Same ID exists)xxxxxxx"<<endl; 
            } 
            else{ 
             addToList(s); 
                Applicant* temp=top; 
                top=s; 
                s->next=temp; 
                 
                cout<<"Applicant Added"<<endl; 
            } 
        } 
 
        //pop operation  
        void deleteApplicant(){ 
            Applicant *temp=NULL; 
            if(isEmpty()){ 
                cout<<"Stack is empty"<<endl; 
            } 
            else{ 
             deleteLastLine(); 
                temp=top;
top=top->next; 
                delete temp; 
                cout<<"Applicant data is deleted"<<endl; 
            } 
        } 
 
        //print the all elements 
        void display(){ 
            Applicant *temp; 
            temp=top; 
            if(isEmpty()){ 
                cout<<"Stack is empty"<<endl; 
            } 
            else{ 
                while(temp!=NULL){ 
                    cout<<"Student ID: "<<temp->id<<endl; 
                    cout<<"Student Name: "<<temp->name<<endl; 
                    cout<<"Student CGPA: "<<temp->cgpa<<endl; 
                    cout<<"Student age: "<<temp->age<<endl; 
                    temp=temp->next; 
                } 
            } 
        } 
         
};//end of stack class 
 
class Queue{ 
  
 public: 
  Applicant*front,*rear; 
  Queue(){ 
   front=NULL; 
   rear=NULL; 
  } 
   
  //checking wheather list is empty or not  
        bool isEmpty(){ 
            if(front==NULL&&rear==NULL){ 
                return true; 
            } 
            else{ 
                return false; 
            } 
        } 
         
        //Search an applicant 
        void searchApplicant(int id){ 
         int found=0; 
            Applicant*temp=front; 
             
            while(temp!=NULL){ 
                if(temp->id==id){ 
     cout<<endl<<"|||||||||||||Applicant Details|||||||||||||"<<endl; 
     cout<<"Applicant ID: "<<temp->id<<endl; 
     cout<<"Applicant name: "<<temp->name<<endl; 
     cout<<"Applicant cgpa: "<<temp->cgpa<<endl; 
     cout<<"Applicant age: "<<temp->age<<endl; 
      
                 found=1; 
                 
                    break; 
                } 
                temp=temp->next; 
            } 
            if(found==0){ 
             cout<<"Applicant not found"<<endl<<endl; 
   } 
        } 
   
  //enQueue function 
  void enQueue(Applicant*s){ 
   if(isEmpty()){ 
    front=s; 
    rear=s; 
   } 
   else{ 
    rear->next=s; 
    rear=s; 
   } 
  } 
   
  //shortlist the applicant 
  void shortlistApplicant(){ 
   if(isEmpty()){ 
    cout<<"No data"<<endl; 
   } 
   else{ 
    ofstream sl_out("shortListedApplicant.txt",ios::app); 
    string ch; 
    Applicant* temp=front; 
    while(temp!=NULL){ 
     cout<<endl<<"|||||||||||||Applicant Details|||||||||||||"<<endl; 
     cout<<"Applicant ID: "<<temp->id<<endl; 
     cout<<"Applicant name: "<<temp->name<<endl; 
     cout<<"Applicant cgpa: "<<temp->cgpa<<endl; 
     cout<<"Applicant age: "<<temp->age<<endl; 
     cout<<"Do you want to shortlist the applicant. Press y or n: "; 
     cin>>ch; 
     if(ch=="y"||ch=="Y"){ 
               sl_out<<temp->id<<" "<<temp->name<<" "<<temp->study<<" "<<temp->cgpa<<" "<<temp->age<<endl; 
      cout<<"Applicant has been shortlisted"<<endl<<endl; 
     } 
     else{ 
      cout<<"Applicant data not added"<<endl; 
     } 
     temp=temp->next; 
    } 
     
   } 
  } 
   
        //display all nodes in the queue 
        void display(){ 
            if(isEmpty()){ 
                cout<<"queue is empty"<<endl; 
            } 
            else{ 
                cout<<"printing all nodes: "<<endl; 
                Applicant* temp=front; 
                while(temp!=NULL){ 
                   cout<<endl<<"|||||||||||||Applicant Details|||||||||||||"<<endl; 
     cout<<"Applicant ID: "<<temp->id<<endl; 
     cout<<"Applicant name: "<<temp->name<<endl; 
     cout<<"Applicant cgpa: "<<temp->cgpa<<endl; 
     cout<<"Applicant age: "<<temp->age<<endl; 
                    temp=temp->next; 
                } 
            } 
        } 
 
}; 
 
int main(){ 
  
 int choice; 
 do{ 
  cout<<"#################Welcome to the company#################"<<endl; 
  cout<<"Enter your choice below.. Enter 0 to exit"<<endl; 
  cout<<"1. HR manager"<<endl; 
  cout<<"2. Hiring panel"<<endl; 
  cout<<"3. Clear Screen"<<endl; 
  cout<<endl<<"Enter your choice: ";cin>>choice; 
  switch(choice){ 
   case 0: break; 
   case 1:{ 
    Queue q; 
    int option, option2; 
    string name; 
    string study; 
    float cgpa; 
    int age; 
    int id; 
     
    fstream
infile("Applicant.txt",ios::in); 
 
    int searchID; 
    
    infile>>id>>name>>study>>cgpa>>age; 
    while(!infile.eof()){ 
     Applicant* ss=new Applicant(); 
      
     ss->setInfo(id,name,study,cgpa,age); 
     infile>>id>>name>>study>>cgpa>>age; 
      
     q.enQueue(ss); 
    } 
    cout<<endl; 
     
    cout<<endl<<"What Do you want to do"<<endl; 
    cout<<"1. Display All applicant"<<endl; 
    cout<<"2. Shortlist Applicant"<<endl; 
    cout<<"3. Search applicant"<<endl; 
    cout<<endl<<"Enter your choice: "; 
    cin>>option2; 
    cout<<endl; 
    switch(option2){ 
     case 0: break; 
     case 1: 
      q.display(); 
      break; 
     case 2: 
      q.shortlistApplicant(); 
      break; 
     case 3:  
      cout<<"Search the Applicant...."<<endl<<"Enter Applicant ID: "; 
      cin>>searchID; 
      q.searchApplicant(searchID); 
      break; 
     default: 
      cout<<"Wrong choice"<<endl; 
    } 
     
    break; 
   } 
   case 2:{ 
     
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
     cout<<"1. Add Applicant"<<endl; 
     cout<<"2. Delete Applicant"<<endl; 
     cout<<"3. Display Applicant"<<endl; 
     cout<<"4. Search Applicant"<<endl; 
     cout<<"5. Clear Screen"<<endl; 
      
     cout<<endl<<"(Enter Your Option): "; 
     cin>>option; 
      
     Applicant* s=new Applicant(); 
      
    
     switch(option){ 
      case 1:  
       cout<<"=======Enter Applicant Details======="<<endl; 
       cout<<"Applicant id: ";cin>>id; 
       cout<<"Applicant name: ";cin>>name; 
       cout<<"Applicant study background: ";cin>>study; 
       cout<<"Applicant CGPA: ";cin>>cgpa; 
       cout<<"Applicant age: "; cin>>age; 
       s->id=id; 
       s->name=name; 
       s->study=study; 
       s->cgpa=cgpa; 
       s->age=age; 
       s1.addApplicant(s); 
       break; 
      case 2: 
       s1.deleteApplicant(); 
       break; 
      case 3: 
       s1.display(); 
       break; 
      case 4: 
       int searchID; 
       cout<<"Search the Applicant...."<<endl<<"Enter Applicant ID: "; 
       cin>>searchID; 
       s1.searchApplicant(searchID); 
       break; 
      case 5: 
       system("cls"); 
       break; 
      default: 
       cout<<"Wrong operation number"<<endl; 
    
     } 
    }while(option!=0); 
     
    break; 
   }//// 
   case 3: system("cls"); 
   break; 
   default: 
    cout<<"Wrong choice..Please Enter correct option"<<endl; 
    break; 
  } 
 }while(choice!=0); 
    return 0; 
}

