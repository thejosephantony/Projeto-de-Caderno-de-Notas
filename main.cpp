#include <iostream>
#include <string>
#include <limits>

#include "LivroNotas.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

int main() {
    string nomeCurso;
    string nomeProfessor;

    cout << "Digite o nome do curso: ";
    getline(cin, nomeCurso);

    cout << "Digite o nome do professor: ";
    getline(cin, nomeProfessor);

    LivroNotas caderno(nomeCurso, nomeProfessor);

    int opcao;

    do {
        caderno.mensagem();

        cout << endl;
        cout << "1 - Cadastrar aluno" << endl;
        cout << "2 - Listar alunos" << endl;
        cout << "3 - Exibir estatisticas da turma" << endl;
        cout << "4 - Salvar dados em arquivo" << endl;
        cout << "0 - Sair" << endl;
        cout << endl;
        cout << "Escolha uma opcao: ";

        cin >> opcao;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << endl;
            cout << "Opcao invalida. Digite um numero." << endl;
            continue;
        }

        switch (opcao) {
            case 1:
                caderno.cadastrarAluno();
                break;

            case 2:
                caderno.listarAlunos();
                break;

            case 3:
                caderno.exibirEstatisticas();
                break;

            case 4: {
                string nomeArquivo;

                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                cout << "Digite o nome do arquivo para salvar: ";
                getline(cin, nomeArquivo);

                if (nomeArquivo.empty()) {
                    nomeArquivo = "relatorio_notas.txt";
                }

                caderno.salvarEmArquivo(nomeArquivo);
                break;
            }

            case 0:
                cout << endl;
                cout << "Encerrando o programa..." << endl;
                break;

            default:
                cout << endl;
                cout << "Opcao invalida." << endl;
                break;
        }

    } while (opcao != 0);

    return 0;
}
