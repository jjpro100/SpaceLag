#include "my-fns.h"

//P2 CONTROLS
#define UP_KEY 0x26
#define LEFT_KEY 0x25
#define DOWN_KEY 0x28
#define RIGHT_KEY 0x27
#define ZERO_KEY 0x30


//int selectionvs[2] = {21,2};
//frequency 1.heart  2.block
class EnemiesP1{
	public:
		EnemiesP1(){
			Pos_X = rand()%(windsizeX-enemy1_size)+1;
			Pos_Y = 0;
			HP = 3;
		}

		~EnemiesP1(){}
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

class Enemies1P1{
	public:
		Enemies1P1(){
			Pos_X = (rand()%2)*1000;
			Pos_Y = rand()%250+100;
			sita = 0.;
			HP = 3;
			if(Pos_X == 0)
				direction = 1;
			else
				direction = -1;
		}

		~Enemies1P1(){}
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

class BulletP1{
	public:
		BulletP1(int a,int b){
			Pos_X = a;
			Pos_Y = b;
		}
		~BulletP1(){}
		int getX();
		int getY();
		void Move(int speed);
		void Printbullet(int bullet_size);
	private:
		int Pos_X;
		int Pos_Y;
};

class Enemies_ArsenalP1{
	public:
	Enemies_ArsenalP1(int a, int b){
		Pos_X = a;
		Pos_Y = b;
		Slope = 1;
	}
	Enemies_ArsenalP1(int a, int b, int c, int d){
			Pos_X = a;
			Pos_Y = b;
			if(a==c)
				c++;
			else{
				Slope = (float)(d-b) / (a-c);
				sita = atan((double)(d-b) / (a-c));
			}
		}
		~Enemies_ArsenalP1(){};
		void Move(int speed,vector<Enemies_ArsenalP1> &Inventory);
		int getX();
		int getY();
		void Printmissiles(int missile1_size);
	private:
		int Pos_X, Pos_Y;
		float Slope;
		double sita;
};

class HeroP1{
	public:
		HeroP1(){
			Pos_X = windsizeX/2;
			Pos_Y = windsizeY-hero1_size;
			HP = 50;
		}
		void Printhero(int herosize);
		void Move(int *p);
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




//P2
class EnemiesP2{
	public:
		EnemiesP2(){
			Pos_X = rand()%(windsizeX-enemy1_size)+1;
			Pos_Y = 700-enemy1_size-1;
			HP = 3;
		}

		~EnemiesP2(){}
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

class Enemies1P2{
	public:
		Enemies1P2(){
			Pos_X = (rand()%2)*1000;
			Pos_Y = rand()%250+100;
			sita = 0.;
			HP = 3;
			if(Pos_X == 0)
				direction = 1;
			else
				direction = -1;
		}

		~Enemies1P2(){}
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

class BulletP2{
	public:
		BulletP2(int a,int b){
			Pos_X = a;
			Pos_Y = b;
		}
		~BulletP2(){}
		int getX();
		int getY();
		void Move(int speed);
		void Printbullet(int bullet_size);
	private:
		int Pos_X;
		int Pos_Y;
};

class Enemies_ArsenalP2{
	public:
	Enemies_ArsenalP2(int a, int b){
		Pos_X = a;
		Pos_Y = b;
		Slope = 1;
	}
	Enemies_ArsenalP2(int a, int b, int c, int d){
			Pos_X = a;
			Pos_Y = b;
			if(a==c)
				c++;
			else{
				Slope = (float)(d-b) / (a-c);
				sita = atan((double)(d-b) / (a-c));
			}
		}
		~Enemies_ArsenalP2(){};
		void Move(int speed,vector<Enemies_ArsenalP2> &InventoryP2);
		int getX();
		int getY();
		void Printmissiles(int missile1_size);
	private:
		int Pos_X, Pos_Y;
		float Slope;
		double sita;
};

class HeroP2{
	public:
		HeroP2(){
			Pos_X = windsizeX/2;
			Pos_Y = 0;
			HP = 50;
		}
		void Printhero(int herosize);
		void Move(int *p);
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

class Blockitem{ //Item of the blackhole
	public:
	    Blockitem(){
	   		Pos_X = rand()%(windsizeX-itemsize)+1;
	   		Pos_Y = rand()%(windsizeY-itemsize)+1;
	    	timeofcreation=time(NULL);
		}
	    ~Blockitem(){};
	    int getX();
	    int getY();
	    int getTimeofcreation();
	    void PrintItem(int itemsize);
	private:
		int timeofcreation;
		int Pos_X;
		int Pos_Y;
};
vector <Blockitem> Blockitems;

class BlockP1{
	public:
		BlockP1(int heroX,int heroY){
			Length = 250;
			Pos_X = heroX;
			Pos_Y = heroY;
		}
		~BlockP1(){}
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
vector <BlockP1> Blockp1;

class BlockP2{
	public:
		BlockP2(int heroX,int heroY){
			Length = 250;
			Pos_X = heroX;
			Pos_Y = heroY;
		}
		~BlockP2(){}
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
vector <BlockP2> Blockp2;

int BlockP2 :: getX(){
	return Pos_X;
}

int BlockP2 :: getY(){
	return Pos_Y;
}

int BlockP2 :: getLength(){
	return Length;
}

void BlockP2 :: PrintBlock(int len){
	setlinestyle(SOLID_LINE,0,3);
	line(Pos_X, Pos_Y, Pos_X+len, Pos_Y);
	line(Pos_X, Pos_Y+3, Pos_X+len, Pos_Y+3);
	line(Pos_X, Pos_Y+6, Pos_X+len, Pos_Y+6);
	line(Pos_X, Pos_Y+9, Pos_X+len, Pos_Y+9);
}

void BlockP2 :: Move(int pace){ //go straight down
	Pos_Y += pace;
}

int BlockP1 :: getX(){
	return Pos_X;
}

int BlockP1 :: getY(){
	return Pos_Y;
}

int BlockP1 :: getLength(){
	return Length;
}

void BlockP1 :: PrintBlock(int len){
	setlinestyle(SOLID_LINE,0,3);
	line(Pos_X, Pos_Y, Pos_X+len, Pos_Y);
	line(Pos_X, Pos_Y+3, Pos_X+len, Pos_Y+3);
	line(Pos_X, Pos_Y+6, Pos_X+len, Pos_Y+6);
	line(Pos_X, Pos_Y+9, Pos_X+len, Pos_Y+9);
}

void BlockP1 :: Move(int pace){ //go straight down
	Pos_Y += pace;
}

int Blockitem :: getX(){
	return Pos_X;
}

int Blockitem  :: getY(){
	return Pos_Y;
}

void Blockitem :: PrintItem(int itemsize){    //print blackhole items
	readimagefile(block,Pos_X,Pos_Y,Pos_X+itemsize,Pos_Y+itemsize);
}

int Blockitem  :: getTimeofcreation(){   //Time when u put the blackhole on the field
	return timeofcreation;
}
//P1

/*class Hearts{
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
};*/

bool Enemytime(); // When would enemies appear?

void CleaningP1(vector<EnemiesP1> &List, vector<Enemies1P1> &List1, vector<BulletP1> &Mybullets,
vector<Enemies_ArsenalP1> &Inventory, HeroP1 &, vector<Enemies_ArsenalP2>&InventoryP2, HeroP2 &MyheroP2, vector<Hearts> &heart);

/*int Hearts :: getX(){
	return Pos_X;
}

int Hearts :: getY(){
	return Pos_Y;
}

void Hearts :: PrintItem(int itemsize){    //print hearts
	readimagefile(heart1,Pos_X,Pos_Y,Pos_X+itemsize,Pos_Y+itemsize);
}*/

void EnemiesP1 :: Printenemy(int enemysize){    //print the bastard enemies
	readimagefile(enemyship,Pos_X,Pos_Y,Pos_X+enemysize,Pos_Y+enemysize);
}

void EnemiesP1 :: Move(int pace){         //enemies moving downward
  		Pos_Y+=pace;
}

void EnemiesP1 :: setHP(int n){         //enemies moving downward
  	HP+=n;
}

int EnemiesP1 :: getX(){      //every enemy x location
  	return Pos_X;
}

int EnemiesP1 :: getHP(){      //every enemy x location
  	return HP;
}

int EnemiesP1 :: getY(){    //enemy y location
  	return Pos_Y;
}
//Enemies1
void Enemies1P1 :: Printenemy(int enemysize){    //print the bastard enemies
	readimagefile(enemyship1,Pos_X,Pos_Y,Pos_X+enemysize,Pos_Y+enemysize);
}
void Enemies1P1 :: Move(int pace){         //enemies moving downward
		Pos_X += pace;
  		Pos_Y += (int)(pace*sin(1./5*sita*180/PI));
  		sita += 0.01;

}

int Enemies1P1 :: getDirection(){      //every enemy x location
  	return direction;
}

int Enemies1P1 :: getHP(){      //every enemy x location
  	return HP;
}

int Enemies1P1 :: getX(){      //every enemy x location
  	return Pos_X;
}

void Enemies1P1 :: setHP(int n){      //every enemy x location
  	HP+=n;
}

int Enemies1P1 :: getY(){    //enemy y location
  	return Pos_Y;
}

//Bullets
void BulletP1 :: Printbullet(int bulletsize){    //print the hero's bullets
	readimagefile(bullet,Pos_X,Pos_Y,Pos_X+bulletsize,Pos_Y+bulletsize);
}

int BulletP1 :: getX(){      //every enemy x location
  	return Pos_X;
}

int BulletP1 :: getY(){    //enemy y location
  	return Pos_Y;
}

void BulletP1 :: Move(int speed){      //every enemy x location
  	Pos_Y-=(speed*2);
}

//items
/*bool Itemtime(){
	int showitem=rand()%3000+1;
	if(showitem%40==0)
		return 1;
	return 0;
}*/


void Enemies_ArsenalP1 :: Printmissiles(int missile_size){    //print the weapons
	readimagefile(missile,Pos_X,Pos_Y,Pos_X+missile1_size,Pos_Y+missile1_size);
}

int Enemies_ArsenalP1 :: getX(){      //every enemy missile x location
	return Pos_X;
}

int Enemies_ArsenalP1 :: getY(){    //every enemy missile y location
	return Pos_Y;
}

void Enemies_ArsenalP1 :: Move(int speed,vector<Enemies_ArsenalP1> &Inventory){         //enemy missiles moving downward

		if(Slope>0){
			Pos_X-=(int)(speed*cos(sita*180/PI));
  			Pos_Y+=(int)fabs(speed*sin(sita*180/PI));
		}
  		else if(Slope<0){
			Pos_X+=(int)(speed*cos(sita*180/PI));
  			Pos_Y+=(int)fabs(speed*sin(sita*180/PI));
		}
  		else if(Slope==0){
			Pos_X-=speed;
		}

}


void PrintScoreP1(){
		char score[25];
		itoa(ScoreP1,score,10);
    	outtextxy(1,20, score);
    }

void CleaningP1(vector<EnemiesP1>& List, vector<Enemies1P1>& List1, vector<BulletP1>& Mybullets,
			vector<Enemies_ArsenalP1>&Inventory, HeroP1 &Myhero, vector<Enemies_ArsenalP2>&InventoryP2, HeroP2 &MyheroP2, vector<Hearts> &heart, vector<Blockitem> &Blockitems, vector<BlockP1> &Blockp1, vector<BlockP2> &Blockp2){    //Delete enemies that are off the screen


	for(int i=0; i<List.size(); i++)           //Erase non existing enemies
  		if(List[i].getY()>windsizeY){
  			ScoreP1 -= 40;
  			List.erase(List.begin()+i);
  		}

	for(int i=0; i<List1.size(); i++)           //Erase non existing enemies1
  		if(List1[i].getX()>windsizeX || List1[i].getX() + enemy1_size<0){
  			//ScoreP1 -= 65;
  			List1.erase(List1.begin()+i);
  		}

	for(int i=0; i<Mybullets.size(); i++) 	//Erase non existing bullets
		 if(Mybullets.size()!=0 && Mybullets[i].getY()<0)
		 	Mybullets.erase(Mybullets.begin()+i);
		 else if(Mybullets[i].getY()>=MyheroP2.getY() && Mybullets[i].getX()>=MyheroP2.getX() && Mybullets[i].getX()<=MyheroP2.getX()+hero1_size &&
		Mybullets[i].getY()<=MyheroP2.getY()+10+hero1_size){
			MyheroP2.setHP(-1);
			Mybullets.erase(Mybullets.begin()+i);
		}
		

	for(int i=0; i<Inventory.size(); i++) {	//Erase non existing bullets
		if(Inventory[i].getY()>=Myhero.getY() && Inventory[i].getX()>=Myhero.getX() && Inventory[i].getX()<=Myhero.getX()+hero1_size &&
		Inventory[i].getY()<=Myhero.getY()+10+hero1_size){
			Inventory.erase(Inventory.begin()+i);
			Myhero.setHP(-1);
		}


		else if(Inventory.size()!=0 && Inventory[i].getY()>=windsizeY || Inventory[i].getY()<=0 || Inventory[i].getX()>=windsizeX || Inventory[i].getX()<=0 )
		 	Inventory.erase(Inventory.begin()+i);
	}

	for(int i=0; i<List.size(); i++){


		for(int j=0; j<Mybullets.size(); j++){
			if(Mybullets[j].getY() + missile1_size <= List[i].getY() + enemy1_size && Mybullets[j].getX() + missile1_size <= List[i].getX()+enemy1_size && Mybullets[j].getX() >= List[i].getX() && Mybullets[j].getY() >= List[i].getY()){
				List[i].setHP(-1);
				Mybullets.erase(Mybullets.begin()+j);
				if(List[i].getHP()<=0)
				{
					ScoreP1 += 100;
					outtextxy(List[i].getX(),List[i].getY()-30, "+100!!");
					readimagefile(boom,List[i].getX(),List[i].getY(),List[i].getX()+enemy1_size,List[i].getY()+enemy1_size);
					List.erase(List.begin()+i);
					delay(20);
				}
			}

		}
		
		/*for(int k=0; k<InventoryP2.size(); k++){
			if(InventoryP2[k].getY() + missile1_size <= List[i].getY() + enemy1_size && InventoryP2[k].getX() + missile1_size <= List[i].getX()+enemy1_size && InventoryP2[k].getX() >= List[i].getX() && InventoryP2[k].getY() >= List[i].getY()){
				List[i].setHP(-1);
				InventoryP2.erase(InventoryP2.begin()+k);
				if(List[i].getHP()<=0)
				{
					ScoreP1 += 100;
					outtextxy(List[i].getX(),List[i].getY()-30, "+100!!");
					readimagefile(boom,List[i].getX(),List[i].getY(),List[i].getX()+enemy1_size,List[i].getY()+enemy1_size);
					List.erase(List.begin()+i);
					delay(20);
				}
			}

		}*/
		
	}

	for(int i=0; i<Blockp1.size(); i++)     
  		if(Blockp1[i].getY()<-20)
  			Blockp1.erase(Blockp1.begin()+i);
	
	for(int i=0; i<Blockp2.size(); i++)     
  		if(Blockp2[i].getY()>windsizeY+20)
  			Blockp2.erase(Blockp2.begin()+i);
	
	for(int i=0; i<List1.size(); i++){

		for(int j=0; j<Mybullets.size(); j++){
			if(Mybullets[j].getY() + missile1_size <= List1[i].getY() + enemy1_size && Mybullets[j].getX() + missile1_size <= List1[i].getX()+enemy1_size && Mybullets[j].getX() >= List1[i].getX() && Mybullets[j].getY() >= List1[i].getY()){
				List1[i].setHP(-1);
				Mybullets.erase(Mybullets.begin()+j);
				if(List1[i].getHP()<=0)
				{
					ScoreP1 += 100;
					outtextxy(List1[i].getX(),List1[i].getY()-30, "+100!!");
					readimagefile(boom,List1[i].getX(),List1[i].getY(),List1[i].getX()+enemy1_size,List1[i].getY()+enemy1_size);
					List1.erase(List1.begin()+i);
					delay(20);
				}
			}

		}
	}

	for(int i=0; i<heart.size(); i++) {	//Erase non existing hearts
         if(heart[i].getY() + itemsize <= Myhero.getY()+hero1_size && heart[i].getX() + itemsize <= Myhero.getX()+hero1_size && 
		 heart[i].getX() >= Myhero.getX() && heart[i].getY() >= Myhero.getY()){
			Myhero.setHP(2);
			heart.erase(heart.begin()+i);
		 }
		 else if(heart[i].getY() + itemsize <= MyheroP2.getY()+hero1_size && heart[i].getX() + itemsize <= MyheroP2.getX()+hero1_size && 
		 heart[i].getX() >= MyheroP2.getX() && heart[i].getY() >= MyheroP2.getY()){
			MyheroP2.setHP(2);
			heart.erase(heart.begin()+i);
		 }
	}
	

	for(int i=0; i<Blockitems.size(); i++) {
         if(Blockitems[i].getY() + itemsize <= Myhero.getY()+hero1_size && Blockitems[i].getX() + itemsize <= Myhero.getX()+hero1_size && 
		 Blockitems[i].getX() >= Myhero.getX() && Blockitems[i].getY() >= Myhero.getY()){
			BlockattackP1++;
			Blockitems.erase(Blockitems.begin()+i);
		 }
		 else if(Blockitems[i].getY() + itemsize <= MyheroP2.getY()+hero1_size && Blockitems[i].getX() + itemsize <= MyheroP2.getX()+hero1_size && 
		 Blockitems[i].getX() >= MyheroP2.getX() && Blockitems[i].getY() >= MyheroP2.getY()){
			BlockattackP2++;
			Blockitems.erase(Blockitems.begin()+i);
		 }
	}

}


void HeroP1 :: setHP(int n){    //print the bastard enemies
	HP+=n;
}

void HeroP1 :: setY(int n){    //print the bastard enemies
	Pos_Y = n;
}

void HeroP1 :: setX(int n){    //print the bastard enemies
	Pos_X = n;
}

int HeroP1 :: getHP(){
	return HP;
}
void HeroP1 :: PrintHP(){
        /*for(int i=0; i<=HP; i++){
			//readimagefile(heart,0+i*30,0,30+i*30,30);
			}*/
	char str[5];
	itoa(HP,str,10);
    outtextxy(1,1, str);
}
void HeroP1 :: Printhero(int herosize){    //print the bastard enemies
	readimagefile(hero1,Pos_X,Pos_Y,Pos_X+herosize,Pos_Y+herosize);
}

void HeroP1 :: Move(int *p){         //enemies moving downward
  	int k=0;
    for(int i=0;i<4;i++)
    if(p[i]!=0)
	k++;
//Controls directions
    if(k==1){
    	if(p[0]==1 && Pos_Y>0)      // up
			Pos_Y-=10;
    	else if(p[1]==1 && Pos_Y<windsizeY-hero1_size && BlockedP1!=true) // down
			Pos_Y+=10;
    	if(p[2]==1 && Pos_X>0) // left
			Pos_X-=10;
    	else if(p[3]==1 && Pos_X<windsizeX-hero1_size)            // right
	    	Pos_X+=10;
   	}

    else if(k==2){
    	if(p[0]==1 && p[3]==1 && Pos_Y>0 && Pos_X<windsizeX-hero1_size ){//up & right
      		if(BlockedP1==true)
			  	Pos_X+=10;
			else{
				Pos_Y-=10;
	    		Pos_X+=10;
			}	
		}
      	else if(p[0]==1 && p[2]==1 && Pos_Y>0 && Pos_X>0){ //up & left
      		if(BlockedP1==true)
			  	Pos_X-=10;
			else{
				Pos_Y-=10;
	    		Pos_X-=10;
			}
		}
    	else if(p[1]==1 && p[2]==1 && Pos_Y<windsizeY+30-hero1_size && Pos_X>-30){ //down & left
				Pos_Y+=10;
	    		Pos_X-=10;
		}
      	else if(p[1]==1 && p[3]==1 && Pos_Y<windsizeY+30-hero1_size && Pos_X<windsizeX-hero1_size+30){ //down & right
				Pos_Y+=10;
	    		Pos_X+=10;
   		}
   	}
}

int HeroP1 :: getX(){      //every enemy x location
	return Pos_X;
}

int HeroP1 :: getY(){    //enemy y location
	return Pos_Y;
}

void ControlsP1(HeroP1 &A){

	int c[4] = {0};

	if(GetAsyncKeyState(I_KEY)==0) c[0]=0;
    if(GetAsyncKeyState(K_KEY)==0) c[1]=0;
    if(GetAsyncKeyState(J_KEY)==0) c[2]=0;
    if(GetAsyncKeyState(L_KEY)==0) c[3]=0;

    if(GetAsyncKeyState(I_KEY)!=0) c[0]=1;
    if(GetAsyncKeyState(K_KEY)!=0) c[1]=1;
    if(GetAsyncKeyState(J_KEY)!=0) c[2]=1;
    if(GetAsyncKeyState(L_KEY)!=0) c[3]=1;

    A.Move(c);

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//P2

bool Enemytime(); // When would enemies appear?

void CleaningP2(vector<EnemiesP2> &List, vector<Enemies1P2> &List1, vector<BulletP2> &Mybullets,
vector<Enemies_ArsenalP2> &Inventory, HeroP2 &, vector<Enemies_ArsenalP1>&InventoryP1, HeroP1 &MyheroP1);

/*int Hearts :: getX(){
	return Pos_X;
}

int Hearts :: getY(){
	return Pos_Y;
}

void Hearts :: PrintItem(int itemsize){    //print hearts
	readimagefile(heart1,Pos_X,Pos_Y,Pos_X+itemsize,Pos_Y+itemsize);
}*/

void EnemiesP2 :: Printenemy(int enemysize){    //print the bastard enemies
	readimagefile(enemyshipP2,Pos_X,Pos_Y,Pos_X+enemysize,Pos_Y+enemysize);
}

void EnemiesP2 :: Move(int pace){         //enemies moving downward
  		Pos_Y-=pace;
}

void EnemiesP2 :: setHP(int n){         //enemies moving downward
  	HP+=n;
}

int EnemiesP2 :: getX(){      //every enemy x location
  	return Pos_X;
}

int EnemiesP2 :: getHP(){      //every enemy x location
  	return HP;
}

int EnemiesP2 :: getY(){    //enemy y location
  	return Pos_Y;
}
//Enemies1
void Enemies1P2 :: Printenemy(int enemysize){    //print the bastard enemies
	readimagefile(enemyshipP2,Pos_X,Pos_Y,Pos_X+enemysize,Pos_Y+enemysize);
}
void Enemies1P2 :: Move(int pace){         //enemies moving downward
		Pos_X += pace;
  		Pos_Y += (int)(pace*sin(1./5*sita*180/PI));
  		sita += 0.01;

}

int Enemies1P2 :: getDirection(){      //every enemy x location
  	return direction;
}

int Enemies1P2 :: getHP(){      //every enemy x location
  	return HP;
}

int Enemies1P2 :: getX(){      //every enemy x location
  	return Pos_X;
}

void Enemies1P2 :: setHP(int n){      //every enemy x location
  	HP+=n;
}

int Enemies1P2 :: getY(){    //enemy y location
  	return Pos_Y;
}

//Bullets
void BulletP2 :: Printbullet(int bulletsize){    //print the hero's bullets
	readimagefile(missile,Pos_X,Pos_Y,Pos_X+bulletsize,Pos_Y+bulletsize);
}

int BulletP2 :: getX(){      //every enemy x location
  	return Pos_X;
}

int BulletP2 :: getY(){    //enemy y location
  	return Pos_Y;
}

void BulletP2 :: Move(int speed){      //every enemy x location
  	Pos_Y+=(speed*2);
}

//items
/*bool Itemtime(){
	int showitem=rand()%3000+1;
	if(showitem%40==0)
		return 1;
	return 0;
}*/

void Enemies_ArsenalP2 :: Printmissiles(int missile_size){    //print the weapons
	readimagefile(bullet,Pos_X,Pos_Y,Pos_X+missile1_size,Pos_Y+missile1_size);
}

int Enemies_ArsenalP2 :: getX(){      //every enemy missile x location
	return Pos_X;
}

int Enemies_ArsenalP2 :: getY(){    //every enemy missile y location
	return Pos_Y;
}

void Enemies_ArsenalP2 :: Move(int speed,vector<Enemies_ArsenalP2> &Inventory){         //enemy missiles moving downward

		if(Slope>0){
			Pos_X-=(int)(speed*cos(sita*180/PI));
  			Pos_Y-=(int)fabs(speed*sin(sita*180/PI));
		}
  		else if(Slope<0){
			Pos_X+=(int)(speed*cos(sita*180/PI));
  			Pos_Y-=(int)fabs(speed*sin(sita*180/PI));
		}
  		else if(Slope==0){
			Pos_X-=speed;
		}

}


void PrintScoreP2(){
		char score[25];
		itoa(ScoreP2,score,10);
    	outtextxy(900,20, score);
    }


void CleaningP2(vector<EnemiesP2>& ListP2, vector<Enemies1P2>& List1P2, vector<BulletP2>& MybulletsP2,
			vector<Enemies_ArsenalP2>&InventoryP2, HeroP2 &MyheroP2, vector<Enemies_ArsenalP1>&InventoryP1, HeroP1 &MyheroP1){    //Delete enemies that are off the screen


	for(int i=0; i<ListP2.size(); i++)           //Erase non existing enemies
  		if(ListP2[i].getY()<0){
  			ScoreP2 -= 40;
  			ListP2.erase(ListP2.begin()+i);
  		}

	for(int i=0; i<List1P2.size(); i++)           //Erase non existing enemies1
  		if(List1P2[i].getX()>windsizeX || List1P2[i].getX() + enemy1_size<0){
  			//ScoreP2 -= 65;
  			List1P2.erase(List1P2.begin()+i);
  		}

	for(int i=0; i<MybulletsP2.size(); i++) 	//Erase non existing bullets
		 if(MybulletsP2.size()!=0 && MybulletsP2[i].getY()>windsizeY)
		 	MybulletsP2.erase(MybulletsP2.begin()+i);
		 else if(MybulletsP2[i].getY()>=MyheroP1.getY() && MybulletsP2[i].getX()>=MyheroP1.getX() && MybulletsP2[i].getX()<=MyheroP1.getX()+hero1_size &&
		MybulletsP2[i].getY()<=MyheroP1.getY()+10+hero1_size){
			MyheroP1.setHP(-1);
			MybulletsP2.erase(MybulletsP2.begin()+i);
		 }

	for(int i=0; i<InventoryP2.size(); i++) {	//Erase non existing bullets
		if(InventoryP2[i].getY()>=MyheroP2.getY() && InventoryP2[i].getX()>=MyheroP2.getX() && InventoryP2[i].getX()<=MyheroP2.getX()+hero1_size && InventoryP2[i].getY()<=MyheroP2.getY()+10+hero1_size){
			InventoryP2.erase(InventoryP2.begin()+i);
			MyheroP2.setHP(-1);
		}


		else if(InventoryP2.size()!=0 && InventoryP2[i].getY()>=windsizeY ||
		InventoryP2[i].getY()<=0 || InventoryP2[i].getX()>=windsizeX || InventoryP2[i].getX()<=0)
		 	InventoryP2.erase(InventoryP2.begin()+i);

	}

	for(int i=0; i<ListP2.size(); i++){


		for(int j=0; j<MybulletsP2.size(); j++){
			if(MybulletsP2[j].getY() + missile1_size <= ListP2[i].getY() + enemy1_size &&
			MybulletsP2[j].getX() + missile1_size <= ListP2[i].getX()+enemy1_size && MybulletsP2[j].getX() >= ListP2[i].getX() &&
			MybulletsP2[j].getY() >= ListP2[i].getY()){
				ListP2[i].setHP(-1);
				MybulletsP2.erase(MybulletsP2.begin()+j);
				if(ListP2[i].getHP()<=0)
				{
					ScoreP2 += 100;
					outtextxy(ListP2[i].getX(),ListP2[i].getY()-30, "+100!!");
					readimagefile(boom,ListP2[i].getX(),ListP2[i].getY(),ListP2[i].getX()+enemy1_size,ListP2[i].getY()+enemy1_size);
					ListP2.erase(ListP2.begin()+i);
					delay(20);
				}
			}

		}
		
		
		
		/*for(int k=0; k<InventoryP1.size(); k++){
			if(InventoryP1[k].getY() + missile1_size <= ListP2[i].getY() + enemy1_size &&
			InventoryP1[k].getX() + missile1_size <= ListP2[i].getX()+enemy1_size && InventoryP1[k].getX() >= ListP2[i].getX() &&
			InventoryP1[k].getY() >= ListP2[i].getY()){
				ListP2[i].setHP(-1);
				InventoryP1.erase(InventoryP1.begin()+k);
				if(ListP2[i].getHP()<=0)
				{
					ScoreP2 += 100;
					outtextxy(ListP2[i].getX(),ListP2[i].getY()-30, "+100!!");
					readimagefile(boom,ListP2[i].getX(),ListP2[i].getY(),ListP2[i].getX()+enemy1_size,ListP2[i].getY()+enemy1_size);
					ListP2.erase(ListP2.begin()+i);
					delay(20);
				}
			}

		}*/
		
		
	}


	for(int i=0; i<List1P2.size(); i++){

		for(int j=0; j<MybulletsP2.size(); j++){
			if(MybulletsP2[j].getY() + missile1_size <= List1P2[i].getY() + enemy1_size &&
			MybulletsP2[j].getX() + missile1_size <= List1P2[i].getX()+enemy1_size && MybulletsP2[j].getX() >= List1P2[i].getX() &&
			MybulletsP2[j].getY() >= List1P2[i].getY()){
				List1P2[i].setHP(-1);
				MybulletsP2.erase(MybulletsP2.begin()+j);
				if(List1P2[i].getHP()<=0)
				{
					ScoreP2 += 100;
					outtextxy(List1P2[i].getX(),List1P2[i].getY()-30, "+100!!");
					readimagefile(boom,List1P2[i].getX(),List1P2[i].getY(),List1P2[i].getX()+enemy1_size,List1P2[i].getY()+enemy1_size);
					List1P2.erase(List1P2.begin()+i);
					delay(20);
				}
			}

		}
	}

	/*for(int i=0; i<heart.size(); i++) {	//Erase non existing hearts
         if(heart[i].getY() + itemsize <= Myhero.getY()+hero1_size && heart[i].getX() + itemsize <= Myhero.getX()+hero1_size && heart[i].getX() >= Myhero.getX() && heart[i].getY() >= Myhero.getY()){
			Myhero.setHP(2);
			heart.erase(heart.begin()+i);
		 }
	}*/


}


void HeroP2 :: setHP(int n){    //print the bastard enemies
	HP+=n;
}

void HeroP2 :: setY(int n){    //print the bastard enemies
	Pos_Y = n;
}

void HeroP2 :: setX(int n){    //print the bastard enemies
	Pos_X = n;
}

int HeroP2 :: getHP(){
	return HP;
}
void HeroP2 :: PrintHP(){
        /*for(int i=0; i<=HP; i++){
			//readimagefile(heart,0+i*30,0,30+i*30,30);
			}*/
	char str[5];
	itoa(HP,str,10);
    outtextxy(940,1, str);
}
void HeroP2 :: Printhero(int herosize){    //print the bastard enemies
	readimagefile(hero1P2,Pos_X,Pos_Y,Pos_X+herosize,Pos_Y+herosize);
}

void HeroP2 :: Move(int *p){         //enemies moving downward
  	int k=0;
    for(int i=0;i<4;i++)
    if(p[i]!=0)
	k++;
//Controls directions
    if(k==1){
    	if(p[0]==1 && Pos_Y>0)      // up
			Pos_Y-=10;
    	else if(p[1]==1 && Pos_Y<windsizeY-hero1_size && BlockedP2!=true) // down
			Pos_Y+=10;
    	if(p[2]==1 && Pos_X>0) // left
			Pos_X-=10;
    	else if(p[3]==1 && Pos_X<windsizeX-hero1_size)            // right
	    	Pos_X+=10;
   	}

    else if(k==2){
    	if(p[0]==1 && p[3]==1 && Pos_Y>0 && Pos_X<windsizeX-hero1_size ){//up & right
      			Pos_Y-=10;
	    		Pos_X+=10;

		}
      	else if(p[0]==1 && p[2]==1 && Pos_Y>0 && Pos_X>0){ //up & left
      			Pos_Y-=10;
	    		Pos_X-=10;
		}
    	else if(p[1]==1 && p[2]==1 && Pos_Y<windsizeY+30-hero1_size && Pos_X>-30){ //down & left
			if(BlockedP2==true)
			  	Pos_X-=10;
			else{
				Pos_Y+=10;
	    		Pos_X-=10;
			}
		}
      	else if(p[1]==1 && p[3]==1 && Pos_Y<windsizeY+30-hero1_size && Pos_X<windsizeX-hero1_size+30){ //down & right
			if(BlockedP2==true)
			  	Pos_X+=10;
			else{
				Pos_Y+=10;
	    		Pos_X+=10;
			}
   		}
   	}
}

int HeroP2 :: getX(){      //every enemy x location
	return Pos_X;
}

int HeroP2 :: getY(){    //enemy y location
	return Pos_Y;
}

void ControlsP2(HeroP2 &A){

	int c[4] = {0};

	if(GetAsyncKeyState(UP_KEY)==0) c[0]=0;
    if(GetAsyncKeyState(DOWN_KEY)==0) c[1]=0;
    if(GetAsyncKeyState(LEFT_KEY)==0) c[2]=0;
    if(GetAsyncKeyState(RIGHT_KEY)==0) c[3]=0;

    if(GetAsyncKeyState(UP_KEY)!=0) c[0]=1;
    if(GetAsyncKeyState(DOWN_KEY)!=0) c[1]=1;
    if(GetAsyncKeyState(LEFT_KEY)!=0) c[2]=1;
    if(GetAsyncKeyState(RIGHT_KEY)!=0) c[3]=1;

    A.Move(c);

}
