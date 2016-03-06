#include "extra.h"

int w = 350, h = 400;
static int temp;

circle circ(175, 200);
Racket r_l('l');Racket r_r('r');

void Keyboard2(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
		r_l.set_direct_r(1);
		if (r_l.get_y_r(1) >= h - 2) break;
		for (int i = 0;i < 4;i++)
		{
			int t = r_l.get_y_r(i) + 10;
			r_l.set_y_r(i, t);
			 
		}
		break;
	case 's':
		r_l.set_direct_r(-1);
		if (r_l.get_y_r(0) <= 2) break;
		for (int i = 0;i < 4;i++)
		{
			int t = r_l.get_y_r(i) - 10;
			r_l.set_y_r(i, t);

		}
		break;
	case 32:
		temp = 1; glutSetWindowTitle("Good luck");break;

	}
}

void Keyboard(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		r_r.set_direct_r(1);
		if (r_r.get_y_r(1) >= h - 2) break;
		for (int i = 0;i < 4;i++)
		{
			int t = r_r.get_y_r(i) + 10;
			r_r.set_y_r(i, t);

		}
		break;
	case GLUT_KEY_DOWN:
		r_r.set_direct_r(-1);
		if (r_r.get_y_r(0) <= 2) break;
		for (int i = 0;i < 4;i++)
		{
			int t = r_r.get_y_r(i) - 10;
			r_r.set_y_r(i, t);

		}
		break;
		
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0);

	r_r.draw_racket();
	r_l.draw_racket();
	circ.draw_circle();


	glutSwapBuffers();
}

void Timer(int = 0)
{
	display();
	if(temp)
		circ.move_circle(r_l,r_r);
	
	glutTimerFunc(15, Timer, 0);
}

void Initialize()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv)
{
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(500, 200);
	glutInitWindowSize(w, h);
	int hwnd = glutCreateWindow("Press space for start");
	
	Initialize();

	glutKeyboardFunc(Keyboard2);
	glutSpecialFunc(Keyboard);
	glutDisplayFunc(display);
	glutTimerFunc(15, Timer, 0);

	
	glutMainLoop();

	return 0;
}