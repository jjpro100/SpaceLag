//#include "my-fns.h"
#include "vsmode.h"


#define ONE 0x31
#define TWO 0x32
#define THREE 0x33

#define Z_KEY 0x5A
#define NINE_KEY 0x39

using namespace std;
//#include<pngwriter.h>

void Controls(Hero &A, vector<Bullet> &B);
void ControlsP1(Hero &A);
void ControlsP2(Hero &A);

//Bullets, Hero, Enemies
		vector <Enemies> List;
		vector <Enemies1> List1;
		Hero Myhero;
		vector <Bullet> Mybullets;
		vector <Enemies_Arsenal> Inventory;
		//Items
		vector <BKholeitem> Holeitem1;
		vector <Blocks> Block;
		vector <Hearts> heart;
		Boss1 Boss1;



int main(){
	int y;
	int y1;
	int page=0;
	int slow_pace=5, middle_pace=8, fast_pace=11, insane_pace=15;
	void PrintScore();

	void PrintScoreP1();
	void PrintScoreP2();
	char scoreP1[25], scoreP2[25];
	

     	vector <EnemiesP1> ListP1;
        vector <Enemies1P1> List1P1;
        HeroP1 MyheroP1;
        vector <BulletP1> MybulletsP1;
        vector <Enemies_ArsenalP1> InventoryP1;

		vector <EnemiesP2> ListP2;
        vector <Enemies1P2> List1P2;
        HeroP2 MyheroP2;
        vector <BulletP2> MybulletsP2;
        vector <Enemies_ArsenalP2> InventoryP2;
        vector <Blockitem> Blockitems;
		


	srand(time(NULL));
	initwindow(windsizeX,windsizeY);
	settextstyle(1, 0, 25);

	int mode=0;

	while(1){
        
        readimagefile(menu, 0, 0, windsizeX, windsizeY);
        if(GetAsyncKeyState(ONE)!=0) mode=1;
        else if(GetAsyncKeyState(TWO)!=0) mode=2;
		
		switch(mode){
		case 1:

		//1P
		while(1){
		setactivepage(page); //Using the magnificent double buffer

		if(Myhero.getHP()<=0 || Score<0 || Myhero.getY()>=751-(hero1_size) || Myhero.getX()>=1051-(hero1_size) || Myhero.getY()<=-51 || Myhero.getX()<=-51){
			readimagefile(gameover, 0, 0, windsizeX, windsizeY);
			outtextxy(20, 40, "Click on alternate window");
			outtextxy(20, 80, " and enter for exit!!");
			cout << "you get : " << Score << endl;
			system("pause");
			//getch();
			break;
		}

		setvisualpage(1 - page);
		cleardevice();

	    if(ismouseclick(WM_LBUTTONDOWN) && BKhole)  //If you got the black hole item
        {
            BKhole=0;
			clearmouseclick(WM_RBUTTONDOWN);
			if(Hole1.size()<1)
				Hole1.push_back(Blackhole(mousex(),mousey()));
        }

		difficult();
		if(Boss1.getHP()<=0)
			boss = false;

		//readimagefile(backgnd,0,0,windsizeX,windsizeY); //Printing background
//Boss1
		if(boss == true){
			Boss1.Printboss1(boss1_size);
			Boss1.Move();

			missilesf = 2;
			missilesv = 13;
			
			/*if(Boss1.getBlaster_timeof_creation()==-1 &&
			Boss1.getTimeof_location()==-1 && Boss1.Time2shoot()){
				Boss1.Locate(Myhero.getX(), Myhero.getY());
			}

			else if((time(NULL)-Boss1.getTimeof_location())<=5 &&
			Boss1.getBlaster_timeof_creation()==-1){
				Boss1.setBlaster_timeof_creation();
			}
			else if((time(NULL)-Boss1.getTimeof_location())<=5){
				Boss1.draw_Boss_blaster();
			}
			else if(time(NULL)-Boss1.getBlaster_timeof_creation()==5){
				Boss1.resetBlaster_timeof_creation();
				Boss1.resetTimeof_location();
			}
			*/
		}
		if(boss == false){
			if(Enemytime()) {
				List.push_back(Enemies());  //Give birth to a vector enemy
				count++;
			}
			for(int i=0; i<List.size(); i++){
				List[i].Move(enemiesv);
				List[i].Printenemy(enemy1_size);
			}
		}

		if(boss == false){
			if(Enemytime1()) {
				List1.push_back(Enemies1());  //Give birth to a vector enemy1
				count++;
			}
			for(int i=0; i<List1.size(); i++){
				List1[i].Move(List1[i].getDirection()*enemies1v);
				List1[i].Printenemy(enemy1_size);
			}

		}


/*printf("%d\n",List1.size());
for(int i=0;i<List1.size();i++){
	printf("x = %d\n",List1[i].getX());
	printf("y = %d\n",List1[i].getY());
}*/
//		Cleaning(List, List1, Mybullets, Inventory, Myhero, heart);

//Rate of Generate missiles

		if(List.size() && (rate%missilesf==0)){
			y=rand()%List.size();
			Inventory.push_back(Enemies_Arsenal((2*List[y].getX()+enemy1_size)/2, List[y].getY()+enemy1_size,Myhero.getX(),Myhero.getY()));
	            //Inventory.push_back(Enemies_Arsenal((2*List[y].getX()+enemy1_size)/2, List[y].getY()+enemy1_size));
        	rate=0;
		}

//Rate of Generate missiles1

		if(List1.size() && (rate1%missilesf==0)){
			y1=rand()%List1.size();
			Inventory.push_back(Enemies_Arsenal((2*List1[y1].getX()+enemy1_size)/2, List1[y1].getY()+enemy1_size,Myhero.getX(),Myhero.getY()));
	            //Inventory.push_back(Enemies_Arsenal((2*List[y].getX()+enemy1_size)/2, List[y].getY()+enemy1_size));
        	rate1=0;
		}

//enemies's missiles

		for(int j=0; j<Inventory.size(); j++){
	    	Inventory[j].Move(missilesv,Inventory);
			Inventory[j].Printmissiles(missile1_size);
	    }

		//Cleaning(List, List1, Mybullets, Inventory, Myhero, heart);
		//printf("%d\n",Myhero.getHP());
		Myhero.Printhero(hero1_size);
		Controls(Myhero,Mybullets);

//if press A

    	if(GetAsyncKeyState(A_KEY)!=0)
			Mybullets.push_back(Bullet(Myhero.getX()+hero1_size/2,Myhero.getY()));

		for(int k=0; k<Mybullets.size(); k++){   //Print and move enemies/their shit
			Mybullets[k].Move(20);
			Mybullets[k].Printbullet(bullet_size);
		}

		Cleaning(List, List1, Mybullets, Inventory, Myhero, heart, Holeitem1, Hole1, Block, Boss1);
//Items
		int n = rand()%items;

		if(Itemtime() && rand()%selection[n]==0)
		switch(n){
			case 0:                              //Create a heart item!
			    heart.push_back(Hearts());
				break;
			case 1:                              //Create a blackhole item!
			    if(Holeitem1.size()<1)
			    	Holeitem1.push_back(BKholeitem());
			    break;
			case 2:
				if(Block.size()<1)
					Block.push_back(Blocks(Myhero.getX(),Myhero.getY()));
			default:;
		}
//draw pictures
		for(int i=0;i<Holeitem1.size();i++)
			Holeitem1[i].PrintItem(itemsize);
		for(int i=0;i<Hole1.size();i++)
			Hole1[i].drawBlackhole();
		for(int i=0;i<heart.size();i++)
			heart[i].PrintItem(itemsize);
		if(Block.size()){
			Block[0].PrintBlock(Block[0].getLength());
			Block[0].Move(10);
		}


		Myhero.PrintHP();
		PrintScore();
//pushed by boss1
		pushedbyboss(Boss1, Myhero);


//Blocked
		if(Block.size()){
			if( Myhero.getY()>Block[0].getY() && Myhero.getY()<=Block[0].getY()+20  && Myhero.getX()<( Block[0].getX()+Block[0].getLength()-5 ) && ( Myhero.getX()+hero1_size )>( Block[0].getX()+5 )){
				Myhero.setY(Block[0].getY()+20);
				blocked = true;
			}
			else
				blocked = false;
		}
		/*if(Inventory.size()){

			printf("%d\n", Inventory[Inventory.size()-1].getX());
			printf("%d\n", Inventory[Inventory.size()-1].getY());
		}*/
        /*printf("total inventory: %d\n", Inventory.size());
		printf("total List: %d\n", List.size());
		printf("total Listone: %d\n", List1.size());
		printf("total Mybullets: %d\n", Mybullets.size());
		printf("Boss HP: %d\n", Boss1.getHP());*/ 
		//	printf("%d\n", Mybullets[Mybullets.size()-1].getY());
		//delay(100);
	//	printf("%d\n", Myhero.getHP());
	    rate++;
	    rate1++;
	    //cout << difficulty << endl;
		page = 1-page;
		delay(15);

	}
	exit(1);
	break;

	//2P
	case 2:
	while(1){
		setactivepage(page); //Using the magnificent double buffer

		if((MyheroP1.getHP()<=0 || ScoreP1<0 || MyheroP1.getY()>=751-(hero1_size) || MyheroP1.getX()>=1051-(hero1_size) || MyheroP1.getY()<=-51 || MyheroP1.getX()<=-51)  ||
	      (MyheroP2.getHP()<=0 || ScoreP2<0 || MyheroP2.getY()>=751-(hero1_size) || MyheroP2.getX()>=1051-(hero1_size) || MyheroP2.getY()+hero1_size<=-31 || MyheroP2.getX()<=-51) ||
		   ScoreP1>=4000 || ScoreP2>=4000){
			
			readimagefile(gameover, 0, 0, windsizeX, windsizeY);
			if((MyheroP1.getHP()<=0 || ScoreP1<0 || MyheroP1.getY()>=751-(hero1_size) || MyheroP1.getX()>=1051-(hero1_size) || MyheroP1.getY()<=-51 || MyheroP1.getX()<=-51) || ScoreP2>=4000) outtextxy(20, 20, "P2 wins!!");
			else if((MyheroP2.getHP()<=0 || ScoreP2<0 || MyheroP2.getY()>=751-(hero1_size) || MyheroP2.getX()>=1051-(hero1_size) || MyheroP2.getY()<=-51 || MyheroP2.getX()<=-51) || ScoreP1>=4000) outtextxy(20, 20, "P1 wins!!");
			outtextxy(20, 40, "Click on alternate window");
			outtextxy(20, 80, " and enter for exit!!");
			cout << "P1 you get : " << ScoreP1 << endl;
			cout << "P2 you get : " << ScoreP2 << endl;
			system("pause");
			//getch();
			break;
		}

		setvisualpage(1 - page);
		cleardevice();

		difficult();

		//readimagefile(backgnd,0,0,windsizeX,windsizeY); //Printing background
      		
			//P1
			if(Enemytime()  && ListP2.size()<5) {
				ListP1.push_back(EnemiesP1());  //Give birth to a vector enemy
				count++;
			}
			//P2
			if(Enemytime() && ListP2.size()<5) {
				ListP2.push_back(EnemiesP2());  //Give birth to a vector enemy
				count++;
			}
			//P1
			for(int i=0; i<ListP1.size(); i++){
				ListP1[i].Move(enemiesv);
				ListP1[i].Printenemy(enemy1_size);
			}
			//P2
			for(int i=0; i<ListP2.size(); i++){
				ListP2[i].Move(enemiesv);
				ListP2[i].Printenemy(enemy1_size);
			}
			//P1
			if(Enemytime1() && List1P1.size()<5) {
				List1P1.push_back(Enemies1P1());  //Give birth to a vector enemy1
				count++;
			}
			//P2
			if(Enemytime1() && List1P2.size()<5) {
				List1P2.push_back(Enemies1P2());  //Give birth to a vector enemy1
				count++;
			}
			//P1
			for(int i=0; i<List1P1.size(); i++){
				List1P1[i].Move(List1P1[i].getDirection()*enemies1v);
				List1P1[i].Printenemy(enemy1_size);
			}
			//P2
			for(int i=0; i<List1P2.size(); i++){
				List1P2[i].Move(List1P2[i].getDirection()*enemies1v);
				List1P2[i].Printenemy(enemy1_size);
			}
/*printf("%d\n",List1.size());
for(int i=0;i<List1.size();i++){
	printf("x = %d\n",List1[i].getX());
	printf("y = %d\n",List1[i].getY());
}*/

//Rate of Generate missiles
		//P1
		if(ListP1.size() && (rate%missilesf==0)){
			y=rand()%ListP1.size();
			InventoryP1.push_back(Enemies_ArsenalP1((2*ListP1[y].getX()+enemy1_size)/2, ListP1[y].getY()+enemy1_size,MyheroP1.getX(),MyheroP1.getY()));
	            //Inventory.push_back(Enemies_Arsenal((2*List[y].getX()+enemy1_size)/2, List[y].getY()+enemy1_size));
        	rate=0;
		}
		//P2
		if(ListP2.size() && (rate%missilesf==0)){
			y=rand()%ListP2.size();
			InventoryP2.push_back(Enemies_ArsenalP2((2*ListP2[y].getX()+enemy1_size)/2, ListP2[y].getY(),MyheroP2.getX(),MyheroP2.getY()));
	            //Inventory.push_back(Enemies_Arsenal((2*List[y].getX()+enemy1_size)/2, List[y].getY()+enemy1_size));
        	rate=0;
		}

//Rate of Generate missiles1
    	//P1  
		if(List1P1.size() && (rate1%missilesf==0)){
			y1=rand()%List1P1.size();
			InventoryP1.push_back(Enemies_ArsenalP1((2*List1P1[y1].getX()+enemy1_size)/2, List1P1[y1].getY()+enemy1_size,MyheroP1.getX(),MyheroP1.getY()));
	            //Inventory.push_back(Enemies_Arsenal((2*List[y].getX()+enemy1_size)/2, List[y].getY()+enemy1_size));
        	rate1=0;
		}
    	//P2
		if(List1P2.size() && (rate1%missilesf==0)){
			y1=rand()%List1P2.size();
			InventoryP2.push_back(Enemies_ArsenalP2((2*List1P2[y1].getX()+enemy1_size)/2, List1P2[y1].getY(),MyheroP2.getX(),MyheroP2.getY()));
	            //Inventory.push_back(Enemies_Arsenal((2*List[y].getX()+enemy1_size)/2, List[y].getY()+enemy1_size));
        	rate1=0;
		}
//enemies' missiles
		//P1
		for(int j=0; j<InventoryP1.size(); j++){
	    	InventoryP1[j].Move(missilesv,InventoryP1);
			InventoryP1[j].Printmissiles(missile1_size);
	    }
		//P2
		for(int j=0; j<InventoryP2.size(); j++){
		    	InventoryP2[j].Move(missilesv,InventoryP2);
				InventoryP2[j].Printmissiles(missile1_size);
		    }

		//P1
		MyheroP1.Printhero(hero1_size);
		ControlsP1(MyheroP1);
		//P2
		MyheroP2.Printhero(hero1_size);
		ControlsP2(MyheroP2);

//if press A
    	//P1
        if(GetAsyncKeyState(A_KEY)!=0 && MybulletsP1.size()<=2)
			MybulletsP1.push_back(BulletP1(MyheroP1.getX()+hero1_size/2,MyheroP1.getY()));
		//P2
		if(GetAsyncKeyState(ZERO_KEY)!=0 && MybulletsP2.size()<=2)
			MybulletsP2.push_back(BulletP2(MyheroP2.getX()+hero1_size/2,MyheroP2.getY()+hero1_size));
		
		
	/*	if(Block.size()){
			Block[0].PrintBlock(Block[0].getLength());
			Block[0].Move(10);
		}		
	*/	
	
		
		//P1
		if(GetAsyncKeyState(Z_KEY)!=0 && BlockattackP1>0){
			BlockattackP1--;
			Blockp1.push_back(BlockP1(MyheroP1.getX()-125, MyheroP1.getY()));
		}
		for(int i=0;i<Blockp1.size();i++){
				Blockp1[i].PrintBlock(Blockp1[i].getLength());
				Blockp1[i].Move(-10);
		}
		
		//P2
		if(GetAsyncKeyState(NINE_KEY)!=0 && BlockattackP2>0){
			BlockattackP2--;
			Blockp2.push_back(BlockP2(MyheroP2.getX()-125, MyheroP2.getY()+hero1_size));
		}
		for(int i=0;i<Blockp2.size();i++){
				Blockp2[i].PrintBlock(Blockp2[i].getLength());
				Blockp2[i].Move(10);
		}
		
		//P1 is blocked
		if(Blockp2.size()){
			for(int i=0;i<Blockp2.size();i++){
				if( MyheroP1.getY()>Blockp2[i].getY() && MyheroP1.getY()<=Blockp2[i].getY()+20  && MyheroP1.getX()<( Blockp2[i].getX()+Blockp2[i].getLength()-5 ) && ( MyheroP1.getX()+hero1_size )>( Blockp2[i].getX()+5 )){
				MyheroP1.setY(Blockp2[i].getY()+20);
				BlockedP1 = true;
			}
			else
				BlockedP1 = false;
			}
		}
		
		//P2 is blocked
		if(Blockp1.size()){
			for(int i=0;i<Blockp1.size();i++){
				if( MyheroP2.getY()+hero1_size<Blockp1[i].getY() && MyheroP2.getY()+hero1_size>=Blockp1[i].getY()-20  &&
				 MyheroP2.getX()<( Blockp1[i].getX()+Blockp1[i].getLength()-5 ) && 
				 ( MyheroP2.getX()+hero1_size )>( Blockp1[i].getX()+5 )){
				MyheroP2.setY(Blockp1[i].getY()-20-hero1_size);
				BlockedP2 = true;
			}
			else
				BlockedP2 = false;
			}
		}
		
		//P1
		for(int k=0; k<MybulletsP1.size(); k++){   //Print and move enemies/their shit
			MybulletsP1[k].Move(20);
			MybulletsP1[k].Printbullet(bullet_size);
		}
		//P2
		for(int k=0; k<MybulletsP2.size(); k++){   //Print and move enemies/their shit
			MybulletsP2[k].Move(20);
			MybulletsP2[k].Printbullet(bullet_size);
		}

		CleaningP1(ListP1, List1P1, MybulletsP1, InventoryP1, MyheroP1, InventoryP2, MyheroP2, heart, Blockitems, Blockp1, Blockp2);
		CleaningP2(ListP2, List1P2, MybulletsP2, InventoryP2, MyheroP2, InventoryP1, MyheroP1);
//Items
//Create a heart item!
		if(Itemtime()) heart.push_back(Hearts());
		for(int i=0;i<heart.size();i++)
			heart[i].PrintItem(itemsize);
//Create a Block item!
		if(rand()%30==0) Blockitems.push_back(Blockitem());	
		for(int i=0;i<Blockitems.size();i++){
			Blockitems[i].PrintItem(itemsize);
			if(time(NULL)-Blockitems[i].getTimeofcreation()>=5){
				Blockitems.erase(Blockitems.begin()+i);
			}
		} 
	   
	    if(Block.size()){
			Block[0].PrintBlock(Block[0].getLength());
			Block[0].Move(10);
		}
	
       //P1
		MyheroP1.PrintHP();
		PrintScoreP1();
		//P2
		MyheroP2.PrintHP();
		PrintScoreP2();
	
		/*printf("P1 %d\n",BlockattackP1);
		printf("P2 %d\n",BlockattackP2);
		printf("P1 (%d , %d)\n",MyheroP1.getX(),MyheroP1.getY());*/
		/*if(Inventory.size()){

			printf("%d\n", Inventory[Inventory.size()-1].getX());
			printf("%d\n", Inventory[Inventory.size()-1].getY());
	}*/
       /* printf("inventoryP2: %d\n", InventoryP2.size());
		printf("ListP2: %d\n", ListP2.size());
		printf("ListoneP2: %d\n", List1P2.size());
		printf("MybulletsP2: %d\n", MybulletsP2.size());
		printf("inventoryP1: %d\n", InventoryP1.size());
		printf("ListP1: %d\n", ListP1.size());
		printf("ListoneP1: %d\n", List1P1.size());
		printf("MybulletsP1: %d\n", MybulletsP1.size());
		printf("total inventory: %d\n", InventoryP1.size()+InventoryP2.size());
		printf("total List: %d\n", ListP1.size()+ListP2.size());
		printf("total ListoneP1: %d\n", List1P1.size()+List1P2.size());
		printf("total MybulletsP1: %d\n", MybulletsP1.size()+MybulletsP2.size());
		*/
		
		
		//if(Mybullets.size())
		//	printf("%d\n", Mybullets[Mybullets.size()-1].getY());
		//delay(100);
	//	printf("%d\n", Myhero.getHP());
	    rate++;
	    rate1++;
	    //cout << difficulty << endl;
		page = 1-page;
		//delay(5);

	}
	exit(1);
	break;
    	
	default: break;
	}
}
	return 0;
}

void Hero :: setHP(int n){    //print the bastard enemies
	HP+=n;
}

void Hero :: setY(int n){    //print the bastard enemies
	Pos_Y = n;
}

void Hero :: setX(int n){    //print the bastard enemies
	Pos_X = n;
}

int Hero :: getHP(){
	return HP;
}
void Hero :: PrintHP(){
        /*for(int i=0; i<=HP; i++){
			//readimagefile(heart,0+i*30,0,30+i*30,30);
			}*/
	char str[5];
	itoa(HP,str,10);
    outtextxy(1,1, str);
}
void Hero :: Printhero(int herosize){    //print the bastard enemies
	readimagefile(hero1,Pos_X,Pos_Y,Pos_X+herosize,Pos_Y+herosize);
}

void Hero :: Move(int *p, vector<Blocks> &Block,class Boss1 &Boss1){         //enemies moving downward
  	int k=0;
    for(int i=0;i<4;i++)
    if(p[i]!=0)
	k++;
//Controls directions
    if(k==1){
    	if(p[0]==1 && Pos_Y>0 && blocked==false && !(pushed==1))      // up
			Pos_Y-=10;
    	else if(p[1]==1 && Pos_Y<windsizeY-hero1_size && !(pushed==3)) // down
			Pos_Y+=10;
    	if(p[2]==1 && Pos_X>0 && !(pushed==4)) // left
			Pos_X-=10;
    	else if(p[3]==1 && Pos_X<windsizeX-hero1_size && !(pushed==2))            // right
	    	Pos_X+=10;
   	}

    else if(k==2){
    	if(p[0]==1 && p[3]==1 && Pos_Y>0 && Pos_X<windsizeX-hero1_size ){//up & right
			if(blocked==true)
				Pos_X+=10;
			if(pushed==1)
				Pos_X+=10;
			else if(pushed==2)
				Pos_Y-=10;
			else{
      			Pos_Y-=10;
	    		Pos_X+=10;
	    	}
		}
      	else if(p[0]==1 && p[2]==1 && Pos_Y>0 && Pos_X>0){ //up & left
      		if(blocked==true)
				Pos_X-=10;
			if(pushed==1)
				Pos_X-=10;
			else if(pushed==4)
				Pos_Y-=10;
			else{
      			Pos_Y-=10;
	    		Pos_X-=10;
	    	}
		}
    	else if(p[1]==1 && p[2]==1 && Pos_Y<windsizeY+30-hero1_size && Pos_X>-30){ //down & left
			if(pushed==4)
				Pos_Y+=10;
			else if(pushed==3)
				Pos_X-=10;
			else{
				Pos_Y+=10;
	    		Pos_X-=10;
			}
		}
      	else if(p[1]==1 && p[3]==1 && Pos_Y<windsizeY+30-hero1_size && Pos_X<windsizeX-hero1_size+30){ //down & right
	    	if(pushed==2)
				Pos_Y+=10;
			else if(pushed==3)
				Pos_X+=10;
			else{
				Pos_Y+=10;
	    		Pos_X+=10;
			}
   		}
   	}
}

int Hero :: getX(){      //every enemy x location
	return Pos_X;
}

int Hero :: getY(){    //enemy y location
	return Pos_Y;
}

void Controls(Hero &A, vector<Bullet> &B){

	int c[4] = {0};

	if(GetAsyncKeyState(I_KEY)==0) c[0]=0;
    if(GetAsyncKeyState(K_KEY)==0) c[1]=0;
    if(GetAsyncKeyState(J_KEY)==0) c[2]=0;
    if(GetAsyncKeyState(L_KEY)==0) c[3]=0;

    if(GetAsyncKeyState(I_KEY)!=0) c[0]=1;
    if(GetAsyncKeyState(K_KEY)!=0) c[1]=1;
    if(GetAsyncKeyState(J_KEY)!=0) c[2]=1;
    if(GetAsyncKeyState(L_KEY)!=0) c[3]=1;

    A.Move(c, Block, Boss1);

}


void Enemies_Arsenal :: Printmissiles(int missile_size){    //print the weapons
	readimagefile(missile,Pos_X,Pos_Y,Pos_X+missile1_size,Pos_Y+missile1_size);
}

int Enemies_Arsenal :: getX(){      //every enemy missile x location
	return Pos_X;
}

int Enemies_Arsenal :: getY(){    //every enemy missile y location
	return Pos_Y;
}

void Enemies_Arsenal :: Move(int speed,vector<Enemies_Arsenal> &Inventory){         //enemy missiles moving downward
	if(Hole1.size() && gravityfield((2*Pos_X+missile1_size)/2,
	(2*Pos_Y+missile1_size)/2, eventhorizon, Hole1[0].getCenterX(),
	Hole1[0].getCenterY())){
		int theX = Hole1[0].getCenterX()-(2*Pos_X+missile1_size)/2;
		int theY = Hole1[0].getCenterY()-(2*Pos_Y+missile1_size)/2;
		double ang = atan2(theY, theX);
		//printf("theX = %d\ntheY = %d\nang = %lf\n",theX,theY,ang);
		Pos_X += (int)(5*cos(ang));
		Pos_Y += (int)(5*sin(ang));
	}
	else{
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
}

int Blackhole :: getCenterX(){
	return centerX;
}

int Blackhole :: getCenterY(){
	return centerY;
}

int Blackhole :: getRadius(){
	return radius;
}

void Blackhole  :: drawBlackhole(){

	setlinestyle(DOTTED_LINE, 0, 1);
	circle(centerX, centerY, radius);
}

int Blackhole  :: getTimeofcreation(){   //Time when u put the blackhole on the field
	return timeofcreation;
}


int BKholeitem :: getX(){
	return Pos_X;
}

int BKholeitem  :: getY(){
	return Pos_Y;
}

void BKholeitem :: PrintItem(int itemsize){    //print blackhole items
	readimagefile(BH,Pos_X,Pos_Y,Pos_X+itemsize,Pos_Y+itemsize);
}

int BKholeitem  :: getTimeofcreation(){   //Time when u put the blackhole on the field
	return timeofcreation;
}

bool gravityfield(int X, int Y, int eventhorizon, int centerX, int centerY){
    if(eventhorizon*eventhorizon>(X-centerX)*(X-centerX)+(Y-centerY)*(Y-centerY)) return 1;
	return 0;
}
