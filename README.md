# Caderno de Notas em C++

Este projeto é um programa simples desenvolvido em C++ com o objetivo de praticar conceitos básicos de Programação Orientada a Objetos, como classes, objetos, construtores, métodos públicos, atributos privados e encapsulamento.

O programa simula um pequeno caderno de notas de um curso, permitindo cadastrar informações do curso, professor, aluno, notas e calcular a média final.

## Objetivo

O objetivo principal do projeto é demonstrar o uso de uma classe em C++ para organizar dados e comportamentos relacionados a um caderno de notas.

A classe `LivroNotas` é responsável por armazenar informações do curso e do aluno, além de calcular e exibir o resultado final.

## Funcionalidades

O programa possui as seguintes funcionalidades:

- Cadastro do nome do curso;
- Cadastro do nome do professor;
- Cadastro do nome do aluno;
- Entrada de duas notas;
- Cálculo da média do aluno;
- Exibição da situação final: aprovado ou reprovado;
- Uso de métodos `set` e `get`;
- Uso de construtor para inicializar objetos.

## Conceitos utilizados

Este projeto utiliza os seguintes conceitos de C++:

- Classe;
- Objeto;
- Construtor;
- Encapsulamento;
- Atributos privados;
- Métodos públicos;
- Entrada e saída de dados;
- Estrutura condicional `if/else`;
- Tipo `string`;
- Tipo `double`.

## Estrutura da classe

A classe principal do projeto é chamada de `LivroNotas`.

Ela possui os seguintes atributos privados:

```cpp
string cursoNome;
string professorNome;
string alunoNome;
double nota1;
double nota2;
```

E os principais métodos:

```cpp
void setCursoNome(string nomeCurso);
string getCursoNome();

void setProfessorNome(string nomeProfessor);
string getProfessorNome();

void mensagem();
void cadastrarAluno();
double calcularMedia();
void exibirResultado();
```

## Exemplo de execução

```txt
Bem-vindo ao caderno de notas do curso: Estruturas de Dados
Professor: Joseph Antony

Digite o nome do aluno: Carlos
Digite a primeira nota: 8
Digite a segunda nota: 6

===== RESULTADO DO ALUNO =====
Aluno: Carlos
Curso: Estruturas de Dados
Nota 1: 8
Nota 2: 6
Media: 7
Situacao: Aprovado
```

## Como compilar

Para compilar o programa no terminal, use:

```bash
g++ main.cpp -o caderno
```

## Como executar

Após compilar, execute com:

```bash
./caderno
```

No Windows, caso esteja usando o terminal comum, o comando pode ser:

```bash
caderno.exe
```

## Arquivo principal

O arquivo principal do projeto pode ser chamado de:

```txt
main.cpp
```

## Possível organização dos arquivos

```txt
caderno-de-notas/
│
├── main.cpp
└── README.md
```

## Exemplo de uso

O usuário informa o nome do aluno e suas notas. Em seguida, o programa calcula a média e informa se o aluno foi aprovado ou reprovado.

A regra usada é:

```txt
Média >= 7.0 → Aprovado
Média < 7.0  → Reprovado
```

## Código utilizado

```cpp
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

class LivroNotas {
public:
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
```

## Melhorias futuras

Algumas melhorias que podem ser implementadas futuramente:

- Cadastrar vários alunos;
- Armazenar as notas em vetores;
- Calcular a maior e menor nota;
- Calcular a média geral da turma;
- Criar um menu interativo;
- Salvar os dados em arquivo;
- Separar o código em arquivos `.h` e `.cpp`;
- Permitir mais de duas notas por aluno.

## Autor

Projeto desenvolvido para estudo de C++ e Programação Orientada a Objetos.
