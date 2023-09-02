#include<stdio.h>
#include<graphics.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<vector>
#include<iostream>
//#include<thread>
//#include<unistd.h>
//#include<pngwriter.h>
#include<string.h>
#include "mymedia.h"
#include "variable.h"
using namespace std;

#define I_KEY 0x54  //T
#define J_KEY 0x46  //F
#define K_KEY 0x47  //G
#define L_KEY 0x48  //H
#define A_KEY 0x41
#define Z_KEY 0x5A
#define NINE_KEY 0x39

#define PI 3.1415926

#define windsizeY 700
#define windsizeX 1000

class Blocks{
	public:
		Blocks(int heroX,int heroY){
			Length = 250;
			Pos_X = rand()%(Length+hero1_size)+(heroX-Length);//be sure the block will appears above the hero
			Pos_Y = rand()%(windsizeY-heroX-150)+1;
		}
		~Blocks(){}
		int getX();
		int getY();
		int getLength();
		void Move(int speed);
		void PrintBlock(int len);
	private:
		int Pos_X;
		int Pos_Y;
		int Length;
};

class Blackhole{ // Blackhole
	public:
		Blackhole(int X, int Y){
  			centerX=X;
  			centerY=Y;
  			radius=50;
  			timeofcreation=time(NULL);
  		}
  		~Blackhole(){};
  		int getCenterX();
  		int getCenterY();
  		int getRadius();
  		int getTimeofcreation();
  		void drawBlackhole();
  			
  	private:
  		int timeofcreation;
  		int centerX;
		int centerY;
  		int radius;		
};
  	vector<Blackhole> Hole1;
    int BKhole = 0, BlackholeExistence=20, BKholeitemExistence=20;
	bool gravityfield(int X, int Y, int eventhorizon, int centerX, int centerY);

int selection[3] = {21,11,2};
//frequency 1.heart  2.blackhole  3.block
class Enemies{  
	public:
		Enemies(){
			Pos_X = rand()%(windsizeX-enemy1_size)+1;
			Pos_Y = 0;
			HP = 3;
		}
		
		~Enemies(){}
		void Printenemy(int enemysize);
		void setHP(int n);
		void Move(int pace);
		int getHP();
		int getX();
		int getY();
	private: 
	    int Pos_X;
		int Pos_Y;		
		int HP;	
};

class Boss1{  
	public:
		Boss1(){
			Pos_X = 300;
			Pos_Y = 2;
			HP = 10;
			Vx = 15;
			Vy = 0;
			heroX=-1;
	        heroY=-1;
	        blaster_timeof_creation=-1;
	        timeof_location=-1;
		}
		
		~Boss1(){}
		void Printboss1(int bosssize);
		void setHP(int n);
		int getSpeed();
		
		int getBlaster_timeof_creation(){
			return blaster_timeof_creation;
		}
	    int getTimeof_location(){
	    	return timeof_location;
	    }
	    void setBlaster_timeof_creation(){
			blaster_timeof_creation=time(NULL);
		}
	    void resetBlaster_timeof_creation(){
			blaster_timeof_creation=-1;
		}
	    void resetTimeof_location(){
	    	timeof_location=-1;
	    }
		void draw_Boss_blaster(){
		    int p[8];
			p[0]=(Pos_X+boss1_size/2);//centerX of the boss 
			p[1]=(Pos_Y+boss1_size/2);//centerY of the boss
			p[2]=p[0]+1500*((int)((heroX-p[0])*cos(PI/6))+(int)(-sin(PI/6)*(heroX-p[1])));//rotate for 30
			p[3]=p[1]+1500*((int)((heroY-p[0])*sin(PI/6))+(int)(cos(PI/6)*(heroX-p[1])));
			p[4]=p[0]+1500*((int)((heroX-p[0])*cos(-PI/6))+(int)(-sin(-PI/6)*(heroX-p[1])));
			p[5]=p[1]+1500*((int)((heroY-p[0])*sin(-PI/6))+(int)(cos(-PI/6)*(heroX-p[1])));
			p[6]=(Pos_X+boss1_size/2);//centerX of the boss
			p[7]=(Pos_Y+boss1_size/2);//centerY of the boss
			
			fillpoly(3, p);

		}
		void Locate(int X, int Y){
			heroX = X;
			heroY = Y;
			timeof_location = time(NULL);
		}
		
		bool Time2shoot(){
			if(rand()%30==0) return 1;
			return 0;
		}
		
		void Move();
		int getHP();
		int getX();
		int getY();
	private: 
	    int heroX;
	    int heroY;
	    int blaster_timeof_creation;
	    int timeof_location;

		int Pos_X;
		int Pos_Y;		
		int HP;
		int Vx;
		int Vy;
};

class Enemies1{  
	public:
		Enemies1(){
			Pos_X = (rand()%2)*1000;
			Pos_Y = rand()%250+100;
			sita = 0.;
			HP = 3;
			if(Pos_X == 0)
				direction = 1;
			else 
				direction = -1;
		}
		
		~Enemies1(){}
		void Printenemy(int enemysize);
		void setHP(int n);
		void Move(int pace);
		int getHP();
		int getX();
		int getY();
		int getDirection();
	private: 
	    int Pos_X;
		int Pos_Y;
		double sita;
		int direction;
		int HP;
};
/*
class Enemies2{  
	public:
		Enemies(){
			Pos_X = rand()%(windsizeX-enemy1_size)+1;
			Pos_Y = 0;
		}
		
		~Enemies(){}
		void Printenemy(int enemysize);
		void Move(int pace);
		int getX();
		int getY();
	private: 
	    int Pos_X;
		int Pos_Y;			
};
*/
class Bullet{
	public:
		Bullet(int a,int b){
			Pos_X = a;
			Pos_Y = b;
		}
		~Bullet(){}
		int getX();
		int getY();
		void Move(int speed);
		void Printbullet(int bullet_size);
	private:
		int Pos_X;
		int Pos_Y;
};

class Enemies_Arsenal{
	public:
	Enemies_Arsenal(int a, int b){
		Pos_X = a;
		Pos_Y = b;
		Slope = 1;
	}
	Enemies_Arsenal(int a, int b, int c, int d){
			Pos_X = a;
			Pos_Y = b;
			if(a==c)
				c++;
			else{
				Slope = (float)(d-b) / (a-c);
				sita = atan((double)(d-b) / (a-c));
			}
		}
		~Enemies_Arsenal(){};
		void Move(int speed,vector<Enemies_Arsenal> &Inventory);
		int getX();
		int getY();
		void Printmissiles(int missile1_size);
	private:
		int Pos_X, Pos_Y;
		float Slope;
		double sita;
};

class Hero{
	public:
		Hero(){
			Pos_X = windsizeX/2;
			Pos_Y = windsizeY-hero1_size;
			HP = 20;
		}
		void Printhero(int herosize);
		void Move(int *p,vector<Blocks> &, Boss1 &Boss1);
		int getX();
		int getY();
		int getHP();
		void setY(int n);
		void setX(int n);
		void setHP(int n);
		void PrintHP();
	private:
		int Pos_X, Pos_Y;
		int HP;
};

class Hearts{
	public:
	   Hearts(){
	   	Pos_X = rand()%(windsizeX-itemsize)+1;
	   	Pos_Y = rand()%(windsizeY-itemsize)+1;
	   }
	   int getX();
	   int getY();
	   void PrintItem(int itemsize);
	private:
		int Pos_X;
		int Pos_Y;
};

class BKholeitem{ //Item of the blackhole
	public:
	    BKholeitem(){
	   		Pos_X = rand()%(windsizeX-itemsize)+1;
	   		Pos_Y = rand()%(windsizeY-itemsize)+1;
	    	timeofcreation=time(NULL);
		}
	    ~BKholeitem(){};
	    int getX();
	    int getY();
	    int getTimeofcreation();
	    void PrintItem(int itemsize);
	private:
		int timeofcreation;
		int Pos_X;
		int Pos_Y;
};

bool Enemytime(); // When would enemies appear?

void Cleaning(vector<Enemies> &List, vector<Enemies1> &List1, vector<Bullet> &Mybullets, 
vector<Enemies_Arsenal> &Inventory, Hero &, vector<Hearts> &, 
vector <BKholeitem> &Holeitem1,vector<Blackhole> &Hole1);

int Blocks :: getX(){
	return Pos_X;
}

int Blocks :: getY(){
	return Pos_Y;
}

int Blocks :: getLength(){
	return Length;
}

void Blocks :: PrintBlock(int len){
	setlinestyle(SOLID_LINE,0,3);
	line(Pos_X, Pos_Y, Pos_X+len, Pos_Y);
	line(Pos_X, Pos_Y+3, Pos_X+len, Pos_Y+3);
	line(Pos_X, Pos_Y+6, Pos_X+len, Pos_Y+6);
	line(Pos_X, Pos_Y+9, Pos_X+len, Pos_Y+9);
}

void Blocks :: Move(int pace){ //go straight down
	Pos_Y += pace;
}

int Hearts :: getX(){
	return Pos_X;
}

int Hearts :: getY(){
	return Pos_Y;
}

void Hearts :: PrintItem(int itemsize){    //print hearts
	readimagefile(heart1,Pos_X,Pos_Y,Pos_X+itemsize,Pos_Y+itemsize);
}
void Enemies :: Printenemy(int enemysize){    //print the bastard enemies
	readimagefile(enemyship,Pos_X,Pos_Y,Pos_X+enemysize,Pos_Y+enemysize);
}
void Enemies :: Move(int pace){         //enemies moving downward
	if(Hole1.size() && gravityfield((2*Pos_X+enemy1_size)/2,
	(2*Pos_Y+enemy1_size)/2, eventhorizon, Hole1[0].getCenterX(),
	Hole1[0].getCenterY())){
		int theX = Hole1[0].getCenterX()-(2*Pos_X+enemy1_size)/2;
		int theY = Hole1[0].getCenterY()-(2*Pos_Y+enemy1_size)/2;
		double ang = atan2(theY, theX);
		//printf("theX = %d\ntheY = %d\nang = %lf\n",theX,theY,ang);
		Pos_X += (int)(5*cos(ang));
		Pos_Y += (int)(5*sin(ang));
	}
	else
  		Pos_Y+=pace;
}

void Enemies :: setHP(int n){         //enemies moving downward
  	HP+=n;
}

int Enemies :: getX(){      //every enemy x location
  	return Pos_X;
}
  
int Enemies :: getHP(){      //every enemy x location
  	return HP;
}
  
int Enemies :: getY(){    //enemy y location
  	return Pos_Y;
}
//Enemies1
void Enemies1 :: Printenemy(int enemysize){    //print the bastard enemies
	readimagefile(enemyship1,Pos_X,Pos_Y,Pos_X+enemysize,Pos_Y+enemysize);
}
void Enemies1 :: Move(int pace){         //enemies moving downward
	if(Hole1.size() && gravityfield((2*Pos_X+enemy1_size)/2,
	(2*Pos_Y+enemy1_size)/2, eventhorizon, Hole1[0].getCenterX(),
	Hole1[0].getCenterY())){
		int theX = Hole1[0].getCenterX()-(2*Pos_X+enemy1_size)/2;
		int theY = Hole1[0].getCenterY()-(2*Pos_Y+enemy1_size)/2;
		double ang = atan2(theY, theX);
		//printf("theX = %d\ntheY = %d\nang = %lf\n",theX,theY,ang);
		Pos_X += (int)(5*cos(ang));
		Pos_Y += (int)(5*sin(ang));
	}
	else {
		Pos_X += pace;
  		Pos_Y += (int)(pace*sin(1./5*sita*180/PI));
  		sita += 0.01;
	}
}

int Enemies1 :: getDirection(){      //every enemy x location
  	return direction;
}

int Enemies1 :: getHP(){      //every enemy x location
  	return HP;
}

int Enemies1 :: getX(){      //every enemy x location
  	return Pos_X;
}
  
void Enemies1 :: setHP(int n){      //every enemy x location
  	HP+=n;
}  

int Enemies1 :: getY(){    //enemy y location
  	return Pos_Y;
}

//boss1
void Boss1 :: Printboss1(int bosssize){    //print the Boss
	readimagefile(boss1,Pos_X,Pos_Y,Pos_X+bosssize,Pos_Y+bosssize);
	
}
void Boss1 :: Move(){         //Boss moving downward
	
	if(Pos_X+boss1_size>=windsizeX){
		Pos_X-=2;
		Vx = 0; 
		Vy = 15;
		} 
	if(Pos_Y+boss1_size>=windsizeY){
	   Pos_Y-=2; 
	   Vx = -15; 
	   Vy = 0;
	}
	if(Pos_X<=0){
	   Pos_X+=2;
	   Vx = 0; 
	   Vy = -15;
	}
	if(Pos_Y<=0){
	   Pos_Y+=2;
	   Vx = 15; 
	   Vy = 0;
	}
	
	Pos_X += Vx;
	Pos_Y += Vy;
}

int Boss1 :: getSpeed(){
	if(Vx>0)
		return 4;//往右走 
	if(Vx<0)
		return 2;//往左走
	if(Vy>0)
		return 1;//往下走
	if(Vy<0)
		return 3;//往上走
}
 
int Boss1 :: getHP(){      //Boss x location
  	return HP;
}

int Boss1 :: getX(){      //Boss x location
  	return Pos_X;
}
  
void Boss1 :: setHP(int n){      //Boss enemy x location
  	HP+=n;
}  

int Boss1 :: getY(){    //boss y location
  	return Pos_Y;
}

/*///Enemies2
void Enemies2 :: Printenemy(int enemysize){    //print the bastard enemies
	readimagefile(enemyship,Pos_X,Pos_Y,Pos_X+enemysize,Pos_Y+enemysize);
}
void Enemies2 :: Move(int pace){         //enemies moving downward
  	Pos_Y+=pace;
}

int Enemies2 :: getX(){      //every enemy x location
  	return Pos_X;
}
  
int Enemies2 :: getY(){    //enemy y location
  	return Pos_Y;
}*/  
  
//Bullets
void Bullet :: Printbullet(int bulletsize){    //print the hero's bullets
	readimagefile(bullet,Pos_X,Pos_Y,Pos_X+bulletsize,Pos_Y+bulletsize);
}
  
int Bullet :: getX(){      //every enemy x location
  	return Pos_X;
}
  
int Bullet :: getY(){    //enemy y location
  	return Pos_Y;
}
  
void Bullet :: Move(int speed){      //every enemy x location
  	Pos_Y-=(speed*2);
}

/*void Enemies_Arsenal :: Move(int speed){
	Pos_Y+=speed;
}
int Enemies_Arsenal :: getX(){
	return Pos_X;
}
int Enemies_Arsenal :: getY(){
	return Pos_Y;
}
void Enemies_Arsenal :: Printmissiles(int missile1_size){
	readimagefile(missile,Pos_X,Pos_Y,Pos_X+missile1_size,Pos_Y+missile1_size);
}
*/
//Time to create enemies
bool Enemytime(){      
  	timetocreate=rand()%3000+1;
	if(timetocreate%enemiesf==0) 
		return 1; 
	return 0;
}
//Time to create enemies1
bool Enemytime1(){      
  	timetocreate1=rand()%3000+1;
	if(timetocreate1%enemies1f==0) 
		return 1; 
	return 0;
}  
//產生items 
bool Itemtime(){      
	int showitem=rand()%3000+1;
	if(showitem%40==0) 
		return 1; 
	return 0;
}
//印分數 
void PrintScore(){
		char score[25];
		itoa(Score,score,10);
    	outtextxy(900,1, score);
    }
//調難度  boss出現 
void difficult(){
	if(count == 120){
		difficulty = 3;
		enemiesf = 21;
		enemiesv = 6;
		enemies1f = 31;
		enemies1v = 6;
		missilesv = 11;
		missilesf = 3;
	}
	else if(count == 40){
		difficulty = 2;
		enemiesf = 31;
		enemiesv = 6;
		enemies1f = 41;
		enemies1v = 4;
		missilesv = 8;
		missilesf = 9;
		boss = true;
	}
}



//pushedbyboss
void pushedbyboss(class Boss1 &Boss1, Hero &Myhero){
	if(boss == true){
		if( Myhero.getY()>=Boss1.getY()+boss1_size && Myhero.getY()<=Boss1.getY()+26+boss1_size  && Myhero.getX()<( Boss1.getX()+boss1_size-5 ) && ( Myhero.getX()+hero1_size )>( Boss1.getX()+5 )){
			Myhero.setY(Boss1.getY()+boss1_size+16);
			pushed = 1;//pushed down 
			printf("puta\n");
		}
		else if( Myhero.getY()+hero1_size<=Boss1.getY() && Myhero.getY()+hero1_size>=Boss1.getY()-26  && Myhero.getX()<( Boss1.getX()+boss1_size-5 ) && ( Myhero.getX()+hero1_size )>( Boss1.getX()+5 )){
			Myhero.setY(Boss1.getY()-66);
			pushed = 3;//pushed up
			cout<<"up"<<endl; 
		}	
		else if( Myhero.getX()+hero1_size<=Boss1.getX() && Myhero.getX()+hero1_size>=Boss1.getX()-26  && Myhero.getY()<=( Boss1.getY()+boss1_size-5 ) && ( Myhero.getY()+hero1_size )>=( Boss1.getY()+5 )){
			Myhero.setX(Boss1.getX()-66);
			pushed = 2;//pushed left
			cout<<"left"<<endl; 
		}
		else if( Myhero.getX()>=Boss1.getX()+boss1_size && Myhero.getX()<=Boss1.getX()+boss1_size+26  && Myhero.getY()<=( Boss1.getY()+boss1_size-5 ) && ( Myhero.getY()+hero1_size )>=( Boss1.getY()+5 )){
			Myhero.setX(Boss1.getX()+boss1_size+16);
			pushed = 4;//pushed right
			cout<<"right"<<endl;
		}
		
		else
			pushed = 0;
	}
}

void Cleaning(vector<Enemies>& List, vector<Enemies1>& List1, vector<Bullet>& Mybullets,  
			vector<Enemies_Arsenal>&Inventory, Hero &Myhero, vector<Hearts> &heart, 
			vector <BKholeitem> &Holeitem1,vector<Blackhole> &Hole1, vector<Blocks> &Block, Boss1 &Boss1){    //Delete enemies that are off the screen
//打到Boss1 
	for(int j=0;j<Mybullets.size();j++)
		if(boss == true && Mybullets[j].getY() + missile1_size <= Boss1.getY() + boss1_size && Mybullets[j].getX() + missile1_size <= Boss1.getX()+boss1_size && Mybullets[j].getX() >= Boss1.getX() && Mybullets[j].getY() >= Boss1.getY()){
			Boss1.setHP(-1);
			Mybullets.erase(Mybullets.begin()+j);
		}
			
//敵人超界 
	for(int i=0; i<List.size(); i++)           //Erase non existing enemies
  		if(List[i].getY()>windsizeY){
  			Score -= 40;
  			List.erase(List.begin()+i);
  		}
  			
//Block超界 
  	for(int i=0; i<Block.size(); i++)     
  		if(Block[i].getY()>windsizeY+20)
  			Block.erase(Block.begin()+i);
//敵人1超界		  	 
	for(int i=0; i<List1.size(); i++)           //Erase non existing enemies1
  		if(List1[i].getX()>windsizeX || List1[i].getX() + enemy1_size<0){
  			Score -= 65;
  			List1.erase(List1.begin()+i);
  		} 
//子彈超界		  	 
	for(int i=0; i<Mybullets.size(); i++) 	//Erase non existing bullets
		 if(Mybullets.size()!=0 && Mybullets[i].getY()<0) 
		 	Mybullets.erase(Mybullets.begin()+i);
//敵人子彈打到我們 
	for(int i=0; i<Inventory.size(); i++) {	//Erase non existing bullets
		if(Inventory[i].getY()>=Myhero.getY() && Inventory[i].getX()>=Myhero.getX() && Inventory[i].getX()<=Myhero.getX()+hero1_size && Inventory[i].getY()<=Myhero.getY()+10+hero1_size){
			Inventory.erase(Inventory.begin()+i);
			Myhero.setHP(-1);
		} 
		 	
//敵人子彈超界 
		else if((Inventory.size()!=0 && Inventory[i].getY()>=windsizeY || Inventory[i].getY()<=0 || Inventory[i].getX()>=windsizeX || Inventory[i].getX()<=0) ||(Inventory[i].getY()>=Myhero.getY() && Inventory[i].getX()>=Myhero.getX() && Inventory[i].getX()+missile1_size<=Myhero.getX()+hero1_size && Inventory[i].getY()+missile1_size<=Myhero.getY()+hero1_size)) 
		 	Inventory.erase(Inventory.begin()+i);
		if(Hole1.size() && gravityfield((2*Inventory[i].getX()+missile1_size)/2, (2*Inventory[i].getY()+missile1_size)/2, 10, Hole1[0].getCenterX(), Hole1[0].getCenterY()))
			Inventory.erase(Inventory.begin()+i);
	}
//我們的子彈打到敵人 
	for(int i=0; i<List.size(); i++){
		if(Hole1.size() && gravityfield((2*List[i].getX()+enemy1_size)/2, (2*List[i].getY()+enemy1_size)/2, 10, Hole1[0].getCenterX(), Hole1[0].getCenterY()))
		{
			List[i].setHP(-1);
			if(List[i].getHP()<=0){
				Score += 100;
				outtextxy(List[i].getX(),List[i].getY()-30, "+100!!");
				readimagefile(boom,List[i].getX(),List[i].getY(),List[i].getX()+enemy1_size,List[i].getY()+enemy1_size);
				List.erase(List.begin()+i);
			}
		}
		
		for(int j=0; j<Mybullets.size(); j++){
			if(Mybullets[j].getY() + missile1_size <= List[i].getY() + enemy1_size && Mybullets[j].getX() + missile1_size <= List[i].getX()+enemy1_size && Mybullets[j].getX() >= List[i].getX() && Mybullets[j].getY() >= List[i].getY()){
				List[i].setHP(-1);
				Mybullets.erase(Mybullets.begin()+j);
				if(List[i].getHP()<=0)
				{       
					Score += 100;
					outtextxy(List[i].getX(),List[i].getY()-30, "+100!!");
					readimagefile(boom,List[i].getX(),List[i].getY(),List[i].getX()+enemy1_size,List[i].getY()+enemy1_size);
					List.erase(List.begin()+i);
					delay(20);
				}
			}
				
		}
	}
		
//我們的子彈打到敵人1
	for(int i=0; i<List1.size(); i++){
		if(Hole1.size() && gravityfield((2*List1[i].getX()+enemy1_size)/2, (2*List1[i].getY()+enemy1_size)/2, 10, Hole1[0].getCenterX(), Hole1[0].getCenterY()))
		{
			List1[i].setHP(-1);
			if(List1[i].getHP()<=0){
				Score += 100;
				outtextxy(List1[i].getX(),List1[i].getY()-30, "+100!!");
				readimagefile(boom,List1[i].getX(),List1[i].getY(),List1[i].getX()+enemy1_size,List1[i].getY()+enemy1_size);
				List1.erase(List1.begin()+i);
			}
		}
		
		for(int j=0; j<Mybullets.size(); j++){
			if(Mybullets[j].getY() + missile1_size <= List1[i].getY() + enemy1_size && Mybullets[j].getX() + missile1_size <= List1[i].getX()+enemy1_size && Mybullets[j].getX() >= List1[i].getX() && Mybullets[j].getY() >= List1[i].getY()){
				List1[i].setHP(-1);
				Mybullets.erase(Mybullets.begin()+j);
				if(List1[i].getHP()<=0)
				{       
					Score += 100;
					outtextxy(List1[i].getX(),List1[i].getY()-30, "+100!!");
					readimagefile(boom,List1[i].getX(),List1[i].getY(),List1[i].getX()+enemy1_size,List1[i].getY()+enemy1_size);
					List1.erase(List1.begin()+i);
					delay(20);
				}
			}
				
		}
	}

	for(int i=0; i<heart.size(); i++) {	//Erase non existing hearts
         if(heart[i].getY() + itemsize <= Myhero.getY()+hero1_size && heart[i].getX() + itemsize <= Myhero.getX()+hero1_size && heart[i].getX() >= Myhero.getX() && heart[i].getY() >= Myhero.getY()){
			Myhero.setHP(2);
			heart.erase(heart.begin()+i);
		 }
	}
	
	for(int i=0; i<Hole1.size(); i++) {	//Erase non existing hearts
         if(BlackholeExistence-(time(NULL)-Hole1[i].getTimeofcreation())<1)
		 Hole1.erase(Hole1.begin()+i);
	}
	
	for(int i=0; i<Holeitem1.size(); i++) {	//Erase non existing hearts
         if((Holeitem1[i].getY() + itemsize <= Myhero.getY()+hero1_size && 
		 Holeitem1[i].getX() + itemsize <= Myhero.getX()+hero1_size &&
		 Holeitem1[i].getX() >= Myhero.getX() && Holeitem1[i].getY() >= Myhero.getY()) ){
			BKhole = 1;
			Holeitem1.erase(Holeitem1.begin()+i);
		 }
		 else if(BKholeitemExistence-(time(NULL)-Holeitem1[i].getTimeofcreation())<1)
		 Holeitem1.erase(Holeitem1.begin()+i);
	}
}
