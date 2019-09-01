 #include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class book
{
protected:
     int b_no;
     string bname;
     int bissued;
public:
      book();
      void set_bname(string bn);
      string get_bname();
      void set_bno(int b_no);
      int get_bno();
      void set_bissued(int b_iss);
      int get_bissued();            
};

book::book()
{
            b_no = 0;
            bissued = 0;
}

void book :: set_bname(string bn)
{
     bname = bn;
}

void book :: set_bno(int bno)
{
     b_no = bno;
}

void book :: set_bissued(int b_iss)
{
     bissued = b_iss;
}


string book :: get_bname()
{
       return bname;
}

int book :: get_bno()
{
       return b_no;
}

int book :: get_bissued()
{
       return bissued;
}





class teacher
{
     
public:
string name;
int limit;
int emp_code;
int bno[3];

public:
teacher();
void set_limit(int lmt);
int get_limit();
//void set_emp_code(int lmt);
//int get_emp_code();
void set_name(string n);
string get_name();


void Insert_Teacher_Data(string tn, int lm);

};

teacher :: teacher()
{
        limit = 0;
        bno[0]=0;
        bno[1]=0;
        bno[2]=0;
}


void teacher :: set_limit(int lmt)
{
     limit = lmt;
}


void teacher :: set_name(string n)
{
     name = n;
}

int teacher :: get_limit()
{
    return limit;
    
}

string teacher :: get_name()
{
    return name;
}

  void  teacher :: Insert_Teacher_Data(string tn, int lm)
    {
            this->set_name(tn);
            this->set_limit(lm);
    }


 class Student
{
     
public:
string name;
int limit;
int bno;

public:
       Student();
void set_limit(int lmt);
int get_limit();
void set_b_code(int bc);
int get_b_code();
void set_name(string n);
string get_name();

};


Student :: Student()
{
        limit = 0;
        bno = 0;
}


void Student :: set_limit(int lmt)
{
     limit = lmt;
}


void Student :: set_name(string n)
{
     name = n;
}

void Student :: set_b_code(int bc)
{
     bno = bc;
}

int Student :: get_b_code()
{
    return bno;
    
}

int Student :: get_limit()
{
    return limit;
    
}

string Student :: get_name()
{
    return name;
}


int main(int argc, char *argv[])
{
    int v=0,g=0;
    int fg=0,hj=0;
    int yyy=0;
    int qqq=0;
    int ww=0;
    int mm=0;
    const int max_bk = 100, max_t = 5, max_std = 5;
    book bk[max_bk];
    teacher tec[max_t];
    Student std[max_std];
    int bkn=0;
    int tn=0;
    int sn=0;
    char ans;
    char menu;
    do
                {
        system("clear");
    cout<<"---------------- Main Menu ---------------------------"<<endl;
    cout<<"1. For Add Book"<<endl;
    cout<<"2. Add Teacher"<<endl;
    cout<<"3. Add Student"<<endl;
    cout<<"4. Issue Book to Teacher"<<endl;
    cout<<"5. For Return Book from teacher"<<endl;
    cout<<"6. Issue Book to Student"<<endl;
    cout<<"7. For Return Book from Student"<<endl;
    cout<<"8. For Check and Display"<<endl;
    cout<<"0. For Exit"<<endl;
    cout<<"------------------------------------------------------"<<endl;
    cout  << "Select from Menu: ";
    cin>>menu;
    switch (menu)
                {
    case '1':{
         cout<<"---------------- Add Book -----------------------"<<endl;
            do{
                
                 string bn;
                 int bno;
                cout  << "Enter Book Name:- ";
                cin>>bn;
                cout  << "Enter Book Code:- ";
                cin>>bno;
                bk[bkn].set_bname(bn);
                bk[bkn].set_bno(bno);
                bk[bkn].set_bissued(0);
                bkn++;
                cout << "Enter another (y/n)?:- " ;
                cin >> ans;
              } while ( ans != 'n' );

             }break;
      case '2':{
         cout<<"---------------- Insert Teacher -----------------------"<<endl;
            do{
                 
                 string tnm;
                cout  << "Enter Teacher Name:- ";
                cin>>tnm;
                tec[tn].set_name(tnm);
                //bk[tn++].set_bno(bno);
                tec[tn].set_limit(0);
                tn++;
                cout << "Enter another (y/n)?:- " ;
                cin >> ans;
              } while ( ans != 'n' );

             }break;
          case '3':{
         cout<<"---------------- Insert Student -----------------------"<<endl;
            do{
                
                 string stdn;
                cout  << "Enter Student Name:- ";
                cin>>stdn;
                std[sn].set_name(stdn);
                std[sn].set_b_code(0);
                std[sn].set_limit(0);
                sn++;
                cout << "Enter another (y/n)?:-" ;
                cin >> ans;
              } while ( ans != 'n' );

             }break;
         case '4':{
         cout<<"---------------- Issue Book to Teacher -----------------------"<<endl;
            do{
                 string tnm;
                 int bcode;
                 
                cout  << "Enter Teacher Name:- ";
                cin>>tnm;
                cout  << "Enter Book Code:- ";
                cin>>bcode;
                for(int i=0; i<max_t; i++)
                {
                        if(tec[i].get_name() == tnm)
                        {
                                             int lm = tec[i].get_limit();
                                             // cout<<"Limit is: "<<lm<<endl;
                                             if(lm <=3)
                                             {
                                                   for(int k=0; k<max_bk; k++)
                                                   {
                                                           if(bk[k].get_bno()==bcode)
                                                           {
                                                                                     cout<<"Issued:- "<<bk[k].get_bissued()<<endl;
                                                                                     if(bk[k].get_bissued()==0)
                                                                                     {
                                                                                                               bk[k].set_bissued(1);
                                                                                                               tec[i].bno[lm] = bcode;
                                                                                                               lm = lm +1;
                                                                                                               tec[i].set_limit(lm);
                                                                                     }
                                                                                     else
                                                                                     {
                                                                                          cout << "This Book is already issued" <<endl;
                                                                                     }
                                                                                   break; 
                                                           }
                                                           else{
                                                              v=1;
                                                           }
                                                   }
                                                                  
                                             }
                                             else
                                             {
                                                 cout << "You have reached the MAXIMUM Limit."<<endl;
                                             }
                        }else{
                            g=1;
                        }
                }
                if(v==1) cout<<"BOOK NOT FOUND!"<<endl;
                if(g==1) cout<<"Teacher Not Found!"<<endl;
                cout << "Enter another (y/n)?:- " ;
                cin >> ans;
              } while ( ans != 'n' );

             }break;
        case '5':{
         cout<<"---------------- Return Book -----------------------"<<endl;
            do{
                 string tnm;
                 int bcode;
                 
                cout  << "Enter Teacher Name:- ";
                cin>>tnm;
                cout  << "Enter Book Code:- ";
                cin>>bcode;
                for(int i=0; i<max_t; i++)
                {
                        if(tec[i].get_name() == tnm)
                            {
                                for(int b=0; b<3; b++)
                                {
                                      int bkno = tec[i].bno[b];
                                      //cout<<"bk: "<<bkno<<endl;
                                      if(bkno == bcode)
                                      {
                                                 int lm = tec[i].get_limit();
                                                 // cout<<"Limit is: "<<lm<<endl;
                                                 if(lm <=3)
                                                 {
                                                       for(int k=0; k<max_bk; k++)
                                                       {
                                                               if(bk[k].get_bno()==bcode)
                                                               {
                                                                                         //cout<<"Issued: "<<bk[k].get_bissued()<<endl;
                                                                                         if(bk[k].get_bissued()==1)
                                                                                         {
                                                                                                                   bk[k].set_bissued(0);
                                                                                                                   lm = lm - 1;
                                                                                                                   tec[i].set_limit(lm);
                                                                                                                   tec[i].bno[lm] = 0;
                                                                                         }
                                                                                       break; 
                                                               }
                                                              else{
                                                                  fg=1;
                                                              }
                                                       }
                                                                       
                                                 }
                                                 
                                      }
                                 }
                        }else{
                            hj=1;
                        }
                }
                if(fg==1) cout<<"BOOK NOT FOUND!"<<endl;
                if(hj==1) cout<<"Teacher Not Found!"<<endl;
                cout << "Enter another (y/n)?:- " ;
                cin >> ans;
              } while ( ans != 'n' );

             }break;
         case '6':{
         cout<<"---------------- Issue Book to Student -----------------------"<<endl;
            do{
                 string stdn;
                 int bcode;
    
                cout  << "Enter student Name:- ";
                cin>>stdn;
                cout  << "Enter Book Code:- ";
                cin>>bcode;
                for(int i=0; i<max_std; i++)
                {
                        if(std[i].get_name() == stdn)
                        {
                                             int lm = std[i].get_limit();
                                             // cout<<"Limit is: "<<lm<<endl;
                                             if(lm == 0)
                                             {
                                                   for(int k=0; k<max_bk; k++)
                                                   {
                                                           if(bk[k].get_bno()==bcode)
                                                           {
                                                                                     //cout<<"Issued: "<<bk[k].get_bissued()<<endl;
                                                                                     if(bk[k].get_bissued()==0)
                                                                                     {
                                                                                                               bk[k].set_bissued(1);
                                                                                                               std[i].set_b_code(bcode);
                                                                                                               lm = lm +1;
                                                                                                               std[i].set_limit(lm);
                                                                                     }
                                                                                     else
                                                                                     {
                                                                                          cout << "This Book is already issued" <<endl;
                                                                                     }
                                                                                   break; 
                                                           }
                                                           else{
                                                                yyy=1;
                                                              }
                                                   }
                                                                  
                                             }
                                             else
                                             {
                                                 cout << "You have reached the MAXIMUM Limit."<<endl;
                                             }
                        }else{
                          qqq=1;
                        }
                }
                if(yyy==1) cout<<"BOOK NOT FOUND!"<<endl;
                if(qqq==1) cout<<"Teacher Not Found!"<<endl;
                cout << "Enter another (y/n)?:- " ;
                cin >> ans;
              } while ( ans != 'n' );

             }break;
        case '7':{
         cout<<"---------------- Return Book -----------------------"<<endl;
            do{
                 string stdn;
                 int bcode;
                 
                cout  << "Enter student Name:- ";
                cin>>stdn;
                cout  << "Enter Book Code:- ";
                cin>>bcode;
                for(int i=0; i<max_std; i++)
                {
                        if(std[i].get_name() == stdn)
                            {
                                for(int b=0; b<3; b++)
                                {
                                      int bkno = std[i].get_b_code();
                                      //cout<<"bk: "<<bkno<<endl;
                                      if(bkno == bcode)
                                      {
                                                 int lm = std[i].get_limit();
                                                 // cout<<"Limit is: "<<lm<<endl;
                                                 if(lm ==1)
                                                 {
                                                       for(int k=0; k<max_bk; k++)
                                                       {
                                                               if(bk[k].get_bno()==bcode)
                                                               {
                                                                                         //cout<<"Issued: "<<bk[k].get_bissued()<<endl;
                                                                                         if(bk[k].get_bissued()==1)
                                                                                         {
                                                                                                                   bk[k].set_bissued(0);
                                                                                                                   lm = lm - 1;
                                                                                                                   std[i].set_limit(lm);
                                                                                                                   std[i].set_b_code(0);
                                                                                         }
                                                                                       break; 
                                                               }
                                                               else{
                                                                  ww=1;
                                                              }
                                                       }
                                                                      
                                                 }
                                      }
                                 }
                        }else{
                            mm=1;
                        }
                }
                if(ww==1) cout<<"BOOK NOT FOUND!"<<endl;
                if(mm==1) cout<<"Teacher Not Found!"<<endl;
                cout << "Enter another (y/n)?:- " ;
                cin >> ans;
              } while ( ans != 'n' );

             }break;
        case '8':{
             char smenu;
             system("clear");
            cout<<"---------------- Search Menu ---------------------------"<<endl;
            cout<<"1. For Display all Book"<<endl;
            cout<<"2. For Display all Teachers"<<endl;
            cout<<"3. For Display all Student"<<endl;
            cout<<"4. For check book is issued or not"<<endl;
            cout<<"5. For check all issued Book"<<endl;
            cout<<"------------------------------------------------------"<<endl;
            cout  << "Select from Menu: ";
            cin>>smenu;
            switch (smenu)
                {
                case '1':{
                for(int i=0; i<bkn; i++)
                {
                        cout<<"Name is: "<<bk[i].get_bname()<<endl;
                        cout<<"Book Code: "<<bk[i].get_bno()<<endl;
                        cout<<"Book issued: "<<bk[i].get_bissued()<<endl;
                }
                getchar();

                     }break;
                case '2':{
                     for(int i=0; i<tn; i++)
                        {
                                cout<<"Name is: "<<tec[i].get_name()<<endl;
                                cout<<"Limit is: "<<tec[i].get_limit()<<endl;
                                for(int j=0; j<3; j++)
                                {
                                        cout<<"Book Code: "<<tec[i].bno[j]<<endl;
                                }
                        }
                        getchar();
                       
       
                     }break;
                case '3':{
                     for(int i=0; i<sn; i++)
                        {
                                cout<<"Name is: "<<std[i].get_name()<<endl;
                                cout<<"Book Code: "<<std[i].get_b_code()<<endl;
                                cout<<"Limit is: "<<std[i].get_limit()<<endl;
                        }
                        getchar();
                       
       
                     }break;
                case '4':{
                     int bk_no;
                     int bb=0;
                     cout  << "Book Code: ";
                     cin>>bk_no;
                     for(int i=0; i<max_bk; i++)
                        {
                                if(bk[i].get_bno()==bk_no)
                                {
                                      cout<<"Name is: "<<bk[i].get_bname()<<endl;
                                      cout<<"Book Code: "<<bk[i].get_bno()<<endl;
                                      if(bk[i].get_bissued()==1)
                                      {
                                          cout<<"Book is issued. "<<endl;
                                      }
                                      else
                                      {
                                          cout<<"Book is not issued. "<<endl;
                                      }
                                }else{
                                      bb=1;
                                     }
                        }if(bb==1) cout<<"book not found!"<<endl;
                        getchar();
                     }break;
                case '5':{
                  int jj=0;
                     for(int i=0; i<max_bk; i++)
                        {
                                if(bk[i].get_bissued()==1)
                                {
                                      cout<<"Name is: "<<bk[i].get_bname()<<endl;
                                      cout<<"Book Code: "<<bk[i].get_bno()<<endl;
                                }else{
                                      jj=1;
                                      }
                        }if(jj==1) cout<<"book not found!"<<endl;
                        getchar();
                     }break;
               default:{
                                                 break;
                                }              break;
               
             }
             }break;
         default:{
                                                 cout << "Really want to Exit (y/n)?: " ;
                     cin >> menu;
                                }              break;
        }
      
    }while(menu!='y');
                getchar();
    return 0;
}

