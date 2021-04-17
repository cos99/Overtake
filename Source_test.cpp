#include <windows.h>
#include <gl/freeglut.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

#define BETA 40
#define TETA 120
#define ALPHA -600

int keybBackground, currentColor;
//Coordonate pentru centrele de greutate ale rotilor
GLdouble xC1W1 = 0.0, yC1W1 = 0.0, xC1W2 = 0.0, yC1W2 = 0.0, xC2W1 = 0.0, yC2W1 = 0.0, xC2W2 = 0.0, yC2W2 = 0.0;


//Liste de display
void init(void)  // initializare fereastra de vizualizare
{
	//glClearColor(0.85, 0.85, 0.85, 0.0); // precizeaza culoarea de fond a ferestrei de vizualizare
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION); // se precizeaza este vorba de o reprezentare 2D, realizata prin proiectie ortogonala
	gluOrtho2D(0.0, 1700.0, 0.0, 900.0); // sunt indicate coordonatele extreme ale ferestrei de vizualizare
	glClear(GL_COLOR_BUFFER_BIT); // reprezentare si colorare fereastra de vizualizare

}

GLuint regHexC1W1, regHexC1W2, regHexC2W1, regHexC2W2;
GLuint regHexC1W1C, regHexC1W2C, regHexC2W1C, regHexC2W2C;
const double TWO_PI = 6.2831853;


class scrPt
{
public:
	GLint x, y;
};

//Generare lista de display pentru prima roata a celei de a doua masini
void wheelsC2W1(void)
{
	scrPt hexVertex;
	GLdouble hexTheta;
	GLint k;

	glClearColor(1.0, 1.0, 1.0, 1.0);
	regHexC2W1 = glGenLists(1);
	glNewList(regHexC2W1, GL_COMPILE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	for (k = 0; k < 200; k++)
	{
		hexTheta = TWO_PI * k / 200;
		hexVertex.x = 550 + 20 * cos(hexTheta);
		hexVertex.y = 200 + 20 * sin(hexTheta);
		glVertex2i(hexVertex.x, hexVertex.y);
		xC2W1 += hexVertex.x;
		yC2W1 += hexVertex.y;
	}
	xC2W1 = xC2W1 / 200;
	yC2W1 = yC2W1 / 200;
	glEnd();

	glEndList();

}

//Generare lista de display pentru a doua roata a celei de a doua masini
void wheelsC2W2(void)
{
	scrPt hexVertex;
	GLdouble hexTheta;
	GLint k;

	glClearColor(1.0, 1.0, 1.0, 1.0);
	regHexC2W2 = glGenLists(1);
	glNewList(regHexC2W2, GL_COMPILE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	for (k = 0; k < 200; k++)
	{
		hexTheta = TWO_PI * k / 200;
		hexVertex.x = 650 + 20 * cos(hexTheta);
		hexVertex.y = 200 + 20 * sin(hexTheta);
		glVertex2i(hexVertex.x, hexVertex.y);
		xC2W2 += hexVertex.x;
		yC2W2 += hexVertex.y;
	}
	xC2W2 = xC2W2 / 200;
	yC2W2 = yC2W2 / 200;
	glEnd();

	glEndList();

}

//Generare lista de display pentru prima roata a primei masini
void wheelsC1W1(void)
{
	scrPt hexVertex;
	GLdouble hexTheta;
	GLint k;

	glClearColor(1.0, 1.0, 1.0, 1.0);
	regHexC1W1 = glGenLists(1);
	glNewList(regHexC1W1, GL_COMPILE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	for (k = 0; k < 200; k++)
	{
		hexTheta = TWO_PI * k / 200;
		hexVertex.x = 250 + 20 * cos(hexTheta);
		hexVertex.y = 200 + 20 * sin(hexTheta);
		glVertex2i(hexVertex.x, hexVertex.y);
		xC1W1 += hexVertex.x;
		yC1W1 += hexVertex.y;
	}
	xC1W1 = xC1W1 / 200;
	yC1W1 = yC1W1 / 200;
	glEnd();

	glEndList();

}

//Generare lista de display pentru a doua roata a primei masini
void wheelsC1W2(void)
{
	scrPt hexVertex;
	GLdouble hexTheta;
	GLint k;

	glClearColor(1.0, 1.0, 1.0, 1.0);
	regHexC1W2 = glGenLists(1);
	glNewList(regHexC1W2, GL_COMPILE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	for (k = 0; k < 200; k++)
	{
		hexTheta = TWO_PI * k / 200;
		hexVertex.x = 350 + 20 * cos(hexTheta);
		hexVertex.y = 200 + 20 * sin(hexTheta);
		glVertex2i(hexVertex.x, hexVertex.y);
		xC1W2 += hexVertex.x;
		yC1W2 += hexVertex.y;
	}
	xC1W2 = xC1W2 / 200;
	yC1W2 = yC1W2 / 200;
	glEnd();

	glEndList();

}


//Generare lista de display pentru capacul primei roti a masinii cu numarul 2
void wheelcoverC2W1(void)
{
	scrPt hexVertex;
	GLdouble hexTheta;
	GLint k;

	glClearColor(1.0, 1.0, 1.0, 1.0);
	regHexC2W1C = glGenLists(1);
	glNewList(regHexC2W1C, GL_COMPILE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.85, 0.85, 0.85);
	glBegin(GL_POLYGON);
	for (k = 0; k < 200; k++)
	{
		hexTheta = TWO_PI * k / 200;
		hexVertex.x = 550 + 15 * cos(hexTheta);
		hexVertex.y = 200 + 15 * sin(hexTheta);
		glVertex2i(hexVertex.x, hexVertex.y);
	}
	glEnd();

	glEndList();

}

//Generare lista de display pentru capacul celei de a doua roata a masinii cu numarul 2
void wheelcoverC2W2(void)
{
	scrPt hexVertex;
	GLdouble hexTheta;
	GLint k;

	glClearColor(1.0, 1.0, 1.0, 1.0);
	regHexC2W2C = glGenLists(1);
	glNewList(regHexC2W2C, GL_COMPILE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.85, 0.85, 0.85);
	glBegin(GL_POLYGON);
	for (k = 0; k < 200; k++)
	{
		hexTheta = TWO_PI * k / 200;
		hexVertex.x = 650 + 15 * cos(hexTheta);
		hexVertex.y = 200 + 15 * sin(hexTheta);
		glVertex2i(hexVertex.x, hexVertex.y);
	}
	glEnd();

	glEndList();

}


//Generare lista de display pentru capacul primei roti a primei masini
void wheelcoverC1W1(void)
{
	scrPt hexVertex;
	GLdouble hexTheta;
	GLint k;

	glClearColor(1.0, 1.0, 1.0, 1.0);
	regHexC1W1C = glGenLists(1);
	glNewList(regHexC1W1C, GL_COMPILE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.85, 0.85, 0.85);
	glBegin(GL_POLYGON);
	for (k = 0; k < 200; k++)
	{
		hexTheta = TWO_PI * k / 200;
		hexVertex.x = 250 + 15 * cos(hexTheta);
		hexVertex.y = 200 + 15 * sin(hexTheta);
		glVertex2i(hexVertex.x, hexVertex.y);
	}
	glEnd();

	glEndList();

}

//Generare lista de display pentru capacul celei de a doua roata a primei masini
void wheelcoverC1W2(void)
{
	scrPt hexVertex;
	GLdouble hexTheta;
	GLint k;

	glClearColor(1.0, 1.0, 1.0, 1.0);
	regHexC1W2C = glGenLists(1);
	glNewList(regHexC1W2C, GL_COMPILE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.85, 0.85, 0.85);
	glBegin(GL_POLYGON);
	for (k = 0; k < 200; k++)
	{
		hexTheta = TWO_PI * k / 200;
		hexVertex.x = 350 + 15 * cos(hexTheta);
		hexVertex.y = 200 + 15 * sin(hexTheta);
		glVertex2i(hexVertex.x, hexVertex.y);
	}
	glEnd();

	glEndList();

}


//Variabile ajutatoare pentru:
double where = 0.0; //pozitia curenta a masinii
double movement = 0.0; // miscarea drumuul drumului
double rotationAngle = 0.0; //rotatia primei masini
double carTranslationY = 0.0, carTranslationX = 0.0; //translatia primei masinii
double teta = TETA; // ajustarea valorii carTranslationX
double beta = BETA; //ajustarea valorii rotationAngle
double alpha = ALPHA; //ajustarea valorii movement
double oldTime = 0.0; //calcularea frame-urilor
double deltaTime = 0.0; //calcularea frameu-urilor
double wheelsRotation = 0.0; //rotatia rotiilor
double RC1 = 0.2, GC1 = 0.2, BC1 = 0.2, RC2 = 0.2, GC2 = 0.2, BC2 = 0.2; //Culori pentru masina
double farB = 0.6;//Culoarea farului

void time(void)
{
	double frameTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
	deltaTime = frameTime - oldTime;
	oldTime = frameTime;
}

void desen(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


	glLineWidth(6);
	glColor3f(0.0, 0.0, 0.0);
	glRecti(-20, 50, 1720, 850); //marginile durmului


	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(6);
	//Miscarea drumului
	glPushMatrix();
	glTranslated(movement, 425, 0.0);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(20, 0xF0F0);
	glBegin(GL_LINES);
	glVertex2f(INFINITE, 0);
	glVertex2f(0, 0);
	glEnd();
	glDisable(GL_LINE_STIPPLE);
	glPopMatrix();




	glLineWidth(3);
	glColor3f(0.0, 0.0, 0.0);
	//A doua masina
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(RC2, GC2, BC2);
	glRecti(500, 200, 700, 280); //corpul masinii
	glColor3f(1.0, 1.0, 1.0);
	glRecti(550, 280, 600, 300); //culoare geam 1
	glRecti(600, 280, 650, 300); //culoare geam 2
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0, 0.0, 0.0);
	glRecti(550, 280, 600, 300); //contur geam 1
	glRecti(600, 280, 650, 300); //contur geam 2
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1.0, 1.0, farB);
	glRecti(680, 260, 702, 282); //farul masinii
	glBegin(GL_TRIANGLES); //lumina emisa de far
	glVertex3f(680, 271, 0.0);
	glVertex3f(750, 310, 0.0);
	glVertex3f(750, 230, 0.0);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0, 0.0, 0.0);



	//Capacul si roata au acelasi centru de greutate
	//Roata 1 masina 2
	glPushMatrix();
	glTranslated(xC2W1, yC2W1, 0);
	glRotated(-wheelsRotation, 0, 0, 1);
	glTranslated(-xC2W1, -yC2W1, 0);
	glCallList(regHexC2W1); //roata
	glCallList(regHexC2W1C); //capacul rotii
	glBegin(GL_LINES); //detalii pentru capacul masinii
	glVertex2i(535, 200);
	glVertex2i(565, 200);
	glVertex2i(550, 215);
	glVertex2i(550, 185);
	glVertex2i(540, 210);
	glVertex2i(560, 190);
	glVertex2i(560, 210);
	glVertex2i(540, 190);
	glEnd();
	glPopMatrix();



	//Roata 2 masina 2
	glPushMatrix();
	glTranslated(xC2W2, yC2W2, 0);
	glRotated(-wheelsRotation, 0, 0, 1);
	glTranslated(-xC2W2, -yC2W2, 0);
	glCallList(regHexC2W2); //roata
	glCallList(regHexC2W2C); //capacul rotii
	glBegin(GL_LINES); //detalii pentru capacul masinii
	glVertex2i(635, 200);
	glVertex2i(665, 200);
	glVertex2i(650, 215);
	glVertex2i(650, 185);
	glVertex2i(640, 210);
	glVertex2i(660, 190);
	glVertex2i(660, 210);
	glVertex2i(640, 190);
	glEnd();
	glPopMatrix();

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0, 0.0, 0.0);

	//Prima masina
	glPushMatrix();
	glTranslated(carTranslationX, carTranslationY, 0.0); // miscarea masinii/depasirea
	glTranslated(300, 240, 0);
	glRotated(rotationAngle, 0, 0, 1);
	glTranslated(-300, -240, 0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(RC1, GC1, BC1); //culoarea corpului masinii
	glRecti(200, 200, 400, 280); //corpul masinii
	glColor3f(1.0, 1.0, 1.0);
	glRecti(250, 280, 300, 300); //culoare geam 1
	glRecti(300, 280, 350, 300); //culoare geam 2
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0, 0.0, 0.0);
	glRecti(250, 280, 300, 300); //contur geam 1
	glRecti(300, 280, 350, 300); //contur geam 2
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1.0, 1.0, farB); //culoare far
	glRecti(380, 260, 402, 282);
	glBegin(GL_TRIANGLES); //lumina farului
	glVertex3f(380, 271, 0.0);
	glVertex3f(450, 310, 0.0);
	glVertex3f(450, 230, 0.0);
	glEnd();
	glPopMatrix();

	//Roata 1 masina 1
	glPushMatrix();
	glTranslated(carTranslationX, carTranslationY, 0.0); //roata se misca o data cu restul masiniii
	glTranslated(300, 240, 0);
	glRotated(rotationAngle, 0, 0, 1);
	glTranslated(-300, -240, 0);
	glTranslated(xC1W1, yC1W1, 0);
	glRotated(-wheelsRotation, 0, 0, 1);
	glTranslated(-xC1W1, -yC1W1, 0);
	glCallList(regHexC1W1); //roata
	glCallList(regHexC1W1C); //capacul rotii
	glBegin(GL_LINES); //detalii pentur capacul masinii
	glVertex2i(235, 200);
	glVertex2i(265, 200);
	glVertex2i(250, 215);
	glVertex2i(250, 185);
	glVertex2i(240, 210);
	glVertex2i(260, 190);
	glVertex2i(260, 210);
	glVertex2i(240, 190);
	glEnd();
	glPopMatrix();

	//Roata 2 masina 1
	glPushMatrix();
	glTranslated(carTranslationX, carTranslationY, 0.0);
	glTranslated(300, 240, 0);
	glRotated(rotationAngle, 0, 0, 1);
	glTranslated(-300, -240, 0);
	glTranslated(xC1W2, yC1W2, 0);
	glRotated(-wheelsRotation, 0, 0, 1);
	glTranslated(-xC1W2, -yC1W2, 0);
	glCallList(regHexC1W2);
	glCallList(regHexC1W2C);
	glBegin(GL_LINES);
	glVertex2i(335, 200);
	glVertex2i(365, 200);
	glVertex2i(350, 215);
	glVertex2i(350, 185);
	glVertex2i(340, 210);
	glVertex2i(360, 190);
	glVertex2i(360, 210);
	glVertex2i(340, 190);
	glEnd();
	glPopMatrix();





	glutSwapBuffers();
	glFlush();
}


int tempOk = 0; //Variabila pentru a verifica daca s-a efectuat o partie din rotatie
//Functia care evalueaza si schimba translatiile si rotatiile
void miscas(void)
{
	double frameTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
	deltaTime = frameTime - oldTime;
	oldTime = frameTime;

	movement += alpha * deltaTime;
	rotationAngle += beta * deltaTime;
	carTranslationX += teta * deltaTime;
	wheelsRotation += 150 * deltaTime;
	if (rotationAngle > 50.0 && tempOk == 0)
		beta = -BETA;
	else if (rotationAngle < -50.0 && tempOk == 0)
	{
		beta = BETA;
		tempOk = 1;
	}
	if (tempOk == 1 && rotationAngle >= 0)
	{
		beta = 0.0;
	}

	if (where < 600)
	{
		teta = TETA;
		where += teta * deltaTime;
	}
	else
	{
		teta = 0.0;
	}

	if (where >= 300 && where < 600)
		carTranslationY -= 120 * deltaTime;
	else if (where < 300)
		carTranslationY += 120 * deltaTime;
	else
	{
		carTranslationX += 200 * deltaTime;
		carTranslationY = 0.0;
	}

	glutPostRedisplay();
}


//La apasare pe click stanga va porni animatia
void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{
			alpha = ALPHA;
			if (tempOk == 1) beta == 0.0;
			else beta = BETA;
			teta = TETA;
			glutIdleFunc(miscas);
		}
		break;
	default:
		break;
	}
}


//Iesire din aplicatie
void callback_Main(int key)
{
	if (key == 0)
	{
		exit(0);
	}
}


//Setare pentru timezone
void Initialize(int key)
{
	switch (key)
	{
	case 0:
		glClearColor(0.8, 0.8, 0.8, 0.0);
		break;
	case 1:
		glClearColor(0.9, 0.9, 0.9, 0.0);
		keybBackground = 1;
		farB = 0.6;
		break;
	case 2:
		glClearColor(0.4, 0.5, 0.7, 0.0);
		keybBackground = 2;
		farB = 0.2;
		break;

	}

}

//Culori prima masina
void changeColorsC1(int value)
{
	switch (value)
	{
	case 1:
		RC1 = 0.9;
		GC1 = 0.2;
		BC1 = 0.2;
		break;
	case 2:
		RC1 = 0.6;
		GC1 = 0.2;
		BC1 = 0.8;
		break;

	case 3:
		RC1 = 0.23;
		GC1 = 0.4;
		BC1 = 0.9;
		break;

	case 4:
		RC1 = 0.0;
		GC1 = 0.4;
		BC1 = 0.0;
		break;
	case 5:
		RC1 = 0.2;
		GC1 = 0.2;
		BC1 = 0.2;
		break;

	}
}

//Culori a doua masina
void changeColorsC2(int value)
{
	switch (value)
	{
	case 1:
		RC2 = 0.9;
		GC2 = 0.2;
		BC2 = 0.2;
		break;
	case 2:
		RC2 = 0.6;
		GC2 = 0.2;
		BC2 = 0.8;
		break;

	case 3:
		RC2 = 0.23;
		GC2 = 0.4;
		BC2 = 0.9;
		break;

	case 4:
		RC2 = 0.0;
		GC2 = 0.4;
		BC2 = 0.0;
		break;
	case 5:
		RC2 = 0.2;
		GC2 = 0.2;
		BC2 = 0.2;
		break;

	}
}

int main(int argc, char** argv)
{
	int menuMain, menuBackground, colorsC1, colorsC2;

	glutInit(&argc, argv); // initializare GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // se utilizeaza un singur buffer | modul de colorare RedGreenBlue (= default)
	glutInitWindowPosition(100, 100); // pozitia initiala a ferestrei de vizualizare (in coordonate ecran)
	glutInitWindowSize(1700, 900); // dimensiunile ferestrei 
	glutCreateWindow("Trafic"); // creeaza fereastra 

	//Creare liste de display
	wheelsC1W1();
	wheelsC1W2();
	wheelsC2W1();
	wheelsC2W2();
	//Creare capace masina
	wheelcoverC1W1();
	wheelcoverC1W2();
	wheelcoverC2W1();
	wheelcoverC2W2();

	glutIdleFunc(time);
	init();
	Initialize(keybBackground);

	glutDisplayFunc(desen); // procedura desen este invocata ori de cate ori este nevoie


	//Submenu pentru timezone
	menuBackground = glutCreateMenu(Initialize);
	glutAddMenuEntry("Day", 1);
	glutAddMenuEntry("Night", 2);

	//Submenu pentru culoarea primei masini
	colorsC1 = glutCreateMenu(changeColorsC1);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Purple", 2);
	glutAddMenuEntry("Blue", 3);
	glutAddMenuEntry("Green", 4);
	glutAddMenuEntry("Gray", 5);

	//Submenu pentru culoarea celei de a doua masini
	colorsC2 = glutCreateMenu(changeColorsC2);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Purple", 2);
	glutAddMenuEntry("Blue", 3);
	glutAddMenuEntry("Green", 4);
	glutAddMenuEntry("Gray", 5);


	//Menu
	menuMain = glutCreateMenu(callback_Main);
	glutAddSubMenu("Timezone ", menuBackground);
	glutAddSubMenu("First car color ", colorsC1);
	glutAddSubMenu("Second car color ", colorsC2);
	glutAddMenuEntry("Exit ", 0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMouseFunc(mouse);
	glutMainLoop(); // ultima instructiune a programului, asteapta (eventuale) noi date de intrare
	return 1;
}