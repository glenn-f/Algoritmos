/* Glenn Fonseca >> GitHub: glenn-f/Algoritmos
 */
#include <iostream>
#include <cstdint>
#include <cstring>

#define ALFAB_SIZE 256
#define TEXT_MAX_LENGHT 1024  // Tamanho máximo do texto
#define WORD_BYTE_SIZE 8 // Tamanho da palavra no sistema: 8->64bits, 4->32bits
#if WORD_BYTE_SIZE == 8
#define INT_T uint64_t
#define INICIAL UINT64_MAX
#else
#define INT_T uint32_t
#define INICIAL UINT32_MAX
#endif

int shift_or(char *texto, char *padrao)
{
    INT_T estado_atual = INICIAL;
    INT_T mask[ALFAB_SIZE];                     // mascara de cada letra do alfabeto
    INT_T tam_padrao = strlen(padrao);          // tamanho do padrao
    INT_T tam_texto = strlen(texto);            // tamanho do texto
    INT_T estado_final = 1 << (tam_padrao - 1); // mascara para encontrar o estado final

    // Inicializar tabela de mascaras com bit '1' todas posicoes
    memset(mask, 0xFF, (ALFAB_SIZE * WORD_BYTE_SIZE));
    // Colocar um bit '0' onde o padrao ocorre invertidamente
    for (int i = 0, j = 1; i < tam_padrao; i++, j <<= 1)
        mask[padrao[i]] &= ~j;
    // Atualizar o estado com SHIFT e depois OR em iteração pelo texto usando a mask do alfabeto
    for (int i = 0; i < tam_texto; i++)
    {
        estado_atual = (estado_atual << 1) | mask[texto[i]];
        // Se encontrar '0' no estado final -> retornar posicao inicial da substring.
        if ((estado_atual & estado_final) == 0)
            return i - (tam_padrao - 1);
    }
    // Caso de falha (padrão não encontrado)
    return -1;
}

int main(int argc, char const *argv[])
{
    int posicao, tam_padrao;
    char padrao[WORD_BYTE_SIZE * 8], texto[TEXT_MAX_LENGHT];

    // Leitura das entradas
    std::cout << "Digite o padrao de busca:\n>>";
    std::cin >> padrao;
    std::cout << "Digite o texto a ser buscado:\n>>";
    std::cin >> texto;
    // Verificação de validade das entradas
    tam_padrao = strlen(padrao);
    if (tam_padrao == 0 || tam_padrao >= (WORD_BYTE_SIZE * 8))
    {
        std::cout << "Tamanho do padrao de busca eh invalido: " << tam_padrao << "\n";
        return -1;
    }
    // Busca pelo padrão usando Shift-Or
    posicao = shift_or(texto, padrao);
    std::cout << "\nBusca com Shift-Or: WORD >> " << WORD_BYTE_SIZE<< " ALFABETO >> " << ALFAB_SIZE << "\n\n";
    // Imprimir resultado
    if (posicao > -1)
    {
        std::cout << "Padrao '" << padrao << "' encontrado na posicao [" << posicao << "]:\n";
        for (int i = 0; i < posicao; i++)
            std::cout << " ";
        for (int i = 0; i < tam_padrao; i++)
            std::cout << "v";
        std::cout << "\n" << texto << "\n";
    }
    else
        std::cout << "Padrao '" << padrao << "' nao esta no texto.\n";
    return 0;
}