#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<graphics.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<vector>
#include<iostream>

using namespace std;

struct rn{
	char name[11];
	int score;
    }Solo[10]={{"Empty", 0},{"Empty", 0},{"Empty", 0},
	{"Empty", 0},{"Empty", 0},{"Empty", 0}, {"Empty", 0},
	{"Empty", 0},{"Empty", 0},{"Empty", 0}};

void displayrank(){
	FILE *P;
    char score[25];
	if((P = fopen("Rank.txt","r+"))==NULL) 
	outtextxy(10,10, "Sorry, no rank currently");
	else{
	  int c=0;
      while(!feof(P) && fscanf(P, " %s %d", &Solo[c].name, &Solo[c].score)) c++;
      c=30;
	  for(int i=0; i<10; i++){
	  outtextxy(30,c, Solo[c].name);
	  itoa(Solo[c].score,score,10);
      outtextxy(30,c, score);
	  c+=30;
	  }
	}
    

}

void ArrangeRank(int Score, char name[]){
      FILE *P;

      P = fopen("Rank.txt","r+");
      if(P == NULL){
          fclose(P);
          P = fopen("Rank.txt","w+");

          for(int i=0; i<10; i++)
          if(Score>=Solo[i].score) {
          	strcpy(Solo[i].name, name); 
            Solo[i].score = Score;
            break;
          }
          
          for(int i=0; i<10; i++)
          fprintf(P, " %s %d", Solo[i].name, Solo[i].score);
      }

      else{
      int c=0;
      while(!feof(P) && fscanf(P, " %s %d", &Solo[c].name, &Solo[c].score)) c++;
      

      for(int i=0; i<10; i++)
      if(Score>=Solo[i].score) {
        strcpy(Solo[i].name, name); 
        Solo[i].score = Score;
        break;
      }

      for(int i=0; i<10; i++)
      fprintf(P, " %s %d", Solo[i].name, Solo[i].score);
      }
      
      fclose(P);
}
