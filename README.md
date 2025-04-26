<h1 align="center">🌲Simulação de Propagação de Incêndio Florestal🔥</h1>

![Image](https://github.com/user-attachments/assets/82580ffd-dcb6-478a-a658-c812402de2c1)

## ☕ Introdução

Este trabalho foi proposto pelo professor Michel Pires Silva, da matéria Algoritmos e Estrutura de Dados I, do Centro Federal de Educação Tecnológica de Minas Gerais (CEFET - MG), Campus V - Divinópolis.

Nesse projeto, consiste em uma simulação computacional que modela dois fenômenos interligados, onde temos uma propagação de um incêndio em uma floresta representada por uma matriz bidimensional, além de um comportamento de um animal tentando escapar do fogo enquanto ele se espalha pela matriz.

O trabalho foi desenvolvido em C++ e aborda uma simulação que integra três desafios em um ambiente dinâmico. A simulação modela a propagação do incêndio florestal de forma realista, levando em conta vários fatores. A direção do vento, configurável para atuar em uma ou mais das quatro direções cardeais e impacta diretamente a direção do fogo. O tipo de terreno também influencia a propagação, sendo representado na matriz por diferentes valores: áreas de água (valor 4) que impedem o fogo de se espalhar, árvores saudáveis (valor 1) que queimam facilmente, árvores em chamas (valor 2) que ajudam a propagar o fogo, e árvores queimadas (valor 3) que não propagam mais o incêndio. Além disso, o tempo de queima das árvores é determinado pelo número de iterações que uma árvore permanece em chamas antes de se tornar cinza.

Simultaneamente, é criado um sistema que permite ao animal se mover sozinho em um ambiente em constante mudança. O animal segue uma lógica de priorização clara: primeiramente, ele busca áreas seguras, como zonas com água, que representam a melhor opção de refúgio. Caso não encontre água, ele busca por áreas vazias ou árvores saudáveis (representadas por valores seguros na matriz). Se o animal ficar completamente cercado pelo fogo, ele morre. Além disso, caso o fogo atinja a casa em que o animal se encontra, ele também morre. A movimentação do animal ocorre de forma ortogonal, ou seja, ele pode se mover para as casas adjacentes acima, abaixo, à esquerda ou à direita, e sua prioridade de movimento é definida pela segurança da área ao redor.

Por fim, o sistema gerencia diferentes estados ao longo do tempo, controlando a evolução da matriz e verificando continuamente as condições de término, como a sobrevivência do animal ou a propagação completa do fogo. Além disso, o sistema respeita um limite máximo de iterações para a simulação. Esses desafios - a propagação do fogo, a inteligência do animal para escapar e o controle dos estados da simulação - são os principais pontos do problema, envolvendo a modelagem do ambiente, a tomada de decisão do animal e a dinâmica do sistema.



## 📚 Metodologia

### 1. Arquitetura do Sistema
O sistema é composto por quatro módulos interconectados:
- **Floresta**: Gerencia a matriz e a propagação do fogo
- **Animal**: Controla a lógica de movimento e sobrevivência
- **Config**: Armazena parâmetros globais
- **Arquivo**: Manipula entrada/saída de dados

---

### 2. Detalhamento das Funcionalidades

#### 2.1 Propagação do Incêndio
**Mecanismo**:
1. Para cada célula em chamas (`2`):
   - Incrementa contador interno `ticsEmChamas`
   - Se `ticsEmChamas >= ticsParaQueimar` (Config):
     - Marca como queimada (`3`)
     - Reseta contador
   - Senão, propaga fogo para adjacentes:
     - Verifica direções habilitadas pelo vento (Config)
     - Só afeta células válidas (`1` = árvore saudável)

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


