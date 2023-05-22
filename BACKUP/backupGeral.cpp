#include <iostream>
#include <gui.h>

using namespace std;


float px = 0.0;
float py = 0.0;
double raio = 0.0;
float a = 0.0;
float b = 0.0;
float theta = 0.0;
float thetaPelvis = 0.0;
float thetaTronco = 0.0;
float thetaBracoEsq = 0.0;
float thetaBracoDir = 0.0;



void piramide()
{
    glBegin(GL_POLYGON);
        glNormal3f(0,1,1);
        glVertex3f(1,1,1);
        glVertex3f(0,2,0);
        glVertex3f(-1,1,1);
    glEnd();
    glBegin(GL_POLYGON);
        glNormal3f(0,1,-1);
        glVertex3f(-1,1,-1);
        glVertex3f(0,2,0);
        glVertex3f(1,1,-1);
    glEnd();
    //errado
    glBegin(GL_POLYGON);
        glNormal3f(1,1,0);
        glVertex3f(1,1,1);
        glVertex3f(1,1,-1);
        glVertex3f(0,2,0);
    glEnd();
    glBegin(GL_POLYGON);
        glNormal3f(1,1,0);
        glVertex3f(-1,1,-1);
        glVertex3f(-1,1,1);
        glVertex3f(0,2,0);
    glEnd();
}

void teste(){

    glBegin(GL_POLYGON);
        glNormal3f(1,1,0);
        glVertex3f(1,0,1);
        glVertex3f(1,0,-1);
        glVertex3f(1,1,1);

    glEnd();
}

void casinha()
{
    GUI::drawBox(-0.9,0,-0.9,0.9,1,0.9,false);

    GUI::setColor(1,0,0);

    piramide();

    GUI::setColor(0,1,0);

    GUI::drawBox(-0.25, 0, -1, 0.25, 0.75, -1, false);
}

void moverComMouse()
{
    px += 2*glutGUI::dtx;
    py += 2*glutGUI::dty;
    raio += 0.02*glutGUI::dax;
    theta += 0.1*glutGUI::daz;
}

void base()
{
    GUI::displayInit();
    GUI::setLight(0,0,2,2,true,false);
    GUI::setColor(2,2,2);
    GUI::drawFloor();
    GUI:: drawOrigin();

    GUI::setColor(0,0,1);
}

 Vetor3D rotacao (Vetor3D v){
     Vetor3D vt;
//     vt.x = cos(thetaRad)*v.x - sin(thetaRad)*v.y;
//     vt.y = sin(thetaRad)*v.x + cos(thetaRad)*v.y;
//     vt.z = v.z;
 }

Vetor3D translacao (Vetor3D v, Vetor3D desl){
    Vetor3D vt;
    vt.x = v.x + desl.x;
    vt.y = v.y + desl.y;
    vt.z = v.z + desl.z;
    return vt;
}

void personagem() {


    float static tx = 0.0;
    float static ty = 0.0;
    float static tz = 0.0;
    float static rx = 0.0;
    float static ry = 0.0;
    float static rz = 0.0;
    float static sx = 1.0;
    float static sy = 1.0;
    float static sz = 1.0;

    tx += 0.5*glutGUI::dtx;
    ty += 0.5*glutGUI::dty;
    tz += 0.5*glutGUI::dtz;
    rx += 0.5*glutGUI::dax;
    ry += 0.5*glutGUI::day;
    rz += 0.5*glutGUI::daz;
    sx += 0.5*glutGUI::dsx;
    sy += 0.5*glutGUI::dsy;
    sz += 0.5*glutGUI::dsz;




    // px += 0.5*glutGUI::dtx;
    // py += 0.5*glutGUI::dty;
    // raio += 0.02*glutGUI::dax;
    // theta += 0.1*glutGUI::daz;

    // thetaTronco += 10*glutGUI::dsx;
    // thetaPelvis += 10*glutGUI::dsy;
    // thetaBracoDir += 10*glutGUI::dax;
    // thetaBracoEsq += 10*glutGUI::day;


        glTranslatef(tx,ty,tz);
        glRotatef(rx, 1, 0, 0);
        glRotatef(ry, 0, 1, 0);
        glRotatef(rz, 0, 0, 1);
        glScalef(sx,sy,sz);

    glPushMatrix();
        // glTranslatef(px,py,0);
        // glRotatef(thetaPelvis,0,0,1);

        GUI::drawBox(-0.2,-0.1,-0.1,0.2,0.1,0.1); // pelvis

        glPushMatrix(); // tronco
            glTranslatef(0,0.1,0);
            glRotatef(thetaTronco,0,0,1);
            GUI::drawBox(-0.15,0.0,-0.1,0.15,0.4,0.1); 
        GUI::setColor(1,0,0);
            glPushMatrix(); // BE
                glTranslatef(0.15,0.4,0);
                glRotatef(thetaBracoEsq,0,0,1);
                GUI::drawBox(-0.05,-0.5,-0.1,0.05,0.0,0.1); 
            glPopMatrix();
            glPushMatrix(); // BD
                glTranslatef(-0.15,0.4,0);
                glRotatef(thetaBracoDir,0,0,1);
                GUI::drawBox(-0.05,-0.5,-0.1,0.05,0.0,0.1); 
            glPopMatrix();
        glPopMatrix();


         


    glPopMatrix();

}



void desenha() {
    base();
    moverComMouse();

    personagem();

    GUI::setColor(1,0,0);
    GUI::displayEnd();
}




void teclado(unsigned char tecla, int mx, int my) {
    GUI::keyInit(tecla,mx,my);

    switch(tecla){
    case 'l':
        glutGUI:: trans_luz = !glutGUI:: trans_luz;
        break;
    case 't':
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;
    case 'a':
        px -= 0.1;
        break;
    case 'd':
        px += 0.1;
        break;
    case 's':
        py -= 0.1;
        break;
    case 'w':
        py += 0.1;
        break;
    case 'E':
        glutGUI:: slices += 5;
        glutGUI:: stacks += 5;
        break;
    case 'e':
        glutGUI:: slices -= 5;
        glutGUI:: stacks -= 5;
        break;

    }

}


int main()
{
    GUI gui = GUI(800,600,desenha, teclado);
}


//inicializando OpenGL
//while(true) {
//    desenha();
//    interacaoUsuario();
//    //if () {
//    //    break;
//    //}
//}





















//adicionar:
//-deslocar cubo com o teclado
//-deslocar cubo com o mouse
//-primitivas OpenGL (glBegin, glEnd)
//-glNormal, iluminação

//-leitor 3DS
//-usar as transformacoes matriciais do proprio OpenGL
//-push/popMatrix (podem ser usados um dentro do outro - nocao de pilha)

//-ordem das transformacoes
//  -translacao e rotacao
//  -testar escala!!!
//-interpretacao de uma composicao de transformacoes já definida
//      <----------- globais
//  -   T.Rz.Ry.Rx.S . v
//      -----------> locais
//  -direita->esquerda: Transfs globais
//  -esquerda->direita: Transfs locais
