#include<stdio.h>
#include<conio.h>
#include<string.h>

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

 clrscr();
 sq();

 textcolor(BROWN);
 gotoxy(32,4);
 cprintf("EPF MANAGEMENT SYSTEM");
 gotoxy(8,5);
 cprintf("Developed By-Himanshu Nagar");
 gotoxy(45,5);
 cprintf("  Guided By-Mrs. Rashi Saxena");

 log=fopen("log","r");
 sizel=sizeof(l);

 if(fread(&l,sizel,1,log)==NULL)
 {
   textcolor(RED);
   gotoxy(25,8);
   cprintf("Press Enter Key for Registration");
   getch();
   log=fopen("log","w");
   textcolor(CYAN);
   gotoxy(10,10);
   cprintf("Enter Company/Institute Name:");
   gets(l.c_name);
   gotoxy(10,11);
   cprintf("Enter User Id:");
   gets(l.id);
   gotoxy(10,12);
   cprintf("Enter Password:");
   gets(l.pass);
   fwrite(&l,sizel,1,log);
   textcolor(GREEN);
   gotoxy(20,15);
   cprintf("Registration Successful");
   gotoxy(20,16);
   cprintf("Press Enter to Login");
   getch();
   fclose(log);
   goto again;
 }

 else
 {
   do
   {
   log=fopen("log","r");
   clrscr();
   sq();
   textcolor(BROWN);
   gotoxy(32,4);
   cprintf("EPF MANAGEMENT SYSTEM");
   gotoxy(8,5);
   cprintf("Developed By-Himanshu Nagar");
   gotoxy(45,5);
   cprintf("  Guided By-Mrs. Rashi Saxena");
   textcolor(GREEN);
   gotoxy(30,8);
   cprintf("Enter User Id:");
   gets(id);
   gotoxy(30,9);
   cprintf("Enter Password:");
   gets(pass);

   if(strcmp(id,l.id)==0&&strcmp(pass,l.pass)==0)
   {
    while(1)
    {
     clrscr();
     sq();
     textcolor(BROWN);
     gotoxy(28,4);
     cprintf("WELCOME TO EPF MANAGEMENT SYSTEM");
     textcolor(WHITE);
     gotoxy(28,6);
     puts(l.c_name);
     textcolor(GREEN);
     gotoxy(38,8);
     cprintf("MAIN MENU");
     textcolor(CYAN);
     gotoxy(33,10);
     cprintf("1. Add New Employee");
     gotoxy(33,11);
     cprintf("2. Search an Employee");
     gotoxy(33,12);
     cprintf("3. List of Employees");
     gotoxy(33,13);
     cprintf("4. Calculate EPF");
     gotoxy(33,14);
     cprintf("5. Modify an Employee");
     gotoxy(33,15);
     cprintf("6. Delete an Employee");
     gotoxy(33,16);
     cprintf("7. Delete All Employees");
     gotoxy(33,17);
     cprintf("8. Exit");
     textcolor(GREEN);
     gotoxy(33,18);
     cprintf("Choose an Option:");
     opt=getch();

     switch(opt)
     {
     case '1':
     empf=fopen("emp","a+");
     sizee=sizeof(e);
     do
     {
     clrscr();
     sq();
     textcolor(BROWN);
     gotoxy(32,4);
     cprintf("EPF MANAGEMENT SYSTEM");
     textcolor(GREEN);
     gotoxy(34,6);
     cprintf("Add New Employee");
     textcolor(CYAN);
     gotoxy(30,8);
     cprintf("Enter Employee's Id:");
     scanf("%s",&emp_id);
     gotoxy(30,9);
     cprintf("Enter Employee's First Name:");
     scanf("%s",&fname);
     gotoxy(30,10);
     cprintf("Enter Employee's Last Name:");
     scanf("%s",&lname);
     gotoxy(30,11);
     cprintf("Enter Employee's Basic Salary:");
     scanf("%lf",&b_s);
     extra=0;
     rewind(empf);
     while(fread(&e,sizee,1,empf)!=NULL)
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
     textcolor(GREEN);
     gotoxy(33,13);
     cprintf("Employee Added Successfully");
     }
     if(extra==1)
     {
     textcolor(RED);
     gotoxy(25,13);
     cprintf("Sorry! Employee Id is Already Available");
     gotoxy(28,14);
     cprintf("Please Enter an Unique Employee Id");
     }
     gotoxy(26,16);
     textcolor(MAGENTA);
     cprintf("Do you want to Add Another Employee(Y/N):");
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
     clrscr();
     sq();
     textcolor(BROWN);
     gotoxy(32,4);
     cprintf("EPF MANAGEMENT SYSTEM");
     textcolor(GREEN);
     gotoxy(34,6);
     cprintf("Search an Employee");
     gotoxy(25,8);
     cprintf("Enter Employee's Id to Search:");
     scanf("%s",&search);
     extra=1;
     while(fread(&e,sizee,1,empf)!=NULL)
     {
      if(strcmp(search,e.emp_id)==0)
      {
       textcolor(CYAN);
       gotoxy(25,10);
       cprintf("Employee's Id:%s",e.emp_id);
       gotoxy(25,11);
       cprintf("Employee's Name:%s %s",e.fname,e.lname);
       gotoxy(25,12);
       cprintf("Employee's Basic Salary:%.2lf",e.b_s);
       extra=0;
       break;
      }
     }
     if(extra!=0)
     {
      textcolor(RED);
      gotoxy(22,10);
      cprintf("Employee is not available in Database");
     }
     textcolor(MAGENTA);
     gotoxy(20,14);
     cprintf("Do you want to Search Another Employee(Y/N):");
     scanf(" %c",&loop);
     }while(loop=='Y'||loop=='y');
     fclose(empf);
     break;
     case '3':
     empf=fopen("emp","r");
     sizee=sizeof(e);
     clrscr();
     sq();
     textcolor(BROWN);
     gotoxy(32,4);
     cprintf("EPF MANAGEMENT SYSTEM");
     textcolor(GREEN);
     gotoxy(34,6);
     cprintf("List of Employees");
     y=8;
     gotoxy(18,y);
     cprintf("|");
     gotoxy(19,y);
     cprintf("S.No.");
     gotoxy(24,y);
     cprintf("|");
     gotoxy(25,y);
     cprintf("ID");
     gotoxy(29,y);
     cprintf("|");
     gotoxy(30,y);
     cprintf("Employee's Name");
     gotoxy(50,y);
     cprintf("|");
     gotoxy(51,y);
     cprintf("Basic Salary");
     gotoxy(63,y);
     cprintf("|");
     y=9;
     s_no=1;
     extra=1;
     while(fread(&e,sizee,1,empf)!=NULL)
     {
      if(extra==12)
      {
       textcolor(GREEN);
       gotoxy(25,21);
       cprintf("Press Enter To See More Employees");
       getch();
       clrscr();
       sq();
       y=5;
       extra=1;
      }
      textcolor(CYAN);
      gotoxy(18,y);
      cprintf("|");
      gotoxy(19,y);
      cprintf("%d",s_no);
      gotoxy(24,y);
      cprintf("|");
      gotoxy(25,y);
      cprintf("%s",e.emp_id);
      gotoxy(29,y);
      cprintf("|");
      gotoxy(30,y);
      cprintf("%s %s",e.fname,e.lname);
      gotoxy(50,y);
      cprintf("|");
      gotoxy(51,y);
      cprintf("%.2lf",e.b_s);
      gotoxy(63,y);
      cprintf("|");
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
     clrscr();
     sq();
     textcolor(BROWN);
     gotoxy(32,4);
     cprintf("EPF MANAGEMENT SYSTEM");
     textcolor(WHITE);
     gotoxy(25,6);
     cprintf("Enter Total Working Days in this Month:");
     scanf("%lf",&t_wd);
     y=8;
     extra=1;
     while(fread(&e,sizee,1,empf)!=NULL)
     {
      if(extra==13)
      {
       gotoxy(25,21);
       cprintf("Press Enter to Proceed Further");
       getch();
       clrscr();
       sq();
       extra=1;
       y=6;
      }
      textcolor(CYAN);
      gotoxy(25,y);
      cprintf("Enter Working Days of %s %s:",e.fname,e.lname);
      scanf("%lf",&wd[n]);
      n++;
      y++;
      extra++;
     }
     rewind(empf);
     clrscr();
     textcolor(BROWN);
     gotoxy(34,1);
     cprintf("EPF SALARY SHEET");
     textcolor(YELLOW);
     gotoxy(25,2);
     cprintf("%s",l.c_name);
     y=3;
     textcolor(RED);
     gotoxy(1,y);
     cprintf("S.No.");
     gotoxy(6,y);
     cprintf("|");
     gotoxy(7,y);
     cprintf("Employee's Name");
     gotoxy(27,y);
     cprintf("|");
     gotoxy(28,y);
     cprintf("Bas.Sal.");
     gotoxy(36,y);
     cprintf("|");
     gotoxy(37,y);
     cprintf("WD");
     gotoxy(39,y);
     cprintf("|");
     gotoxy(40,y);
     cprintf("Employee's Con.");
     gotoxy(55,y);
     cprintf("|");
     gotoxy(56,y);
     cprintf("Employer's Con.");
     gotoxy(71,y);
     cprintf("|");
     gotoxy(72,y);
     cprintf("Pa. Sal.");
     s_no=1;
     n=0;
     y=4;
     extra=1;
     while(fread(&e,sizee,1,empf)!=NULL)
     {
      if(extra==16)
      {
       textcolor(GREEN);
       gotoxy(25,20);
       cprintf("Press Enter to Proceed Further");
       getch();
       clrscr();
       extra=1;
       y=2;
      }
      textcolor(CYAN);
      gotoxy(1,y);
      cprintf("%d",s_no);
      gotoxy(6,y);
      cprintf("|");
      gotoxy(7,y);
      cprintf("%s %s",e.fname,e.lname);
      gotoxy(27,y);
      cprintf("|");
      gotoxy(28,y);
      cprintf("%.0lf",e.b_s);
      gotoxy(36,y);
      cprintf("|");
      sal=((e.b_s/t_wd)*wd[n]);
      e_c=sal*0.12;
      em_c=sal*0.12;
      p_s=sal-e_c;
      gotoxy(37,y);
      cprintf("%.0lf",wd[n]);
      gotoxy(39,y);
      cprintf("|");
      gotoxy(40,y);
      cprintf("%.2lf",e_c);
      gotoxy(55,y);
      cprintf("|");
      gotoxy(56,y);
      cprintf("%.2lf",em_c);
      gotoxy(71,y);
      cprintf("|");
      gotoxy(72,y);
      cprintf("%.2lf",p_s);
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
     clrscr();
     sq();
     textcolor(BROWN);
     gotoxy(32,4);
     cprintf("EPF MANAGEMENT SYSTEM");
     textcolor(GREEN);
     gotoxy(34,6);
     cprintf("Modify an Employee");
     gotoxy(25,8);
     cprintf("Enter Employee's Id to Modify Details:");
     scanf("%s",&search);
     extra=0;
     while(fread(&e,sizee,1,empf)!=NULL)
     {
      if(strcmp(search,e.emp_id)==0)
      {
       textcolor(CYAN);
       gotoxy(25,10);
       cprintf("Enter New Employee's First Name:");
       scanf("%s",&e.fname);
       gotoxy(25,11);
       cprintf("Enter New Employee's Last Name:");
       scanf("%s",&e.lname);
       gotoxy(25,12);
       cprintf("Enter New Employee's Basic Salary:");
       scanf("%lf",&e.b_s);
       fwrite(&e,sizee,1,temp);
       textcolor(GREEN);
       gotoxy(25,14);
       cprintf("Employee's Modification Successfull");
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
      textcolor(RED);
      gotoxy(20,14);
      cprintf("Sorry! This Employee is not Available in Database");
     }
     textcolor(MAGENTA);
     gotoxy(23,16);
     cprintf("Do you want to Modify Another Employee(Y/N):");
     scanf(" %c",&loop);
     }while(loop=='Y'||loop=='y');
     break;
     case '6':
     do
     {
     clrscr();
     sq();
     empf=fopen("emp","a+");
     temp=fopen("temp","w");
     sizee=sizeof(e);
     textcolor(BROWN);
     gotoxy(32,4);
     cprintf("EPF MANAGEMENT SYSTEM");
     textcolor(GREEN);
     gotoxy(34,6);
     cprintf("Delete an Employee");
     textcolor(CYAN);
     gotoxy(25,8);
     cprintf("Enter Employee's Id to Delete:");
     scanf("%s",&search);
     gotoxy(25,9);
     cprintf("Are you sure you want to Delete(Y/N):");
     scanf("%s",&sure);
     extra=0;
     if(sure=='Y'||sure=='y')
     {
      while(fread(&e,sizee,1,empf)!=NULL)
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
      textcolor(GREEN);
      gotoxy(30,11);
      cprintf("Employee Deleted Successfully");
      }
      if(extra==0)
      {
       textcolor(RED);
       gotoxy(20,11);
       cprintf("Sorry! This Employee is not Available in Database");
      }
      textcolor(MAGENTA);
      gotoxy(22,13);
      cprintf("Do you want to Delete Another Employee(Y/N):");
      scanf("%s",&loop);
     }
     else
     {
      textcolor(MAGENTA);
      gotoxy(25,11);
      cprintf("Do you want to Delete Another Employee:(Y/N):");
      scanf("%s",&loop);
     }
     fclose(empf);
     fclose(temp);
     }while(loop=='Y'||loop=='y');
     break;
     case '7':
     clrscr();
     sq();
     textcolor(BROWN);
     gotoxy(32,4);
     cprintf("EPF MANAGEMENT SYSTEM");
     textcolor(GREEN);
     gotoxy(32,6);
     cprintf("Delete All Employees");
     textcolor(CYAN);
     gotoxy(38,8);
     cprintf("Warning");
     textcolor(RED);
     gotoxy(15,9);
     cprintf("Are you sure you want to Delete All Employees(Y/N):");
     scanf(" %c",&sure);
     if(sure=='Y'||sure=='y')
     {
      remove("emp");
      textcolor(GREEN);
      gotoxy(25,11);
      cprintf("All Employees Deleted Successfully");
     }
     textcolor(MAGENTA);
     gotoxy(28,13);
     cprintf("Press Enter to go to Main Menu");
     getch();
     break;
     case '8':
     clrscr();
     sq();
     textcolor(CYAN);
     gotoxy(28,10);
     cprintf("Thank You! Have a Nice Day");
     textcolor(RED+BLINK);
     gotoxy(30,11);
     cprintf("Press Any Key to Exit");
     fclose(log);
     getch();
     exit(0);
     break;

     default :
     clrscr();
     sq();
     textcolor(BLUE);
     gotoxy(30,10);
     cprintf("Please Enter a Valid Option");
     gotoxy(28,11);
     cprintf("Press Enter to go to Main Menu");
     getch();

     }
    }
   }

   else
   {
    clrscr();
    sq();
    textcolor(BROWN);
    gotoxy(32,4);
    cprintf("EPF MANAGEMENT SYSTEM");
    textcolor(GREEN);
    gotoxy(28,8);
    cprintf("Entered Credentials are not Correct");
    gotoxy(28,10);
    fclose(log);
    cprintf("Do you want to Login Again(Y/N):");
    loop=getch();
   }
   }while(loop=='Y'||loop=='y');

 }

     clrscr();
     sq();
     textcolor(CYAN);
     gotoxy(28,10);
     cprintf("Thank You! Have a Nice Day");
     textcolor(RED+BLINK);
     gotoxy(30,11);
     cprintf("Press Any Key to Exit");
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
  textcolor(YELLOW);
  gotoxy(x,y);
  cprintf("%c",sq);
  x=x+2;
  count++;
 }
 x=6;
 y=4;
 count=1;
 while(count<=20)
 {
  textcolor(YELLOW);
  gotoxy(x,y);
  cprintf("%c",sq);
  printf("\t\t\t\t\t\t\t\t\t ");
  cprintf("%c",sq);
  y++;
  count++;
 }
 count=1;
 x=8,y=23;
 while(count<=34)
 {
  textcolor(YELLOW);
  gotoxy(x,y);
  cprintf("%c",sq);
  x=x+2;
  count++;
 }
}