#include<stdio.h>
#include<malloc.h>
#include<ctype.h>
#include<string.h>
//HELLO TO YOU! TO CHECK FOR THE PASSENGERS LIST ON FILE, FIND THE ONE NAMED "LIST.txt"
//THANK YOU!
typedef struct{
 char name[30], addr[30];
 int age;
 }pass;
void table(); void reserve();
void change(); void list();
char tempCol, tab[11][7] = {0}; //table of seats
int i, row, col;
int main(){
 int res, ch, seatrow, tempseatcol;
 char seatcol;
 FILE *file;
 file = fopen("seatno.txt", "r");
 while ((fscanf(file, "%d %c", &seatrow, &seatcol)) != EOF)
 {
 for(int i=1; i<=6; i++)
 if(seatcol == i+64)
 {
 tempseatcol = i;
 tab[seatrow][tempseatcol] = 'X';
 }
 }
 fclose(file);
 printf("\n\n\t\t\t\t ***AVAILABLE SEATS***\n"); table(tab);
 do{ //MAIN MENU
 for(int i=0; i<5; i++)
 {
 if(i == 0) printf("\n\n\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
 else if(i == 2) printf("\n\t\t\t@@ \t~~LC AIRLINES~~ \t@@");
 if(i == 4) printf("\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
 else printf("\n\t\t\t@@ \t\t\t\t@@");
 }
 printf("\n\n\t***MAIN MENU***");
 printf("\n\n\t\t[1] Reserve a seat"); printf("\n\t\t[2] Change a seat");
 printf("\n\t\t[3] Display list of passengers"); printf("\n\t\t[4] Exit");
 printf("\n\n\t\tEnter your choice: "); scanf("%d",&ch);
 switch(ch)
 {
 case 1:
 printf("\n\n\t\tHow many seats do you want to reserve? "); scanf("%d", &res);
 for(int i=0; i<res; i++)
 reserve();
 table(tab); break;
 case 2:change();
 break;
 case 3:list();
 break;
 case 4:

printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
 printf("\n\n\tThank you for using our system!\n");
 break;
 }
printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
 }while (ch!=4);
 return 0;
}
void table(char tab[11][7])
{
 printf("\n\t\t     A   B   C\t   D   E   F");
 printf("\n\t\t------------------------------");
 for(int i=1; i<11; i++)
 {printf("\n\t\t|%-2d| %c | %c | %c | | %c | %c | %c |", i, tab[i][1], tab[i][2], tab[i][3],
tab[i][4], tab[i][5], tab[i][6]);
 printf("\n\t\t-------------------------------");}
}
void reserve()
{

printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
 printf("\n\n\tCHOOSE AN AVAILABLE SEAT: \n"); table(tab);
 pass s; char x; s.age=0;
 FILE *fp1, *fp2, *fp3;
 fp1 = fopen("LIST.txt", "a"); fp2 = fopen("seatno.txt", "a"); fp3 = fopen("no.txt", "a+");
 printf("\n\t\tEnter desired seat: "); scanf("%d %c", &row, &tempCol);
 for(int i=1; i<=6; i++)
 {
 if(toupper(tempCol) == i+64)
 {
 col = i;
 if(tab[row][col] == 'X')
 {
 printf("\n\t\tSorry, seat %d%c is already taken. Select another seat?(Y/N): ", row,
toupper(tempCol));
 scanf(" %c", &x);
 if(toupper(x) == 'Y')
 {
 printf("\n\n");
 reserve(); return;
 }
 else if(toupper(x) == 'N')
 return;
 }
 else
 {
 for(int i=1; i<=6; i++)
 {
 if(toupper(tempCol) == i+64)
 {
 int res;
 col = i;
 printf("\t\tDo you want to reserve seat %d%c? (Y/N) ", row, toupper(tempCol));
 scanf(" %c", &res);
 if(toupper(res) == 'Y')
 tab[row][col] = 'X';
 else
 return;
 }
 }
 fflush(stdin); printf("\n\t\tEnter name: "); scanf("%[^\n]s", s.name);
 printf("\t\tEnter age: "); scanf("%d", &s.age);
 fflush(stdin); printf("\t\tEnter city: "); scanf("%[^\n]s", s.addr);
 int j, n;
 while (fscanf(fp3, " %d", &j) == 1) { }
 n = j%100; n++;
 fprintf(fp1, "%d\t%s\t%d\t%s\t\t%d%c\n", n, s.name, s.age, s.addr, row,
toupper(tempCol));
 fprintf(fp2, "%d %c\n", row, toupper(tempCol));
 fprintf(fp3, "%d\n", n);
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
 printf("\n\n\t\tSeat %d%c is successfully reserved!\n", row, toupper(tempCol));
 }
 }
 } fclose(fp1); fclose(fp2); fclose(fp3);
}
void change()
{
 static char tempcol; static char oldcol, f, letra;
 char nam[30], name[30], b[30], city[30], d[30];
 static int i=0, age, c, q, a, numero; static int nameFound=0;
 static int oldrow, e; static int newrow; static int finaloldcol; static int newcol; static int flag;
 FILE *fp, *fp4, *fx, *fx1;
 fp4=fopen("temPass.txt","w");
 fx=fopen("seatno.txt","r"); fx1=fopen("tempseatno.txt","w");
printf("\n\t\tEnter your recorded name: "); scanf(" %[^\n]", nam);
 fp = fopen("LIST.txt", "r");
 while(fscanf(fp,"%d\t%[^\t]\t%d\t%[^\t]\t\t%d%c", &a, b, &c, d, &e, &f) != EOF)
 {
 if(strcmp(nam,b)==0)
 nameFound=3;
 }
 if(nameFound==0)
 {
 printf("\n\n\t\tRECORD NOT FOUND!\n\n");
 change(); return;
 }
 fclose(fp);
fp = fopen("LIST.txt", "r");
printf("\n\n\t\tHere are the available seats: \n\n");
table(tab);
do{
 printf("\n\t\tEnter your new seat: "); scanf("%d %c", &newrow, &tempcol);
 for(int i=1; i<=6; i++) // checks if the seat is already taken
 if(toupper(tempcol) == i+64)
 {
 newcol = i;
 if(tab[newrow][newcol] == 'X')
 {
 printf("\n\t\tSorry, seat %d%c is already taken. Select an unoccupied seat. ", newrow,
toupper(tempcol));
 flag = 2;
 }
 else
 flag = 3;
 }
} while(flag == 2);
 if(fp==NULL)
printf("Error cannot open file\n");
while(fscanf(fp,"%d\t%[^\t]\t%d\t%[^\t]\t\t%d%c", &q, name, &age, city, &oldrow, &oldcol) &&
fscanf(fx,"%d %c",&numero, &letra) != EOF)
{//printing modified content into temp file
 if(strcmp(nam,name)==0)
 {
 for(int i=1; i<=6; i++)
 if(toupper(oldcol) == i+64)
 {
 finaloldcol = i;
 tab[oldrow][finaloldcol] = ' ';
 }
 oldrow = newrow; oldcol = toupper(tempcol);
 tab[newrow][newcol] = 'X';
 numero=newrow; letra=toupper(tempcol);
 }
 if(fp4==NULL)
 printf("Error cannot open file\n");
 fprintf(fp4,"%d\t%s\t%d\t%s\t\t%d%c\n", q, name, age, city, oldrow, oldcol);
 fprintf(fx1,"%d %c\n", numero, letra);
}
 fclose(fp); fclose(fp4); fclose(fx); fclose(fx1);
 remove("seatno.txt"); remove("LIST.txt");
 FILE *E = fopen("tempseatno.txt", "r"); FILE *S = fopen("seatno.txt", "w");
 while(fscanf(E,"%d %c",&numero, &letra) != EOF)
 {
 fprintf(S,"%d %c\n", numero, letra);
 }
 fclose(E); fclose(S); remove("tempseatno.txt");
 FILE *T = fopen("temPass.txt", "r"); FILE *L = fopen("LIST.txt", "w");
 while(fscanf(T,"%d\t%[^\t]\t%d\t%[^\t]\t\t%d%c", &q, name, &age, city, &oldrow, &oldcol) != EOF)
 {
 fprintf(L,"%d\t%s\t%d\t%s\t\t%d%c\n", q, name, age, city, oldrow, oldcol);
 }
 fclose(T); fclose(L); remove("tempPass.txt");

printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
 printf("\n\n\t\t\tYour seat is successfully changed!\n"); table(tab);
}
void list()
{

printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
 printf("\n\n\tNO.\t%s\t\tAGE\t%s\t\t\tSEAT NUMBER\n\n", "NAME", "ADDRESS");
 char list[100];
 FILE *f1 = fopen("LIST.txt", "r");
 while (fgets(list, 100, f1)) printf("\t%s", list);
 }
