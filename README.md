<h1 align="center"> 🔥🌲 Simulação de Propagação de Incêndio Florestal </h1>

<div align="center"> 
   <img src="![Image](https://github.com/user-attachments/assets/01bec733-3390-49e3-b680-7266121428ee)">
</div>

## ☕ Introdução

Nesse projeto, consiste em uma simulação computacional que modela dois fenômenos interligados, onde temos uma propagação de um incêndio em uma floresta representada por uma matriz bidimensional, além de um comportamento de um animal tentando escapar do fogo enquanto ele se espalha pela matriz.

O trabalho foi desenvolvido em C++ e aborda uma simulação que integra três desafios em um ambiente dinâmico. A simulação modela a propagação do incêndio florestal de forma realista, levando em conta vários fatores. A direção do vento, configurável para atuar em uma ou mais das quatro direções cardeais e impacta diretamente a direção do fogo. O tipo de terreno também influencia a propagação, sendo representado na matriz por diferentes valores: áreas de água (valor 4) que impedem o fogo de se espalhar, árvores saudáveis (valor 1) que queimam facilmente, árvores em chamas (valor 2) que ajudam a propagar o fogo, e árvores queimadas (valor 3) que não propagam mais o incêndio. Além disso, o tempo de queima das árvores é determinado pelo número de iterações que uma árvore permanece em chamas antes de se tornar cinza.

Simultaneamente, é criado um sistema que permite ao animal se mover sozinho em um ambiente em constante mudança. O animal segue uma lógica de priorização clara: primeiramente, ele busca áreas seguras, como zonas com água, que representam a melhor opção de refúgio. Caso não encontre água, ele busca por áreas vazias ou árvores saudáveis (representadas por valores seguros na matriz). Se o animal ficar completamente cercado pelo fogo, ele morre. Além disso, caso o fogo atinja a casa em que o animal se encontra, ele também morre. A movimentação do animal ocorre de forma ortogonal, ou seja, ele pode se mover para as casas adjacentes acima, abaixo, à esquerda ou à direita, e sua prioridade de movimento é definida pela segurança da área ao redor.

Por fim, o sistema gerencia diferentes estados ao longo do tempo, controlando a evolução da matriz e verificando continuamente as condições de término, como a sobrevivência do animal ou a propagação completa do fogo. Além disso, o sistema respeita um limite máximo de iterações para a simulação. Esses desafios - a propagação do fogo, a inteligência do animal para escapar e o controle dos estados da simulação - são os principais pontos do problema, envolvendo a modelagem do ambiente, a tomada de decisão do animal e a dinâmica do sistema.



## 📚 Metodologia

## Estudos de Casos

## 👨‍💻 Modo de Compilação e Execução
### Pré-requisitos
- Sistema operacional Linux ou macOS (Windows pode usar WSL)
- Compilador g++ instalado
- Git para clonar o repositório
- Make para automatização

### Passo a Passo

1. **Clone o repositório**:
   ```bash
   git clone https://github.com/seu-usuario/simulacao-incendio.git
   cd simulacao-incendio
2. **Compilar o projeto**:
Dentro da pasta do projeto, execute os seguintes comandos:
   ```bash
   make clean   # Remove arquivos de compilações anteriores
   make         # Compila todo o código fonte
3. **Prepare o arquivo de Entrada**
Certifique-se que existe um arquivo "input.dat" na pasta raiz
   Formato esperado:
   ```bash
   LINHAS COLUNAS POS_X_FOGO POS_Y_FOGO
   MATRIZ...
4. **Executar a Simulação**
   ```bash
   make run    # Compila (se necessário) e executa
5. **Verifique os resultados**

O arquivo output.dat sera gerado com:
   Matriz inicial e final

   Caminho percorrido pelo animal

   Resultado da simulação
### Comandos Adicionais

| Comando       | Descrição                              |
|---------------|----------------------------------------|
| `make clean`  | 🗑️ Remove arquivos compilados         |
| `make debug`  | 🐛 Compila em modo depuração           |
| `make test`   | 🧪 Executa testes unitários            |

   
## Conclusão

## Referências
Este projeto usa um Makefile fornecido pelo professor Michel Pires Silva.

# Autores

[<img loading="lazy" src="https://avatars.githubusercontent.com/u/177992576?v=4" width=115><br><sub>Bernardo Silva Andrade</sub>](https://github.com/BernardoSilvaAndrade) 


