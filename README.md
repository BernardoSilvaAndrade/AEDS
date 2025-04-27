<h1 align="center">🌲Simulação de Propagação de Incêndio Florestal🔥</h1>

<div align="center">
  <img src="![Image](https://github.com/user-attachments/assets/82580ffd-dcb6-478a-a658-c812402de2c1)">
</div>

## ☕ Introdução

Este trabalho foi proposto pelo professor Michel Pires Silva, da matéria Algoritmos e Estruturas de Dados I, do CEFET - MG, Campus V - Divinópolis. O projeto consiste em uma simulação que modela a propagação de incêndio em uma floresta e o comportamento de um animal tentando escapar do fogo. A simulação é desenvolvida em C++ e visa integrar a dinâmica do fogo com a movimentação inteligente do animal em um ambiente de constante mudança.

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
- **Simulação**: Controla o loop principal e coordena as interações 

---

### 2. Detalhamento das Funcionalidades

#### 2.1 Propagação do Incêndio
- **Mecanismo**:  
  1. Células em chamas (`2`) têm duração controlada por `ticsParaQueimar`  
  2. A cada iteração, o fogo se expande para células adjacentes com árvores (`1`)  
  3. Direção do incêndio influenciada por configurações de vento (Norte/Sul/Leste/Oeste), onde ele pode se propagar por todas as casas adjacentes, ou para so uma direção.   
  4. Após 2 tics se tem uma combustão completa, a casa de fogo (`2`) se torna uma árvore queimada (`3`)  

#### 2.2 Comportamento do Animal  
- **Lógica de Movimento**:  
   1. **Sistema de Prioridades**:  
     - **Prioridade Máxima**:  
       - `4` = Água 
     - **Prioridade Intermediária**:  
       - `0` = Área vazia (não queima)  
       - `1` = Árvore saudável 
     - **Prioridade Mínima**:  
       - `3` = Árvore queimada (não propaga mais fogo, árvore totalmente queimada)
       - Última casa visitada 

  2. **Atualização da Matriz**:  
     - Ao se mover, marca a posição anterior:
       - Se sair de `4` (água) → transforma em `0` e todas suas casas adjacentes se transformam em `1`  

#### 2.3 Parâmetros de Configuração  
- **ticsTotais**:  
  Define o número máximo de iterações da simulação.  
  - *Padrão*: `20`  
  - *Como alterar*: Aumente para simulações mais longas (ex: `30`) ou reduza para testes rápidos. 

- **ventoAtivo[]**:  
  Vetor que controla as direções de propagação do fogo (ordem: Norte, Sul, Oeste, Leste).  
  - *Padrão*: `[true, true, true, true]` (todas direções ativas)  
  - *Personalização*:  
    ```cpp
    // Exemplo: vento só para Oeste (índice 2)
    config.configurarVento(false, false, true, false);
    ```  


---

#### 2.4 Fluxo de Dados  
1. **Entrada (`input.dat`)**: 
    - **Formato**:
     ```
     LINHAS COLUNAS FOGO_X FOGO_Y  
     VALORES_DA_MATRIZ...  
     ```
   - **Observação**: O fogo inicial (`0,2`) é automaticamente inserido na posição `(FOGO_X, FOGO_Y)` durante a leitura.
   - **Exemplo completo**:  
     ```
     5 5 0 2  
     0 1 2 1 0  // Fogo já incluso na posição (0,2)  
     1 3 1 1 1 
     1 1 1 1 1  
     1 1 1 1 1  
     0 1 1 1 0  
     ```  

2. **Saída (`output.dat`)**:
   - Registra a evolução completa, incluindo:  
     - Estados intermediários da matriz  
     - Posições do animal em cada tic
     - Trajetória do animal no formato:
     ```
     Caminho: (0,0) → (1,0) → (2,0)
     ```
    - Estado final (sobrevivência ou motivo da morte).

## Estudos de Casos
## Exemplos

Aqui estão dois exemplos de simulação:

### Exemplo 1: Animal Morre após Algumas Iterações

Neste exemplo, a simulação mostra um cenário onde o incêndio se espalha rapidamente e o animal não consegue escapar a tempo. A matriz é atualizada a cada iteração, e o animal acaba morrendo.

#### Exemplo 01: 
     ```
     Matriz inicial:    Iteraçao 01:     Iteracao 02:    Iteracao 03:    Itercao 04:    
     
     5 5 5 5            5 5 5 5          5 5 5 5         5 5 5 5         5 5 5 5        
     0 4 1 1 1          0 4 1 1 1        0 4 1 1 1       1 0 1 1 1       1 0 1 1 2      
     1 1 1 1 1          1 1 1 1 1        1 1 1 1 1       1 1 1 1 2       1 1 1 2 2      
     1 1 1 4 1          1 1 1 4 1        1 1 1 4 2       1 1 1 4 2       1 1 2 4 3     
     1 1 1 1 1          1 1 1 1 2        1 1 1 2 2       1 1 2 2 3       1 2 2 3 3      
     0 1 1 1 2          0 1 1 2 2        0 1 2 2 3       0 2 2 3 3       0 2 3 3 3      
     Animal (0, 0)      Animal (0, 0)    Animal (0, 0)   Animal (0, 1)   Animal (0, 1)  
     
     Iteracao 05:       Itercao 06:     Iteracao 07:

     5 5 5 5            5 5 5 5         5 5 5 5 
     0 1 1 2 2          0 1 2 2 3       0 2 2 3 3
     1 1 2 2 3          1 1 2 3 3       2 2 3 3 3
     1 2 2 4 3          2 2 3 4 3       2 3 3 4 3
     2 2 3 3 3          2 3 3 3 3       3 3 3 3 3
     0 3 3 3 3          0 3 3 3 3       0 3 3 3 3
     Animal (0, 1)      Animal (1, 1)   Animal (1, 1)

      Dados da simulacao:
    Casas de água visitadas: 1
    Caminho percorrido pelo animal:
    (0, 0) --> (0, 0) --> (0, 0) --> (0, 1) --> (0, 1) --> (0, 1) --> (1, 1)
    Total de passos: 3
    Condição final: Animal esta cercado pelo fogo.

     ``` 
### Exemplo 2: Vento Ativado e Animal Sobrevive

Neste exemplo, o vento foi ativado, o que fez o fogo se espaplhar apenas para a direcao que o vento esta ativado. Neste caso, a ventania esta apenas para o oeste, todas as outras direcoes estao desativadas. No entanto, o animal conseguiu escapar a tempo e não morreu.

#### Exemplo 02:
 ```
     Matriz inicial:    Iteraçao 01:     Iteracao 02:    Iteracao 03:    Itercao 04:    
     
     5 5 5 5            5 5 5 5          5 5 5 5         5 5 5 5         5 5 5 5        
     0 4 1 1 1          0 4 1 1 1        0 4 1 1 1       1 0 1 1 1       1 0 1 1 1      
     1 1 1 1 1          1 1 1 1 1        1 1 1 1 1       1 1 1 1 1       1 1 1 1 1      
     1 1 1 4 1          1 1 1 4 1        1 1 1 4 1       1 1 1 4 1       1 1 1 4 1     
     1 1 1 1 1          1 1 1 1 1        1 1 1 1 1       1 1 1 1 1       1 1 1 1 1      
     0 1 1 1 2          0 1 1 2 2        0 1 2 2 3       0 2 2 3 3       0 2 3 3 3      
     Animal (0, 0)      Animal (0, 0)    Animal (0, 0)   Animal (0, 1)   Animal (0, 1)  
     
     Iteracao 05: 
      
     5 5 5 5           
     0 1 1 1 1          
     1 1 1 1 1          
     1 1 1 4 1          
     1 1 1 1 1      
     0 3 3 3 3          
     Animal (0, 1)      

      Dados da simulacao:
    Casas de água visitadas: 1
    Caminho percorrido pelo animal:
    (0, 0) --> (0, 0) --> (0, 0) --> (0, 1) --> (0, 1) --> (0, 1)
    Total de passos: 2
    Condição final: Animal sobreviveu até o fim da simulação..

 ```
 OBS: Neste caso, os tics param por causa que todo o incendio parou de se espalhar


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

 Este trabalho desenvolveu uma simulação que ilustra como o incêndio se propaga em uma floresta e como um animal tenta escapar desse perigo. O código, implementado em C++, cria um ambiente virtual simples, onde o fogo se espalha de acordo com regras pré-definidas, enquanto o animal toma decisões para buscar segurança.

 A simulação é dividida em duas partes principais: uma controla a propagação do fogo, influenciada pela direção do vento, e a outra gerencia o comportamento do animal, que busca constantemente os locais mais seguros. O interessante desse modelo é sua flexibilidade, permitindo ajustes fáceis em parâmetros como a direção do vento ou o tempo necessário para que uma árvore se queime completamente.

 O resultado é um programa capaz de simular diferentes cenários, demonstrando como o animal pode sobreviver ou ser pego pelo fogo. No final, o projeto mostrou como a programação pode ser usada para criar modelos de processos da natureza. Ele também ajudou a entender como estudar sistemas simples pode nos ensinar sobre fenômenos mais complexos, abrindo espaço para explorar ideias mais avançadas no futuro.

## Referências
Este projeto usa um Makefile fornecido pelo professor Michel Pires Silva.

# Autores

[<img loading="lazy" src="https://avatars.githubusercontent.com/u/177992576?v=4" width=115><br><sub>Bernardo Silva Andrade</sub>](https://github.com/BernardoSilvaAndrade) 


