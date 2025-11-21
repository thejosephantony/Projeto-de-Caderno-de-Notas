#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;
using std::getline;



// definicao da classe

class LivroNotas {

public:
    // funcao que configura o nome do curso
    void setCursoNome(string nome){
        cursoNome = nome;          // armazena o nome do curso no objeto
    } // fim da funcao setCursoNome

    string getCursoNome(){
        return cursoNome;
    }


    // funcao que exibe uma mensagem ao usuario
    void mensagem(){

    cout << "Bem-vindo ao caderno de notas de " << getCursoNome() << "!\n" << endl;

    }   // fim da funcao mensagem
private:
    string cursoNome;
    }; // fim da classe LivroNotas


// a funcao main inicia a execucao do programa
int main(){
    string NomeDoCurso; // string de caracteres que armazena o nome do curso
    LivroNotas meuLivroNotas; // cria um objeto LivroNotas chamaado meuLivroNotas

    cout << "Nome inicial do curso �: " << meuLivroNotas.getCursoNome() << endl;

    cout << "Informe o seu curso: \n" <<endl;
    getline(cin, NomeDoCurso); // le o nome do curso com espacos em branco
    meuLivroNotas.setCursoNome(NomeDoCurso);
    cout << endl;

    meuLivroNotas.mensagem(); // exibe a mensagem com o novo nome do curso
    return 0;
    }


