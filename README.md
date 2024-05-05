
# astro-flight-management

Sistema de gestão de astronautas e voos espaciais em C++ da disciplina de Linguagem de Programação.

## Funcionalidades

- Cadastro de Astronautas: Inclui dados como CPF, nome e idade dos astronautas.
- Cadastro de Voos: Inclui o código do voo.
- Adicionar e Remover Astronautas de Voo (por CPF): Permite adicionar ou remover astronautas de um voo específico usando o CPF como referência, desde que o voo esteja em planejamento.
- Lançamento de Voos: A função para lançar um voo garante que pelo menos um astronauta esteja presente e disponível. Após o lançamento, os astronautas envolvidos ficam indisponíveis.
- Finalizar Voos (com ou sem sucesso): Permite a finalização de um voo, retornando os astronautas ao estado disponível ou marcando-os como mortos, dependendo do resultado do voo.
- Listar Voos: Lista todos os voos (planejados, em curso ou finalizados) com seus astronautas. 
- Listar Astronautas e Voos feitos por eles: Exibe os astronautas e os voos em que participaram.
- Listar Mortos: Exibir uma lista de astronautas mortos.


## Configuração e execução no Linux

**Clone o projeto**:

```bash
  git clone https://github.com/Aerttyz/astro-flight-management
```

**Navegue até diretório do projeto**:

```bash
  cd astro-flight-management
```

**Instale as ferramentas essenciais para C++**:

Primeiramente, atualize os repositórios de pacotes:
```bash
  sudo apt update
```

Em seguida, instale o pacote `build-essential` que inclui o compilador `g++` e outras ferramentas:
```bash
  sudo apt install build-essential
```

**Verifique a instalação**:

Após a instalação, verifique a versão do compilador `g++` para garantir que está disponível:

```bash
  g++ --version
```
**Compilar o código**:
Usando o `Makefile`
```bash
  make
```
**Executar o programa**:
```bash
  ./programa
```
## Aprendizados

Este projeto me permitiu aprofundar meu conhecimento em C++ e no uso de Makefile. Além disso, desenvolvi uma lógica de programação mais sólida e um entendimento aprimorado de programação orientada a objetos em C++.

## Feedback

Se você tiver algum feedback, por favor me deixe saber por meio de alesandro.silva.711@ufrn.edu.br

