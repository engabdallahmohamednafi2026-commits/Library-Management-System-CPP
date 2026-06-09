#include <iostream>
#include <vector>
#include <string>
using namespace std;
//function to color
string f(int x)
{
    return "\033[1;" + to_string(x) +"m";
}
string e()
{
   return "\033[0m";
}
class Book
{
  public:
    int id;
    string title;
    string author;
    string status;
    void show_all_book(vector<Book> &books)
    {
      for(auto &val : books)
      {
        cout<<"ID:"<<val.id<<"\n";
        cout<<"Title:"<<val.title<<"\n";
        cout<<"Author:"<<val.author<<"\n";
        cout<<"Status:"<<val.status<<"\n";
        cout<<"--------------------------\n";
      } 
                
    }
    void search(vector<Book> &books, int ID)
    {      
      bool flag = true;
      for(auto &val : books)  
      if(ID == val.id)
      {
        cout<<"Title:"<<val.title<<"\n";
        cout<<"Author:"<<val.author<<"\n";
        cout<<"Status:"<<val.status<<"\n";
        flag = false;
        break;  
      }
      if(flag){cout<<"Book Not Found\n";} 
    }
    void borrowBook(vector<Book> &books, int ID)
    {
       bool flag = true;
      for(auto &val : books)
      {  
       if(ID == val.id)
      {
        if(val.status[0] == 'A' || val.status[0] == 'a')
        {
          cout<<"The book: "<<val.title<<"\n\nis borrowed now\n";
          val.status = "borrowed"; 
          flag = false;
          break;
        }
        else{
          cout<<"The book: "<<val.title<<"\n\nis Already Borrowed\n";
          flag = false;
          break;
        }
     
      }
     }
      if(flag){cout<<"Book Not Found\n";} 
    }
    void retuenBook(vector<Book> &books, int ID)
    {
      bool flag = true;
      for(auto &val : books)
      {  
      if(ID == val.id)
      {
        if(val.status[0] == 'B' || val.status[0] == 'b')
        {
          cout<<"The book :"<<val.title<<"\n\nis Avallable now\n";
          val.status = "Avallable";
          flag =false;
          break;
        }
        else{
          cout<<"The book: "<<val.title<<"\n\nis Already Avallable\n";
          flag = false;
           break; 
        }
        
      }
    }
      if(flag){cout<<"Book Not Found\n";} 
   

    }
    void deleteBook(vector<Book> &books, int ID)
    {
      bool flag = true;
      for(int i=0;i<books.size();i++) 
      { 
      if(ID == books[i].id)
      {
        books.erase(books.begin()+i);
        flag = false;
        break;  
      }
      if(flag){cout<<"Book Not Found\n";} 
     }
    }

};

int main()
{
cout<<"    \033[1;30m                       ------------------------------\n";
cout<<"    \033[1;30m                       |\033[1;32m libarary Management System\033[1;30m |";
cout<<"  \n\033[1;30m                           ------------------------------\033[0m\n\n";
cout<<f(30)<<"-------------------\n";
cout<<f(30)<<"|"<<f(34)<<"1)add            "<<f(30)<<"|\n";
cout<<f(30)<<"|"<<f(32)<<"2)Show all books "<<f(30)<<"|\n";
cout<<f(30)<<"|"<<f(33)<<"3)search by ID   "<<f(30)<<"|\n";
cout<<f(30)<<"|"<<f(35)<<"4)Borrowing Book "<<f(30)<<"|\n" ;
cout<<f(30)<<"|"<<f(36)<<"5)return Book    "<<f(30)<<"|\n" ;
cout<<f(30)<<"|"<<f(31)<<"6)delet Book     "<<f(30)<<"|\n" ;
cout<<f(30)<<"|"<<f(37)<<"7)Exest          "<<f(30)<<"|\n";
cout<<f(30)<<"-------------------\n"<<e();
vector<Book> bookvector;
Book b;
char x ='\n';
while(true)
{
int num;
cout<<x<<f(31)<<"Choose number to"<<f(32)<<" do oprator \033[33m[add,Show all Book,....] :"<<e();
if(cin>>num)//شرط لو دخل نص مش رقم
{ 
if(num == 1)
{  
 

 int id;
 cout<<f(30)<<"ID: ";
 cin>>id;

  string title;
 cout<<f(30)<<"Title: ";
 getline(cin>>ws,title);

  string author;
 cout<<f(30)<<"author: ";
 getline(cin>>ws,author);
  
 string status;
 cout<<f(30)<<"status type[Avallable/Borrowed]: ";
 getline(cin>>ws,status);
 cout<<f(35)<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n"<<e();
 b.id = id;
 b.title =title;
 b.author = author;
 b.status= status;
 bookvector.emplace_back(b);
}
else if(num == 2)
{
  
  b.show_all_book(bookvector);
}
else if(num == 3)
{ 
  while(true)//علشان يدخل يلف لحد ما يدرج ال آي دي رقم مش نص
  {
  int id;
  cout<<f(30)<<"Enter ID:"<<e();
  if(cin>>id)
  {
    b.search(bookvector,id);
    cout<<f(35)<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n"<<e();
    break;
  }
  else
  {
    cout<<f(37)<<" Pless,The  ID must consist of"<<f(32)<<"{only Numbers} ||"<<f(31)<<"{not character}\n"<<e();
     cin.clear();
     cin.ignore(10000,'\n');
  }
 }
}
else if(num == 4)
{
  while(true)//علشان يدخل رقم مش نص 
  {
  int id;
  cout<<f(30)<<"Enter ID:"<<e();
  if(cin>>id)
  {
    b.borrowBook(bookvector,id);

    break;
  }
  else{
    cout<<"The  ID must consist of {only Numbers} || {not character}\n"; 
    cout<<f(35)<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n"<<e();

    cin.clear();
  cin.ignore(10000,'\n');
}
 }
}
else if(num == 5)
{
  while(true)//علشان يدخل رقم مش نص 
  {
  int id;
  cout<<f(30)<<"Enter ID:"<<e();
  if(cin>>id)
  {
    b.retuenBook(bookvector,id);
    cout<<f(35)<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n"<<e();
    break;
  }
  else
  {
    cout<<f(37)<<" Pless,The  ID must consist of"<<f(32)<<"{only Numbers} ||"<<f(31)<<"{not character}\n"<<e();
    cin.clear();
    cin.ignore(10000,'\n');
  }
 }
}
else if(num == 6)
{
    while(true)//علشان يدخل رقم مش نص 
  {
  int id;
   cout<<f(30)<<"Enter ID:"<<e();
  if(cin>>id)
  {
    b.deleteBook(bookvector,id);
    break;
  }
  else{
   cout<<f(37)<<" Pless,The  ID must consist of"<<f(32)<<"{only Numbers} ||"<<f(31)<<"{not character}\n"<<e();
    cout<<f(35)<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n"<<e();
     
   cin.clear();
     cin.ignore(10000,'\n');
}
}
}
else if(num == 7)
{
  cout<<f(37)<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n"<<e();
  break;
}
else
{
  cout<<f(37)<<"please,Enter the number"<<f(32)<<"form 1 to 6 only --"<<f(31)<<"Not{"<<num<<"}\n";
}
}

else
{
  cout<<f(37)<<"please,Enter the number form"<<f(32)<<"(1 to 6)\n\n"<<f(31)<<"not character or any thing\n";
  cin.clear();
  cin.ignore(10000,'\n');
}
}
cout<<f(33)<<"Thank you to using our libarary"<<e();
cin.get();
cin.get();
return 0;
} 