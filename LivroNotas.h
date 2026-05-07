#ifndef LIVRONOTAS_H
#define LIVRONOTAS_H

#include <string>
#include <vector>

using std::string;
using std::vector;

struct Aluno {
    string nome;
    vector<double> notas;

    double calcularMedia() const;
};

class LivroNotas {
public:
    LivroNotas(string nomeCurso, string nomeProfessor);

    void mensagem() const;
    void cadastrarAluno();
    void listarAlunos() const;
    void exibirEstatisticas() const;
    void salvarEmArquivo(string nomeArquivo) const;

private:
    string cursoNome;
    string professorNome;
    vector<Aluno> alunos;

    double calcularMediaTurma() const;
    double maiorMedia() const;
    double menorMedia() const;
    string situacao(double media) const;

    int lerQuantidadeNotas() const;
    double lerNota(int numeroNota) const;
};
