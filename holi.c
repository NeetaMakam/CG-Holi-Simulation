#include<GL/GLUT.H>
#include<math.h>
#include<string.h>
int i, k;

void output(int x, int y, char *string, void *font)
{
	int len, i;
	glRasterPos2f(x, y);
	len = (int)strlen(string);
	for (i = 0; i<len; i++)
	{
		glutBitmapCharacter(font, string[i]);
	}
}

void Head(float x1, float y1, double r)
{
	float x2, y2, angle;
	glPointSize(1);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1, y1);
	for (angle = -1.58; angle <= 1.625; angle += 0.2)
	{
		x2 = x1 + sin(angle)*r;
		y2 = y1 + cos(angle)*r*1.7;
		glVertex2f(x2, y2);
	}
	glEnd();
}

void Circle(float x1, float y1, double r)
{
	float x2, y2, angle;
	glPointSize(1);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1, y1);
	for (angle = 0; angle <= 3 * 3.14; angle += 0.2)
	{
		x2 = x1 + sin(angle)*r;
		y2 = y1 + cos(angle)*r*1.5;
		glVertex2f(x2, y2);
	}
	glEnd();
}

void DrawText(char * str, float x, float y, float z)
{
	char *c;
	glPushMatrix();
	glTranslated(x, y, 0);
	glScaled(z, 0.4, 0);

	for (c = str; *c != '\0'; c++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
	glPopMatrix();
	glFlush();
}

void Map()
{
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2f(0, 500);
	glVertex2f(500, 500);
	glColor3f(1, 1, 1);
	glVertex2f(500, 0);
	glVertex2f(0, 0);
	glEnd();

	glColor3f(0, 0, 0);
	glLineWidth(10);
	DrawText("M A P", 170, 400, 0.3);
	glLineWidth(5);
	DrawText("> Onam (o)", 50, 170, 0.2);
	DrawText("> Holi (h)", 250, 270, 0.2);
	DrawText("> Dussehra (u)", 250, 170, 0.2);
	DrawText("> Diwali (d)", 50, 270, 0.2);
	DrawText("<- BACK (i)", 50, 70, 0.2);
	DrawText("EXIT (e) ->", 270, 70, 0.2);
	glFlush();
}

void Elevator(int x1, int x2, int y1, int y2)
{
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y1);
	glVertex2f(x2, y2);
	glVertex2f(x1, y2);
	glEnd();
}

void Spray(int x1, int y1, int x2, int y2, int x3, int y3)
{
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glEnd();
}

void Holi()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);

	//////////////////////////////////////////// BACKGROUND ////////////////////////////////////////////
	glColor3f(0.53, 0.80, 0.98);				//Sky
	glBegin(GL_POLYGON);
	glVertex2f(0, 150);
	glVertex2f(500, 150);
	glColor3f(0.53, 0.60, 0.78);
	glVertex2f(500, 500);
	glVertex2f(0, 500);
	glEnd();

	glColor3f(1, 0.49, 0.31);					//Ground
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(500, 0);
	glVertex2f(500, 150);
	glVertex2f(0, 150);
	glEnd();

	//////////////////////////////////////////// Buildings ///////////////////////////////////////////////
	glColor3f(0.39, 0.58, 0.93);				//Building1
	glBegin(GL_POLYGON);
	glVertex2f(425, 150);
	glVertex2f(500, 150);
	glVertex2f(500, 375);
	glVertex2f(425, 375);
	glEnd();

	//////////////////// Windows ///////////////
	glColor3f(0, 0, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(435, 170);
	glVertex2f(455, 170);
	glVertex2f(455, 185);
	glVertex2f(435, 185);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(435, 225);
	glVertex2f(455, 225);
	glVertex2f(455, 240);
	glVertex2f(435, 240);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(435, 280);
	glVertex2f(455, 280);
	glVertex2f(455, 295);
	glVertex2f(435, 295);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(435, 335);
	glVertex2f(455, 335);
	glVertex2f(455, 350);
	glVertex2f(435, 350);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(485, 170);
	glVertex2f(495, 170);
	glVertex2f(495, 185);
	glVertex2f(485, 185);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(485, 225);
	glVertex2f(495, 225);
	glVertex2f(495, 240);
	glVertex2f(485, 240);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(485, 280);
	glVertex2f(495, 280);
	glVertex2f(495, 295);
	glVertex2f(485, 295);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(485, 335);
	glVertex2f(495, 335);
	glVertex2f(495, 350);
	glVertex2f(485, 350);
	glEnd();

	glColor3f(0.5, 0.5, 0.5);
	Elevator(460, 480, 150, 200);				//Elevator


	glColor3f(0.87, 1, 1);						//Building2
	glBegin(GL_POLYGON);
	glVertex2f(375, 150);
	glVertex2f(450, 150);
	glVertex2f(450, 350);
	glVertex2f(375, 350);
	glEnd();
	glPushMatrix();

	////////////////// Windows /////////////////
	glColor3f(0, 0, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(385, 170);
	glVertex2f(395, 170);
	glVertex2f(395, 185);
	glVertex2f(385, 185);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(385, 220);
	glVertex2f(395, 220);
	glVertex2f(395, 235);
	glVertex2f(385, 235);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex2f(385, 270);
	glVertex2f(395, 270);
	glVertex2f(395, 285);
	glVertex2f(385, 285);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex2f(385, 320);
	glVertex2f(395, 320);
	glVertex2f(395, 335);
	glVertex2f(385, 335);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(425, 170);
	glVertex2f(435, 170);
	glVertex2f(435, 185);
	glVertex2f(425, 185);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex2f(425, 220);
	glVertex2f(435, 220);
	glVertex2f(435, 235);
	glVertex2f(425, 235);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex2f(425, 270);
	glVertex2f(435, 270);
	glVertex2f(435, 285);
	glVertex2f(425, 285);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(425, 320);
	glVertex2f(435, 320);
	glVertex2f(435, 335);
	glVertex2f(425, 335);
	glEnd();

	glColor3f(0.5, 0.5, 0.5);
	Elevator(400, 420, 150, 185);				//Elevator

	glLineWidth(2);
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(460, 151);
	glVertex2f(480, 151);
	glVertex2f(480, 364);
	glVertex2f(460, 364);
	glEnd();

	/////////////////////////////////////////// Tree ///////////////////////////////////////////////////
	glPopMatrix();
	glColor3f(0.67, 1, 0.18);					//Leaves
	glBegin(GL_POLYGON);
	glVertex2f(0, 400);
	glVertex2f(25, 350);
	glVertex2f(65, 300);
	glVertex2f(165, 300);
	glVertex2f(210, 350);
	glVertex2f(235, 400);
	glVertex2f(260, 475);
	glVertex2f(265, 500);
	glVertex2f(0, 500);
	glEnd();

	glColor3f(0.871f, 0.722f, 0.529f);			//Trunk
	glBegin(GL_POLYGON);
	glVertex2f(95, 170);
	glVertex2f(167, 170);
	glVertex2f(165, 170);
	glVertex2f(160, 170);
	glVertex2f(155, 170);
	glVertex2f(150, 350);
	glVertex2f(153, 450);
	glVertex2f(156, 500);
	glVertex2f(155, 500);
	glVertex2f(95, 500);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(95, 500);
	glVertex2f(77, 500);
	glVertex2f(78, 450);
	glVertex2f(80, 300);
	glVertex2f(81, 170);
	glVertex2f(95, 170);
	glEnd();

	glBegin(GL_POLYGON);						//Branch
	glVertex2f(145, 350);
	glVertex2f(215, 500);
	glVertex2f(195, 500);
	glVertex2f(215, 475);
	glVertex2f(190, 450);
	glVertex2f(165, 430);
	glVertex2f(140, 400);
	glEnd();
	glColor3f(0.67, 1, 0.18);					//Clipping
	glBegin(GL_POLYGON);
	glVertex2f(205, 500);
	glVertex2f(173, 390);
	glVertex2f(205, 400);
	glVertex2f(240, 500);
	glEnd();

	//////////////////////////////////////////// Wall ///////////////////////////////////////////////////
	glColor3f(0.83, 0.83, 0.83);
	glBegin(GL_POLYGON);
	glVertex2f(0, 80);
	glVertex2f(400, 100);
	glVertex2f(400, 210);
	glVertex2f(125, 225);
	glVertex2f(0, 175);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0, 80);
	glVertex2f(125, 90);
	glVertex2f(0, 65);
	glEnd();

	/////////////////////////////////////////// ANDROIDS ////////////////////////////////////////////////
	glColor3f(0, 1, 0);							//Droid1
	glBegin(GL_POLYGON);						//Head
	glVertex2f(110, 145);
	glVertex2f(110, 155);
	glVertex2f(115, 165);
	glVertex2f(125, 170);
	glVertex2f(135, 165);
	glVertex2f(140, 155);
	glVertex2f(140, 145);
	glEnd();

	glLineWidth(7);
	glBegin(GL_LINES);
	glVertex2f(130, 165);
	glVertex2f(135, 180);
	glVertex2f(125, 165);
	glVertex2f(123, 180);
	glEnd();

	glBegin(GL_POLYGON);						//Body
	glVertex2f(110, 140);
	glVertex2f(110, 80);
	glVertex2f(140, 80);
	glVertex2f(140, 140);
	glEnd();

	glLineWidth(15);							//Legs
	glBegin(GL_LINES);
	glVertex2f(122, 80);
	glVertex2f(120, 55);
	glVertex2f(130, 80);
	glVertex2f(130, 55);
	glEnd();

	glLineWidth(17);							//Hand
	glBegin(GL_LINES);
	glVertex2f(135, 125);
	glVertex2f(155, 140);
	glEnd();

	glColor3f(0, 0, 0);							//Eye
	glPointSize(7);
	glBegin(GL_POINTS);
	glVertex2f(132, 155);
	glEnd();

	glColor3f(0.5, 0.5, 0.5);					//Gun
	glLineWidth(10);
	glBegin(GL_LINES);
	glVertex2f(135, 127);
	glVertex2f(160, 142);
	glEnd();
	glLineWidth(4);
	glBegin(GL_LINES);
	glVertex2f(125, 120);
	glVertex2f(135, 127);
	glEnd();

	glColor3f(0, 1, 0);							//Droid 2
	glBegin(GL_POLYGON);						//Head
	glVertex2f(410, 120);
	glVertex2f(410, 130);
	glVertex2f(415, 140);
	glVertex2f(425, 145);
	glVertex2f(435, 140);
	glVertex2f(440, 130);
	glVertex2f(440, 120);
	glEnd();

	glLineWidth(7);
	glBegin(GL_LINES);
	glVertex2f(420, 140);
	glVertex2f(415, 155);
	glVertex2f(425, 140);
	glVertex2f(427, 155);
	glEnd();

	glBegin(GL_POLYGON);						//Body
	glVertex2f(410, 115);
	glVertex2f(410, 55);
	glVertex2f(440, 55);
	glVertex2f(440, 115);
	glEnd();

	glLineWidth(15);							//Legs
	glBegin(GL_LINES);
	glVertex2f(420, 55);
	glVertex2f(420, 30);
	glVertex2f(428, 55);
	glVertex2f(430, 30);
	glEnd();

	glLineWidth(17);							//Hand
	glBegin(GL_LINES);
	glVertex2f(415, 100);
	glVertex2f(395, 115);
	glEnd();

	glColor3f(0, 0, 0);							//Eye
	glPointSize(7);
	glBegin(GL_POINTS);
	glVertex2f(417, 130);
	glEnd();

	glColor3f(0.5, 0.5, 0.5);					//Gun
	glLineWidth(10);
	glBegin(GL_LINES);
	glVertex2f(415, 102);
	glVertex2f(390, 117);
	glEnd();
	glLineWidth(4);
	glBegin(GL_LINES);
	glVertex2f(415, 102);
	glVertex2f(425, 95);
	glEnd();

	glColor3f(0, 1, 0);							//Droid3
	glBegin(GL_POLYGON);						//Head
	glVertex2f(260, 145);
	glVertex2f(260, 155);
	glVertex2f(265, 165);
	glVertex2f(275, 170);
	glVertex2f(285, 165);
	glVertex2f(290, 155);
	glVertex2f(290, 145);
	glEnd();

	glLineWidth(7);
	glBegin(GL_LINES);
	glVertex2f(280, 165);
	glVertex2f(285, 180);
	glVertex2f(275, 165);
	glVertex2f(273, 180);
	glEnd();

	glBegin(GL_POLYGON);						//Body
	glVertex2f(260, 140);
	glVertex2f(260, 80);
	glVertex2f(290, 80);
	glVertex2f(290, 140);
	glEnd();

	glLineWidth(15);							//Legs
	glBegin(GL_LINES);
	glVertex2f(270, 80);
	glVertex2f(270, 55);
	glVertex2f(280, 80);
	glVertex2f(280, 55);
	glEnd();

	glLineWidth(17);							//Hand
	glBegin(GL_LINES);
	glVertex2f(285, 125);
	glVertex2f(305, 140);
	glVertex2f(265, 125);
	glVertex2f(245, 140);
	glEnd();

	glColor3f(0, 0, 0);							//Eye
	glPointSize(7);
	glBegin(GL_POINTS);
	glVertex2f(278, 155);
	glVertex2f(272, 155);
	glEnd();

	glColor3f(0, 1, 0);							//Droid4
	glBegin(GL_POLYGON);						//Head
	glVertex2f(30, 145);
	glVertex2f(30, 155);
	glVertex2f(35, 165);
	glVertex2f(45, 170);
	glVertex2f(55, 165);
	glVertex2f(60, 155);
	glVertex2f(60, 145);
	glEnd();

	glLineWidth(7);
	glBegin(GL_LINES);
	glVertex2f(50, 165);
	glVertex2f(55, 180);
	glVertex2f(45, 165);
	glVertex2f(43, 180);
	glEnd();

	glBegin(GL_POLYGON);						//Body
	glVertex2f(30, 140);
	glVertex2f(30, 80);
	glVertex2f(60, 80);
	glVertex2f(60, 140);
	glEnd();

	glLineWidth(15);							//Legs
	glBegin(GL_LINES);
	glVertex2f(42, 80);
	glVertex2f(40, 55);
	glVertex2f(50, 80);
	glVertex2f(50, 55);
	glEnd();

	glLineWidth(17);							//Hand
	glBegin(GL_LINES);
	glVertex2f(55, 125);
	glVertex2f(70, 140);
	glEnd();

	glBegin(GL_POINTS);
	glPointSize(10);
	glVertex2f(70, 140);
	glPointSize(8);
	glColor3f(1, 0, 0);
	glVertex2f(70, 140);
	glEnd();

	glColor3f(0, 0, 0);							//Eye
	glPointSize(7);
	glBegin(GL_POINTS);
	glVertex2f(52, 155);
	glEnd();

	glLineWidth(8);								//Platter
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_LINES);
	glVertex2f(45, 110);
	glVertex2f(75, 110);
	glEnd();

	glColor3f(1, 0, 0);							//Color
	glBegin(GL_POLYGON);
	glVertex2f(48, 110);
	glVertex2f(53, 117);
	glVertex2f(67, 126);
	glVertex2f(72, 110);
	glEnd();

	//////////////////////////// Spray1 //////////////////////////////
	glPushMatrix();							//Save
	for (i = 0; i <= 3; i++)
	{
		glColor3f(0.83, 0.83, 0.83);
		Spray(160, 142, 178, 144, 180, 150);
		glTranslated(20, 5, 0);
		glColor3f(1, 0, 0);
		Spray(160, 142, 178, 144, 180, 150);
		for (k = 0; k <= 100000000; k++);
		glFlush();
	}
	glColor3f(0.83, 0.83, 0.83);
	Spray(160, 142, 178, 144, 180, 150);
	glPopMatrix();							//Load

	glColor3f(1, 0, 0);						//Color Change
	glBegin(GL_POLYGON);					//Head	
	glVertex2f(260, 145);
	glVertex2f(260, 155);
	glVertex2f(265, 165);
	glColor3f(0, 1, 0);
	glVertex2f(275, 170);
	glVertex2f(285, 165);
	glVertex2f(290, 155);
	glVertex2f(290, 145);
	glEnd();

	glLineWidth(7);
	glBegin(GL_LINES);
	glVertex2f(280, 165);
	glVertex2f(285, 180);
	glVertex2f(275, 165);
	glColor3f(1, 0, 0);
	glVertex2f(273, 180);
	glEnd();

	glLineWidth(17);							//Hand
	glBegin(GL_LINES);
	glVertex2f(285, 125);
	glVertex2f(305, 140);
	glVertex2f(265, 125);
	glColor3f(1, 0, 0);
	glVertex2f(245, 140);
	glEnd();

	glBegin(GL_POLYGON);						//Body
	glColor3f(1, 0, 0);
	glVertex2f(260, 140);
	glColor3f(0, 1, 0);
	glVertex2f(260, 80);
	glVertex2f(290, 80);
	glVertex2f(290, 140);
	glEnd();

	glColor3f(0, 0, 0);							//Eye
	glPointSize(7);
	glBegin(GL_POINTS);
	glVertex2f(278, 155);
	glVertex2f(272, 155);
	glEnd();
	for (k = 0; k <= 100000000; k++);
	glFlush();

	//////////////////////////// Spray2 //////////////////////////////
	glPushMatrix();							//Save
	for (i = 0; i <= 4; i++)
	{
		glColor3f(0.83, 0.83, 0.83);
		Spray(390, 117, 370, 115, 368, 109);
		glTranslated(-20, 8, 0);
		glColor3f(1, 1, 0);
		Spray(390, 117, 370, 115, 368, 109);
		for (k = 0; k <= 100000000; k++);
		glFlush();
	}
	glColor3f(0.83, 0.83, 0.83);
	Spray(390, 117, 370, 115, 368, 109);
	glPopMatrix();							//Load

	glColor3f(1, 0, 0);						//Color Change
	glBegin(GL_POLYGON);
	glVertex2f(260, 145);
	glVertex2f(260, 155);
	glVertex2f(265, 165);
	glColor3f(1, 1, 0);
	glVertex2f(275, 170);
	glVertex2f(285, 165);
	glVertex2f(290, 155);
	glVertex2f(290, 145);
	glEnd();

	glColor3f(0, 1, 0);
	glLineWidth(7);
	glBegin(GL_LINES);
	glVertex2f(280, 165);
	glColor3f(1, 1, 0);
	glVertex2f(285, 180);
	glColor3f(0, 1, 0);
	glVertex2f(275, 165);
	glColor3f(1, 0, 0);
	glVertex2f(273, 180);
	glEnd();

	glLineWidth(17);							//Hand
	glBegin(GL_LINES);
	glColor3f(0, 1, 0);
	glVertex2f(285, 125);
	glColor3f(1, 1, 0);
	glVertex2f(305, 140);
	glColor3f(0, 1, 0);
	glVertex2f(265, 125);
	glColor3f(1, 0, 0);
	glVertex2f(245, 140);
	glEnd();

	glBegin(GL_POLYGON);						//Body
	glColor3f(1, 0, 0);
	glVertex2f(260, 140);
	glColor3f(0, 1, 0);
	glVertex2f(260, 80);
	glVertex2f(290, 80);
	glColor3f(1, 1, 0);
	glVertex2f(290, 140);
	glEnd();

	glColor3f(0, 0, 0);							//Eye
	glPointSize(7);
	glBegin(GL_POINTS);
	glVertex2f(278, 155);
	glVertex2f(272, 155);
	glEnd();
	for (k = 0; k <= 100000000; k++);
	glFlush();

	//////////////////////////// Elevators ///////////////////////////
	glPushMatrix();							//Save
	for (i = 0; i <= 32; i++)
	{
		glColor3f(0.39, 0.58, 0.93);
		Elevator(460, 480, 150, 200);
		glTranslated(0, 5, 0);
		glColor3f(0.5, 0.5, 0.5);
		Elevator(460, 480, 150, 200);
		for (k = 0; k <= 100000000; k++);
		glFlush();
	}
	glPopMatrix();							//Load
	for (k = 0; k <= 100000000; k++);
	glFlush();
	Map();
}

void Start()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);
	glColor3f(0, 0.9, 0);
	glPointSize(10);
	DrawText("COMPUTER GRAPHICS PROJECT", 30, 450, 0.22);
	DrawText("FESTIVALS OF INDIA", 80, 400, 0.22);

	glBegin(GL_POLYGON);
	glVertex2f(260, 200);
	glVertex2f(260, 300);
	glVertex2f(300, 300);
	glVertex2f(300, 200);
	glEnd();
	Head(280, 310, 20);

	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex2f(270, 320);
	glVertex2f(268, 350);
	glVertex2f(286, 320);
	glVertex2f(288, 350);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
	glVertex2f(270, 200);
	glVertex2f(270, 160);
	glVertex2f(290, 200);
	glVertex2f(290, 160);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(255, 290);
	glVertex2f(240, 330);
	glVertex2f(305, 290);
	glVertex2f(305, 250);
	glEnd();

	glPointSize(10);
	glColor3f(0, 0, 0);
	glBegin(GL_POINTS);
	glVertex2f(275, 320);
	glVertex2f(295, 320);
	glEnd();
	glFlush();

	glColor3f(0, 0.9, 0);
	Circle(400, 350, 30);
	Circle(430, 350, 30);
	Circle(370, 350, 30);
	Circle(430, 300, 30);
	Circle(370, 300, 30);
	Circle(400, 300, 30);
	Circle(350, 325, 30);
	Circle(450, 325, 30);

	glColor3f(0.2, 0.2, 0.2);
	glLineWidth(6);
	DrawText("W I T H", 370, 340, 0.1);
	DrawText("A N D R O I D S", 330, 295, 0.1);

	glColor3f(0, 0.8, 0);
	glBegin(GL_POLYGON);
	glVertex2f(60, 50);
	glVertex2f(10, 75);
	glVertex2f(60, 100);
	glVertex2f(230, 100);
	glVertex2f(280, 75);
	glVertex2f(230, 50);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(90, 150);
	glVertex2f(40, 175);
	glVertex2f(90, 200);
	glVertex2f(190, 200);
	glVertex2f(240, 175);
	glVertex2f(190, 150);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(90, 250);
	glVertex2f(40, 275);
	glVertex2f(90, 300);
	glVertex2f(190, 300);
	glVertex2f(240, 275);
	glVertex2f(190, 250);
	glEnd();

	glLineWidth(4);
	glColor3f(0.2, 0.2, 0.2);
	glPointSize(4);
	DrawText("P I Y U S H", 103, 256, 0.08);
	DrawText("P R A V E E N", 93, 156, 0.08);
	DrawText("P R I Y A N G S H U", 75, 56, 0.08);

	glColor3f(0, 0.8, 0);
	glBegin(GL_POLYGON);
	glVertex2f(350, 50);
	glVertex2f(450, 50);
	glVertex2f(450, 230);
	glVertex2f(350, 230);
	glEnd();

	glLineWidth(4);
	glColor3f(0.2, 0.2, 0.2);
	glPointSize(4);
	DrawText("C l i c k  ' i ' ", 360, 170, 0.06);
	DrawText(" for instructions", 350, 85, 0.08);
	glFlush();
}

void Instructions()
{
	glColor3f(0, 0.8, 0);				//White Screen
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glColor3f(0, 0, 0.8);
	glVertex2f(0, 500);
	glVertex2f(500, 500);
	glColor3f(0, 0.8, 0);
	glVertex2f(500, 0);
	glEnd();
	glFlush();

	glColor3f(0.95, 0.95, 0);		//Scroll
	Circle(85, 480, 5);
	Circle(415, 480, 5);

	glColor3f(0, 0, 0);
	glLineWidth(4);
	glBegin(GL_LINES);
	glVertex2f(85, 375);
	glVertex2f(85, 490);
	glVertex2f(415, 375);
	glVertex2f(415, 490);
	glEnd();

	glColor3f(0.95, 0.95, 0);
	Circle(85, 453, 5);
	Circle(415, 453, 5);
	glBegin(GL_POLYGON);
	glVertex2f(85, 380);
	glVertex2f(80, 385);
	glVertex2f(80, 480);
	glVertex2f(420, 480);
	glVertex2f(420, 385);
	glVertex2f(415, 380);
	glEnd();
	Circle(85, 386, 5);
	Circle(415, 386, 5);

	glColor3f(0, 0.9, 0);
	glLineWidth(15);
	glBegin(GL_LINES);				//Hand Left
	glVertex2f(68, 445);
	glVertex2f(80, 445);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(429, 445);			//Hand Right
	glVertex2f(420, 445);
	glEnd();

	glColor3f(0, 0, 0);
	glLineWidth(10);
	DrawText("I N S T R U C T I O N S", 100, 410, 0.15);

	glColor3f(0, 0.9, 0);			//Androids
	glBegin(GL_POLYGON);
	glVertex2f(50, 400);
	glVertex2f(70, 400);
	glVertex2f(70, 450);
	glVertex2f(50, 450);
	glEnd();
	Head(60, 455, 10);
	glBegin(GL_POLYGON);
	glVertex2f(450, 400);
	glVertex2f(430, 400);
	glVertex2f(430, 450);
	glVertex2f(450, 450);
	glEnd();
	Head(440, 455, 10);

	glLineWidth(15);
	glBegin(GL_LINES);
	glVertex2f(71, 435);
	glVertex2f(80, 428);
	glVertex2f(431, 435);
	glVertex2f(420, 428);
	glEnd();

	glLineWidth(4);
	glBegin(GL_LINES);
	glVertex2f(67, 467);
	glVertex2f(69, 474);
	glVertex2f(63, 467);
	glVertex2f(63, 474);
	glVertex2f(433, 467);
	glVertex2f(431, 474);
	glVertex2f(437, 467);
	glVertex2f(437, 474);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
	glVertex2f(65, 400);
	glVertex2f(65, 380);
	glVertex2f(58, 400);
	glVertex2f(58, 380);
	glVertex2f(435, 400);
	glVertex2f(435, 380);
	glVertex2f(442, 400);
	glVertex2f(442, 380);
	glEnd();

	glColor3f(0, 0, 0);
	glPointSize(6);
	glBegin(GL_POINTS);
	glVertex2f(64, 463);
	glVertex2f(436, 463);
	glEnd();

	glLineWidth(5);
	DrawText(">> Press 'm' for MAP", 70, 300, 0.2);
	DrawText(">> When in Map ", 70, 245, 0.2);
	DrawText("  > Press the given key for", 70, 190, 0.2);
	DrawText("    the desired festival", 70, 135, 0.2);
	DrawText(">> Press ' m ' to go back ", 70, 80, 0.2);
	DrawText("    to MAP", 70, 25, 0.2);

	glFlush();
}

void Exit()
{
	glColor3f(0.4, 0, 0.4);					//Stage
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(500, 0);
	glVertex2f(500, 300);
	glVertex2f(0, 300);
	glEnd();

	glColor3f(0.6, 0.6, 0.6);					//BG
	glBegin(GL_POLYGON);
	glVertex2f(0, 300);
	glVertex2f(500, 300);
	glColor3f(0.4, 0.4, 0.4);
	glVertex2f(500, 500);
	glVertex2f(0, 500);
	glEnd();

	glColor3f(0, 0, 0);
	DrawText("    Hope You ", 100, 450, 0.2);
	DrawText("   Enjoyed It !!!", 100, 350, 0.2);

	glColor3f(1, 0, 0);					//Curtain
	glBegin(GL_POLYGON);
	glVertex2f(0, 280);
	glVertex2f(50, 280);
	glColor3f(0.4, 0, 0);
	glVertex2f(50, 500);
	glVertex2f(0, 500);
	glEnd();
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(450, 280);
	glVertex2f(500, 280);
	glColor3f(0.4, 0, 0);
	glVertex2f(500, 500);
	glVertex2f(450, 500);
	glEnd();

	////////////////////////////// ANDROIDS ///////////////////////////////

	glColor3f(0, 0.5, 0);					//Droid1
	glBegin(GL_POLYGON);					//Body
	glVertex2f(230, 80);
	glVertex2f(270, 80);
	glVertex2f(270, 150);
	glVertex2f(230, 150);
	glEnd();

	Head(250, 155, 20);						//Head
	glLineWidth(6);
	glBegin(GL_LINES);
	glVertex2f(240, 169);
	glVertex2f(234, 195);
	glVertex2f(260, 168);
	glVertex2f(267, 195);
	glEnd();

	glLineWidth(10);						//Hands
	glBegin(GL_LINES);
	glVertex2f(228, 146);
	glVertex2f(220, 115);
	glVertex2f(272, 146);
	glVertex2f(280, 115);
	glEnd();

	glLineWidth(10);						//Legs
	glBegin(GL_LINES);
	glVertex2f(236, 80);
	glVertex2f(236, 55);
	glVertex2f(264, 80);
	glVertex2f(264, 55);
	glEnd();

	glColor3f(0, 0.5, 0);					//Droid2
	glBegin(GL_POLYGON);					//Body
	glVertex2f(170, 80);
	glVertex2f(210, 80);
	glVertex2f(210, 150);
	glVertex2f(170, 150);
	glEnd();

	Head(190, 155, 20);						//Head
	glLineWidth(6);
	glBegin(GL_LINES);
	glVertex2f(180, 169);
	glVertex2f(174, 195);
	glVertex2f(200, 168);
	glVertex2f(207, 195);
	glEnd();

	glLineWidth(10);						//Hands
	glBegin(GL_LINES);
	glVertex2f(168, 146);
	glVertex2f(160, 115);
	glVertex2f(212, 146);
	glVertex2f(220, 115);
	glEnd();

	glLineWidth(10);						//Legs
	glBegin(GL_LINES);
	glVertex2f(176, 80);
	glVertex2f(176, 55);
	glVertex2f(204, 80);
	glVertex2f(204, 55);
	glEnd();

	glColor3f(0, 0.5, 0);					//Droid3
	glBegin(GL_POLYGON);					//Body
	glVertex2f(290, 80);
	glVertex2f(330, 80);
	glVertex2f(330, 150);
	glVertex2f(290, 150);
	glEnd();

	Head(310, 155, 20);						//Head
	glLineWidth(6);
	glBegin(GL_LINES);
	glVertex2f(300, 169);
	glVertex2f(294, 195);
	glVertex2f(320, 168);
	glVertex2f(327, 195);
	glEnd();

	glLineWidth(10);						//Hands
	glBegin(GL_LINES);
	glVertex2f(288, 146);
	glVertex2f(280, 115);
	glVertex2f(332, 146);
	glVertex2f(340, 115);
	glEnd();

	glLineWidth(10);						//Legs
	glBegin(GL_LINES);
	glVertex2f(296, 80);
	glVertex2f(296, 55);
	glVertex2f(324, 80);
	glVertex2f(324, 55);
	glEnd();

	glColor3f(0, 0, 0);
	glPointSize(6);
	glBegin(GL_POINTS);
	glVertex2f(302, 167);
	glVertex2f(318, 167);
	glVertex2f(242, 167);
	glVertex2f(258, 167);
	glVertex2f(198, 167);
	glVertex2f(182, 167);
	glEnd();

	glFlush();

	////////////////////////////// MOTION ///////////////////////////////

	for (i = 1; i <= 7; i++)
	{
		glColor3f(0.4, 0, 0.4);					//Stage
		glBegin(GL_POLYGON);
		glVertex2f(0, 0);
		glVertex2f(500, 0);
		glVertex2f(500, 270);
		glVertex2f(0, 270);
		glEnd();

		glColor3f(0, 0.5, 0);
		if (i % 2 != 0)
		{
			glColor3f(0, 0.5, 0);					//Droid1
			glBegin(GL_POLYGON);					//Body
			glVertex2f(230, 80);
			glVertex2f(270, 80);
			glVertex2f(270, 150);
			glVertex2f(230, 150);
			glEnd();

			Head(250, 155, 20);						//Head
			glLineWidth(6);
			glBegin(GL_LINES);
			glVertex2f(240, 169);
			glVertex2f(234, 195);
			glVertex2f(260, 168);
			glVertex2f(267, 195);
			glEnd();

			glLineWidth(10);						//Hands
			glBegin(GL_LINES);
			glVertex2f(228, 146);
			glVertex2f(220, 115);
			glVertex2f(272, 146);
			glVertex2f(280, 115);
			glEnd();

			glLineWidth(10);						//Legs
			glBegin(GL_LINES);
			glVertex2f(236, 80);
			glVertex2f(236, 55);
			glVertex2f(264, 80);
			glVertex2f(264, 55);
			glEnd();

			glColor3f(0, 0.5, 0);					//Droid2
			glBegin(GL_POLYGON);					//Body
			glVertex2f(170, 80);
			glVertex2f(210, 80);
			glVertex2f(210, 150);
			glVertex2f(170, 150);
			glEnd();

			Head(190, 155, 20);						//Head
			glLineWidth(6);
			glBegin(GL_LINES);
			glVertex2f(180, 169);
			glVertex2f(174, 195);
			glVertex2f(200, 168);
			glVertex2f(207, 195);
			glEnd();

			glLineWidth(10);						//Hands
			glBegin(GL_LINES);
			glVertex2f(168, 146);
			glVertex2f(160, 115);
			glVertex2f(212, 146);
			glVertex2f(220, 115);
			glEnd();

			glLineWidth(10);						//Legs
			glBegin(GL_LINES);
			glVertex2f(176, 80);
			glVertex2f(176, 55);
			glVertex2f(204, 80);
			glVertex2f(204, 55);
			glEnd();

			glColor3f(0, 0.5, 0);					//Droid3
			glBegin(GL_POLYGON);					//Body
			glVertex2f(290, 80);
			glVertex2f(330, 80);
			glVertex2f(330, 150);
			glVertex2f(290, 150);
			glEnd();

			Head(310, 155, 20);						//Head
			glLineWidth(6);
			glBegin(GL_LINES);
			glVertex2f(300, 169);
			glVertex2f(294, 195);
			glVertex2f(320, 168);
			glVertex2f(327, 195);
			glEnd();

			glLineWidth(10);						//Hands
			glBegin(GL_LINES);
			glVertex2f(288, 146);
			glVertex2f(280, 115);
			glVertex2f(332, 146);
			glVertex2f(340, 115);
			glEnd();

			glLineWidth(10);						//Legs
			glBegin(GL_LINES);
			glVertex2f(296, 80);
			glVertex2f(296, 55);
			glVertex2f(324, 80);
			glVertex2f(324, 55);
			glEnd();

			glColor3f(0, 0, 0);
			glPointSize(6);
			glBegin(GL_POINTS);
			glVertex2f(302, 167);
			glVertex2f(318, 167);
			glVertex2f(242, 167);
			glVertex2f(258, 167);
			glVertex2f(198, 167);
			glVertex2f(182, 167);
			glEnd();
		}
		if (i % 2 == 0)
		{
			glColor3f(0, 0.5, 0);					//Droid1
			glBegin(GL_POLYGON);					//Body
			glVertex2f(230, 70);
			glVertex2f(270, 70);
			glVertex2f(270, 110);
			glVertex2f(230, 110);
			glEnd();

			glLineWidth(6);							//Head
			glBegin(GL_LINES);
			glVertex2f(240, 89);
			glVertex2f(234, 75);
			glVertex2f(260, 88);
			glVertex2f(267, 75);
			glEnd();

			glLineWidth(10);						//Hands
			glBegin(GL_LINES);
			glVertex2f(228, 110);
			glVertex2f(220, 115);
			glVertex2f(272, 110);
			glVertex2f(280, 115);
			glEnd();

			glLineWidth(10);						//Legs
			glBegin(GL_LINES);
			glVertex2f(236, 80);
			glVertex2f(236, 55);
			glVertex2f(264, 80);
			glVertex2f(264, 55);
			glEnd();

			glColor3f(0, 0.5, 0);					//Droid2
			glBegin(GL_POLYGON);					//Body
			glVertex2f(170, 70);
			glVertex2f(210, 70);
			glVertex2f(210, 110);
			glVertex2f(170, 110);
			glEnd();

			glLineWidth(6);							//Head
			glBegin(GL_LINES);
			glVertex2f(180, 89);
			glVertex2f(174, 75);
			glVertex2f(200, 88);
			glVertex2f(207, 75);
			glEnd();

			glLineWidth(10);						//Hands
			glBegin(GL_LINES);
			glVertex2f(168, 110);
			glVertex2f(160, 115);
			glVertex2f(212, 110);
			glVertex2f(220, 115);
			glEnd();

			glLineWidth(10);						//Legs
			glBegin(GL_LINES);
			glVertex2f(176, 80);
			glVertex2f(176, 55);
			glVertex2f(204, 80);
			glVertex2f(204, 55);
			glEnd();

			glColor3f(0, 0.5, 0);					//Droid3
			glBegin(GL_POLYGON);					//Body
			glVertex2f(290, 70);
			glVertex2f(330, 70);
			glVertex2f(330, 110);
			glVertex2f(290, 110);
			glEnd();

			glLineWidth(6);							//Head
			glBegin(GL_LINES);
			glVertex2f(300, 89);
			glVertex2f(294, 75);
			glVertex2f(320, 88);
			glVertex2f(327, 75);
			glEnd();

			glLineWidth(10);						//Hands
			glBegin(GL_LINES);
			glVertex2f(288, 110);
			glVertex2f(280, 115);
			glVertex2f(332, 110);
			glVertex2f(340, 115);
			glEnd();

			glLineWidth(10);						//Legs
			glBegin(GL_LINES);
			glVertex2f(296, 80);
			glVertex2f(296, 55);
			glVertex2f(324, 80);
			glVertex2f(324, 55);
			glEnd();
		}
		for (k = 0; k < 500000000; k++);
		glFlush();
	}
	for (k = 0; k < 1000000000; k++);
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(0, 500);
	glVertex2f(500, 500);
	glVertex2f(500, 0);
	glEnd();
	glColor3f(0, 1, 0);
	DrawText("Press ' r ' to Restart", 120, 250, 0.2);
	glFlush();
}

void KeyBoard(unsigned char key, int x, int y)
{
	if (key == 'i')
		Instructions();
	if (key == 'm')
		Map();
	//if (key == 'o')
		//Onam();
	if (key == 'h')
		Holi();
	//if (key == 'd')
		//Diwali();
	//if (key == 'u')
		//Dussehra();
	if (key == 'e')
		Exit();
	if (key == 'r')
	Start();
	if (key == 'n')
		Start();
}

void Start0()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glColor3f(0, 1, 0);
	glVertex2f(0, 500);
	glColor3f(0, 0, 1);
	glVertex2f(500, 500);
	glColor3f(0, 1, 1);
	glVertex2f(500, 0);
	glEnd();
	glColor3f(0, 0, 0);
	glLineWidth(3);
	output(145, 450, "DAYANANDA SAGAR COLLEGE OF ENGINEERING", GLUT_BITMAP_TIMES_ROMAN_24);
	output(159, 420, "Department of Computer Science and Engineering", GLUT_BITMAP_TIMES_ROMAN_24);
	output(195, 390, "Computer Graphics Project", GLUT_BITMAP_TIMES_ROMAN_24);
	output(150, 360, "Project Title:", GLUT_BITMAP_TIMES_ROMAN_24);
	output(200, 330, "INCREDIBLE INDIA", GLUT_BITMAP_TIMES_ROMAN_24);
	output(150, 300, "Project By:", GLUT_BITMAP_TIMES_ROMAN_24);
	output(170, 270, "Piyush Ranjan", GLUT_BITMAP_TIMES_ROMAN_24);
	output(255, 270, "1DS14CS071", GLUT_BITMAP_TIMES_ROMAN_24);
	output(170, 240, "Praveen Chandran", GLUT_BITMAP_TIMES_ROMAN_24);
	output(255, 240, "1DS14CS074", GLUT_BITMAP_TIMES_ROMAN_24);
	output(170, 210, "Priyangshu Roy", GLUT_BITMAP_TIMES_ROMAN_24);
	output(255, 210, "1DS14CS076", GLUT_BITMAP_TIMES_ROMAN_24);
	output(150, 160, "Project Guide:", GLUT_BITMAP_TIMES_ROMAN_24);
	output(170, 120, "Prof Kusuma", GLUT_BITMAP_TIMES_ROMAN_24);
	output(250, 120, "Professor,DSCE", GLUT_BITMAP_TIMES_ROMAN_24);
	output(170, 80, "Prof Ravichandran", GLUT_BITMAP_TIMES_ROMAN_24);
	output(250, 80, "Assistant Professor,DSCE", GLUT_BITMAP_TIMES_ROMAN_24);
	output(380, 50, "Click n for NEXT", GLUT_BITMAP_TIMES_ROMAN_24);
	glFlush();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
	Start0();
	glFlush();
}

void main(int argc, char** argv)
{
	int id;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	id = glutCreateWindow("FESTIVALS");
	glutDisplayFunc(display);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POINT_SMOOTH);
	glutKeyboardFunc(KeyBoard);
	glutMainLoop();
}
