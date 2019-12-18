#include<iostream>
#include<cstdio>
#include <fstream>
#include<dos.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<dos.h>
#include<windows.h>
#include<math.h>

#define BLACK           0
#define BLUE			1
#define GREEN			2
#define CYAN			3
#define RED				4
#define MAGENTA			5
#define BROWN			6
#define LIGHTGRAY		7
#define DARKGRAY		8 
#define LIGHTBLUE		9
#define LIGHTGREEN		10
#define LIGHTCYAN		11
#define LIGHTRED		12
#define LIGHTMAGENTA	13
#define YELLOW			14
#define WHITE			15
#define DONT_BLINK		0
#define BLINK			1
using namespace std;
void gotoxy( int  c, int  r)
{
  HANDLE hConsoleOutput; 
  COORD dwCursorPosition;
  dwCursorPosition.X = c; 
  dwCursorPosition.Y = r; 
  hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE); 
  SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);  
  SetConsoleTextAttribute(hConsoleOutput,WHITE);

}

void gotorc(char ch[], int c, int r, int color)
{
  HANDLE hConsoleOutput; 
  COORD dwCursorPosition;
  cout.flush();
  dwCursorPosition.X = c; 
  dwCursorPosition.Y = r; 
  hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE); 
  SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);  
  SetConsoleTextAttribute(hConsoleOutput,color);
  cout<<ch;
  SetConsoleTextAttribute(hConsoleOutput,WHITE);
  
}


 

int main()
 {system("cls");
int speed=100;
int store;

 int n,h,direction,chance,score=0,plate,c,i,r,d;
 char ch=' ';
 
 int s;
 int st;
  int level=1;
  

 c=rand()%79+1;



 r=22;
 int ji=rand()%4+1;
//file creating
ofstream fout("highscore.txt",ios::app);
fout.close();
    
		
 // hori
   for(c=1;c<=39;c++)
 {
 gotorc("-" ,c , 1,BROWN);
  
  gotorc( "-",c,39,BROWN);
    }

 //verti
 for(r=1;r<=79;r++)
 {gotorc("|",1,r,BROWN);
  
  gotorc("|",79,r,BROWN);
  }

// declaring ball direction in plate
  c=62;r=37;
  
  d=55;
  //plate dimentions
  plate=57;
  chance=4;

  gotorc("            ",60,1,YELLOW);
  


 // display zero score
    gotorc("                 ",59,1,YELLOW);
    
    gotorc("score",60,1,YELLOW);
    
    gotorc("00000",68,1,CYAN);
    //display message
    char gi=getch();
    gotorc("Press Q for Quit/Press H for High Score",15,1,YELLOW);
  if(gi=='H')
{system("cls");
cout<<"126";}

 //CHANC
    gotorc("       ",6,1,0);
    gotorc( "chance " ,2,1, 10);
    
 // at start display
    gotorc("O",c,r,10);
    
    gotorc("++=======++",plate,38,1);

    
  if(GetAsyncKeyState(VK_LEFT))
//for negative x axis
    direction=2;

  if(GetAsyncKeyState(VK_RIGHT))
    //positive x axis
	direction=1;



 //COLUMN OF SCORE
    h=74;
 c=rand()%79+1;
direction=rand()%8+1;
while((ch!='q')&&(ch!='Q'))
 {while((c<=78)&&(c>=2)&&(r<=37)&&(r>=2))




 //make ball
  {gotorc("O",c,r,10);
   

 // SCORE
   gotoxy(h,1);
   
  cout<<score;
   

 //make plate
   gotorc("++=======++",plate,38,YELLOW);
   
   Sleep(speed);

 

 //rase ball
   gotorc("O",c,r ,0);
   //rase plate

 
   gotorc("++=======++",plate,38, BLACK);
   

 if(kbhit())
   ch=getch();

 //directionECTIO TO plate with keysddda
 if(GetAsyncKeyState(VK_LEFT)){
 
  if(plate>2)  plate-=2;}
else{

 if(GetAsyncKeyState(VK_RIGHT))
  if(plate<70) plate+=2;
}
 if(ch=='a')
    plate=c-4;

 //scoring
 if(score==10)
    h=h--;

 if(score==100)
    h=h--;

 if(score==1000)
    h=h--;

 if(score==10000)
    h=h--;

 // declare directionectio with coordinate

 if(direction==1 )
// forth quardant
 
   {c++;r--;}
//third quardant


 if(direction==2 )
   {c--;r--;}



if(direction==3 )
   {c--;r++;}

//1st East etc
 
 if(direction==4 )
   {c++;r++;}

//on positive x-axis y=0

if(direction==5  )
{c++;0;}
//on negative  x -axis x=0

if(direction==6 )
{c--;0 ;}

//on positive y-axis x=0

if(direction==7  )
{0;r++;}


// negative y-axis x=0

if(direction==8)
{0;r--;};



}


 // change in directionection of ball
 if(c==1)
    {
	c=2; 
 if(direction=2)
  {direction=1;}
 if(direction==3)
    direction=4;
}
   

 if(c==79)
  {if(direction==1)
     direction=2;
   if(direction==4)
     direction=3;
     c=78;
    }

 if(r==1)
  {r=2;
   if(direction==2)
     direction=3;
   if(direction==1)
     direction=4;
    }
   

 
direction=rand()%4+1;

 //codition if ball hit plate
 if((r==38)&&(c>=plate)&&(c<=plate+9))
  {r=37;
   if(direction==3)
     direction=2;
   if(direction==4)
     direction=1;
     score+=2;
     
fout<<score<<',';  
fout.close();
      }
    
  
gotoxy(2,39);
cout<<"level";
gotoxy(8,39);
cout<< level;
	
	
	 
  


      
      
if(score==20){
level=2;	
speed-=6;
}
else
if(score==40)
{
level=3;
	speed-=6;
}
else
if(score==60)
{level=4;
	
	speed-=1;
}else
if(score==70)
{
level=5;
	speed-=1;
}


 //condition for not hiting  plate
 if((r==38)&&((c<plate)||(c>plate+9)))

 //reduction chance

  { //chance condition
   if(chance==0)

  {gotorc("        Game over             ",33,15,YELLOW);
     
     gotoxy(28,18);
     cout<<"       Your score       "<<score;
     ch=getch();
     exit(0);
     }

    chance--;

     gotoxy(8,1);
      cout<<chance;



 
    gotorc("      H for High Score  Q for quit R for play again       ",16,15,12);



    ch=getch();
 
 if((ch=='q')||(ch=='Q'))
 // raising statement
    {gotoxy(16,15);
    cout<<"                              ";
    gotoxy(33,11);
    cout<<"                              ";

     gotorc("Game  over",33,11,YELLOW);
     
     gotoxy(28,18);
     cout<<"Your score ::"<<score;
     ch=getch();
     exit(0);
     }

 //choice for restart
 if((ch=='r')||(ch=='R'))
 //restore game
    {gotoxy(16,15);
     cout<<"                                  ";
     gotoxy(33,11);
     cout<<"                        ";


 //revalue
     c=61;r=37;
     plate=54;

 //again display
     gotorc("0",c,r,10);
    
     gotorc("++=======++",plate,38,YELLOW);
     
     ch=getch();
     if(GetAsyncKeyState(VK_LEFT))
     direction=2;

     if(GetAsyncKeyState(VK_RIGHT))
     direction=1;

 // end of gotorc loop
    }
if(ch=='H'){
system("cls");	
	gotoxy(30,30);
	cout<<"high Score::"<<"56";
}



 //end of if loop
    }
 //end of while loop
    }
}



