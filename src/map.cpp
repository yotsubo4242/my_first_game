#include "game.h"

#define MAP_WIDTH  10
#define MAP_HEIGHT 10

static const int map[MAP_HEIGHT][MAP_WIDTH]={
    {1,1,1,1,1,1,1,1,1,1},
    {1,2,1,0,1,0,1,0,0,1},
    {1,0,1,0,1,0,1,1,0,1},
    {1,0,1,0,1,0,0,0,0,1},
    {1,0,1,0,1,0,0,0,0,1},
    {1,0,1,0,1,0,0,0,0,1},
    {1,0,1,0,1,0,1,1,0,1},
    {1,0,1,0,1,0,1,0,0,1},
    {1,0,0,0,0,0,1,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};

static const double HEX_SIZE=FIELD_SIZE/10;

void drawRectangularPrism(float width, float height, float depth) {
    float w = width / 2.0f;
    float h = height / 2.0f;
    float d = depth / 2.0f;

    glBegin(GL_QUADS);

    // Front face
    glVertex3f(-w, -h,  d);
    glVertex3f( w, -h,  d);
    glVertex3f( w,  h,  d);
    glVertex3f(-w,  h,  d);

    // Back face
    glVertex3f(-w, -h, -d);
    glVertex3f(-w,  h, -d);
    glVertex3f( w,  h, -d);
    glVertex3f( w, -h, -d);

    // Left face
    glVertex3f(-w, -h, -d);
    glVertex3f(-w, -h,  d);
    glVertex3f(-w,  h,  d);
    glVertex3f(-w,  h, -d);

    // Right face
    glVertex3f(w, -h, -d);
    glVertex3f(w,  h, -d);
    glVertex3f(w,  h,  d);
    glVertex3f(w, -h,  d);

    // Top face
    glVertex3f(-w,  h, -d);
    glVertex3f(-w,  h,  d);
    glVertex3f( w,  h,  d);
    glVertex3f( w,  h, -d);

    // Bottom face
    glVertex3f(-w, -h, -d);
    glVertex3f( w, -h, -d);
    glVertex3f( w, -h,  d);
    glVertex3f(-w, -h,  d);

    glEnd();
}

void draw_map(void)
{
    //図形の色 (白)
    static const GLfloat white[] = { 0.9, 0.9, 0.9, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, white);
    
    for(int r=0;r<MAP_HEIGHT;++r){
        for(int c=0;c<MAP_WIDTH;++c){
            glPushMatrix();{
                //床
                glTranslatef((c+0.5)*HEX_SIZE,-HEX_SIZE,(r+0.5)*HEX_SIZE);
                glutSolidCube(HEX_SIZE);
                if(map[r][c]==1){
                    //壁
                    glPushMatrix();{
                        glTranslatef(0,HEX_SIZE,0); //上に移動
                        drawRectangularPrism(HEX_SIZE / 4, HEX_SIZE, HEX_SIZE);
                    }glPopMatrix();
                }
            }glPopMatrix();
        }}
}