#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void textcolor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void sq();

struct log
{
 char c_name[50];
 char id[20];
 char pass[20];
};

struct emp
{
 char emp_id[10];
 char fname[30];
 char lname[30];
 double b_s;
};

void main()
{
 FILE *log,*empf,*temp;

 struct log l;
 struct emp e;

 int sizel,sizee,count,x,y,s_no,extra,n=0;
 char id[20],pass[20],opt,loop='Y',search[10],emp_id[10],fname[30],lname[30],sure;
 double b_s,t_wd,wd[100],sal=0,e_c=0,em_c=0,p_s=0;

 again:

 system("cls");
 sq();

 textcolor(6);
 gotoxy(32,4);
 printf("EPF MANAGEMENT SYSTEM");
 gotoxy(8,5);
 printf("Developed By-Himanshu Nagar");
 gotoxy(45,5);
 printf("  Guided By-Mrs. Rashi Saxena");

 log=fopen("log","r");
 sizel=sizeof(l);

 if(fread(&l,sizel,1,log) != 1)
 {
   textcolor(4);
   gotoxy(25,8);
   printf("Press Enter Key for Registration");
   getch();
   log=fopen("log","w");
   textcolor(3);
   gotoxy(10,10);
   printf("Enter Company/Institute Name:");
   fgets(l.c_name, sizeof(l.c_name), stdin);
   gotoxy(10,11);
   printf("Enter User Id:");
   fgets(l.id, sizeof(l.id), stdin);
   gotoxy(10,12);
   printf("Enter Password:");
   fgets(l.pass, sizeof(l.pass), stdin);
   fwrite(&l,sizel,1,log);
   textcolor(2);
   gotoxy(20,15);
   printf("Registration Successful");
   gotoxy(20,16);
   printf("Press Enter to Login");
   getch();
   fclose(log);
   goto again;
 }

 else
 {
   do
   {
   log=fopen("log","r");
   system("cls");
   sq();
   textcolor(6);
   gotoxy(32,4);
   printf("EPF MANAGEMENT SYSTEM");
   gotoxy(8,5);
   printf("Developed By-Himanshu Nagar");
   gotoxy(45,5);
   printf("  Guided By-Mrs. Rashi Saxena");
   textcolor(2);
   gotoxy(30,8);
   printf("Enter User Id:");
   fgets(id, sizeof(id), stdin);
   gotoxy(30,9);
   printf("Enter Password:");
   fgets(pass, sizeof(pass), stdin);

   if(strcmp(id,l.id)==0&&strcmp(pass,l.pass)==0)
   {
    while(1)
    {
     system("cls");
     sq();
     textcolor(6);
     gotoxy(28,4);
     printf("WELCOME TO EPF MANAGEMENT SYSTEM");
     textcolor(7);
     gotoxy(28,6);
     puts(l.c_name);
     textcolor(2);
     gotoxy(38,8);
     printf("MAIN MENU");
     textcolor(3);
     gotoxy(33,10);
     printf("1. Add New Employee");
     gotoxy(33,11);
     printf("2. Search an Employee");
     gotoxy(33,12);
     printf("3. List of Employees");
     gotoxy(33,13);
     printf("4. Calculate EPF");
     gotoxy(33,14);
     printf("5. Modify an Employee");
     gotoxy(33,15);
     printf("6. Delete an Employee");
     gotoxy(33,16);
     printf("7. Delete All Employees");
     gotoxy(33,17);
     printf("8. Exit");
     textcolor(2);
     gotoxy(33,18);
     printf("Choose an Option:");
     opt=getch();

     switch(opt)
     {
     case '1':
     empf=fopen("emp","a+");
     if (empf == NULL) 
     {
      printf("Error opening file.\n");
     }
     sizee=sizeof(e);
     do
     {
     system("cls");
     sq();
     textcolor(6);
     gotoxy(32,4);
     printf("EPF MANAGEMENT SYSTEM");
     textcolor(2);
     gotoxy(34,6);
     printf("Add New Employee");
     textcolor(3);
     gotoxy(30,8);
     printf("Enter Employee's Id:");
     scanf("%10s",emp_id);
     gotoxy(30,9);
     printf("Enter Employee's First Name:");
     scanf("%30s",fname);
     gotoxy(30,10);
     printf("Enter Employee's Last Name:");
     scanf("%30s",lname);
     gotoxy(30,11);
     printf("Enter Employee's Basic Salary:");
     scanf("%lf",&b_s);
     extra=0;
     rewind(empf);
     while(fread(&e,sizee,1,empf) == 1)
     {
      if(strcmp(emp_id,e.emp_id)==0)
      {
      extra=1;
      break;
      }
      else
      extra=0;
     }
     if(extra==0)
     {
     strcpy(e.emp_id,emp_id);
     strcpy(e.fname,fname);
     strcpy(e.lname,lname);
     e.b_s=b_s;
     fwrite(&e,sizee,1,empf);
     textcolor(2);
     gotoxy(33,13);
     printf("Employee Added Successfully");
     }
     if(extra==1)
     {
     textcolor(4);
     gotoxy(25,13);
     printf("Sorry! Employee Id is Already Available");
     gotoxy(28,14);
     printf("Please Enter an Unique Employee Id");
     }
     gotoxy(26,16);
     textcolor(5);
     printf("Do you want to Add Another Employee(Y/N):");
     scanf(" %c",&loop);
     }while(loop=='Y'||loop=='y');
     fclose(empf);
     break;
     case '2':
     empf=fopen("emp","r");
     sizee=sizeof(e);
     do
     {
     rewind(empf);
     system("cls");
     sq();
     textcolor(6);
     gotoxy(32,4);
     printf("EPF MANAGEMENT SYSTEM");
     textcolor(2);
     gotoxy(34,6);
     printf("Search an Employee");
     gotoxy(25,8);
     printf("Enter Employee's Id to Search:");
     scanf("%s",&search);
     extra=1;
     while(fread(&e,sizee,1,empf) == 1)
     {
      if(strcmp(search,e.emp_id)==0)
      {
       textcolor(3);
       gotoxy(25,10);
       printf("Employee's Id:%s",e.emp_id);
       gotoxy(25,11);
       printf("Employee's Name:%s %s",e.fname,e.lname);
       gotoxy(25,12);
       printf("Employee's Basic Salary:%.2lf",e.b_s);
       extra=0;
       break;
      }
     }
     if(extra!=0)
     {
      textcolor(4);
      gotoxy(22,10);
      printf("Employee is not available in Database");
     }
     textcolor(5);
     gotoxy(20,14);
     printf("Do you want to Search Another Employee(Y/N):");
     scanf(" %c",&loop);
     }while(loop=='Y'||loop=='y');
     fclose(empf);
     break;
     case '3':
     empf=fopen("emp","r");
     sizee=sizeof(e);
     system("cls");
     sq();
     textcolor(6);
     gotoxy(32,4);
     printf("EPF MANAGEMENT SYSTEM");
     textcolor(2);
     gotoxy(34,6);
     printf("List of Employees");
     y=8;
     gotoxy(18,y);
     printf("|");
     gotoxy(19,y);
     printf("S.No.");
     gotoxy(24,y);
     printf("|");
     gotoxy(25,y);
     printf("ID");
     gotoxy(29,y);
     printf("|");
     gotoxy(30,y);
     printf("Employee's Name");
     gotoxy(50,y);
     printf("|");
     gotoxy(51,y);
     printf("Basic Salary");
     gotoxy(63,y);
     printf("|");
     y=9;
     s_no=1;
     extra=1;
     while(fread(&e,sizee,1,empf) == 1)
     {
      if(extra==12)
      {
       textcolor(2);
       gotoxy(25,21);
       printf("Press Enter To See More Employees");
       getch();
       system("cls");
       sq();
       y=5;
       extra=1;
      }
      textcolor(3);
      gotoxy(18,y);
      printf("|");
      gotoxy(19,y);
      printf("%d",s_no);
      gotoxy(24,y);
      printf("|");
      gotoxy(25,y);
      printf("%s",e.emp_id);
      gotoxy(29,y);
      printf("|");
      gotoxy(30,y);
      printf("%s %s",e.fname,e.lname);
      gotoxy(50,y);
      printf("|");
      gotoxy(51,y);
      printf("%.2lf",e.b_s);
      gotoxy(63,y);
      printf("|");
      y++;
      s_no++;
      extra++;
     }
     getch();
     fclose(empf);
     break;
     case '4':
     empf=fopen("emp","r");
     sizee=sizeof(e);
     system("cls");
     sq();
     textcolor(6);
     gotoxy(32,4);
     printf("EPF MANAGEMENT SYSTEM");
     textcolor(7);
     gotoxy(25,6);
     printf("Enter Total Working Days in this Month:");
     scanf("%lf",&t_wd);
     y=8;
     extra=1;
     while(fread(&e,sizee,1,empf) == 1)
     {
      if(extra==13)
      {
       gotoxy(25,21);
       printf("Press Enter to Proceed Further");
       getch();
       system("cls");
       sq();
       extra=1;
       y=6;
      }
      textcolor(3);
      gotoxy(25,y);
      printf("Enter Working Days of %s %s:",e.fname,e.lname);
      scanf("%lf",&wd[n]);
      n++;
      y++;
      extra++;
     }
     rewind(empf);
     system("cls");
     textcolor(6);
     gotoxy(34,1);
     printf("EPF SALARY SHEET");
     textcolor(14);
     gotoxy(25,2);
     printf("%s",l.c_name);
     y=3;
     textcolor(4);
     gotoxy(1,y);
     printf("S.No.");
     gotoxy(6,y);
     printf("|");
     gotoxy(7,y);
     printf("Employee's Name");
     gotoxy(27,y);
     printf("|");
     gotoxy(28,y);
     printf("Bas.Sal.");
     gotoxy(36,y);
     printf("|");
     gotoxy(37,y);
     printf("WD");
     gotoxy(39,y);
     printf("|");
     gotoxy(40,y);
     printf("Employee's Con.");
     gotoxy(55,y);
     printf("|");
     gotoxy(56,y);
     printf("Employer's Con.");
     gotoxy(71,y);
     printf("|");
     gotoxy(72,y);
     printf("Pa. Sal.");
     s_no=1;
     n=0;
     y=4;
     extra=1;
     while(fread(&e,sizee,1,empf) == 1)
     {
      if(extra==16)
      {
       textcolor(2);
       gotoxy(25,20);
       printf("Press Enter to Proceed Further");
       getch();
       system("cls");
       extra=1;
       y=2;
      }
      textcolor(3);
      gotoxy(1,y);
      printf("%d",s_no);
      gotoxy(6,y);
      printf("|");
      gotoxy(7,y);
      printf("%s %s",e.fname,e.lname);
      gotoxy(27,y);
      printf("|");
      gotoxy(28,y);
      printf("%.0lf",e.b_s);
      gotoxy(36,y);
      printf("|");
      sal=((e.b_s/t_wd)*wd[n]);
      e_c=sal*0.12;
      em_c=sal*0.12;
      p_s=sal-e_c;
      gotoxy(37,y);
      printf("%.0lf",wd[n]);
      gotoxy(39,y);
      printf("|");
      gotoxy(40,y);
      printf("%.2lf",e_c);
      gotoxy(55,y);
      printf("|");
      gotoxy(56,y);
      printf("%.2lf",em_c);
      gotoxy(71,y);
      printf("|");
      gotoxy(72,y);
      printf("%.2lf",p_s);
      s_no++;
      n++;
      y++;
      extra++;
     }
     getch();
     fclose(empf);
     break;
     case '5':
     do
     {
     empf=fopen("emp","a+");
     temp=fopen("temp","w");
     sizee=sizeof(e);
     system("cls");
     sq();
     textcolor(6);
     gotoxy(32,4);
     printf("EPF MANAGEMENT SYSTEM");
     textcolor(2);
     gotoxy(34,6);
     printf("Modify an Employee");
     gotoxy(25,8);
     printf("Enter Employee's Id to Modify Details:");
     scanf("%s",&search);
     extra=0;
     while(fread(&e,sizee,1,empf) == 1)
     {
      if(strcmp(search,e.emp_id)==0)
      {
       textcolor(3);
       gotoxy(25,10);
       printf("Enter New Employee's First Name:");
       scanf("%s",&e.fname);
       gotoxy(25,11);
       printf("Enter New Employee's Last Name:");
       scanf("%s",&e.lname);
       gotoxy(25,12);
       printf("Enter New Employee's Basic Salary:");
       scanf("%lf",&e.b_s);
       fwrite(&e,sizee,1,temp);
       textcolor(2);
       gotoxy(25,14);
       printf("Employee's Modification Successfull");
       extra=1;
      }
      else
      {
      fwrite(&e,sizee,1,temp);
      }
     }
     fclose(empf);
     fclose(temp);
     remove("emp");
     rename("temp","emp");
     if(extra==0)
     {
      textcolor(4);
      gotoxy(20,14);
      printf("Sorry! This Employee is not Available in Database");
     }
     textcolor(5);
     gotoxy(23,16);
     printf("Do you want to Modify Another Employee(Y/N):");
     scanf(" %c",&loop);
     }while(loop=='Y'||loop=='y');
     break;
     case '6':
     do
     {
     system("cls");
     sq();
     empf=fopen("emp","a+");
     temp=fopen("temp","w");
     sizee=sizeof(e);
     textcolor(6);
     gotoxy(32,4);
     printf("EPF MANAGEMENT SYSTEM");
     textcolor(2);
     gotoxy(34,6);
     printf("Delete an Employee");
     textcolor(3);
     gotoxy(25,8);
     printf("Enter Employee's Id to Delete:");
     scanf("%s",&search);
     gotoxy(25,9);
     printf("Are you sure you want to Delete(Y/N):");
     scanf("%s",&sure);
     extra=0;
     if(sure=='Y'||sure=='y')
     {
      while(fread(&e,sizee,1,empf) == 1)
      {
       if(strcmp(search,e.emp_id)!=0)
       {
	      fwrite(&e,sizee,1,temp);
       }
       else
       {
	extra=1;
       }
      }
      fclose(empf);
      fclose(temp);
      remove("emp");
      rename("temp","emp");
      if(extra==1)
      {
      textcolor(2);
      gotoxy(30,11);
      printf("Employee Deleted Successfully");
      }
      if(extra==0)
      {
       textcolor(4);
       gotoxy(20,11);
       printf("Sorry! This Employee is not Available in Database");
      }
      textcolor(5);
      gotoxy(22,13);
      printf("Do you want to Delete Another Employee(Y/N):");
      scanf("%s",&loop);
     }
     else
     {
      textcolor(5);
      gotoxy(25,11);
      printf("Do you want to Delete Another Employee:(Y/N):");
      scanf("%s",&loop);
     }
     fclose(empf);
     fclose(temp);
     }while(loop=='Y'||loop=='y');
     break;
     case '7':
     system("cls");
     sq();
     textcolor(6);
     gotoxy(32,4);
     printf("EPF MANAGEMENT SYSTEM");
     textcolor(2);
     gotoxy(32,6);
     printf("Delete All Employees");
     textcolor(3);
     gotoxy(38,8);
     printf("Warning");
     textcolor(4);
     gotoxy(15,9);
     printf("Are you sure you want to Delete All Employees(Y/N):");
     scanf(" %c",&sure);
     if(sure=='Y'||sure=='y')
     {
      remove("emp");
      textcolor(2);
      gotoxy(25,11);
      printf("All Employees Deleted Successfully");
     }
     textcolor(5);
     gotoxy(28,13);
     printf("Press Enter to go to Main Menu");
     getch();
     break;
     case '8':
     system("cls");
     sq();
     textcolor(3);
     gotoxy(28,10);
     printf("Thank You! Have a Nice Day");
     textcolor(128+4);
     gotoxy(30,11);
     printf("Press Any Key to Exit");
     fclose(log);
     getch();
     exit(0);
     break;

     default :
     system("cls");
     sq();
     textcolor(1);
     gotoxy(30,10);
     printf("Please Enter a Valid Option");
     gotoxy(28,11);
     printf("Press Enter to go to Main Menu");
     getch();

     }
    }
   }

   else
   {
    system("cls");
    sq();
    textcolor(6);
    gotoxy(32,4);
    printf("EPF MANAGEMENT SYSTEM");
    textcolor(2);
    gotoxy(28,8);
    printf("Entered Credentials are not Correct");
    gotoxy(28,10);
    fclose(log);
    printf("Do you want to Login Again(Y/N):");
    loop=getch();
   }
   }while(loop=='Y'||loop=='y');

 }

     system("cls");
     sq();
     textcolor(3);
     gotoxy(28,10);
     printf("Thank You! Have a Nice Day");
     textcolor(128+4);
     gotoxy(30,11);
     printf("Press Any Key to Exit");
     fclose(log);
     getch();
     exit(0);

}


void sq()
{
 int count,x,y;
 char sq='*';
 count=1;
 x=6,y=3;
 while(count<=35)
 {
  textcolor(14);
  gotoxy(x,y);
  printf("%c",sq);
  x=x+2;
  count++;
 }
 x=6;
 y=4;
 count=1;
 while(count<=20)
 {
  textcolor(14);
  gotoxy(x,y);
  printf("%c",sq);
  printf("\t\t\t\t\t\t\t\t\t ");
  printf("%c",sq);
  y++;
  count++;
 }
 count=1;
 x=8,y=23;
 while(count<=34)
 {
  textcolor(14);
  gotoxy(x,y);
  printf("%c",sq);
  x=x+2;
  count++;
 }
}