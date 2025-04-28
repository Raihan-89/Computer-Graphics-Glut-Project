#include <iostream>
#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define pi 3.142857
#include<iostream>
using namespace std;


float carX = 0;
float carY = 0;
float rightCarX = 600;
float rightCarY = 0;
float grassPosition = 0.0f;
float homePosition = 0.0f;
float treePosition = 0.0f;
float roadLinesPosition = 0.0f;
float rightSideCarPosition = 100.0f;
float randNumber = -100;
bool isGameOver = false;
// Define the size of the cars (width and height)
float carWidth = 50; // Adjust as per your car size
float carHeight = 50; // Adjust as per your car size

// Function to draw a filled circle
void drawCircle(float cx, float cy, float radius, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int angle = 0; angle <= 360; angle++) {
        float theta = angle * 3.14159 / 180.0;
        glVertex2f(cx + radius * cos(theta), cy + radius * sin(theta));
    }
    glEnd();
}


void drawTrafficLight(int x, int y) {
    // Draw the traffic light frame
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(x - 25, y + 70);
    glVertex2f(x + 10, y + 70);
    glVertex2f(x + 10, y - 70);
    glVertex2f(x - 25, y - 70);
    glEnd();

    // Draw the red light
    drawCircle(x-8, y + 58, 6, 1.0f, 0.0f, 0.0f);

    // Draw the yellow light
    drawCircle(x-8, y+35, 6, 1.0f, 1.0f, 0.0f);

    // Draw the green light
    drawCircle(x-8, y+10, 6, 0.0f, 1.0f, 0.0f);
}
void redDot(float x, float y){
    float radius = 5;
    // Sun
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(252, 3, 28);
    glVertex2f(x,y);
    for(int i = 0; i <= 360; i++){
        float a = x + radius * cos(i * (pi/180));
        float b = y + radius * sin(i * (pi/180));
        glVertex2f(a,b);
    }
    glEnd();
}
void redFlower(float x, float y){
    float radius = 10;
    // Sun
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255);
    glVertex2f(x,y);
    for(int i = 0; i <= 360; i++){
        float a = x + radius * cos(i * (pi/180));
        float b = y + radius * sin(i * (pi/180));
        glVertex2f(a,b);
    }
    glEnd();
}
void flower(float x, float y){
    float radius = 30;
    // Sun
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(27,81,12);
    glVertex2f(x,y);
    for(int i = 0; i <= 360; i++){
        float a = x + radius * cos(i * (pi/180));
        float b = y + radius * sin(i * (pi/180));
        glVertex2f(a,b);
    }
    glEnd();


}

void cloud(float x, float y){
    float radius = 20;
    // Sun
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255);
    glVertex2f(x,y);
    for(int i = 0; i <= 360; i++){
        float a = x + radius * cos(i * (pi/180));
        float b = y + radius * sin(i * (pi/180));
        glVertex2f(a,b);
    }
    glEnd();
}

void sun(){
    float radius = 40;
    // Sun
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(251,243,108);
    glVertex2f(180,420);
    for(int i = 0; i <= 360; i++){
        float x = 180 + radius * cos(i * (pi/180));
        float y = 420 + radius * sin(i * (pi/180));
        glVertex2f(x,y);
    }
    glEnd();
}

void sky(){
    //Sky
    glBegin(GL_QUADS);
    glColor3ub(42,131,225);
    glVertex2f( 0,400 );
    glVertex2f( 500, 400);
    glVertex2f( 500, 500);
    glVertex2f( 0, 500);
    glEnd();
}

void grass(){
    glPushMatrix();
    glTranslatef(grassPosition, 0, 0);
    //Upper Grass
    glBegin(GL_QUADS);
    glColor3ub(0,165,1);
    glVertex2f( 0,300 );
    glVertex2f( 1000, 300);
    glVertex2f( 1000, 400);
    glVertex2f( 0, 400);
    glEnd();

    // Draw the traffic light
    drawTrafficLight(150, 300); // Another traffic light to the left
    drawTrafficLight(600, 300); // Another traffic light to the left
    glPopMatrix();

    //Lower Grass
    glBegin(GL_QUADS);
    glColor3ub(0,165,1);
    glVertex2f( 0,0 );
    glVertex2f( 1000, 0 );
    glVertex2f( 1000, 100);
    glVertex2f( 0, 100);
    glEnd();
    flower(20,30);
    flower(55,30);
    flower(20,50);
    redFlower(15,25);
    redFlower(25,35);
    redFlower(25,25);
    redFlower(15,35);
    redDot(20,30);

    flower(420,30);
    flower(455,30);
    flower(420,50);
    flower(440,60);
    redFlower(435,45);
    redFlower(445,55);
    redFlower(445,45);
    redFlower(435,55);
    redDot(440,50);
}

void road(){
    //Middle Road
    glBegin(GL_QUADS);
    glColor3ub(80,80,80);
    glVertex2f( 0,100 );
    glVertex2f( 500, 100 );
    glVertex2f( 500, 300);
    glVertex2f( 0, 300);
    glEnd();
}

void wheel(float x, float y){
    float radius = 15;
    // Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(30,30,30);
    glVertex2f(x,y);
    for(int i = 0; i <= 360; i++){
        float a = x + radius * cos(i * (pi/180));
        float b = y + radius * sin(i * (pi/180));
        glVertex2f(a,b);
    }
    glEnd();
}

void car(float x,float y){
    //Car body
    glBegin(GL_QUADS);
    glColor3ub(2,75,153);
    glVertex2f( carX+x+0,carY+y+220 );
    glVertex2f( carX+x+100, carY+y+220 );
    glVertex2f( carX+x+100, carY+y+250);
    glVertex2f( carX+x+0, carY+y+250);
    glEnd();

    //Car Hoddie
    glBegin(GL_QUADS);
    glColor3ub(3,59,90);
    glVertex2f( carX+x+5,carY+y+250 );
    glVertex2f( carX+x+90, carY+y+250 );
    glVertex2f( carX+x+75, carY+y+280);
    glVertex2f( carX+x+20, carY+y+280);
    glEnd();

    //Car Window
    glBegin(GL_QUADS);
    glColor3ub(210,200,199);
    glVertex2f( carX+x+12,carY+y+250 );
    glVertex2f( carX+x+40, carY+y+250 );
    glVertex2f( carX+x+40, carY+y+275);
    glVertex2f( carX+x+23, carY+y+275);
    glEnd();

    //Window Divider
    glBegin(GL_QUADS);
    glColor3ub(210,200,199);
    glVertex2f( carX+x+45,carY+y+250 );
    glVertex2f( carX+x+47, carY+y+250 );
    glVertex2f( carX+x+47, carY+y+278);
    glVertex2f( carX+x+45, carY+y+278);
    glEnd();

    //Car Window
    glBegin(GL_QUADS);
    glColor3ub(210,200,199);
    glVertex2f( carX+x+53,carY+y+250 );
    glVertex2f( carX+x+83, carY+y+250 );
    glVertex2f( carX+x+70, carY+y+275);
    glVertex2f( carX+x+53, carY+y+275);
    glEnd();

    wheel(carX+x+25,carY+y+225);
    wheel(carX+x+75,carY+y+225);
}

void rightSideCar(float x,float y){
    glPushMatrix();
    glTranslatef(rightSideCarPosition, 0, 0);

    //Car body
    glBegin(GL_QUADS);
    glColor3ub(152,194,223);
    glVertex2f( x+0,y+220 );
    glVertex2f( x+100, y+220 );
    glVertex2f( x+100, y+250);
    glVertex2f( x+0, y+250);
    glEnd();

    //Car Hoddie
    glBegin(GL_QUADS);
    glColor3ub(41,58,77);
    glVertex2f( x+9,y+250 );
    glVertex2f( x+95, y+250 );
    glVertex2f( x+81, y+280);
    glVertex2f( x+23, y+280);
    glEnd();

    //Car Window
    glBegin(GL_QUADS);
    glColor3ub(210,200,199);
    glVertex2f( x+12,y+250 );
    glVertex2f( x+42, y+250 );
    glVertex2f( x+42, y+275);
    glVertex2f( x+23, y+275);
    glEnd();

    //Window Divider
    glBegin(GL_QUADS);
    glColor3ub(210,200,199);
    glVertex2f( x+47,y+250 );
    glVertex2f( x+49, y+250 );
    glVertex2f( x+49, y+278);
    glVertex2f( x+47, y+278);
    glEnd();

    //Car Window
    glBegin(GL_QUADS);
    glColor3ub(210,200,199);
    glVertex2f( x+55,y+250 );
    glVertex2f( x+85, y+250 );
    glVertex2f( x+75, y+275);
    glVertex2f( x+55, y+275);
    glEnd();

    wheel(x+25,y+225);
    wheel(x+75,y+225);
    glPopMatrix();
}

void roadLines(){
    glPushMatrix();
    glTranslatef(roadLinesPosition, 0, 0);
    //Middle Road Lines
    glBegin(GL_QUADS);
    glColor3ub(225,220,224);

    float x = 0;
    for(int i = 0; i < 30; i++){
        glVertex2f( x+0,190 );
        glVertex2f( x+50, 190 );
        glVertex2f( x+50, 210);
        glVertex2f( x+0, 210);

        x+=70;
    }

    glEnd();
    glPopMatrix();
}

void leaf(float x,float y){
    float radius = 25;
    // Sun
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(27,81,12);
    glVertex2f(x,y);
    for(int i = 0; i <= 360; i++){
        float a = x + radius * cos(i * (pi/180));
        float b = y + radius * sin(i * (pi/180));
        glVertex2f(a,b);
    }
    glEnd();
}

void tree(){
    glPushMatrix();
    glTranslatef(treePosition, 0, 0);

    //First tree
    glBegin(GL_QUADS);
    glColor3ub(141,72,5);
    glVertex2f( 50,300 );
    glVertex2f( 70, 300 );
    glVertex2f( 70, 350);
    glVertex2f( 50, 350);
    glEnd();
    leaf(45,350);
    leaf(75,350);
    leaf(70,375);
    leaf(50,375);
    leaf(60,400);


    //Second tree
    glBegin(GL_QUADS);
    glColor3ub(141,72,5);
    glVertex2f( 250,300 );
    glVertex2f( 270, 300 );
    glVertex2f( 270, 350);
    glVertex2f( 250, 350);
    glEnd();
    leaf(245,350);
    leaf(275,350);
    leaf(270,375);
    leaf(250,375);
    leaf(260,400);

    //Third tree
    glBegin(GL_QUADS);
    glColor3ub(141,72,5);
    glVertex2f( 450,300 );
    glVertex2f( 470, 300 );
    glVertex2f( 470, 350);
    glVertex2f( 450, 350);
    glEnd();
    leaf(445,350);
    leaf(475,350);
    leaf(470,375);
    leaf(450,375);
    leaf(460,400);

    //Fourth tree
    glBegin(GL_QUADS);
    glColor3ub(141,72,5);
    glVertex2f( 650,300 );
    glVertex2f( 670, 300 );
    glVertex2f( 670, 350);
    glVertex2f( 650, 350);
    glEnd();
    leaf(645,350);
    leaf(675,350);
    leaf(670,375);
    leaf(650,375);
    leaf(660,400);

    //Fifth tree
    glBegin(GL_QUADS);
    glColor3ub(141,72,5);
    glVertex2f( 850,300 );
    glVertex2f( 870, 300 );
    glVertex2f( 870, 350);
    glVertex2f( 850, 350);
    glEnd();
    leaf(845,350);
    leaf(875,350);
    leaf(870,375);
    leaf(850,375);
    leaf(860,400);

    //Sixth tree
    glBegin(GL_QUADS);
    glColor3ub(141,72,5);
    glVertex2f( 1050,300 );
    glVertex2f( 1070, 300 );
    glVertex2f( 1070, 350);
    glVertex2f( 1050, 350);
    glEnd();
    leaf(1045,350);
    leaf(1075,350);
    leaf(1070,375);
    leaf(1050,375);
    leaf(1060,400);

    glPopMatrix();
}

void home(float x,float y){
    // Home (moving)
    glPushMatrix();
    glTranslatef(homePosition, 0, 0);

    //Home
    glBegin(GL_QUADS);
    glColor3ub(93,83,77);
    glVertex2f( x+320,y+320 );
    glVertex2f( x+400, y+320 );
    glVertex2f( x+400, y+370);
    glVertex2f( x+320, y+370);
    glEnd();

    //Roof
    glBegin(GL_QUADS);
    glColor3ub(163,75,55);
    glVertex2f( x+310,y+370 );
    glVertex2f( x+410, y+370 );
    glVertex2f( x+390, y+410);
    glVertex2f( x+330, y+410);
    glEnd();

    //Door
    glBegin(GL_QUADS);
    glColor3ub(200,196,195);
    glVertex2f( x+350,y+320 );
    glVertex2f( x+370, y+320 );
    glVertex2f( x+370, y+350);
    glVertex2f( x+350, y+350);
    glEnd();

    //Window
    glBegin(GL_QUADS);
    glColor3ub(200,196,195);
    glVertex2f( x+325,y+345 );
    glVertex2f( x+345, y+345 );
    glVertex2f( x+345, y+365);
    glVertex2f( x+325, y+365);
    glEnd();

    //Window
    glBegin(GL_QUADS);
    glColor3ub(200,196,195);
    glVertex2f( x+375,y+345 );
    glVertex2f( x+395, y+345 );
    glVertex2f( x+395, y+365);
    glVertex2f( x+375, y+365);
    glEnd();

    //Road
    glBegin(GL_QUADS);
    glColor3ub(80,80,80);
    glVertex2f( x+340,300 );
    glVertex2f( x+380, 300 );
    glVertex2f( x+380, y+320);
    glVertex2f( x+340, y+320);
    glEnd();

    //Road Line
    glBegin(GL_QUADS);
    glColor3ub(225,220,224);
    glVertex2f( x+340,300 );
    glVertex2f( x+350, 300 );
    glVertex2f( x+350, y+320);
    glVertex2f( x+340, y+320);
    glEnd();

    //Road Line
    glBegin(GL_QUADS);
    glColor3ub(225,220,224);
    glVertex2f( x+370,300 );
    glVertex2f( x+380, 300 );
    glVertex2f( x+380, y+320);
    glVertex2f( x+370, y+320);
    glEnd();

    glPopMatrix();

}

void myInit ()
{

	//glClearColor(0.0, 1.0, 0.0, 0.0);
	//glClearColor(184.0f/255.0f, 213.0f/255.0f, 238.0f/255.0f, 1.0f);
	//glColor3f(0.0, 0.2, 0.0);
	glClearColor(255.0f/255.0f,255.0f/255.0f, 255.0f/255.0f, 1.0f);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	// setting window dimension in X- and Y- direction
	glOrtho(0, 500, 0, 500, -10.0, 10.0);


}
void checkCollision(){
    // Check for collision
    if (
  carX < rightCarX + carWidth &&
  carX + carWidth > rightCarX &&
  carY < randNumber + carHeight &&
  carY + carHeight > randNumber
) {
  isGameOver = true;
}
     //if(carX >= rightCarX && carY == rightCarY){
     //   isGameOver = true;
    //}
}
void display ()
{

glClear(GL_COLOR_BUFFER_BIT);
    if (!isGameOver) {
        sky();
        sun();
        // First Cloud
        cloud(80,470);
        cloud(100,480);
        cloud(110,465);
        cloud(120,470);
        // Second Cloud
        cloud(405,470);
        cloud(420,480);
        cloud(430,465);
        cloud(440,470);
        // Third Cloud
        cloud(305,450);
        cloud(320,470);
        cloud(330,445);
        cloud(340,450);
        grass();
        tree();
        road();
        roadLines();
        car(50,0);
        rightSideCar(rightCarX,randNumber);
        //car(160,-90);
        //car(300,20);
        home(0,0);
        home(400,20);

        checkCollision(); // Check for collision
    } else {
        glColor3ub(255, 0, 0);
        glRasterPos2f(200, 200);
        const char* message = "Game Over!";
        for (const char* c = message; *c != '\0'; c++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
        }
    }
/*
sky();
sun();
grass();
tree();
road();
roadLines();
car(50,0);
rightSideCar(rightCarX,randNumber);
//car(160,-90);
//car(300,20);
home(0,0);
home(400,20);


//Triangle
glBegin(GL_TRIANGLES);
glColor3f(0,0,0);
glVertex2f( 250,250 );
glVertex2f( 300, 200 );
glVertex2f( 200, 200);
glEnd();

//lines
glBegin(GL_LINES);
glColor3f(0,1,0);
glVertex2f( 250,500 );
glVertex2f( 250, 0 );
glEnd();

//point

glPointSize(100);
glBegin(GL_POINTS);
glColor3f(0,1,0);
glVertex2f( 100,100 );
glEnd();

//Quads
glBegin(GL_QUADS);
glColor3ub(128,0,0);
glVertex2f( 0,0 );
glVertex2f( 200, 0 );
glVertex2f( 200, 200);
glVertex2f( 0, 200);
glEnd();

//polygon
glBegin(GL_POLYGON);
glColor3f(0,1,0);
glVertex2f( 100,100 );
glVertex2f( 100, 0 );
glVertex2f( 50, 0 );
glVertex2f( 10, 50 );
glVertex2f( 50, 200 );

glEnd();

*/
glFlush();
}

void my_keyboard(unsigned char key, int x, int y)
{
    if(key == 'w'){
        if(carY+80 < 100){
            carY+=5;
        }
    }
    if(key == 's'){
        if(carY+140 > 30){
            carY-=5;
        }
    }
    if(key == 'a'){
        if(carX+50 > 0){
            carX-=5;
        }
    }
    if(key == 'd'){
        if(carX+50 <400){
            carX+=5;
        }
    }
    cout<<key<<endl;

}

void update(int value) {

	// Move the grass and home
    grassPosition -= 3.0f;
    homePosition -= 3.0f;
    treePosition -= 3.0f;
    roadLinesPosition -= 3.0f;
    //rightSideCarPosition -= 3.0f;
    rightCarX -= 3;

    // Reset positions if out of bounds
    if(grassPosition <= -500.0f) grassPosition = 0.0f; // Reset grass to the right side
    if(homePosition <= -500.0f) homePosition = 0.0f;   // Reset home to the right side
    if(treePosition <= -500.0f) treePosition = 0.0f;
    if(roadLinesPosition <= -500.0f) roadLinesPosition = 0.0f;
    if(rightCarX <= -200){
        rightCarX = 600;
        randNumber = -100 + rand() % (50 - (-100) + 1);
    }
	glutPostRedisplay();
	glutTimerFunc(15, update, 0);
}

int main (int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// giving window size in X- and Y- direction
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 0);

	// Giving name to window
	glutCreateWindow("Rush Driving");
	myInit();


	glutDisplayFunc(display);
	glutKeyboardFunc(my_keyboard);
	glutTimerFunc(25, update, 0);

	glutMainLoop();
}
