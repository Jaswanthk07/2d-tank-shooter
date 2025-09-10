/// TANK SHOOTER 2D
/// PREPARED BY:
/// JASWANTH(S20220010168)
/// NAVEEN(S20220010149)
/// DINESH(S20220010062)
/// GIRIDHAR(S20220010153)

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>
#include <iostream>
#include <vector>
using namespace std;

int screen_width, screen_height;
bool welcome = 1, game = 0, over = 0, pause = 0;
int startx, starty;
int tankx = 30, tanky, tankl = 120;
vector<pair<int, int>> fire;
int enemytankx[10], enemytanky[10];
int tankw = 200, tankh = 150;
int score = 0;

int tankSpeed = 15;
int fireSpeed = 30;
int sleep = 20;
int tanks = 5;
int modulo = 600;

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(20.0);
    glLineWidth(5.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, screen_width, 0.0, screen_height);
}

void welcomeScreen()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Gradient Background
    glBegin(GL_QUADS);
    glColor3ub(0, 128, 255); // Blue Top
    glVertex2i(0, screen_height);
    glVertex2i(screen_width, screen_height);
    glColor3ub(173, 216, 230); // Light Blue Bottom
    glVertex2i(screen_width, 0);
    glVertex2i(0, 0);
    glEnd();

    // Title "TANK SHOOTER"
    string title = "TANK SHOOTER";
    int titleX = screen_width / 2 - (title.size() * 9); // Approximate centering
    int titleY = screen_height - 100;                  // Positioned at the top
    glColor3ub(255, 255, 255); // White Text
    glRasterPos2i(titleX, titleY);
    for (char c : title)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }

    // Instructions Text
    string welcome_text = "Welcome to Tank Shooter game.\nInstructions:\n";
    welcome_text += "1. Use A, S, W, D to control your tank.\nA = left\nD = right\nW = up\nS = down\n";
    welcome_text += "2. Use SpaceBar to shoot.\n";
    welcome_text += "3. To avoid collision with enemy tanks, you can either destroy enemy tanks by shooting it or simply dodging it.\n";
    welcome_text += "4. Shooting the enemy tank will give you 20 points, whereas dodging it will give 10 points.\n";
    welcome_text += "5. Press Esc to quit the game.\n";
    welcome_text += "6. Press P to pause/resume.\n";
    memset(enemytankx, -1, sizeof(enemytankx));
    memset(enemytanky, -1, sizeof(enemytanky));
    fire.clear();
    score = 0;
    tankx = 30;
    tanky = screen_height / 2 - tankh / 2;

    int instructionX = 50;
    int instructionY = screen_height - 150; // Positioned below the title
    glColor3ub(255, 255, 255); // White Text
    glRasterPos2i(instructionX, instructionY);
    for (char c : welcome_text)
    {
        if (c == '\n')
        {
            instructionY -= 30;
            glRasterPos2i(instructionX, instructionY);
        }
        else
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }
    }

    // Start Button
    int w = 200, h = 100;
    startx = screen_width / 2 - w / 2;
    starty = screen_height / 4;

    glColor3ub(50, 205, 50); // Lime Green Button
    glBegin(GL_QUADS);
    glVertex2i(startx, starty);
    glVertex2i(startx + w, starty);
    glVertex2i(startx + w, starty + h);
    glVertex2i(startx, starty + h);
    glEnd();

    // Start Button Text
    string start = "Start Game";
    glColor3ub(255, 255, 255); // White Text
    glRasterPos2i(startx + 40, starty + 40);
    for (char c : start)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }

    glFlush();
}

void drawTank(int x, int y, int type)
{
    if (type == 1)
        glColor3ub(35, 108, 23);
    else
        glColor3ub(131, 33, 36);
    // glLineWidth(5);

    glBegin(GL_QUADS);
    glVertex2i(x, y);
    glVertex2i(x + tankw, y);
    glVertex2i(x + tankw, y + tankh);
    glVertex2i(x, y + tankh);
    glEnd();

    int tempw = 50, temph = 40;
    if (type == 1)
        glColor3ub(0, 255, 0);
    else
        glColor3ub(255, 0, 0);

    glBegin(GL_QUADS);
    glVertex2i(x + tempw, y + temph);
    glVertex2i(x + tankw - tempw, y + temph);
    glVertex2i(x + tankw - tempw, y + tankh - temph);
    glVertex2i(x + tempw, y + tankh - temph);
    glEnd();

    // glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(x + tankw - tempw, y + tankh / 2);
    if (type == 1)
        glVertex2i(x + tankw - tempw + tankl, y + tankh / 2);
    else
        glVertex2i(x + tempw - tankl, y + tankh / 2);

    glEnd();
    glFlush();
}

void drawFire()
{
    glColor3ub(255, 255, 0);
    glBegin(GL_POINTS);
    for (int i = 0; i < fire.size(); i++)
        glVertex2i(fire[i].first, fire[i].second);

    glEnd();
    glFlush();
}

bool opponentCollision(int n)
{
    int x = enemytankx[n] - tankl, y = enemytanky[n], xl = enemytankx[n] + tankw, yl = enemytanky[n] + tankh;
    int tempx, tempy, tempxl, tempyl;
    for (int i = 0; i < tanks; i++)
    {
        if (i == n || enemytankx[i] == -1 || enemytanky[i] == -1)
            continue;
        tempx = enemytankx[i] - tankl;
        tempy = enemytanky[i];
        tempxl = enemytankx[i] + tankw;
        tempyl = enemytanky[i] + tankh;
        if (((x >= tempx && x <= tempxl) || (xl >= tempx && xl <= tempxl)) && ((y >= tempy && y <= tempyl) || (yl >= tempy && yl <= tempyl)))
        {
            return false;
        }
    }
    return true;
}

void generate_tank(int n)
{
    do
    {
        enemytankx[n] = screen_width + rand() % modulo;
        enemytanky[n] = rand() % (screen_height - tankh);
        // cout << n << ": " << enemytankx[n] << " " << enemytanky[n] << endl;
    } while (!opponentCollision(n));
}

void translate()
{
    for (int i = 0; i < tanks; i++)
    {
        enemytankx[i] -= tankSpeed;
        if (enemytankx[i] + tankw < 0)
        {
            enemytankx[i] = -1;
            enemytanky[i] = -1;
            score += 10;
        }
    }
    for (int i = 0; i < fire.size(); i++)
    {
        fire[i].first += fireSpeed;
        if (fire[i].first > screen_width)
        {
            fire.erase(fire.begin() + i);
            i--;
        }
    }

    glutPostRedisplay();
}

void fireCollision()
{
    bool temp;
    int fx, fy, tx, ty, txl, tyl;
    for (int i = 0; i < fire.size(); i++)
    {
        temp = 0;
        fx = fire[i].first;
        fy = fire[i].second;
        for (int j = 0; j < tanks; j++)
        {
            //            tx = enemytankx[j] - tankl + 100;
            if (enemytankx[j] == -1 || enemytanky[j] == -1)
                continue;
            tx = enemytankx[j];
            txl = enemytankx[j] + tankw;
            ty = enemytanky[j];
            tyl = enemytanky[j] + tankh;
            if (fx >= tx && fx <= txl && fy >= ty && fy <= tyl)
            {
                enemytankx[j] = -1;
                enemytanky[j] = -1;
                fire.erase(fire.begin() + i);
                temp = 1;
                score += 20;
            }
        }
        if (temp)
            i--;
    }
}

void tankCollision()
{
    int tx, txl, ty, tyl;

    int x = tankx, xl = tankx + tankw;
    int y = tanky, yl = tanky + tankh;
    for (int i = 0; i < tanks; i++)
    {
        if (enemytankx[i] == -1 || enemytanky[i] == -1)
            continue;
        tx = enemytankx[i];
        txl = tx + tankw;
        ty = enemytanky[i];
        tyl = ty + tankh;
        if (((x >= tx && x <= txl) || (xl >= tx && xl <= txl)) && ((y >= ty && y <= tyl) || (yl >= ty && yl <= tyl)))
        {

            welcome = 0;
            game = 0;
            pause = 0;
            over = 1;
        }
    }
}

void drawRoad()
{
    glColor3ub(237, 201, 175);//Sand Color
    glBegin(GL_QUADS);
    glVertex2i(0, 0);
    glVertex2i(screen_width, 0);
    glVertex2i(screen_width, screen_height);
    glVertex2i(0, screen_height);
    glEnd();

    glLineWidth(20);
    glColor3ub(48, 128, 20);//Sap Green Grass Color
    glBegin(GL_LINES);
    glVertex2i(0, screen_height / 2);
    glVertex2i(screen_width, screen_height / 2);
    glVertex2i(0, screen_height / 4);
    glVertex2i(screen_width, screen_height / 4);
    glVertex2i(0, 3 * screen_height / 4);
    glVertex2i(screen_width, 3 * screen_height / 4);
    glEnd();
    glLineWidth(5);
    glFlush();
}

void drawHUD() {
    glColor3ub(1, 1, 1); // Set text color to black
    std::string hudText = "Score: " + std::to_string(score) + " | Press P to Pause";

    // Position the text at the top-left corner of the screen
    glRasterPos2i(10, screen_height - 30);

    // Render each character of the string
    for (char c : hudText) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

void gameScreen()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    drawRoad();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    drawTank(tankx, tanky, 1);
    drawHUD();

    for (int i = 0; i < tanks; i++)
    {
        if (enemytankx[i] == -1 || enemytanky[i] == -1)
            generate_tank(i);

        drawTank(enemytankx[i], enemytanky[i], 2);
    }
    drawFire();
    if (!pause)
    {
        fireCollision();
        tankCollision();
        Sleep(sleep);
        translate();
    }

}

void overScreen()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Gradient Background
    glBegin(GL_QUADS);
    glColor3ub(255, 69, 0); // Top Red-Orange
    glVertex2i(0, screen_height);
    glVertex2i(screen_width, screen_height);
    glColor3ub(255, 165, 0); // Bottom Orange
    glVertex2i(screen_width, 0);
    glVertex2i(0, 0);
    glEnd();

    // Game Over Message
    string message = "GAME OVER";
    int x = screen_width / 2 - 50, y = screen_height / 2 + 100;
    int len = message.size();
    glColor3ub(1, 1, 1); // Black Text
    glRasterPos2i(x, y);
    for (int i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }

    // Score Display
    message = "YOUR SCORE: ";
    x -= 20;
    y -= 100;
    glColor3ub(1, 1, 1); // Black Text
    len = message.size();
    glRasterPos2i(x, y);
    for (int i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }

    char buffer[20];
    sprintf(buffer, "%d", score);
    len = strlen(buffer);
    for (int i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, buffer[i]);
    }

    // Back Button
    int w = 200, h = 100;
    startx = screen_width / 2 - w / 2 + 20;
    starty = screen_height / 4;

    glColor3ub(0, 0, 255); // Blue Button
    glBegin(GL_QUADS);
    glVertex2i(startx, starty);
    glVertex2i(startx + w, starty);
    glVertex2i(startx + w, starty + h);
    glVertex2i(startx, starty + h);
    glEnd();

    // Back Button Text
    message = "Go Back";
    len = message.size();
    glColor3ub(255, 255, 255); // White Text
    glRasterPos2i(startx + 55, starty + 40);
    for (int i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }
    glFlush();
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    if (welcome)
        welcomeScreen();
    else if (game)
        gameScreen();
    else if (over)
        overScreen();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 27)
        exit(0);

    if (game)
    {
        if (key == 'a' && !pause)
        {
            tankx -= tankSpeed;
            if (tankx < 0)
                tankx = 0;
        }
        else if (key == 's' && !pause)
        {
            tanky -= tankSpeed;
            if (tanky < 0)
                tanky = 0;
        }
        else if (key == 'd' && !pause)
        {
            tankx += tankSpeed;
            if (tankx + tankw + tankl > screen_width)
                tankx = screen_width - tankw - tankl;
        }
        else if (key == 'w' && !pause)
        {
            tanky += tankSpeed;
            if (tanky + tankh > screen_height)
                tanky = screen_height - tankh;
        }
        else if (key == ' ' && !pause)
        {
            fire.push_back(make_pair(tankx + tankw + tankl - 40, tanky + (tankh / 2)));
        }
        else if (key == 'p')
        {
            pause = !pause;
        }
        glutPostRedisplay();
    }
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if (x >= startx && x <= startx + 200 && y <= screen_height - starty && y >= screen_height - starty - 100)
        {
            if (welcome)
            {
                welcome = 0;
                over = 0;
                game = 1;
                pause = 0;
                glutPostRedisplay();
            }
            if (over)
            {
                welcome = 1;
                over = 0;
                game = 0;
                pause = 0;
                glutPostRedisplay();
            }
        }
    }
}

int main(int argc, char **argv)
{
    memset(enemytankx, -1, sizeof(enemytankx));
    memset(enemytanky, -1, sizeof(enemytanky));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    screen_width = glutGet(GLUT_SCREEN_WIDTH);
    screen_height = glutGet(GLUT_SCREEN_HEIGHT);
    glutInitWindowSize(screen_width, screen_height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tank Shooter");
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutFullScreen();
    myInit();
    srand(clock());
    glutMainLoop();
    return 0;
}
