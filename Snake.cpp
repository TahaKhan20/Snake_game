#include<graphics.h>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<time.h>
#include<stdio.h>
using namespace std;

class coordinates
{
	private:
		int x_cor;
		int y_cor;
	
	public:
		coordinates()
		{
			x_cor = 0;
			y_cor = 0;
		}
		void set_x_cor(int x)
		{
			x_cor = x;
		}
		void set_y_cor(int y)
		{
			y_cor = y;
		}
		int get_x_cor()
		{
			return x_cor;
		}
		int get_y_cor()
		{
			return y_cor;
		}
};

coordinates C1;

void border()
{
	setcolor(RED);
	
	rectangle(0,0,600,50);
	rectangle(0,550,600,600);
	rectangle(0,50,50,550);
	rectangle(550,50,600,550);
	
	setfillstyle(SOLID_FILL,RED);
	
	floodfill(300,25,RED);
	floodfill(300,575,RED);
	floodfill(25,300,RED);
	floodfill(575,300,RED);
}	

int snake(int x = 0, int y = 0, char move = 'e', int size = 4)
{
	
	
	setcolor(YELLOW);
	int count = 0;
	int xcor = 0;
	int ycor = 0;
	int temp_x = 0;
	int temp_y = 0;
	static int pre_x = -1;
	static int pre_y = -1;
	int m = 0;
	int j = 0;
	int i = 0;
	
//	int**sn;
//	sn = new int*[50];
//	
//	for(int i = 0; i < 50; i++)
//	{
//		sn[i] = new int[50];
//	}
//	
	int c = 0;
	setfillstyle(SOLID_FILL,YELLOW);
	for(int w = 0; w < size; w++)
	{
		
		if(pre_x == x && pre_y != y)
		{
			j = w;
			i = 0;
		}
		else
		{
			i = w;
			j = 0;
		}
		
//		
//		
//		if(c >= 0)
//		{
//			if(c == 0)
//			{
//				xcor = 200+20*i;
//		ycor = 200 + 20*j;
//		temp_x = xcor;
//		temp_y = ycor;
//		
//		if(move == 'l' || move == 'r')
//		{
//			xcor= xcor + 20*x;
//			circle(xcor,ycor,10);
//			c++;
//		}
//		else if(move == 'u' || move == 'd')
//		{
//			ycor= ycor + 20*y;
//			circle(xcor,ycor,10);
//			c++;
//		}
//		else
//		{
//			circle(xcor,ycor,10);
//		}
//			}
//			if (c > 0)
//		{
//			xcor = temp_x;
//			ycor = temp_y;
//			circle(xcor,ycor,10);
//			temp_x += 20*x;
//			temp_y += 20*y;
//			move = 'e';
//		}
//		
//		
//
//		//size-=1;
//		}
//	
		xcor = 200+20*i + 20*x;
		ycor = 200+20*j+20*y;
		circle(xcor,ycor,10);
		if(xcor <= 50 || ycor <= 50 || xcor >= 550 || ycor >= 550)
		{
			return -1;
		}
		
		if(w == 0 && (move == 'l' || move == 'u'))
		{
			circle(xcor - 5,ycor - 5,3);
			circle(xcor - 5,ycor + 5,3);
			m = w;
		}
		else if(w == size-1 && (move == 'r' || move == 'd'))
		{
			circle(xcor - 5,ycor - 5,3);
			circle(xcor - 5,ycor + 5,3);
			m = w;
		}
		
		floodfill(xcor,ycor,YELLOW);
	}
	pre_x = x;
	C1.set_x_cor(200 + 20*x + 20*m);
	C1.set_y_cor(200 + 20*y + 20*m);
	cout << "Snake  x: " << 200+20*x << " y: " << 200+20*y;
	pre_y = y;
	return 0;
}

int killed()
{
	
}
int food(int xcor, int ycor)
{
	cout << "x: " << xcor << "	y: " << ycor << endl;
	if((xcor + 20 > C1.get_x_cor()) && xcor - 20 < C1.get_x_cor() && ycor + 20 > C1.get_y_cor() && ycor - 20 < C1.get_y_cor())
	{
		
		return 1;
	}
	
	else
	{
		
		setcolor(BROWN);
		circle(xcor,ycor,5);
	setfillstyle(SOLID_FILL,BROWN);
	floodfill(xcor,ycor,BROWN);
	return 0;
	}
}


main()
{
	initwindow(600,600);
	
	int x_move = 0;
	int y_move = 0;
	int left = 0;
	int right = 0;
	int up = 0;
	int down = 0;
	int f = 1;
	char move = 'l';
	for(;;)
	{
		
		border();
		
		static int size = 3;
		
		int xcor;
		int ycor;
		if(f > 0)
		{
			srand(time(0));
			xcor = rand()%500 + 50;
			ycor = rand()%500 + 50;
			size++;
			f = food(xcor,ycor);
			
			
		}
		else
		{
			f = food(xcor,ycor);
		}
		int end = snake(x_move,y_move,move,size);
		if(GetAsyncKeyState(VK_LEFT))
		{
			up = 0;
			down = 0;
			right = 0;
			left++;
		}
		else if(GetAsyncKeyState(VK_RIGHT))
		{
			up = 0;
			down = 0;
			left = 0;
			right++;
		}
		else if(GetAsyncKeyState(VK_UP))
		{
			left = 0;
			right = 0;
			down = 0;
			up++;
			
		}
		else if(GetAsyncKeyState(VK_DOWN))
		{
			left = 0;
			right = 0;
			up = 0;
			down++;
		
		}
		
		if(left > 0)
		{
			x_move -= 1;
			move = 'l';
		}
		if(right > 0)
		{
			x_move += 1;
			move = 'r';
		}
		if(up > 0)
		{
			y_move -= 1;
			move = 'u';
		}
		if(down > 0)
		{
			y_move += 1;
			move = 'd';
		}
		
		if(end == -1)
		{
			return 0;
		}
		delay(1000);
		cleardevice();
	}
	
	
}