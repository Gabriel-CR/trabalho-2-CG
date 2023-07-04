#include "controller.h"

//Controller::Controller() {
//    t = Vetor3D(0, 0, 0);
//    r = Vetor3D(0, 0, 0);
//    e = Vetor3D(1, 1, 1);

//    desenha_objetos = false;
//    selecionar = true;
//    draw_cenario = false;
//    s = (int)objetos.size() - 1;
//    cam_id = 0;
//}

void Controller::desenha() {
    GUI::displayInit();
    GUI::setLight(0, -5,5,3, true, false);
    GUI::setColor(1,0.6,0);
    GUI::drawFloor(15, 13);
    GUI::drawOriginAL(2.5);

    if (desenha_objetos) {
        for (int i = 0; i < (int)objetos.size(); i++) {
            if (objetos[i]->selecionado) {
                objetos[i]->translacao = t;
                objetos[i]->rotacao = r;
                objetos[i]->escala = e;
            }
            objetos[i]->desenha();
        }
    }

    if (cam_id == 2) {
        glutGUI::cam->rotatey(0, 1);
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

void Controller::teclado(unsigned char tecla, int mx, int my) {
    switch (tecla) {
    case 27:
        exit(0);
        break;
    case 'z':
        if (desenha_objetos) { objetos.push_back(new Cubo()); }
        break;
    case 't':
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;
    case 'l':
        glutGUI::trans_luz = !glutGUI::trans_luz;
        break;
    case 'i': // colocar objeto na alinhado com o global
        t = Vetor3D(0, 0, 0);
        r = Vetor3D(0, 0, 0);
        e = Vetor3D(1, 1, 1);
        break;
    case 'd':
        desenha_objetos = !desenha_objetos;
        break;
    case 'D':   // remove todos os elementos do vetor
        objetos.clear();
        break;
    case 'c':
        if (desenha_objetos) { objetos.push_back(new Cama()); }
        break;
    case 'C':
        if (desenha_objetos) { objetos.push_back(new Cadeira()); }
        break;
    case 'g':
        if (desenha_objetos) { objetos.push_back(new GuardaRoupa()); }
        break;
    case 'G':
        if (desenha_objetos) { objetos.push_back(new Geladeira()); }
        break;
    case 's':
        if (desenha_objetos) { objetos.push_back(new Sofa()); }
        break;
    case 'T':
        if (desenha_objetos) { objetos.push_back(new Televisao()); }
        break;
    case 'm':
        if (desenha_objetos) { objetos.push_back(new Mesa()); }
        break;
    case 'M':
        if (desenha_objetos) { objetos.push_back(new Microondas()); }
        break;
    case 'f':
        if (desenha_objetos) { objetos.push_back(new Fogao()); }
        break;
    case 'p':
        if (desenha_objetos) { objetos.push_back(new Pc()); }
        break;
    case 'P':
        if (desenha_objetos) { objetos.push_back(new Documento()); }
        break;
    case 'e':
        if (desenha_objetos) { objetos.push_back(new MesaPc()); }
        break;
    case 'a':
        if (desenha_objetos) { objetos.push_back(new Piscina()); }
        break;
    case 'E':
        if (desenha_objetos) { objetos.push_back(new Escorregador()); }
        break;
    case 'v':
        if (desenha_objetos) { objetos.push_back(new VasoSanitario()); }
        break;
    case 'k':
        if (desenha_objetos) { objetos.push_back(new Pia()); }
        break;
    case 'V':
        if (desenha_objetos) { objetos.push_back(new Chuveiro()); }
        break;
    case 'o':
        if (desenha_objetos) { objetos.push_back(new Parede()); }
        break;
    case 'O':
        if (desenha_objetos) { objetos.push_back(new Teto()); }
        break;

    case 'n':
        if (desenha_objetos) {
            cenario();
        }
        break;
    case 'Q':
        trocar_camera();
        break;
    case 'F':
        if (s > -1) { apagar_objeto(); }
        break;
    case 'A':
        if (s > -1) { apagar_ultimo_objeto(); }
        break;
    case 'L':
        objetos[s]->desenha_local = !objetos[s]->desenha_local;
        break;
    case '-':
        if (objetos.size() > 0) { selecionar_anterior(); }
        break;
    case '+':
        if (objetos.size() > 0) { selecionar_proximo(); }
        break;
    case '/':
        selecionar = !selecionar;
        objetos[s]->selecionado = false;
        break;

    default:
        break;
    }
}

void Controller::cenario() {
    cout << "desenhando..." << endl;
    objetos.clear();

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

    objetos.push_back(new Parede( Vetor3D(3, 0, 0), Vetor3D(0, 0, 0), Vetor3D(0, 0, 0) ));
    objetos.push_back(new Teto( Vetor3D(3, 2, 0), Vetor3D(0, 0, 0), Vetor3D(0, 0, 0) ));
}

void Controller::trocar_camera() {
    (cam_id + 1 > 6) ? cam_id = 0 : cam_id += 1;

    switch (cam_id) {
    case 0:
        glutGUI::cam = new CameraDistante(0,10,20, 0,0,0, 0,1,0);
        break;
    case 1:
        glutGUI::cam = new CameraDistante(-4.59024,38.9058,4.10113,  0,-0.223607,0,  0,1,0);
        break;
    case 2:
        glutGUI::cam = new CameraDistante(-18.6038,4.64228,-10.1431,  0,0,0,  0,1,0);
        break;
    case 3:
        glutGUI::cam = new CameraDistante(-20,4,0,  0,0,0,  0,1,0);
        break;
    case 4:
        glutGUI::cam = new CameraJogo(-1.5,2,0,  0,2,0,  0,1,0);
        break;
    case 5:
        glutGUI::cam = new CameraJogo(-1.5,2,4,  0,2,4,  0,1,0);
        break;
    case 6:
        glutGUI::cam = new CameraJogo(-5,2,-5,  -2,0,0,  0,1,0);
        break;
    }
}

void Controller::apagar_objeto() {
    objetos.erase(objetos.begin() + s);
}

void Controller::apagar_ultimo_objeto() {
    objetos.pop_back();
}

void Controller::zerar_vetores() {
    t = objetos[s]->translacao;
    r = objetos[s]->rotacao;
    e = objetos[s]->escala;
}

void Controller::selecionar_anterior() {
    if (selecionar) {
        if (s == -1) { s = 0; }
        objetos[s]->selecionado = false;
        (s == 0) ? s = objetos.size() - 1 : s -= 1;
        objetos[s]->selecionado = true;
        zerar_vetores();
    }
}

void Controller::selecionar_proximo() {
    if (selecionar) {
        if (s == (int)objetos.size() - 1) {
            objetos[s]->selecionado = false;
        }

        s = (s + 1) % (int)objetos.size();

        zerar_vetores();

        if (s == 0) {
            objetos[s]->selecionado = true;
        } else {
            objetos[s]->selecionado = true;
            objetos[s - 1]->selecionado = false;
        }
    }
}
