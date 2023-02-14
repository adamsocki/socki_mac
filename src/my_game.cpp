



void MyGameInit()
{

}


void MyGameLogicUpdate_Logic()
{

}




void MyGameUpdate_Render()
{
    glClearColor(0.4f, 0.4f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a rectangle to the screen
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.4f, 0.2f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.4f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();
}