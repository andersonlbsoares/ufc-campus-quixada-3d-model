#include <iostream>

#include <vector>
#include <gui.h>
#include <fstream>
#include <sstream>

#include <trabalho01/objeto.h>
#include <trabalho01/caramujao.h> 
#include <trabalho01/banco.h>
#include <trabalho01/entrada.h>
#include <trabalho01/pedraFundamental.h>
#include <trabalho01/arvore.h>
#include <trabalho01/bloco.h>
#include <trabalho01/piso.h>

using namespace std;

int id = 0;

int idCamera = 0;

bool selecao = false;
bool editando = false;

vector<Objeto*> objetos;

void trocarCamera(){
    if(idCamera == 6){
        idCamera = 1;
    }else{
        idCamera++;
    }

    if(idCamera == 1){
        glutGUI::cam = new CameraDistante(24.77, 11.12, 27.56, 0, 0, 0, 0, 1, 0);
    }else if(idCamera == 2){
        glutGUI::cam = new CameraDistante(7.77223, 1.77327, -4.49384, 4.72906, 0.66237, 2.4915, -0.0576222, 0.989538, 0.132266);
    }else if (idCamera == 3){
        glutGUI::cam = new CameraJogo(5.65011, 0.946898, 17.5768, 1.48875, 0.280209, 3.4939, -0.012852, 0.998971, -0.043494);
    }else if (idCamera == 4){
        glutGUI::cam = new CameraJogo(-32.9998, 29.6562, -31.7999, 0, 1, 0, 0.38177, 0.847885, 0.367889);
    }else if (idCamera == 5){
        glutGUI::cam = new CameraJogo(4.41697, 1.10883, 13.6336, 1.0718, 0.0331828, 10.9031, -0.187255, 0.970347, -0.152848);
    }else if (idCamera == 6){
        glutGUI::cam = new CameraJogo(-16.7814, 1.38986, -3.70563, -2.08898, 0.795535, 1.76197, 0.0355054, 0.999282, 0.0132129);
    }




}

void carregar(){    // carrega do arquivo csv todos os objetos criados
    std::ifstream arquivo("objetos.csv");
    if (arquivo.is_open()) {
        string linha;

        while (getline(arquivo, linha)) {
            stringstream ss(linha);
            string valor;
            vector<string> valores;
            while (getline(ss, valor, ',')) {
                valores.push_back(valor);
            }
            if(stoi(valores[9]) == 1){
                objetos.push_back(new caramujao(stof(valores[0]),stof(valores[1]),stof(valores[2]),stof(valores[3]),stof(valores[4]),stof(valores[5]),stof(valores[6]),stof(valores[7]),stof(valores[8]),false,false,stoi(valores[9])));
            }
            else if(stoi(valores[9]) == 2){
                objetos.push_back(new banco(stof(valores[0]),stof(valores[1]),stof(valores[2]),stof(valores[3]),stof(valores[4]),stof(valores[5]),stof(valores[6]),stof(valores[7]),stof(valores[8]),false,false,stoi(valores[9])));
            }
            else if(stoi(valores[9]) == 3){
                objetos.push_back(new entrada(stof(valores[0]),stof(valores[1]),stof(valores[2]),stof(valores[3]),stof(valores[4]),stof(valores[5]),stof(valores[6]),stof(valores[7]),stof(valores[8]),false,false,stoi(valores[9])));
            }
            else if(stoi(valores[9]) == 4){
                objetos.push_back(new pedraFundamental(stof(valores[0]),stof(valores[1]),stof(valores[2]),stof(valores[3]),stof(valores[4]),stof(valores[5]),stof(valores[6]),stof(valores[7]),stof(valores[8]),false,false,stoi(valores[9])));
            }
            else if(stoi(valores[9]) == 5){
                objetos.push_back(new arvore(stof(valores[0]),stof(valores[1]),stof(valores[2]),stof(valores[3]),stof(valores[4]),stof(valores[5]),stof(valores[6]),stof(valores[7]),stof(valores[8]),false,false,stoi(valores[9])));
            }
            else if(stoi(valores[9]) == 6){
                objetos.push_back(new bloco(stof(valores[0]),stof(valores[1]),stof(valores[2]),stof(valores[3]),stof(valores[4]),stof(valores[5]),stof(valores[6]),stof(valores[7]),stof(valores[8]),false,false,stoi(valores[9])));
            }
            else if(stoi(valores[9]) == 7){
                objetos.push_back(new piso(stof(valores[0]),stof(valores[1]),stof(valores[2]),stof(valores[3]),stof(valores[4]),stof(valores[5]),stof(valores[6]),stof(valores[7]),stof(valores[8]),false,false,stoi(valores[9])));
            }
            

        }
        arquivo.close();
        selecao = true;
    } else {
        cout << "Erro ao abrir o arquivo" << endl;
    }
}

bool isArquivoVazio() {     // verifica se o arquivo csv está vazio
    std::ifstream arquivo("objetos.csv");
    arquivo.seekg(0, std::ios::end);  // move o ponteiro de leitura para o final do arquivo

    if (arquivo.tellg() == 0) {
        return true;
    } else {
        return false;
    }
}

void transformacoes(){
    if(selecao){
        objetos[id]->translacao.x += glutGUI::dtx;
        objetos[id]->translacao.y += glutGUI::dty;
        objetos[id]->translacao.z += glutGUI::dtz;
        objetos[id]->rotacao.x += glutGUI::dax;
        objetos[id]->rotacao.y += glutGUI::day;
        objetos[id]->rotacao.z += glutGUI::daz;
        objetos[id]->escala.x += glutGUI::dsx;
        objetos[id]->escala.y += glutGUI::dsy;
        objetos[id]->escala.z += glutGUI::dsz;
    }
}

void teclado(unsigned char tecla, int mx, int my) {
    GUI::keyInit(tecla,mx,my);

    switch(tecla){
    case 'l':
        glutGUI:: trans_luz = !glutGUI:: trans_luz;
        break;
    case 't':   // ativa/desativa a ediçao dos objetos
        objetos[id]->setSelecionado();
        editando = !editando;
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;
    case '1':
        objetos.push_back(new caramujao(0,0,1));
        selecao = true;
        break;
    case '2':
        objetos.push_back(new banco(0,0,2));
        selecao = true;
        break;
    case '3':
        objetos.push_back(new entrada(0,0,3));
        selecao = true;
        break;
    case '4':
        objetos.push_back(new pedraFundamental(0,0,4));
        selecao = true;
        break;
    case '5':
        objetos.push_back(new arvore(0,0,5));
        selecao = true;
        break;
    case '6':
        objetos.push_back(new bloco(0,0,6));
        selecao = true;
        break;
    case '7':
        objetos.push_back(new piso(0,0,7));
        selecao = true;
        break;
    case '0':
        trocarCamera();
        break;
    case ',':
        cout << "Posicao da camera: " << glutGUI::cam->e.x << ", " << glutGUI::cam->e.y << ", " << glutGUI::cam->e.z << ", " 
        << glutGUI::cam->c.x << ", " << glutGUI::cam->c.y << ", " << glutGUI::cam->c.z << ", "
        << glutGUI::cam->u.x << ", " << glutGUI::cam->u.y << ", " << glutGUI::cam->u.z << endl;
        break;
    case '+':   // seleciona o proximo objeto
        if(editando){
            if(id < objetos.size()-1){
                objetos[id]->setSelecionado();
                id = id+1;
                objetos[id]->setSelecionado();
            }else{
                objetos[id]->setSelecionado();
                id = 0;
                objetos[id]->setSelecionado();
            }
        }
        break;
    case '-':   // seleciona o objeto anterior
        if(editando){
            if(id > 0){
                objetos[id]->setSelecionado();
                id = id-1;
                objetos[id]->setSelecionado();
            }else{
                objetos[id]->setSelecionado();
                id = objetos.size()-1;
                objetos[id]->setSelecionado();
            }
        }
        break;
    case 127: //delete
        if(editando){
            if(objetos.size() > 0){
                objetos.erase(objetos.begin()+id);
                if(id > 0){
                    objetos[id-1]->setSelecionado();
                    id = id-1;
                }else{
                    objetos[id]->setSelecionado();
                }
            }
        }
        break;
    case 'e':
        if(editando){
            objetos[id]->setOrigem();
        }
        break;


    case 32: // tecla de espaço
        if(objetos.size() != 0){
        // salva em um csv
            std::ofstream arquivo("objetos.csv");
            if (arquivo.is_open()) {
                for(int a = 0; a < objetos.size(); a++){
                    arquivo << objetos[a]->getTranslacao().x << "," << objetos[a]->getTranslacao().y << "," << objetos[a]->getTranslacao().z << "," << objetos[a]->getRotacao().x << "," << objetos[a]->getRotacao().y << "," << objetos[a]->getRotacao().z << "," << objetos[a]->getEscala().x << "," << objetos[a]->getEscala().y << "," << objetos[a]->getEscala().z << "," << objetos[a]->getTipo() << std::endl;
                }
                cout << "Objetos Salvos" << endl;
                arquivo.close();
            } else {
                cout << "Erro ao salvar os objetos" << endl;
            }

        }else{
            cout << "Nenhum objeto criado para salvar" << endl;
        }
        break;


    case 8: //tecla backspace
        int valor = objetos.size();
        if(editando){
            if(objetos.size() > 0){
                if(objetos[valor] == objetos[id]){
                    if(id > 0){
                        objetos[id]->setSelecionado();
                        id = id-1;
                        objetos[id]->setSelecionado();
                    }else{
                        objetos[id]->setSelecionado();
                        id = objetos.size()-1;
                        objetos[id]->setSelecionado();
                    }
                    objetos.erase(objetos.begin()+valor);
                }else{
                    objetos.erase(objetos.begin()+valor);
                }
            }
        }
        break;
    }
}

void desenha() {
    GUI::displayInit();

    glClearColor(0.529, 0.808, 0.922, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    GUI::setLight(1, 0, 7, 0, true, false);
    GUI::setColor(0.1, 0.5, 0.1, 1, false);
    GUI::drawFloor(30, 30);

    if(idCamera == 3){
        if(glutGUI::cam->c.z < 32){
            glutGUI::cam->e.z -= 0.015;
            glutGUI::cam->c.z += 0.02;
        }
    }else if(idCamera == 6){
        if(glutGUI::cam->e.x < 0 ){
            glutGUI::cam->e.x += 0.035;
            glutGUI::cam->e.z += 0.005;
            glutGUI::cam->c.z += 0.02;
        }
    }


    if(isArquivoVazio() == false && objetos.size() == 0){
        carregar();
    }

    for (int i = 0; i < objetos.size(); ++i) {
        glPushMatrix();
            objetos[i]->desenha();
        glPopMatrix();
    }
    transformacoes();

    GUI::displayEnd();

}

int main()
{
    // int ajuda = 1;
    // while(ajuda == 1){
    //     objetos.push_back(new bloco(-12,0,7,0,180,0,1,1,1,false,false,6));
    //     objetos.push_back(new bloco(-5,0,7,0,180,0,1,1,1,false,false,6));
        
    //     objetos.push_back(new bloco(-12,0,-7,0,0,0,1,1,1,false,false,6));
    //     objetos.push_back(new bloco(-5,0,-7,0,0,0,1,1,1,false,false,6));
        
    //     objetos.push_back(new bloco(10,0,-7,0,90,0,1,1,1,false,false,6));

    //     objetos.push_back(new entrada(4,0,14,0,0,0,1,1,1,false,false,3));

    //     objetos.push_back(new piso(4,0,3,0,0,0,1,1,20,false,false,7));
    //     objetos.push_back(new piso(-4,0,0,0,90,0,1,1,15,false,false,7));
    //     objetos.push_back(new piso(5,0,-7,0,90,0,1,1,3,false,false,7));
    //     objetos.push_back(new piso(-5,0,0,0,0,0,1,1,7,false,false,7));
    //     objetos.push_back(new piso(-12,0,0,0,0,0,1,1,7,false,false,7));
        
    //     objetos.push_back(new pedraFundamental(2,0,12,0,90,0,1,1,1,false,false,4));

    //     objetos.push_back(new arvore(-4,0,13,0,0,0,1,1,1,false,false,5));
    //     objetos.push_back(new arvore(0,0,9,0,0,0,1,1,1,false,false,5));

    //     objetos.push_back(new caramujao(2,0,10,0,70,0,1,1,1,false,false,1));
    //     objetos.push_back(new caramujao(2,0,8,0,110,0,1,1,1,false,false,1));
    //     objetos.push_back(new caramujao(2,0,6,0,70,0,1,1,1,false,false,1));
    //     objetos.push_back(new caramujao(2,0,4,0,110,0,1,1,1,false,false,1));

    //     objetos.push_back(new caramujao(6,0,10,0,70,0,1,1,1,false,false,1));
    //     objetos.push_back(new caramujao(6,0,8,0,110,0,1,1,1,false,false,1));
    //     objetos.push_back(new caramujao(6,0,6,0,70,0,1,1,1,false,false,1));
    //     objetos.push_back(new caramujao(6,0,4,0,110,0,1,1,1,false,false,1));

    //     objetos.push_back(new banco(2.5,0,10,0,70,0,1,1,1,false,false,2));
    //     objetos.push_back(new banco(2.5,0,8,0,110,0,1,1,1,false,false,2));
    //     objetos.push_back(new banco(2.5,0,6,0,70,0,1,1,1,false,false,2));
    //     objetos.push_back(new banco(2.5,0,4,0,110,0,1,1,1,false,false,2));

    //     objetos.push_back(new banco(5.5,0,10,0,70,0,1,1,1,false,false,2));
    //     objetos.push_back(new banco(5.5,0,8,0,110,0,1,1,1,false,false,2));
    //     objetos.push_back(new banco(5.5,0,6,0,70,0,1,1,1,false,false,2));
    //     objetos.push_back(new banco(5.5,0,4,0,110,0,1,1,1,false,false,2));
    //     ajuda = 2;

    // }
    cout << "Hello World!" << endl;
    GUI gui = GUI(800,600, desenha, teclado);
}
