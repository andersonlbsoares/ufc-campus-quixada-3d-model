// scala, translada, e rotaciona
#include <iostream>
#include <gui.h>

using namespace std;

Model3DS carro = Model3DS("../3ds/cartest.3DS");

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

float static tx = 0.0;
float static ty = 0.0;
float static tz = 0.0;
float static rx = 0.0;
float static ry = 0.0;
float static rz = 0.0;
float static sx = 1.0;
float static sy = 1.0;
float static sz = 1.0;



void base()
{
    GUI::displayInit();
    GUI::setLight(0,0,2,2,true,false);
    GUI::setColor(2,2,2);
    GUI::drawFloor();
    GUI:: drawOrigin();
    GUI::setColor(0,0,1);
}


void banco(){
    GUI::drawOrigin(0.5);
    glPushMatrix();
        GUI::setColor(0.5,0.5,0.5);
        GUI::drawBox(0.5,0,-0.15,1.5,0.3,0.15);
        glPushMatrix();
            GUI::setColor(0.7,0.7,0.7);
            GUI::drawBox(0.45,0.3,-0.20,1.55,0.35,0.2);
        glPopMatrix();
    glPopMatrix();
}

void caramujao(){
    GUI::drawOrigin(0.5);
    glPushMatrix();
        GUI::setColor(0.2,0.2,0.2);
        GUI::drawBox(-0.1,0,-0.1,0.1,1,0.1);
        glPushMatrix();
            GUI::setColor(0.4,0.4,0.4);
            GUI::drawBox(-0.7,1,-0.15,0.7,1.1,0.15);
        glPopMatrix();
        glPushMatrix();
            GUI::setColor(0.6,0.6,0.6);
            GUI::drawBox(-0.7,1.1,-0.5,-0.6,1.2,0.5);
            GUI::drawBox(-0.5,1.1,-0.5,-0.4,1.2,0.5);
            GUI::drawBox(-0.3,1.1,-0.5,-0.2,1.2,0.5);
            GUI::drawBox(-0.1,1.1,-0.5,0.0,1.2,0.5);
            GUI::drawBox(0.1,1.1,-0.5,0.2,1.2,0.5);
            GUI::drawBox(0.3,1.1,-0.5,0.4,1.2,0.5);
            GUI::drawBox(0.5,1.1,-0.5,0.6,1.2,0.5);
        glPopMatrix();
    glPopMatrix();
}

void arbusto(){
    GUI::drawOrigin(0.5);
    glPushMatrix();
        GUI::setColor(0,0.5,0.01);
        //diminui o numero de poligonos da esfera
        glutSolidSphere(0.5,3,10);
        glutSolidSphere(0.5,3,10);
        glutSolidSphere(0.5,2,10);
        glRotatef(90,0,1,0);
        glutSolidSphere(0.5,3,10);
        //desenha uma flor no topo do arbusto
        glPushMatrix();
            glTranslatef(0,0.5,0);
            GUI::setColor(1,0,0);
            glutSolidSphere(0.1,3,10);
            glPushMatrix();
                glTranslatef(0,0.1,0);
                GUI::setColor(1,1,0);
                glutSolidSphere(0.05,3,10);
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void personagem() {
    GUI::drawOrigin(0.5);
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
                thetaBracoEsq -= 0.8;
                GUI::drawBox(-0.05,-0.5,-0.1,0.05,0.0,0.1); 
            glPopMatrix();
            glPushMatrix(); // BD
                glTranslatef(-0.15,0.4,0);
                glRotatef(thetaBracoDir,0,0,1);
                thetaBracoDir += 0.8;
                GUI::drawBox(-0.05,-0.5,-0.1,0.05,0.0,0.1); 
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}



void desenha() {
    base();
    caramujao();
    banco();
    arbusto();
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
    case 'i':
        tx = 0.0;
        ty = 0.0;
        tz = 0.0;
        rx = 0.0;
        ry = 0.0;
        rz = 0.0;
        sx = 1.0;
        sy = 1.0;
        sz = 1.0;
        break;

    }

}


int main()
{
    GUI gui = GUI(800,600,desenha, teclado);





}



















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
