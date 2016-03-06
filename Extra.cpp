#include "extra.h"

void circle::draw_circle()
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(x_q[0] = double(x - radius), y_q[0] = double(y - radius));
	glVertex2f(x_q[1] = double(x - radius), y_q[1] = double(y + radius));
	glVertex2f(x_q[2] = double(x + radius), y_q[2] = double(y + radius));
	glVertex2f(x_q[3] = double(x + radius), y_q[3] = double(y - radius));
	glEnd();
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	for (float i = 0.0; i < 2 * 3.14; i += 3.14 / 18)
	{
		glVertex2f(this->x + this->radius*sin(i), this->y + this->radius*cos(i));
	}
	glEnd();
}


void circle::move_circle(Racket& rac_l, Racket& rac_r)
{
	srand(time(NULL));
	static bool t = true;
	int ran = (rand() % 4);
	static int temp;// temp '1' - move to left, if temp '2' - move to right
	static double state_x = x; static double state_y = y;// condition for compare(coords last bump)
	static double y_ = 0, x_ = 0; 

	if(t)
	{
		switch (ran)
		{
		case 0 :
		
			y_ = -2; x_ = -2; temp = 1;
			t = false;
			break;
		case 1:
			y_ = 2; x_ = -2;temp = 1;
			t = false;
			break;
		case 2:
			y_ = 2; x_ = 2;temp = 2;
			t = false;
			break;
		case 3:
			y_ = -2; x_= 2;temp = 2;
			t = false;
			break;
		}

	}
	if (temp == 1)// up or down
	{
		
		if ((((y_q[0] > rac_l.get_y_r(3)) && (y_q[0] <  rac_l.get_y_r(2))) || ((y_q[1] >  rac_l.get_y_r(3)) && (y_q[1] < rac_l.get_y_r(2))) || ((y_q[3] < rac_l.get_y_r(2)) && (y_q[3] > rac_l.get_y_r(3)))) 
			&& ((x_q[0] < rac_l.get_x_r(2)) && (x_q[0] > rac_l.get_x_r(1))))
			 // bump into racket
		{
			
			if (y < state_y)
			{
				x_ *= -1;
				
				if (rac_l.get_direct_r() == -1)
				{
					x_ -= 0.2;
					y_ -= 0.4;
					
				}
				else if (rac_l.get_direct_r() == 1) {
					y_ -= 0.5;
					x_ += 0.3;
					
				}
				
			}
			else if (y > state_y)
			{
				cout << 1.2 << " ";
				x_ *= -1;
				if (rac_l.get_direct_r() == -1)
				{
					y_ += 0.5;
					x_+= 0.3;
					
				}
				else if (rac_l.get_direct_r() == 1) {
					y_ -= 0.4;
					x_ -= 0.2;
					
				}

			}
			state_x = x; state_y = y;
			temp = 2;
			y += y_;
			x += x_;
			return;
		
		}
	}

	if (temp == 2)
	{	
		if((((y_q[2] > rac_r.get_y_r(0)) && (y_q[2] < rac_r.get_y_r(1))) || ((y_q[3] > rac_r.get_y_r(0)) && (y_q[3] < rac_r.get_y_r(1))) || ((y_q[1] < rac_l.get_y_r(1)) && (y_q[0] > rac_l.get_y_r(0)))) 
			&& ((x_q[2] > rac_r.get_x_r(0))&& (x_q[2] < rac_r.get_x_r(3))))//bump into racket
		
		{
			if (y < state_y)
			{
				x_ *= -1;
				if (rac_r.get_direct_r() == -1)
				{
					x_ += 0.2;
					y_ -= 0.4;
				}

				else if (rac_r.get_direct_r() == 1) {
					y_ -= 0.5;
					x_ += 0.3;
				}

			}

			else if (y > state_y)
			{
				x_ *= -1;
				if (rac_r.get_direct_r() == -1)
				{
					y_ += 0.5;
					x_ += 0.3;

				}
				else if (rac_r.get_direct_r() == 1) {

					x_ += 0.2;
					y_ += 0.4;
				}
			}
			
			temp = 1;
			state_x = x;
			state_y = y;
			y += y_;
			x += x_;
			return;
		}
	}

	if (y <= 0 + radius)// bump into down
	{
		state_x = x; state_y = y;
		y_ *= -1;
	}

	else if (y >= h - radius)// bump into upper
	{
		state_x = x; state_y = y;
		y_ *= -1;
		
				
	}

	if (x +radius <= 0) exit(0);
	else if (x-radius >= w) exit(0);

	rac_l.set_direct_r(0);
	rac_r.set_direct_r(0);

	y += y_;
	x += x_;

}

