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

int pontoSelecionado = 0; //names = [1,n] //n = pontosControle.size()
//bool transPontos = glutGUI::trans_obj; //= true;

void desenhaPontosDeControle()
{
    //desenhando pontos de controle
    for (int i = 0; i < (int)objetos.size(); i++) {
        //definindo cor da selecao
        if (i == pontoSelecionado - 1) {
            GUI::setColor(1,1,1,1,true);
        } else {
            GUI::setColor(0,0,1,1,true);
        }
        //desenhando (definindo nomes para o picking)
        Vetor3D p = pontosControle[i];
        glPushName(i + 1); //não se deve definir name = 0!
//            GUI::drawSphere(p.x,p.y,p.z,0.2);
            objetos[i]->desenha();
        glPopName();
    }

    //teste triangulo
    glBegin(GL_TRIANGLES);
        glNormal3f(0,0,1); //definir a normal permite ver as cores mais vivas ao posicionar a iluminacao adequadamente
        GUI::setColor(1,1,1);
        glVertex3f(0,0,1);
        GUI::setColor(0,0,1,0.0);
        glVertex3f(2,0,1);
        GUI::setColor(0,1,0,0.0);
        glVertex3f(0,2,1);
    glEnd();
    //teste triangulo usando glColor (sem iluminacao)
    glDisable(GL_LIGHTING);
    glBegin(GL_TRIANGLES);
        glNormal3f(0,0,1);
        glColor4f(0,1,0,1);
        glVertex3f(-1,2,1);
        glColor4f(0,0,1,1);
        glVertex3f(-3,0,1);
        glColor4f(1,1,1,0);
        glVertex3f(-1,0,1);
    glEnd();
    glEnable(GL_LIGHTING);
}

//picking
int picking( GLint cursorX, GLint cursorY, int w, int h ) {
    int BUFSIZE = 512;
    GLuint selectBuf[512];

    GUI::pickingInit(cursorX,cursorY,w,h,selectBuf,BUFSIZE);

//de acordo com a implementacao original da funcao display
    //lembrar de nao inicializar a matriz de projecao, para nao ignorar a gluPickMatrix
    GUI::displayInit();
    //só precisa desenhar o que for selecionavel
    desenhaPontosDeControle();
//fim-de acordo com a implementacao original da funcao display

    //retornando o name do objeto (ponto de controle) mais proximo da camera (z minimo! *[matrizes de normalizacao da projecao])
    return GUI::pickingClosestName(selectBuf,BUFSIZE);
}
//-------------------picking------------------

//-------------------viewPorts------------------
bool viewports = false;
bool scissored = false;

void cenario();

//visao de duas cameras (duas viewports), viewport auxiliar sobrepondo a principal
void viewPorts() {
    float width = glutGUI::width;
    float height = glutGUI::height;

    glMatrixMode(GL_MODELVIEW);

    //viewport principal
    //glViewport(glutGUI::width/4, 2*glutGUI::height/4, glutGUI::width/4, glutGUI::height/4);
    glViewport(0, 0, width, height);
        glLoadIdentity();
        gluLookAt(glutGUI::cam->e.x,glutGUI::cam->e.y,glutGUI::cam->e.z, glutGUI::cam->c.x,glutGUI::cam->c.y,glutGUI::cam->c.z, glutGUI::cam->u.x,glutGUI::cam->u.y,glutGUI::cam->u.z);
            cenario();

    //viewport auxiliar sobrepondo a principal
    if (!scissored) {
        //misturando com a principal
        glViewport(0, 3*height/4, width/4, height/4);
    } else {
        //recortando/substituindo o pedaço
        GUI::glScissoredViewport(0, 3*height/4, width/4, height/4);
    }
        glLoadIdentity();
        Vetor3D eye = pontosControle[4];
        Vetor3D center = pontosControle[2];
        //gluLookAt(0,3,1, 0,0,0, 0,0,-1);
        gluLookAt(eye.x,eye.y,eye.z, center.x,center.y,center.z, 0.0,1.0,0.0);
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

    //GUI::setColor(1,1,1,1,true);
    //GUI::drawFloor(5,5,0.05,0.05);
    GUI::setColor(0,0,0);
    Desenha::drawGrid( 5, 0, 1, 1 );

    desenhaPontosDeControle();
}

void desenha() {
    GUI::displayInit();

    if (!viewports) {
        cenario();
    } else {
        viewPorts();
    }

    //transladando ponto selecionado atraves do picking
    //if (pontoSelecionado > 0 and pontoSelecionado <= objetos.size()) {
    if (pontoSelecionado!=0) {
        pontosControle[pontoSelecionado-1].x += 0.5*glutGUI::dtx;
        pontosControle[pontoSelecionado-1].y += 0.5*glutGUI::dty;
        pontosControle[pontoSelecionado-1].z += 0.5*glutGUI::dtz;
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
    case 's':
        scissored = !scissored;
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
                cout << pontoSelecionado << " " << pick << endl;
//                t = objetos[pontoSelecionado]->translacao;
//                r = objetos[pontoSelecionado]->rotacao;
//                e = objetos[pontoSelecionado]->escala;
                pontoSelecionado = pick;
                glutGUI::lbpressed = false;
            }
        }
    }
}

int main()
{
    cout << "Hello World!" << endl;

    int n = 1;
    float dist = 1.0;
    for (int i = 0; i < n; i++) {
        objetos.push_back(new Cadeira());
//        pontosControle.push_back( Vetor3D((i-n/2)*dist,1,0) );
        pontosControle.push_back( Vetor3D(objetos[i]->translacao) );
    }

    GUI gui = GUI(800,600,desenha,teclado,mouse);
}
