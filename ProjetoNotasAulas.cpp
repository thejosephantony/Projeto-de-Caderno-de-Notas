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
    // o construtor aqui inicializa CursoNome com a string fornecida como argumetno
    LivroNotas( string nome){
        setCursoNome(nome);
    }

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

    // cria dois objetos LivroNotas

    LivroNotas livroNotas1("Estruturas de Dados\n");
    LivroNotas livroNotas2("Arquitetura de Computadores\n");

     // exibe valor inicial de courseName para cada LivroNotas
    cout << "livroNotas1 criados para o curso: " << livroNotas1.getCursoNome()
    << "livroNotas2 criados para o curso: " << livroNotas2.getCursoNome() << endl;

    return 0;
    }



