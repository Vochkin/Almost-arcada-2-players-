#pragma once
#include <Windows.h>
#include <iostream>
#include <glut.h>
#include <time.h>
#include <random>

using namespace std;

extern int w, h;
extern double  w_r, h_r;
class Racket;

class circle
{
	double radius = 6;
	int direction_racket = 0;// -1(to left), 1(to right), 0(not move)
	double x; double y;
	double x_q[4]; double y_q[4];
public:

	circle(int x_c, int y_c)
	{
		x = x_c;
		y = y_c;
		
	}
	void set_direct(int i) { direction_racket = i; }

	int get_x_q(int t) { return x_q[t]; }
	int get_y_q(int t) { return y_q[t]; }

	void set_x(double a) { x = a; }
	void set_y(double b) { y = b; }

	void draw_circle();
	void move_circle(Racket&, Racket&);
	
};

class Racket
{
private:
	double rack_x[4];
	double rack_y[4];
	double w_r = 3;
	double h_r = 80;// size of racket
	int direction = 0;
public:

	Racket(char s)
	{
		if (s == 'l')
		{
			rack_x[0] = 20; rack_y[0] = h / 2 - h_r / 2;
			rack_x[1] = 20; rack_y[1] = h / 2 + h_r / 2;
			rack_x[2] = 20 + w_r; rack_y[2] = h / 2 + h_r / 2;
			rack_x[3] = 20 + w_r; rack_y[3] = h / 2 - h_r / 2;
		}
		else if (s == 'r')
		{
			rack_x[0] = w - 20 - w_r; rack_y[0] = h / 2 - h_r / 2;
			rack_x[1] = w - 20 - w_r; rack_y[1] = h / 2 + h_r / 2;
			rack_x[2] = w - 20; rack_y[2] = h / 2 + h_r / 2;
			rack_x[3] = w - 20; rack_y[3] = h / 2 - h_r / 2;
		}
	}

	double get_w_r() { return w_r; }
	double get_h_r() { return h_r; }

	void set_direct_r(int s) { direction = s; }
	int get_direct_r() { return direction; }

	void set_x_r(int i, double s) { rack_x[i] = s; }
	double get_x_r(int i) { return rack_x[i]; }
	void set_y_r(int i, double s) { rack_y[i] = s; }
	double get_y_r(int i) { return rack_y[i]; }

	void draw_racket()
	{
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_QUADS);
		glVertex2f(rack_x[0], rack_y[0]);
		glVertex2f(rack_x[1], rack_y[1]);
		glVertex2f(rack_x[2], rack_y[2]);
		glVertex2f(rack_x[3], rack_y[3]);
		glEnd();
	}
};

