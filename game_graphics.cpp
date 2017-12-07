//
// Created by Jack Roach on 11/30/17.
//

#include "graphics.h"
#include <string>
#include <iostream>
#include "Player.h"
#include "Consonant.h"
#include "Vowel.h"

using namespace std;

//Determine screen
enum screen_type {menu, game};

GLdouble width, height;
int wd;
int UNIT = 50;

Player p1;
Consonant c1 = Consonant('i', UNIT, 0);
Vowel v1 = Vowel('t', UNIT *2, 0);

void init() {
    width = UNIT * 11;
    height = UNIT * 14;
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.5f, 0.0f, 1.0f); // Black and opaque
}

void displayStart() {
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(0, 0);
    glVertex2i(0, height);
    glVertex2i(width, height);
    glVertex2i(width, 0);
    glEnd();
    string message = "Click anywhere to begin";
    glColor3f(1, 1, 1);
    glRasterPos2i(150, 240);
    for (int i = 0; i < message.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }
}

void road(int x, int y) {
//yellow lines
    glColor3f(0.9,0.8,0.0);
    glBegin(GL_QUADS);
    glVertex2i(UNIT*x, UNIT*y-4);
    glVertex2i(UNIT*x, UNIT*y+4);
    glVertex2i(UNIT*(x+1), UNIT*y+4);
    glVertex2i(UNIT*(x+1), UNIT*y-4);
    glBegin(GL_QUADS);
    return;
};

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    /*
     * Draw here
     */

    //shape




    //Two Lane Road
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_QUADS);
    glVertex2i(0, UNIT);
    glVertex2i(0, UNIT*3);
    glVertex2i(width, UNIT*3);
    glVertex2i(width, UNIT);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glPointSize(1.0);
    glBegin(GL_LINES);
    glVertex2d(0,UNIT);
    glVertex2d(width,UNIT);
    glBegin(GL_LINES);
    glVertex2d(0,UNIT*3);
    glVertex2d(width,UNIT*3);
    glEnd();

    //Three Lane Road #1
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_QUADS);
    glVertex2i(0, UNIT*4);
    glVertex2i(0, UNIT*7);
    glVertex2i(width, UNIT*7);
    glVertex2i(width, UNIT*4);
    glEnd();
    
    glColor3f(0.0,0.0,0.0);
    glPointSize(1.0);
    glBegin(GL_LINES);
    glVertex2d(0,UNIT*4);
    glVertex2d(width,UNIT*4);
    glBegin(GL_LINES);
    glVertex2d(0,UNIT*7);
    glVertex2d(width,UNIT*7);
    glEnd();

    //Three Lane Road #2
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_QUADS);
    glVertex2i(0, UNIT*8);
    glVertex2i(0, UNIT*11);
    glVertex2i(width, UNIT*11);
    glVertex2i(width, UNIT*8);
    glEnd();
    
    glColor3f(0.0,0.0,0.0);
    glPointSize(1.0);
    glBegin(GL_LINES);
    glVertex2d(0,UNIT*8);
    glVertex2d(width,UNIT*8);
    glBegin(GL_LINES);
    glVertex2d(0,UNIT*11);
    glVertex2d(width,UNIT*11);
    glEnd();

    // drawing menu
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2i(0, UNIT * 13);
    glVertex2i(0, height);
    glVertex2i(width, height);
    glVertex2i(width, UNIT * 13);
    glEnd();

    /***** Yellow Road Lines *****/
    for (int i = 0; i < 12;i++){
        if (i%2 == 0){
            road(i, 2);
        }
    }
    for (int i = 0; i < 12;i++){
        if (i%2 != 0){
            road(i, 5);
        }
    }
    for (int i = 0; i < 12;i++){
        if (i%2 == 0){
            road(i, 6);
        }
    }
    for (int i = 0; i < 12;i++){
        if (i%2 != 0){
            road(i, 9);
        }
    }
    for (int i = 0; i < 12;i++){
        if (i%2 == 0){
            road(i, 10);
        }
    }

    // drawing word box
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(UNIT*3, UNIT * 12);
    glVertex2i(UNIT*3, UNIT * 13);
    glVertex2i(UNIT*8, UNIT * 13);
    glVertex2i(UNIT*8, UNIT * 12);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glPointSize(1);
    glBegin(GL_LINES);
    glVertex2d(UNIT * 3,UNIT * 12);
    glVertex2d(UNIT * 8,UNIT*12);
    glBegin(GL_LINES);
    glVertex2d(UNIT * 3,UNIT * 13);
    glVertex2d(UNIT * 8,UNIT * 13);
    glBegin(GL_LINES);


    glVertex2d(UNIT * 3,UNIT * 12);
    glVertex2d(UNIT * 3,UNIT * 13);

    glBegin(GL_LINES);
    glVertex2d(UNIT * 4,UNIT * 12);
    glVertex2d(UNIT * 4,UNIT * 13);

    glBegin(GL_LINES);
    glVertex2d(UNIT * 5,UNIT * 12);
    glVertex2d(UNIT * 5,UNIT * 13);

    glBegin(GL_LINES);
    glVertex2d(UNIT * 6,UNIT * 12);
    glVertex2d(UNIT * 6,UNIT * 13);

    glBegin(GL_LINES);
    glVertex2d(UNIT * 7,UNIT * 12);
    glVertex2d(UNIT * 7,UNIT * 13);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(UNIT * 8,UNIT * 12);
    glVertex2d(UNIT * 8,UNIT * 13);
    glEnd();

    // drawing new game
    string newGame = "New Game";
    glColor3f(1, 1, 1);
    glRasterPos2i(UNIT * 0.2, UNIT * 13.7);
    for (int i = 0; i < newGame.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, newGame[i]);
    }

    // drawing new game
    string saveGame = "Save Game";
    glColor3f(1, 1, 1);
    glRasterPos2i(UNIT * 3.3, UNIT * 13.7);
    for (int i = 0; i < saveGame.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, saveGame[i]);
    }

    // drawing load game
    string loadGame = "Load Game";
    glColor3f(1, 1, 1);
    glRasterPos2i(UNIT * 6.3, UNIT * 13.7);
    for (int i = 0; i < loadGame.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, loadGame[i]);
    }

    // drawing exit button
    string exit = "Exit";
    glColor3f(1, 1, 1);
    glRasterPos2i(UNIT * 10, UNIT * 13.7);
    for (int i = 0; i < exit.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, exit[i]);
    }

    p1.draw();
    c1.draw();
    v1.draw();

    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y)
{
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }

    glutPostRedisplay();

    return;
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            p1.movePlayer(0,UNIT);

            break;
        case GLUT_KEY_LEFT:
            p1.movePlayer(-UNIT, 0);

            break;
        case GLUT_KEY_RIGHT:
            p1.movePlayer(UNIT, 0);

            break;
        case GLUT_KEY_UP:
            p1.movePlayer(0,-UNIT);

            break;
    }

    glutPostRedisplay();

    return;
}

void cursor(int x, int y) {


    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON and (x > 12 and x < 120) and (y > 669 and y < 690)) {
        cout << "Inside New Game" << endl;
    }

    if (button == GLUT_LEFT_BUTTON and (x > 166 and x < 276) and (y > 669 and y < 690)) {
        cout << "Inside Save Game" << endl;
    }

    if (button == GLUT_LEFT_BUTTON and (x > 315 and x < 430) and (y > 669 and y < 690)) {
        cout << "Inside Load Game" << endl;
    }


    if (button == GLUT_LEFT_BUTTON and (x > 500 and x < 550) and (y > 669 and y < 690)) {
        cout << "Inside Exit" << endl;
    }


    glutPostRedisplay();
}

void timer(int extra) {

    glutPostRedisplay();
    glutTimerFunc(30, timer, 0);
}

/* Main function: GLUT runs as a console application starting at main()  */
int graphicsPlay(int argc, char** argv) {

    init();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(450, 100); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Fun with Drawing!" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(0, timer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}
