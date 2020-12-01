#include <iostream>
#include <graphics.h> 
#include <conio.h>
#include <stdlib.h>
#define Round(a) (int)(a+0.5)  
#define DELAY 10
using namespace std ;
int color = 15;


void linePoint(){
	// ve duong truyen
	line (0,20,650,20);
    line (0,40,650,40);
    // ve diem thu
    circle (640,30,5);
    // ve diem truyen
	circle (50,30,3);
	circle (100,30,3);
	circle (150,30,3);
	circle (200,30,3);
	circle (250,30,3);
	circle (300,30,3);
	circle (350,30,3);
	circle (400,30,3);
	circle (450,30,3);
	circle (500,30,3);
	circle (550,30,3);
	circle (600,30,3);
}
// thuat toan ve duong thang
void lineDDA(int x1, int y1, int x2, int y2){       
    int x_unit = 1, Dx = x2 - x1, Dy = y2 - y1;     
    int x = x1;
    float y = y1;
    float m = (float)Dy/Dx;    
    putpixel(x, Round(y), color);
       
    while(x < x2){
        delay(10);  
        x += x_unit;
        y += m;
        putpixel(x,Round(y), color);
    }
}
// Hien thi chu
void showText(int x,int y,char *str){
	int c = getcolor();
	int color = rand() % 16 + 1;
	setcolor(color);
	outtextxy(x+3,y,str);
	setcolor(c);
	delay(10);
}

void showTextBackground(int x,int y,char *str,int color){
	int bk = getbkcolor();
	setbkcolor(color);
	outtextxy(x,y,str);
	delay(10);
	setbkcolor(bk);
}

void getText(){
	while (!ismouseclick(WM_LBUTTONDOWN) || mousex() < 200 || mousey() > 465 || mousey() < 190 || mousex() > 580 ){
		settextstyle(1,0,4);
		setcolor (10);
		outtextxy(150,70,"BAN MUON");
		outtextxy(70,140,"TIEP TUC KHONG?");
		settextstyle(10,0,3);
		showText (220,270,"CO");
		showText (220,340,"KHONG");
	}
	clearmouseclick(WM_LBUTTONDOWN);
}
//Chay chuong trinh
void display(){
	linePoint();
	int x,y,n;
    y = 30;
    n = getmaxx()-50;
    x = 50;
    while(!kbhit()){
	    setcolor(15);
    	lineDDA(x,y, 650, 30);
		setfillstyle(1,15);
		floodfill(x,y,15);
		delay(10);
		setcolor(0); 
		lineDDA(x,y, 650, 30);
		setfillstyle(1,0);
		floodfill(x,y,0);
		x = x + 50;	
		if (x > n) {
			cleardevice();
    		getText();
			break; 
        }
	}	
}

void run(){
	linePoint();
	display();
	//kiem tra co muon tiep tuc khong
	if (mousey() <= 325) {
			showTextBackground(220,270,"CO",15);
			cleardevice();
			display();
			while (!ismouseclick(WM_LBUTTONDOWN)){
				delay(0);
			}
	} else {
			showTextBackground (220,340,"KHONG",15);
			exit(0);
	}
}

int main() {
	// Thiet lap moi truong do hoa
	initwindow(660, 480);
	setbkcolor(0);
	
    run();
    getch();
    closegraph();
	return 0;
}
