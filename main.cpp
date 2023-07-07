#include <iostream>

using namespace std;

#include <gui.h>
#include <vector>
#include "cadeira.h"

//-------------------picking------------------
vector<Vetor3D> pontosControle;
vector<Objeto*> objetos;
Vetor3D t = Vetor3D(0, 0, 0);
Vetor3D r = Vetor3D(0, 0, 0);
Vetor3D e = Vetor3D(1, 1, 1);
bool draw_shadow = false;
bool draw_shadow_objeto = true;
bool pontual = false;
bool luzesEscondidas = true;
float k = 0.0;
float distancia = 3.0;

bool viewports = false;
bool scissored = false;

int pontoSelecionado = 0; //names = [1,n] //n = pontosControle.size()
//bool transPontos = glutGUI::trans_obj; //= true;

void desenhaPontosDeControle() {
    // desenhando objetos selecionáveis do cenário
    for (int i = 0; i < (int)objetos.size(); i++) {
        glPushName(i + 1); // não se deve definir name = 0!
            objetos[i]->desenha();
        glPopName();
    }
}

//picking
int picking( GLint cursorX, GLint cursorY, int w, int h ) {
    int BUFSIZE = 512;
    GLuint selectBuf[512];

    GUI::pickingInit(cursorX,cursorY,w,h,selectBuf,BUFSIZE);

    // de acordo com a implementacao original da funcao display
    // lembrar de nao inicializar a matriz de projecao, para nao ignorar a gluPickMatrix
    GUI::displayInit();
    // só precisa desenhar o que for selecionavel
    desenhaPontosDeControle();
    // fim-de acordo com a implementacao original da funcao display

    // retornando o name do objeto (ponto de controle) mais proximo da camera (z minimo! *[matrizes de normalizacao da projecao])
    return GUI::pickingClosestName(selectBuf,BUFSIZE);
}
//-------------------picking------------------

//-------------------viewPorts------------------
void cenario();

//visao de duas cameras (duas viewports), viewport auxiliar sobrepondo a principal
void viewPorts() {
    float width = glutGUI::width;
    float height = glutGUI::height;

    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, width, height);
        glLoadIdentity();
        gluLookAt(glutGUI::cam->e.x,glutGUI::cam->e.y,glutGUI::cam->e.z, glutGUI::cam->c.x,glutGUI::cam->c.y,glutGUI::cam->c.z, glutGUI::cam->u.x,glutGUI::cam->u.y,glutGUI::cam->u.z);
            cenario();

    glViewport(0, 3*height/4, width/4, height/4);
    glLoadIdentity();
    glLoadIdentity();
    gluLookAt(distancia,0,0, 0,0,0, 0,1,0);
        cenario();

    glViewport(0, 3*height/8, width/4, height/4);
    glLoadIdentity();
    gluLookAt(0,distancia,0, 0,0,0, 0,0,-1);
        cenario();

    glViewport(0, 0, width/4, height/4);
    glLoadIdentity();
    gluLookAt(0,0,distancia, 0,0,0, 0,1,0);
        cenario();
}
//-------------------viewPorts------------------

void cenario() {
    //GUI::setLight(1,1,3,5,true,false);               //multiplas fontes de luz
    //GUI::setLight(2,-1.5,0.5,-1,true,false);         //multiplas fontes de luz
    GUI::setLight(3,-5,3,5,true,false);
    //GUI::setLight(3,-5,3,5,true,true); //atenuada
    //GUI::setLight(3,-5,3,5,true,false,false,false,true,true); //spot (holofote, lanterna)

    GUI::drawOrigin(0.5);

    GUI::setColor(1,1,1,1,true);
    GUI::drawFloor(5,5,0.05,0.05);
//    GUI::setColor(0,0,0);
//    Desenha::drawGrid( 5, 0, 1, 1 );

    desenhaPontosDeControle();
}

void sombra() {
//    GUI::setLight(4,1,3,5,true,false,false,luzesEscondidas);
//    GUI::setLight(5,-1.5,0.5,-1,true,false,false,luzesEscondidas);
//    GUI::setLight(6,-5,3,5,true,false,false,luzesEscondidas);

    GUI::drawOrigin(0.5);

    //GUI::setColor(1,0,0);
    GUI::setColor(0.6,0.4,0.0);
    glPushMatrix();
        //-------------------sombra-------------------
        glTranslated(0.0,k,0.0); //glTranslated(0.0,k-0.001,0.0);
        GUI::drawFloor(25,25); //-0.001 definido dentro do drawFloor
        //-------------------sombra-------------------
    glPopMatrix();

    for (int i = 0; i < (int)objetos.size(); ++i) {
        glPushMatrix();
            /*
             * Fazer um if para caso não seja para mostrar a combra do objeto selecionado
             */
            objetos[i]->desenha();
        glPopMatrix();
    }

    //-------------------sombra-------------------
    //definindo a luz que sera usada para gerar a sombra
    float lightPos[4] = {1.5 + glutGUI::lx, 1.5 + glutGUI::ly, 1.5 + glutGUI::lz, pontual};
    GUI::setLight(0,1.5,1.5,1.5,true,false,false,false,pontual);
    //desenhando os objetos projetados
    glPushMatrix();
            GLfloat sombra[4][4];
            GUI::shadowMatrixYk(sombra,lightPos,k);
            glMultTransposeMatrixf( (GLfloat*)sombra );

        glDisable(GL_LIGHTING);
        glColor3d(0.0,0.0,0.0);
        if (draw_shadow) {
            bool aux = glutGUI::draw_eixos;
            glutGUI::draw_eixos = false;
            for (int i = 0; i < (int)objetos.size(); ++i) {
                glPushMatrix();
                    if (!(!draw_shadow_objeto && i == pontoSelecionado - 1)) {
                        objetos[i]->desenha();
                    }
                glPopMatrix();
            }
            glutGUI::draw_eixos = aux;
        }
        glEnable(GL_LIGHTING);
    glPopMatrix();
    //-------------------sombra-------------------
}

void desenha() {
    GUI::displayInit();

    if (draw_shadow) {
        sombra();
    } else if (viewports) {
        viewPorts();
    } else {
        cenario();
    }

    for (int i = 0; i < (int)objetos.size(); ++i) {
        glPushMatrix();
            objetos[i]->desenha();
        glPopMatrix();
    }

    if (pontoSelecionado != 0) {
//        pontosControle[pontoSelecionado-1].x += 0.5*glutGUI::dtx;
//        pontosControle[pontoSelecionado-1].y += 0.5*glutGUI::dty;
//        pontosControle[pontoSelecionado-1].z += 0.5*glutGUI::dtz;
        objetos[pontoSelecionado-1]->selecionado = true;
        objetos[pontoSelecionado-1]->translacao = t;
        objetos[pontoSelecionado-1]->rotacao = r;
        objetos[pontoSelecionado-1]->escala = e;
    }

    t.x += glutGUI::dtx;
    t.y += glutGUI::dty;
    t.z += glutGUI::dtz;
    r.x += 4.0*glutGUI::dax;
    r.y += 4.0*glutGUI::day;
    r.z += 4.0*glutGUI::daz;
    e.x += glutGUI::dsx;
    e.y += glutGUI::dsy;
    e.z += glutGUI::dsz;

    GUI::displayEnd();
}

void teclado(unsigned char key, int x, int y) {
    GUI::keyInit(key,x,y);

    switch (key) {
    case 't':
        glutGUI::trans_obj = !glutGUI::trans_obj;
        //transPontos = glutGUI::trans_obj;
        break;
    case 'l':
        glutGUI::trans_luz = !glutGUI::trans_luz;
        break;

    case 'v':
        viewports = !viewports;
        break;
    case '+':
        distancia += 1.0;
        break;
    case '-':
        distancia > 3 ? distancia -= 1.0 : distancia = 3.0;
        break;
    case 's':
        draw_shadow_objeto = !draw_shadow_objeto;
        break;
    case 'd':
        draw_shadow = !draw_shadow;
        break;
    case 'p':
        pontual = !pontual;
        break;

    default:
        break;
    }
}

void mouse(int button, int state, int x, int y) {
    GUI::mouseButtonInit(button,state,x,y);

    // if the left button is pressed
    if (button == GLUT_LEFT_BUTTON) {
        // when the button is pressed
        if (state == GLUT_DOWN) {
            //picking
            int pick = picking( x, y, 5, 5 );
            if (pick != 0) {
                if (pontoSelecionado - 1 >= 0) {
                    objetos[pontoSelecionado - 1]->selecionado = false;
                }
                pontoSelecionado = pick;
                t = objetos[pontoSelecionado-1]->translacao;
                r = objetos[pontoSelecionado-1]->rotacao;
                e = objetos[pontoSelecionado-1]->escala;
                objetos[pontoSelecionado-1]->selecionado = true;
                glutGUI::lbpressed = false;
            }
        }
    }
}

int main()
{
    cout << "Hello World!" << endl;
    objetos.push_back(new Cadeira());
    objetos.push_back(new Cadeira());
    // precisa desenhar o cenario todo antes de iniciar o programa

    GUI gui = GUI(800,600,desenha,teclado,mouse);
}
