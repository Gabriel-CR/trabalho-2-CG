#include <iostream>

using namespace std;

#include <gui.h>
#include <vector>
#include <objeto.h>

#include <shape.h>
#include <cama.h>
#include <mesapc.h>
#include <pc.h>
#include <documento.h>
#include <cadeira.h>
#include <guardaroupa.h>
#include <sofa.h>
#include <televisao.h>
#include <piscina.h>
#include <escorregador.h>
#include <parede.h>

#include <mesa.h>
#include <cubo.h>
#include <fogao.h>
#include <geladeira.h>
#include <microondas.h>
#include <vasosanitario.h>
#include <pia.h>
#include <chuveiro.h>
#include <teto.h>

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
GLfloat k = 0.0;
float distancia = 10.0;
int view_port = 1;
int cam_id = 1;
bool viewports = false;
bool scissored = false;
bool ortho = false;
bool enable_pick = false;

int pontoSelecionado = 0; //names = [1,n] //n = pontosControle.size()
//bool transPontos = glutGUI::trans_obj; //= true;

void trocar_camera() {
    (cam_id + 1 > 7) ? cam_id = 0 : cam_id += 1;

    switch (cam_id) {
    case 0:
        glutGUI::cam = new CameraDistante(0,10,20, 0,0,0, 0,1,0);
        break;
    case 1:
        glutGUI::cam = new CameraDistante(4.89371,2.08418,6.21982,  4,0,0,  0,1,0);
        break;
    case 2:
        glutGUI::cam = new CameraDistante(3.96518,2.87032,5.51583, 4.04424,0.0180712,-0.0114385, 0,1,0);
        break;
    case 3:
        glutGUI::cam = new CameraDistante(2.9813,3.00707,4.62673,  5.41546,0.179585,3.12905,  0,1,0);
        break;
    case 4:
        glutGUI::cam = new CameraDistante(4.78903,2.7093,5.65548, 4.0221,-0.0190038,0.00617758, 0,1,0);
        break;
    case 5:
        glutGUI::cam = new CameraDistante(-15.7642,5.73366,-5.55515, -5.46877,0.722722,-5.57549, 0,1,0);
        break;
    case 6:
        glutGUI::cam = new CameraDistante(-16.7051,2.92491,-5.5601, -5.46877,0.722722,-5.57549, 0,1,0);
        break;
    case 7:
        glutGUI::cam = new CameraDistante(-15.7477,2.54459,-0.871436, -5.46877,0.722722,-5.57549, 0,1,0);
        break;
    }
}

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

    if (view_port == 1) {
        GUI::glScissoredViewport(0, 0, width/4, height/4);
        glLoadIdentity();
        glLoadIdentity();
        gluLookAt(-20,5,0, 0,0,0, 0,1,0);
            cenario();
    } else if (view_port == 2) {
        GUI::glScissoredViewport(0, 0, width/4, height/4);
        glLoadIdentity();
        gluLookAt(0,28,0, 0,0,0, 0,0,1);
            cenario();
    } else if (view_port == 3) {
        GUI::glScissoredViewport(0, 0, width/4, height/4);
        glLoadIdentity();
        gluLookAt(-8,4,20, 0,0,0, 0,1,0);
            cenario();
    }
}
//-------------------viewPorts------------------

void init_cenario() {
    cout << "desenhando..." << endl;

    objetos.push_back(new Cama( Vetor3D(1, 0, 5.3), Vetor3D(0, -90, 0), Vetor3D(0, 0, 0) ));
    objetos.push_back(new MesaPc( Vetor3D(1, 0, 2.3), Vetor3D(0, 0, 0), Vetor3D(0, 0, 0) ));
    objetos.push_back(new Pc( Vetor3D(0.2, 1.1, 2.3), Vetor3D(0, 0, 0), Vetor3D(0, 0, 0) ));
    objetos.push_back(new Documento( Vetor3D(1.7, 1.1, 2.3), Vetor3D(0, 0, 0), Vetor3D(0, 0, 0) ));
    objetos.push_back(new Cadeira( Vetor3D(1, 0, 2.7), Vetor3D(0, 180, 0), Vetor3D(0, 0, 0) ));
    objetos.push_back(new GuardaRoupa( Vetor3D(4, 0, 4), Vetor3D(0, -90, 0), Vetor3D(0, 0, 0) ));

    objetos.push_back(new Sofa( Vetor3D(3, 0, -1), Vetor3D(0, -90, 0), Vetor3D(0, 0, 0) ));
    objetos.push_back(new Sofa( Vetor3D(1, 0, 0.5), Vetor3D(0, 180, 0), Vetor3D(0, 0, 0) ));
    objetos.push_back(new Televisao( Vetor3D(1, 0, -3), Vetor3D(0, 0, 0), Vetor3D(0, 0, 0) ));

    objetos.push_back(new Chuveiro( Vetor3D(6, 0, 6.5), Vetor3D(0, 180, 0), Vetor3D(0, 0, 0) ));
    objetos.push_back(new Pia( Vetor3D(7.1, 1, 3), Vetor3D(0, 180, 0), Vetor3D(0, 0, 0) ));
    objetos.push_back(new VasoSanitario( Vetor3D(5, 0, 3), Vetor3D(0, 90, 0), Vetor3D(0, 0, 0) ));

    objetos.push_back(new Mesa( Vetor3D(5.5, 0, -2), Vetor3D(0, 0, 0), Vetor3D(0, 0, 0) ));
    objetos.push_back(new Cadeira( Vetor3D(5.5, 0, -3), Vetor3D(0, 0, 0), Vetor3D(0, 0, 0) ));
    objetos.push_back(new Cadeira( Vetor3D(5.5, 0, -1), Vetor3D(0, 180, 0), Vetor3D(0, 0, 0) ));

    objetos.push_back(new Geladeira( Vetor3D(0, 0, -5.8), Vetor3D(0, 0, 0), Vetor3D(0, 0, 0) ));
    objetos.push_back(new Fogao( Vetor3D(2, 0, -5.5), Vetor3D(0, 0, 0), Vetor3D(0, 0, 0) ));
    objetos.push_back(new GuardaRoupa( Vetor3D(5, 0, -6), Vetor3D(0, 0, 0), Vetor3D(-0.06, -0.5, 0) ));
    objetos.push_back(new Microondas( Vetor3D(5, 1.3, -6), Vetor3D(0, 0, 0), Vetor3D(0, 0, 0) ));

    objetos.push_back(new Piscina( Vetor3D(-4.7, 0.01, 2), Vetor3D(0, 90, 0), Vetor3D(0.5, 0.5, 0.5) ));
    objetos.push_back(new Escorregador( Vetor3D(-6, 0, -5), Vetor3D(0, 45, 0), Vetor3D(0, 0, 0) ));

//    objetos.push_back(new Parede( Vetor3D(3, 0, 0), Vetor3D(0, 0, 0), Vetor3D(0, 0, 0) ));
//    objetos.push_back(new Teto( Vetor3D(3, 2, 0), Vetor3D(0, 0, 0), Vetor3D(0, 0, 0) ));
}

void cenario() {
    GUI::setLight(0,-10.0,10.0,0.0,true,false,false,false,pontual);
    GUI::drawOrigin(2);

    GUI::setColor(1,0.6,0);
    GUI::drawFloor(15,15,0.05,0.05);

    desenhaPontosDeControle();
}

/*
* recebe a posição da luz e np (normal do plano)
* desenha a sombra de cada objeto em um plano
*/
void desenha_sombra(float lightPos[4], Vetor3D np, float k) {
    glPushMatrix();
        GUI::setColor(1,0.6,0);
        GUI::drawPlane(np, -k-0.0005, 25.0, 25.0, 0.5, 0.5);
    glPopMatrix();
    glPushMatrix();
        GLfloat sombra[4][4];
        GLfloat plano[4] = {np.x, np.y, np.z, k};
        GUI::shadowMatrix(sombra, plano, lightPos);
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
}

void sombra() {
    GUI::drawOrigin(0.5);

    for (int i = 0; i < (int)objetos.size(); ++i) {
        glPushMatrix();
            objetos[i]->desenha();
        glPopMatrix();
    }

    //-------------------sombra-------------------
    // permitir o usuario transladar a luz
    float lightPos[4] = {-10.0 + glutGUI::lx, 10.0 + glutGUI::ly, 0.0 + glutGUI::lz, pontual};
    // alterar entre luz pontual e luz distante com o uso do atributo pontual
    GUI::setLight(0,-10.0,10.0,0.0,true,false,false,false,pontual);
    //desenhando os objetos projetados
//    desenha_sombra(lightPos, Vetor3D(0, 0, 1), 0);
    desenha_sombra(lightPos, Vetor3D(0, 1, 0), 0);
    desenha_sombra(lightPos, Vetor3D(0, 0, 1), 10.0);
    desenha_sombra(lightPos, Vetor3D(-sqrt(2)/2, sqrt(2)/2, 0), 5.0);

    //-------------------sombra-------------------
}

void desenha() {
    GUI::displayInit();

    if (draw_shadow) {
        sombra();
    } else {
        cenario();
    }
    if (viewports) {
        viewPorts();
    }

    for (int i = 0; i < (int)objetos.size(); ++i) {
        glPushMatrix();
            objetos[i]->desenha();
        glPopMatrix();
    }

    if (pontoSelecionado != 0) {
        objetos[pontoSelecionado-1]->selecionado = true;
        objetos[pontoSelecionado-1]->translacao = t;
        objetos[pontoSelecionado-1]->rotacao = r;
        objetos[pontoSelecionado-1]->escala = e;
    }

    t.x += 2.0*glutGUI::dtx;
    t.y += 2.0*glutGUI::dty;
    t.z += 2.0*glutGUI::dtz;
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
    case 'V':
        view_port == 3 ? view_port = 1 : view_port++;
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
    case 'P':
        enable_pick = !enable_pick;
        break;
    case 'k':
        k -= 1.0;
        break;
    case 'K':
        k += 1.0;
        break;
    case 'c':
        trocar_camera();
        break;

    case '!':
        cout << glutGUI::cam->e.x << "," << glutGUI::cam->e.y << "," << glutGUI::cam->e.z << endl;
        cout << glutGUI::cam->c.x << "," << glutGUI::cam->c.y << "," << glutGUI::cam->c.z << endl;
        cout << endl;
        break;

    default:
        break;
    }
}

void mouse(int button, int state, int x, int y) {
    GUI::mouseButtonInit(button,state,x,y);

    // if the left button is pressed
    if (button == GLUT_LEFT_BUTTON && enable_pick) {
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

int main() {
    cout << "Hello World!" << endl;
    // precisa desenhar o cenario todo antes de iniciar o programa
    init_cenario();

    GUI gui = GUI(800,600,desenha,teclado,mouse);
}
