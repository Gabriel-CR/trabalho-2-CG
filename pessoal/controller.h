#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <vector>

using namespace std;

#include <gui.h>
#include <objeto.h>

#include <shape.h>

#include <cubo.h>
#include <sofa.h>
#include <televisao.h>
#include <cama.h>
#include <guardaroupa.h>
#include <cadeira.h>
#include <mesa.h>
#include <fogao.h>
#include <geladeira.h>
#include <microondas.h>
#include <pc.h>
#include <documento.h>
#include <mesapc.h>
#include <piscina.h>
#include <escorregador.h>
#include <vasosanitario.h>
#include <pia.h>
#include <chuveiro.h>
#include <parede.h>
#include <teto.h>

class Controller {
public:
    static Vetor3D t;
    static Vetor3D r;
    static Vetor3D e;

    static vector<Objeto*> objetos;
    static vector<float> coordenadas;

    static bool desenha_objetos;
    static bool selecionar;
    static bool draw_cenario;
    static int s;
    static int cam_id;

//    Controller();
    static void desenha();
    static void teclado(unsigned char tecla, int mx, int my);
    static void cenario();
    static void trocar_camera();
    static void apagar_objeto();
    static void apagar_ultimo_objeto();
    static void zerar_vetores();
    static void selecionar_anterior();
    static void selecionar_proximo();
};

#endif // CONTROLLER_H
