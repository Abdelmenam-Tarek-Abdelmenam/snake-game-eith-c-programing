
// outher :- Abdelmenam elbahy
// writen in 2020
// snake game c programin console apllication


#define Score 100
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

char game[22][42];  // the play ground

// the global variable of the snake body positions
 int tallrow[Score],tallcol[Score],tallrow1[Score],tallcol1[Score];
 int snakcolmn,snakrow;char x;char head='O';

 /************************ main function ************************************/
int main()
{
int i,j ; // variables for for loop
int foodrow=(rand()%20+1),foodcol=(rand()%40+1);   // variable for food position
int score=0; //to track the score
int speed=500;  //determine the snake speed
int level =1; // determine level of game
srand(time(0)); // to make the food position change every time

// the first random positions of the snake and the food
snakrow=(rand()%20+1);snakcolmn=(rand()%40+1);
foodrow=(rand()%20+1);foodcol=(rand()%40+1);

// make the interface
system("cls");
intro(score,level);
start : ;
printf("to play the saved game click 'o or O' else click any key ");
x=getch();
if(x=='o' || x=='O'){read(&score,&snakrow ,&snakcolmn,&level ,&speed );}
else{printf("\nenter the speed level that you want from(0 to 8 ) ...");
scanf("%d",&level);
speed=250-level*25;
}

// INITIALIZE the play ground
for(i=0;i<22 ; i++)
{   for(j=0 ; j<42 ;j++)
    {    game[i][j] =' ';
    }}
for(j=0 ; j<42 ;j++)
    {   game[0][j] ='-';
       game[21][j] ='-';
    }
 for(j=1 ; j<21 ;j++)
    {   game[j][0] ='|';
       game[j][41] ='|';
    }
system("cls");
game[foodrow][foodcol]='&'; // make food sympol

 /************************start the game************************************/
while(1){
  intro(score,level);  //the instructions

 if(snakcolmn == foodcol && snakrow==foodrow ) { //eat the food
while(1)
{
    // make new food in new place
foodrow=rand()%20+1;
foodcol=rand()%40+1;
for(int i=0; i<score+1; i++){ game[tallrow[i]][tallcol[i]]='Ü';}
if(game[foodrow][foodcol]!='o'){break;}
}
score ++;

// he pass the game
if(score>=99){system("cls"); printf("\n\n\n\n\n\n\n\t\t\t\t\a you are so good in this game \n\n\n\n\n\n\n\n\n"); return 0;}
}

 /********************draw the play ground **********************************/
game[foodrow][foodcol]='&';
game[snakrow][snakcolmn]=head;
for(int i=0; i<score+1; i++){ game[tallrow[i]][tallcol[i]]='o';}
 /************************************************************/
for(i=0;i<22 ; i++)
{   for(j=0 ; j<42 ;j++)
    {   printf("%c",game[i][j] );
    }
    printf("\n     ");
}
 /************************************************************/
 if(game[snakrow][snakcolmn]=='o' )
    {system("cls");
         printf("you lose \n");
printf("do you want to play again (y)\n");
x=getch();
if(x=='y'){
return main();}
break;
}
delay(speed);
game[snakrow][snakcolmn]=' ';
for(int i=0; i<score+1; i++)
    { game[tallrow[i]][tallcol[i]]=' ';
}

// make the snake body walk
 for(int i=0 ;i<=score ;i++){
    tallrow1[i]=tallrow[i];
    tallcol1[i]=tallcol[i];
    }

 /******************  get user direction ************************************/
if(kbhit()) //check if any button clicked
{x=getch();
}
     if(x=='H'){   snakrow--; tallrow[0] = snakrow+1 ; tallcol[0]= snakcolmn; head='^'; }
else if (x=='P'){  snakrow++;  tallrow[0] = snakrow-1 ; tallcol[0]= snakcolmn ;head='v'; }
else if(x=='M'){   snakcolmn++;tallrow[0] = snakrow ; tallcol[0]= snakcolmn-1 ;head='>';}
else if(x=='K'){   snakcolmn--;tallrow[0] = snakrow ; tallcol[0]= snakcolmn+1 ;head='<';}
for(int i=1;i<=score ;i++){
 tallrow[i] =tallrow1[i-1];
 tallcol[i]= tallcol1[i-1] ;
}
 /************************************************************/

// other buttons
if(x==' '){
printf("pause...\n");
printf("print any key to continue,c to exit");
x=getch();
if(x=='c'){ system("cls");
 printf("do you want to save (y),else click any key");
x=getch();
if(x=='y'){open(score , snakrow ,snakcolmn ,level ,speed);}
break;
}}
else if(x==''){
        system("cls");
 printf("do you want to save (y),else click any key");
x=getch();
if(x=='y'){open(score , snakrow ,snakcolmn ,level ,speed);}
break;}
else if(x=='n' || x=='N' ){return main();}
else if(x=='S' || x=='s' ){ system("cls");      open(score , snakrow ,snakcolmn,level ,speed) ;}

// losing
if(snakcolmn == 0 || snakcolmn==41 || snakrow==0 || snakrow==21 || game[snakrow][snakcolmn]=='o' )
    {system("cls");
         printf("you lose \n");
printf("do you want to play again (y)\n");
x=getch();
if(x=='y'){
return main();}
break;
}
system("cls");
}
 /************************************************************/
printf("\nyou exit the game \n your score is %d and your level is %d \n good luck...",score,level);
return 0;
}

 /************************************************************/
void intro(int score,int level)
{  //printing options
    printf("\t\t welcome in snake game \n \n");
    printf("  -you can use the arrow to MOVE\n ");
    printf("  -if you want to PAUSE the game click  on the ' space ' button \n");
    printf("  -if you want to EXIT the game click on the ' ESC' button \n");
    printf("  -if you want a NEW GAME click on ' n or N ' \n");
    printf("eat the star to increase your score  \n ");
    printf("\t\t\t your score is %d \t your speed level is %d \n     ",score,level);
}

//save the progress
 /************************************************************/
void open( int x,int y,int z ,int l,int s){
//save the results in a file
  FILE *fpointer;
 fpointer=fopen("SAVE.txt","w");
 fprintf(fpointer,"%d\n%d\n%d\n%d\n%d",x,y,z,l,s);
 fclose(fpointer);
 printf("\n saved succesfuly");
 exit(0);
}
 /************************************************************/

void read(int *x,int *y,int *z,int *l,int *s)
{
// save the results in file
     FILE *fpointer;
     fpointer=fopen("SAVE.txt","r");
     fscanf(fpointer,"%d",&*x);
     fscanf(fpointer,"%d",&*y);
     fscanf(fpointer,"%d",&*z);
     fscanf(fpointer,"%d",&*l);
     fscanf(fpointer,"%d",&*s);
    fclose(fpointer);
}

 /************************************************************/
void delay (unsigned int period ){
//maKe a delay in melli seconds
int end=clock()+period;
while(clock()< end);
}
 /************************************************************/
