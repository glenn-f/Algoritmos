/* Glenn Fonseca >> GitHub: glenn-f/Algoritmos
 */
#include <iostream>
#include <cstdint>
#include <cstring>

#define ALFAB_SIZE 256
#define TEXT_MAX_LENGHT 1024 // Tamanho máximo do texto
#define WORD_BYTE_SIZE 8     // Tamanho da palavra no sistema: 8->64bits, 4->32bits
#if WORD_BYTE_SIZE == 8
#define INT_T uint64_t
#define INICIAL UINT64_MAX
#else
#define INT_T uint32_t
#define INICIAL UINT32_MAX
#endif

int bndm(char *texto, char *padrao)
{
    INT_T mask[ALFAB_SIZE];
    int tam_padrao = strlen(padrao); // tamanho do padrao
    int tam_texto = strlen(texto);   // tamanho do texto
    int i, j, estado_atual, temp_j;

    // Inicializar tabela de mascaras com bit '0' todas posicoes
    memset(mask, 0, (ALFAB_SIZE * WORD_BYTE_SIZE));
    // Colocar um bit '1' onde o padrao ocorre
    for (j = 1, i = tam_padrao - 1; i >= 0; i--, j <<= 1)
        mask[padrao[i]] |= j;
    // Busca pelo padrão
    for (j = 0; j <= tam_texto - tam_padrao; j += temp_j)
    { // i=posicao do padrao (invertido), j = posicao do texto
        i = tam_padrao - 1;
        temp_j = tam_padrao;
        estado_atual = ~0;
        // verifica se o padrao é encontrado inversamente
        while (i >= 0 && estado_atual != 0)
        {
            // atualiza estado
            estado_atual &= mask[texto[j + i]];
            i--;
            if (estado_atual != 0) // verifica se estado valido (caractere encontrado)
            {
                if (i >= 0) // atualiza o próximo j ou retorna posicao
                    temp_j = i + 1;
                else
                    return j;
            }
            estado_atual <<= 1;
        }
        // avança temp_j caracteres no texto
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
    // Busca pelo padrão usando BNDM
    posicao = bndm(texto, padrao);
    std::cout << "\nBusca com BNDM: WORD >> " << WORD_BYTE_SIZE << " ALFABETO >> " << ALFAB_SIZE << "\n\n";
    // Imprimir resultado
    if (posicao > -1)
    {
        std::cout << "Padrao '" << padrao << "' encontrado na posicao [" << posicao << "]:\n";
        for (int i = 0; i < posicao; i++)
            std::cout << " ";
        for (int i = 0; i < tam_padrao; i++)
            std::cout << "v";
        std::cout << "\n"
                  << texto << "\n";
    }
    else
        std::cout << "Padrao '" << padrao << "' nao esta no texto.\n";
    return 0;
}