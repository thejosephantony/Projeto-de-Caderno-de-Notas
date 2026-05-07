#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

class LivroNotas {
public:
    // Construtor
    LivroNotas(string nomeCurso, string nomeProfessor) {
        setCursoNome(nomeCurso);
        setProfessorNome(nomeProfessor);
    }

    void setCursoNome(string nomeCurso) {
        cursoNome = nomeCurso;
    }

    string getCursoNome() {
        return cursoNome;
    }

    void setProfessorNome(string nomeProfessor) {
        professorNome = nomeProfessor;
    }

    string getProfessorNome() {
        return professorNome;
    }

    void mensagem() {
        cout << "Bem-vindo ao caderno de notas do curso: "
             << getCursoNome() << endl;

        cout << "Professor: " << getProfessorNome() << endl;
        cout << endl;
    }

    void cadastrarAluno() {
        cout << "Digite o nome do aluno: ";
        getline(cin, alunoNome);

        cout << "Digite a primeira nota: ";
        cin >> nota1;

        cout << "Digite a segunda nota: ";
        cin >> nota2;
    }

    double calcularMedia() {
        return (nota1 + nota2) / 2;
    }

    void exibirResultado() {
        double media = calcularMedia();

        cout << endl;
        cout << "===== RESULTADO DO ALUNO =====" << endl;
        cout << "Aluno: " << alunoNome << endl;
        cout << "Curso: " << cursoNome << endl;
        cout << "Nota 1: " << nota1 << endl;
        cout << "Nota 2: " << nota2 << endl;
        cout << "Media: " << media << endl;

        if (media >= 7.0) {
            cout << "Situacao: Aprovado" << endl;
        } else {
            cout << "Situacao: Reprovado" << endl;
        }
    }

private:
    string cursoNome;
    string professorNome;
    string alunoNome;
    double nota1;
    double nota2;
};

int main() {
    LivroNotas livroNotas1("Estruturas de Dados", "Joseph Antony");

    livroNotas1.mensagem();

    livroNotas1.cadastrarAluno();

    livroNotas1.exibirResultado();

    return 0;
}

