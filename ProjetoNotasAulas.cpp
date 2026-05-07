#include "LivroNotas.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;

double Aluno::calcularMedia() const {
    if (notas.empty()) {
        return 0.0;
    }

    double soma = 0.0;

    for (double nota : notas) {
        soma += nota;
    }

    return soma / notas.size();
}

LivroNotas::LivroNotas(string nomeCurso, string nomeProfessor) {
    cursoNome = nomeCurso;
    professorNome = nomeProfessor;
}

void LivroNotas::mensagem() const {
    cout << endl;
    cout << "======================================" << endl;
    cout << "        CADERNO DE NOTAS EM C++        " << endl;
    cout << "======================================" << endl;
    cout << "Curso: " << cursoNome << endl;
    cout << "Professor: " << professorNome << endl;
    cout << "======================================" << endl;
}

void LivroNotas::cadastrarAluno() {
    Aluno aluno;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << endl;
    cout << "Digite o nome do aluno: ";
    getline(cin, aluno.nome);

    int quantidadeNotas = lerQuantidadeNotas();

    for (int i = 1; i <= quantidadeNotas; i++) {
        double nota = lerNota(i);
        aluno.notas.push_back(nota);
    }

    alunos.push_back(aluno);

    cout << endl;
    cout << "Aluno cadastrado com sucesso!" << endl;
}

int LivroNotas::lerQuantidadeNotas() const {
    int quantidade;

    while (true) {
        cout << "Digite a quantidade de notas do aluno: ";
        cin >> quantidade;

        if (cin.fail() || quantidade <= 0) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Quantidade invalida. Digite um numero maior que zero." << endl;
        } else {
            return quantidade;
        }
    }
}

double LivroNotas::lerNota(int numeroNota) const {
    double nota;

    while (true) {
        cout << "Digite a nota " << numeroNota << ": ";
        cin >> nota;

        if (cin.fail() || nota < 0.0 || nota > 10.0) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Nota invalida. Digite uma nota entre 0 e 10." << endl;
        } else {
            return nota;
        }
    }
}

void LivroNotas::listarAlunos() const {
    if (alunos.empty()) {
        cout << endl;
        cout << "Nenhum aluno cadastrado." << endl;
        return;
    }

    cout << endl;
    cout << "=========== LISTA DE ALUNOS ===========" << endl;

    cout << std::fixed << std::setprecision(2);

    for (size_t i = 0; i < alunos.size(); i++) {
        double media = alunos[i].calcularMedia();

        cout << endl;
        cout << "Aluno " << i + 1 << endl;
        cout << "Nome: " << alunos[i].nome << endl;

        cout << "Notas: ";
        for (double nota : alunos[i].notas) {
            cout << nota << " ";
        }

        cout << endl;
        cout << "Media: " << media << endl;
        cout << "Situacao: " << situacao(media) << endl;
    }
}

void LivroNotas::exibirEstatisticas() const {
    if (alunos.empty()) {
        cout << endl;
        cout << "Nenhum aluno cadastrado para gerar estatisticas." << endl;
        return;
    }

    int aprovados = 0;
    int reprovados = 0;

    for (const Aluno& aluno : alunos) {
        if (aluno.calcularMedia() >= 7.0) {
            aprovados++;
        } else {
            reprovados++;
        }
    }

    cout << endl;
    cout << "========= ESTATISTICAS DA TURMA =========" << endl;
    cout << std::fixed << std::setprecision(2);

    cout << "Curso: " << cursoNome << endl;
    cout << "Professor: " << professorNome << endl;
    cout << "Quantidade de alunos: " << alunos.size() << endl;
    cout << "Media geral da turma: " << calcularMediaTurma() << endl;
    cout << "Maior media: " << maiorMedia() << endl;
    cout << "Menor media: " << menorMedia() << endl;
    cout << "Aprovados: " << aprovados << endl;
    cout << "Reprovados: " << reprovados << endl;
}

double LivroNotas::calcularMediaTurma() const {
    if (alunos.empty()) {
        return 0.0;
    }

    double soma = 0.0;

    for (const Aluno& aluno : alunos) {
        soma += aluno.calcularMedia();
    }

    return soma / alunos.size();
}

double LivroNotas::maiorMedia() const {
    if (alunos.empty()) {
        return 0.0;
    }

    double maior = alunos[0].calcularMedia();

    for (const Aluno& aluno : alunos) {
        if (aluno.calcularMedia() > maior) {
            maior = aluno.calcularMedia();
        }
    }

    return maior;
}

double LivroNotas::menorMedia() const {
    if (alunos.empty()) {
        return 0.0;
    }

    double menor = alunos[0].calcularMedia();

    for (const Aluno& aluno : alunos) {
        if (aluno.calcularMedia() < menor) {
            menor = aluno.calcularMedia();
        }
    }

    return menor;
}

string LivroNotas::situacao(double media) const {
    if (media >= 7.0) {
        return "Aprovado";
    }

    return "Reprovado";
}

void LivroNotas::salvarEmArquivo(string nomeArquivo) const {
    ofstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        cout << endl;
        cout << "Erro ao abrir o arquivo." << endl;
        return;
    }

    arquivo << std::fixed << std::setprecision(2);

    arquivo << "======================================" << endl;
    arquivo << "        RELATORIO DO CADERNO          " << endl;
    arquivo << "======================================" << endl;
    arquivo << "Curso: " << cursoNome << endl;
    arquivo << "Professor: " << professorNome << endl;
    arquivo << "======================================" << endl;

    if (alunos.empty()) {
        arquivo << "Nenhum aluno cadastrado." << endl;
    } else {
        for (size_t i = 0; i < alunos.size(); i++) {
            double media = alunos[i].calcularMedia();

            arquivo << endl;
            arquivo << "Aluno " << i + 1 << endl;
            arquivo << "Nome: " << alunos[i].nome << endl;

            arquivo << "Notas: ";
            for (double nota : alunos[i].notas) {
                arquivo << nota << " ";
            }

            arquivo << endl;
            arquivo << "Media: " << media << endl;
            arquivo << "Situacao: " << situacao(media) << endl;
        }

        arquivo << endl;
        arquivo << "========= ESTATISTICAS DA TURMA =========" << endl;
        arquivo << "Quantidade de alunos: " << alunos.size() << endl;
        arquivo << "Media geral da turma: " << calcularMediaTurma() << endl;
        arquivo << "Maior media: " << maiorMedia() << endl;
        arquivo << "Menor media: " << menorMedia() << endl;
    }

    arquivo.close();

    cout << endl;
    cout << "Dados salvos no arquivo: " << nomeArquivo << endl;
}
