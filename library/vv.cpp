//  		    PROGRAM ON LIBRARY MANAGEMENT

//                        INCLUDE HEADER FILES
  #include<iostream>

  #include<fstream>

  #include<stdlib.h>

  #include<stdio.h>

  #include<string.h>

  #include<ctype.h>


using namespace std;

//                          FUNCTION DEFINITIONS


	void issue_book();
	void return_book();
	void stock_issue_book(char);
    void add_issue_return();
    void disp_book_name();
    void list_of_books();
    void total_book();
    void add_book();
    int mem_ship();
    void box();


//	       STRUCTURE DEFINITION


struct s_date
  {
	int dd;
	int mm;
	int yy;
  };


  class student
	{
	   public:
		   void enter_student();
		   void delete_student();
		   void modify_student();
		   int memno;
		   char name[30];
		   char address[30];
		   char f_name[30];
		   s_date dob;
		   char clas[3];
		   char sec[2];
		   int noi;
		   ~student()
			  {
			  noi=0;
			  }
	}A;


struct books

   {
	  int book_no;
      char book_name[35];
      char a_name[35];
      char p_name[35];
      char st;
   }record,B;

   char fbook_name[35];


char *strupr(char *str)
{
	unsigned char *p = (unsigned char *)str;

  	while (*p) {
    	 *p = toupper((unsigned char)*p);
      	p++;
  	}

  	return str;

}



//                          MAIN FUNCTION

int main()

{
	  int choice;

	  while(choice!='4')

	{
		system("clear");
		cout<<"\n\t\tStudent Library System\n";
		cout<<"\t\t**********************\n";
		cout<<"\n\t1.Membership\n";
		cout<<"\t2. Add/Issue/Return Books\n";
		cout<<"\t3. List of Books\n";
		cout<<"\t4. Quit from Library\n\n";
		cout<<" \n\t  Enter your choice : ";
	 	choice=getchar();

		switch(choice)

		{   
			case'1':
				mem_ship();
			  	break;
		  	case'2':
				add_issue_return();
				break;
		  	case'3':
				list_of_books();
				break;
		  	case'4':
				break;
		  	default:
				cout<<"\a";
				break;
		}
	}
	return 0;
}

//                      FUNCTION DECLARATIONS
int mem_ship()

{
	char choice;

	while(choice!='4')
	{
		system("clear");

		cout<<"\n\n\t\tMembership\n";
		cout<<"\t\t************\n";
		cout<<"\n\t1.Add Members\n";
		cout<<"\t2. Delete Members\n";
		cout<<"\t3. Modify Members\n";
		cout<<"\t4. Back to previous Menu\n\n";
		cout<<"\n\t   Enter your choice : ";
		choice=getchar();

  		switch(choice)
  		{

		   case '1':
				A.enter_student();
				break;
		   case '2':
				A.delete_student();
				break;
		   case '3':
				A.modify_student();
				break;
		   case '4':
				break;
		   default:
				cout<<"\a";
				break;
		}
	} 
	return(choice);
}

void add_issue_return()

{
	char choice;

 	while(choice!='4')

	{
		system("clear");

		cout<<"\n\n\t\tAdd/Issue/Return Books\n";
		cout<<"\t\t**********************\n";
		cout<<"\n\t1. Add Books\n";
		cout<<"\t2. Issue Books\n";
		cout<<"\t3. Return Books\n";
		cout<<"\t4. Back to previous Menu\n\n";
		cout<<"\n\t Enter your choice : ";
		choice=getchar();

		switch(choice)

		{
		  	case'1':
			   	add_book();
				break;
		 	case'2':
				issue_book();
				break;
		  	case'3':
				return_book();
				break;
		  	case'4':
				break;
		  	default:
				cout<<"\a";
				break;
	    }
	}
}

void list_of_books()

{
    char choice;

    while (choice!='4')
	{
	    system("clear");
	   	cout<<"\n\n\t\tList of Books\n";
	   	cout<<"\t\t*************\n";
	   	cout<<"\n\t1. Total Books\n";
	   	cout<<"\t2. Books Issued\n";
	   	cout<<"\t3. Books in stock\n";
	   	cout<<"\t4. Back to Previous Menu.\n\n";
	   	cout<<"\t\t  Enter your Choice : ";
	   	choice=getchar();
	    switch (choice)
	    {
		   	case '1':
			 	total_book();
			 	break;
		    case '2':
			 	stock_issue_book('I');
			 	break;
		    case '3':
			 	stock_issue_book('S');
			 	break;
		    case '4':
			 	break;
		    default:
			 	cout<<"\a";
			 	break;
	    }
	}
}

 void student::enter_student()
	{
	  int tmem,flag=0;
	  char ch='Y';
	  student stud;
	  s_date t_dob;
	do
	   {
			system("clear");
			flag=0;
			cout<<"\n\n\t\t Membership data entry  ";
			cout<<"\n\n\t\t=========================";
			cout<<"\n\nMembership no. :   ";
			cin>>A.memno;
			ifstream ob1;
			ob1.open("STUD.dat",ios::binary);
			while(ob1.read((char *)&stud,sizeof(stud)))
			{
	   			if(stud.memno==A.memno)
				{
		 			flag=1;
		 			break;
				}
			}
			if(flag==1)
			{
	   			cout<<"\n This Membership Number Already Exits \a\n\n";
	    		cout<<" Please Try Again !!";
	   			break;
			}
			else
			{

				cout<<"\nName :   ";
				// cin.ignore();
        		// cin.getline(A.name,50);
				// gets(A.name);
				cin>>A.name;
				strupr(A.name);
				cout<<"\nAddress :   ";
				cin>>A.address;
				//cin.getline(A.address,50);
				//gets(A.address);
				strupr(A.address);
				cout<<"\nFather's name :  ";
				cin>>A.f_name;
				// cin.getline(A.f_name,50);
				//gets(A.f_name);
				strupr(A.f_name);
				cout<<"\nClass :  ";
				cin>>A.clas;
				cout<<"\nSection : ";
				cin>>A.sec;
				cout<<"\nDate of Birth (dd/mm/yy): ";
				cin>>A.dob.dd;
				cin>>A.dob.mm;
				cin>>A.dob.yy;
				ofstream ob2;
				ob2.open("STUD.dat",ios::app|ios::binary);
				ob2.write((char*)&A,sizeof(A));
				ob2.close();
			}

			cout<<"\n\nDo you Want to add more members ?(Y/N):  ";
			cin>>ch;
	  	}while(ch=='Y'||ch=='y');
	  	
	}
void student::delete_student()
{
	int rn;
	int flag=0;
	ifstream ob3;
	ob3.open("STUD.dat",ios::binary);
	ofstream ob4;
	ob4.open("TEMP.dat",ios::binary);
	cout<<"\n\nEnter the membership number to be deleted : ";
	cin>>rn;
	while(ob3.read((char*)&A,sizeof(A)))
	{
		if(rn==A.memno)
	  		flag=1;
		else
	  		ob4.write((char *)&A,sizeof(A));
	}
  	remove("STUD.dat");
  	rename("TEMP.dat","STUD.dat");
  	if(flag==0)
		cout<<"\n\nNo Record found \a";
  	else
		cout<<"\nRecord deleted !!  " ;
  // getchar(); 
}

void student::modify_student()
{ 
	char ch;
  	int rn;
  	int flag=0;
  	ifstream ob5;
  	ob5.open("STUD.dat",ios::binary);
  	ofstream ob6;
  	ob6.open("TEMP.dat",ios::binary);
 	cout<<"\nEnter the member number to modify: ";
 	cin>>rn;
 	while(ob5.read((char *)&A,sizeof(A)))
	{
		if(rn==A.memno)
	  	{
		    flag=1;
		  	cout<<"\n\n Membership No.  :  "<<A.memno;
		  	cout<<"\n\n Name is  :  "<<A.name;
		  	cout<<"\n\n Address is  :  "<<A.address;
		  	cout<<"\n\n Fathers Name is  :  "<<A.f_name;
		  	cout<<"\n\nDate of Birth (dd/mm/yy): "<<A.dob.dd<<"  "<<A.dob.mm<<"  "<<A.dob.yy<<"\n";
		  	cout<<"\nDo you want to modify this record(Y/N)   :";
		  	cin>>ch;
		  	if(ch=='Y'||ch=='y')
		    {
			    system("clear");
			    ob5.open("STUD.dat",ios::out|ios::in) ;
			    cout<<"\nModifying member number      :"<<A.memno<<"\n";
			    cout<<"\nDo you want to modify name(Y/N)     :";
			    cin>>ch;
		     	if(ch=='Y'||ch=='y')
		       	{
		       		cout<<"\nEnter the modified name      :";
		       		cin>>A.name;
		       		// cin.ignore();
        			// cin.getline(A.name,50);
		       		// //gets(A.name);
		       		strupr(A.name);
				}
		 		cout<<"\nDo you want to modify address(Y/N) :  ";
		  		cin>>ch;
		  		if(ch=='Y'||ch=='y')
		    	{
		    		cout<<"\nEnter the modified address     :";
		    		cin>>A.address;
		    		//cin.getline(A.address,50);
		    		//gets(A.address);
		    		strupr(A.address);
		    	}
		  		cout<<"\nDo you want to modify father name(Y/N):  ";
		  		cin>>ch;
		  		if(ch=='Y'||ch=='y')
		  		{
		  			cout<<"\nEnter the modified father's name      :";
		  			cin>>A.f_name;
		  			//cin.getline(A.f_name,50);
		  			//gets(A.f_name);
		  			strupr(A.f_name);
		  		}
		  		cout<<"\nDo you want to modify Class(Y/N) :  ";
		  		cin>>ch;
		  		if(ch=='Y'||ch=='y')
		    	{
		     		cout<<"\nEnter the modified class      : ";
		     		cin>>A.clas;
		    	}
		  		cout<<"\nDo you want to modify section(y/n)  :";
		  		cin>>ch;
		  		if(ch=='Y'||ch=='y')
		    	{
		     		cout<<"\nEnter the modified section      :";
		     		cin>>A.sec;
		    	}
		 		cout<<"\nDo you want to madify Date of Birth (dd/mm/yy)(y/n): ";
		  		cin>>ch;
		  		if(ch=='Y'||ch=='y')
		  		{
		  			cout<<"\nEnter the modified dob    :";
		  			cin>>A.dob.dd;
		  			cin>>A.dob.mm;
		  			cin>>A.dob.yy;
				}
		 	}
	      	ob6.write((char*)&A,sizeof(A));
		}
		else{
	  		ob6.write((char*)&A,sizeof(A));
		}
	}
  	remove("STUD.dat");
  	rename("TEMP.dat","STUD.dat");
  	if(flag==0)
		cout<<"\n\nNo Record found \a";
  	else
		cout<<"\nRecord modified !!  " ;

  // getchar();
}

void add_book()
{
	int tmem,flag=0;
	char ch='Y';
	books libdata;
	do
	{
		system("clear");
		flag=0;
		cout<<"\n\n\t\t Books data entry  ";
		cout<<"\n\n\t\t===================";
		cout<<"\n\nBook no. :   ";
		cin>>record.book_no;
		ifstream ob8;
		ob8.open("libdata.dat",ios::binary);
	 	while(ob8.read((char *)&libdata,sizeof(libdata)))
	   	{
	   		if(libdata.book_no==record.book_no)
		 	{
		 		flag=1;
		 		break;
		 	}
	   	}
	 	if(flag==1)
	   	{
	   		cout<<"\n This Book Number Already Exits \a\n\n";
	   		cout<<" Please Try Again !!";
	   		break;
	   	}
	 	else
	   	{
	   		cout<<"\nBook Name :   ";
	 		cin>>record.book_name;
	 		//cin.ignore();
        	//cin.getline(record.book_name,50);
	 		//gets(record.book_name);
	 		cout<<"\nAuthor Name :   ";
			cin>>record.a_name;
			//cin.getline(record.a_name,50);
			// gets(record.a_name);
			cout<<"\nPublisher name :  ";
			cin>>record.p_name;
			// cin.getline(record.p_name,50);
			// gets(record.p_name);
			record.st='S';
			cout<<"\nStatus    "<<record.st;
			ofstream ob9;
			ob9.open("libdata.dat",ios::app|ios::binary);
			ob9.write((char*)&record,sizeof(record));
			ob9.close();
		}
	 	cout<<"\n\nDo you Want to add more books ?(Y/N):  ";
	 	cin>>ch;
	}while(ch=='Y'||ch=='y');
	
}


void total_book()

{
    system("clear");
    int n,i=0;
    ifstream disp_tot_bk;
    disp_tot_bk.open("libdata.dat",ios::out|ios::binary|ios::app);
    if(!disp_tot_bk)
	{
	    system("clear");
	    cout<<"\aError Opening Library Data File.\n";
	    exit(0);
	}

    system("clear");
    cout<<"\n\t\t    Total Books";
    cout<<"\n\t\t    ^^^^^^^^^^^";
    cout<<"\n\n Book No         Name        Author                   Issued/Stock\n";
    cout<<"^^^^^^^^^       ^^^^^^       ^^^^^^^                  ^^^^^^^^^^^^^^\n";


    while(disp_tot_bk.read((char*)&record,sizeof(books)))
	{
	    cout<<"   "<<record.book_no<<"    ";
	    cout<<"        ";
	    cout<<record.book_name<<"     " ;
	    cout<<"    ";
	    cout<<record.a_name<<"\t\t\t\t";
	    cout<<record.st<<"\n";
	    i++;

	}
    cout<<"\n\nTotal number of books : "<<i<<"\n";
    disp_tot_bk.close();
    cout<<"\n\nPress any key...";
    
}

void stock_issue_book(char mtype)

{

    system("clear");
    int n,i=0;
    ifstream stck_issu_bk;
    stck_issu_bk.open("libdata.dat",ios::out|ios::binary|ios::app);

    if(!stck_issu_bk)
	{
	    system("clear");
	    cout<<"\aError Opening Library Data File.\n";
	    exit(0);
	}
	i=0;
	system("clear");

	if(mtype=='I')
	{
		cout<<"\t\t\tList of Books Issued\n";
		cout<<"\t\t     ^^^^^^^^^^^^^^^^^^^^\n\n";
	}
	else
	{
		cout<<"\n\t\t      List of books in Stock\n";
		cout<<"\t\t      ^^^^^^^^^^^^^^^^^^^^^^\n\n";
	}

    cout<<"Book No    Name            \t\t    Status\n";
    cout<<"^^^^^^^    ^^^^            \t\t     ^^^^^^\n"; 
    int count=0;

    while(stck_issu_bk.read((char*)&record,sizeof(books)))
	{

	    if(record.st==mtype)
	    {
		  cout<<record.book_no<<"\t";
		  cout<<"   ";

	       disp_book_name();


		  cout<<record.st<<"\n";
		  i++;
		  count++;
	    }

		  if(count>13)
		    {
		       count=0;
		       getchar();
		       system("clear");

				if(mtype=='I')
			  	{
			     	cout<<"\t\t    List of books Issued\n";
			     	cout<<"\t\t    ^^^^^^^^^^^^^^^^^^^^\n\n";
			  	}

				else
			  	{
			    	 cout<<"\t\t    List of books in Stock\n";
			     	cout<<"\t\t    ^^^^^^^^^^^^^^^^^^^^^^\n\n";
			  	}
				cout<<"Book No    Name    \t\t                  Status\n";
				cout<<"^^^^^^^    ^^^^          \t\t          ^^^^^^\n";
		    }
	}
	cout<<"\n\nTotal number of Books : "<<i<<"\n";
	stck_issu_bk.close();
	cout<<"\n\nPress any key...";
	   // getchar();
  }


 void disp_book_name()

  {
      int i=0;
      strcpy(fbook_name,NULL);
      strcpy(fbook_name,record.book_name);
      i=strlen(fbook_name);

      if(i<34)
		{
	    	for(;i<34;i++)
	      	{
		  		fbook_name[i]=' ';
	      	}
		}
	  cout<<fbook_name;
	  strcpy(fbook_name,NULL);
  }






void return_book()

{
	  int bno,mno,f1=0,f2=0;

	  cout<<"\n\n    Return of Books\n";
	  cout<<"    ^------------^\n";

	  cout<<"Enter the book Number (0 to Exit) : ";
	  cin>>bno;

	  cout<<"\nEnter the member number : ";
	  cin>>mno;

	  if(mno==0||bno==0)
		return;

	  ifstream ob;
	  ob.open("stud.dat",ios::binary);
	  while(ob.read((char*)&A,sizeof(A)))
	  {
			if(A.memno==mno)
		  	{
		  		f1=1;
		  		break;
		  	}
	  }

  char name[35];

  ifstream ob1;
  ob1.open("libdata.dat",ios::binary);
  while(ob1.read((char*)&B,sizeof(B)))
	{
	if(B.book_no==bno&&B.st=='I')
	  {
	  	strcpy(name,B.book_name);
	  	f2=1;
	  	break;
	  }
	}

  if(f1==1&&f2==1)
	{
	ifstream ob2;
	ob2.open("stud.dat",ios::binary);

	ofstream ob3;
	ob3.open("temp");
	while(ob2.read((char*)&A,sizeof(A)))
	  {
	  if(A.memno==mno)
		--A.noi;
	  ob3.write((char*)&A,sizeof(A));
	  }
	remove("stud.dat");
	rename("temp","stud.dat");


	ifstream ob4;
	ob4.open("libdata.dat",ios::binary);
	ofstream ob5;
	ob5.open("temp");

	while(ob4.read((char*)&B,sizeof(B)))
	  {
	  if(B.book_no==bno&&B.st=='I')
		B.st='S';
	  ob5.write((char*)&B,sizeof(B));
	  }
	remove("libdata.dat");
	rename("temp","libdata.dat");


	cout<<"\n\n"<<name<<" is returned";
	}
  else
	cout<<"\nConnot return \a";


  // getchar();

}



void issue_book()

{

  int bno,mno,f1=0,f2=0;

  cout<<"\n\n    Issue of Books\n";
  cout<<"    ^------------^\n";

  cout<<"Enter the book Number (0 to Exit) : ";
  cin>>bno;

  cout<<"\nEnter the member number : ";
  cin>>mno;

  if(mno==0||bno==0)
	return;

  ifstream ob;
  ob.open("stud.dat",ios::binary);
  while(ob.read((char*)&A,sizeof(A)))
	{
	if(A.memno==mno&&A.noi<3)
	  {
	  f1=1;
	  break;
	  }
	}

  char name[35];

  ifstream ob1;
  ob1.open("libdata.dat",ios::binary);
  while(ob1.read((char*)&B,sizeof(B)))
	{
	if(B.book_no==bno&&B.st=='S')
	  {
	  strcpy(name,B.book_name);
	  f2=1;
	  break;
	  }
	}

  if(f1==1&&f2==1)
	{
	ifstream ob2;
	ob2.open("stud.dat",ios::binary);

	ofstream ob3;
	ob3.open("temp");
	while(ob2.read((char*)&A,sizeof(A)))
	  {
	  if(A.memno==mno&&A.noi<3)
		A.noi++;
	  ob3.write((char*)&A,sizeof(A));
	  }
	remove("stud.dat");
	rename("temp","stud.dat");


	ifstream ob4;
	ob4.open("libdata.dat",ios::binary);
	ofstream ob5;
	ob5.open("temp");

	while(ob4.read((char*)&B,sizeof(B)))
	  {
	  if(B.book_no==bno&&B.st=='S')
		B.st='I';
	  ob5.write((char*)&B,sizeof(B));
	  }
	remove("libdata.dat");
	rename("temp","libdata.dat");

	cout<<"\n\n"<<name<<" is issued";
	}
  else

	cout<<"\nConnot issue !!\a";
  // getchar();
}