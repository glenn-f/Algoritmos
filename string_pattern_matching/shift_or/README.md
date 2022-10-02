# Algoritmo Shift-Or

Este algoritmo usa o **paralelismo de bits** para simular um **automato não-determinístico** que busca o padrão no texto. Por usar bits para simular uma **máquina de estados**, a sua limitação é a **arquitetura do sistema**, usualmente 32bits ou 64bits por palavra. Isso quer dizer que o tamanho do padrão em caracteres pode ser de no **máximo** o tamanho da palavra **w** (em bits) do sistema em questão.

O número de operações reduzidas por está técnica é um fator de até **w** (limite superior).

O algoritmo deve utilizar uma estrutura de dados que guarde as máscaras de bits do alfabeto e os estados da busca.

## Implementação

- v1: utiliza o algoritmo para encontrar apenas a primeira correspondência no texto, se houver. Imprime o resultado mostrando onde começa o padrão. Está limitado a um texto de 1024 caracteres. As entradas são lidas do teclado em linha de comando.

## Execução

### v1

Compile e execute o programa:

```sh
 g++ -std=c++11 shift_or_v1.cpp -o v1
 ./v1
```
Coloque as entradas na linha de comando conforme o programa solicita e veja seu resultado em seguida.
