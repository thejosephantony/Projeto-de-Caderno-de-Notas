# Caderno de Notas em C++

Este projeto é um sistema simples de caderno de notas desenvolvido em C++.  
Ele foi criado com o objetivo de praticar conceitos de Programação Orientada a Objetos, organização de código em múltiplos arquivos e manipulação básica de dados.

O programa permite cadastrar alunos, registrar várias notas para cada aluno, calcular médias, exibir estatísticas da turma e salvar os dados em um arquivo de texto.

## Objetivo

O objetivo principal do projeto é simular um pequeno sistema acadêmico para gerenciamento de notas de uma turma.

A classe `LivroNotas` é responsável por armazenar os dados do curso, professor e alunos, além de realizar operações como cálculo de médias, listagem de alunos, geração de estatísticas e salvamento de relatório.

## Funcionalidades

O programa possui as seguintes funcionalidades:

- Cadastro do nome do curso;
- Cadastro do nome do professor;
- Cadastro de vários alunos;
- Cadastro de várias notas para cada aluno;
- Armazenamento das notas em `vector`;
- Cálculo da média individual de cada aluno;
- Verificação da situação do aluno: aprovado ou reprovado;
- Listagem de todos os alunos cadastrados;
- Cálculo da média geral da turma;
- Identificação da maior média;
- Identificação da menor média;
- Contagem de alunos aprovados e reprovados;
- Menu interativo;
- Validação básica de entradas;
- Salvamento dos dados em arquivo `.txt`;
- Separação do código em arquivos `.h` e `.cpp`.

## Conceitos utilizados

Este projeto utiliza os seguintes conceitos de C++:

- Classe;
- Objeto;
- Struct;
- Construtor;
- Encapsulamento;
- Atributos privados;
- Métodos públicos;
- Separação entre interface e implementação;
- Arquivos de cabeçalho `.h`;
- Arquivos de implementação `.cpp`;
- Vetores com `std::vector`;
- Strings com `std::string`;
- Entrada e saída de dados;
- Estrutura condicional `if/else`;
- Estrutura de repetição `for`;
- Estrutura de repetição `do while`;
- Estrutura `switch case`;
- Manipulação de arquivos com `ofstream`;
- Formatação de números com `iomanip`;
- Validação de entrada com `cin.fail()`.

## Estrutura do projeto

O projeto está organizado da seguinte forma:

```txt
caderno-de-notas/
│
├── LivroNotas.h
├── LivroNotas.cpp
└── main.cpp
```

## Descrição dos arquivos

### `main.cpp`

Arquivo principal do programa.

Ele é responsável por:

- Ler o nome do curso;
- Ler o nome do professor;
- Criar o objeto `LivroNotas`;
- Exibir o menu principal;
- Chamar as funções de cadastro, listagem, estatísticas e salvamento.

### `LivroNotas.h`

Arquivo de cabeçalho.

Ele contém:

- A definição da `struct Aluno`;
- A declaração da classe `LivroNotas`;
- A declaração dos atributos e métodos da classe.

### `LivroNotas.cpp`

Arquivo de implementação.

Ele contém:

- A implementação dos métodos da `struct Aluno`;
- A implementação dos métodos da classe `LivroNotas`;
- As regras de cadastro, cálculo, listagem e salvamento.

## Estrutura da struct Aluno

A `struct Aluno` representa um aluno cadastrado no sistema.

```cpp
struct Aluno {
    string nome;
    vector<double> notas;

    double calcularMedia() const;
};
```

Ela possui:

- `nome`: armazena o nome do aluno;
- `notas`: armazena as notas do aluno;
- `calcularMedia()`: calcula a média das notas do aluno.

## Estrutura da classe LivroNotas

A classe principal do projeto é chamada de `LivroNotas`.

Ela possui os seguintes atributos privados:

```cpp
string cursoNome;
string professorNome;
vector<Aluno> alunos;
```

Esses atributos armazenam:

- O nome do curso;
- O nome do professor;
- A lista de alunos cadastrados.

## Principais métodos da classe

```cpp
LivroNotas(string nomeCurso, string nomeProfessor);

void mensagem() const;
void cadastrarAluno();
void listarAlunos() const;
void exibirEstatisticas() const;
void salvarEmArquivo(string nomeArquivo) const;
```

Esses métodos são responsáveis por:

- Inicializar o caderno de notas;
- Exibir a mensagem inicial;
- Cadastrar alunos;
- Listar alunos;
- Exibir estatísticas da turma;
- Salvar os dados em arquivo.

A classe também possui métodos auxiliares privados:

```cpp
double calcularMediaTurma() const;
double maiorMedia() const;
double menorMedia() const;
string situacao(double media) const;

int lerQuantidadeNotas() const;
double lerNota(int numeroNota) const;
```

Esses métodos auxiliam no cálculo das médias, validação das notas e definição da situação do aluno.

## Regra de aprovação

A regra usada pelo programa é:

```txt
Média >= 7.0 → Aprovado
Média < 7.0  → Reprovado
```

## Menu do programa

Ao executar o programa, o usuário verá um menu semelhante a este:

```txt
1 - Cadastrar aluno
2 - Listar alunos
3 - Exibir estatisticas da turma
4 - Salvar dados em arquivo
0 - Sair
```

## Exemplo de execução

```txt
Digite o nome do curso: Estruturas de Dados
Digite o nome do professor: Joseph Antony

======================================
        CADERNO DE NOTAS EM C++
======================================
Curso: Estruturas de Dados
Professor: Joseph Antony
======================================

1 - Cadastrar aluno
2 - Listar alunos
3 - Exibir estatisticas da turma
4 - Salvar dados em arquivo
0 - Sair

Escolha uma opcao: 1

Digite o nome do aluno: Carlos
Digite a quantidade de notas do aluno: 3
Digite a nota 1: 8
Digite a nota 2: 7
Digite a nota 3: 9

Aluno cadastrado com sucesso!
```

## Exemplo de listagem

```txt
=========== LISTA DE ALUNOS ===========

Aluno 1
Nome: Carlos
Notas: 8.00 7.00 9.00
Media: 8.00
Situacao: Aprovado
```

## Exemplo de estatísticas

```txt
========= ESTATISTICAS DA TURMA =========
Curso: Estruturas de Dados
Professor: Joseph Antony
Quantidade de alunos: 3
Media geral da turma: 7.83
Maior media: 9.00
Menor media: 6.50
Aprovados: 2
Reprovados: 1
```

## Salvamento em arquivo

O programa permite salvar os dados cadastrados em um arquivo `.txt`.

Exemplo de nome de arquivo:

```txt
relatorio_notas.txt
```

Caso o usuário não digite um nome de arquivo, o programa pode usar o nome padrão:

```txt
relatorio_notas.txt
```

O arquivo gerado contém:

- Nome do curso;
- Nome do professor;
- Alunos cadastrados;
- Notas dos alunos;
- Média de cada aluno;
- Situação de cada aluno;
- Estatísticas gerais da turma.

## Como compilar

Para compilar o projeto, use o comando:

```bash
g++ main.cpp LivroNotas.cpp -o caderno
```

## Como executar

No Linux ou WSL:

```bash
./caderno
```

No Windows:

```bash
caderno.exe
```

## Código-fonte

O projeto é dividido em três arquivos principais:

```txt
LivroNotas.h
LivroNotas.cpp
main.cpp
```

Essa divisão deixa o código mais organizado e facilita futuras manutenções.

## Possíveis melhorias futuras

Mesmo com as melhorias implementadas, o projeto ainda pode evoluir com novas funcionalidades, como:

- Editar dados de um aluno cadastrado;
- Remover aluno;
- Pesquisar aluno pelo nome;
- Ordenar alunos por média;
- Salvar e carregar dados automaticamente;
- Usar arquivos `.csv`;
- Criar uma interface gráfica;
- Criar login de professor;
- Permitir diferentes critérios de aprovação;
- Criar relatórios mais detalhados.

## Autor: Joseph Antony

Projeto desenvolvido para estudo de C++ e Programação Orientada a Objetos.

## Licença

Este projeto é de uso educacional e pode ser modificado livremente para fins de aprendizado.
