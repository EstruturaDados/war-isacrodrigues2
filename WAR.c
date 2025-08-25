// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================
// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.
#include <stdio.h> // Incluído para usar funções como exit() se necessário
#include <string.h>
#include <locale.h>

// --- Constantes Globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.
#define NUM_TERRITORIOS 42
#define NUM_MISSOES 3
#define TAMANHO_MAXIMO_NOME 50

// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.
struct territorio {
    char nome[TAMANHO_MAXIMO_NOME];
    char cor[TAMANHO_MAXIMO_NOME];
    int tropas;
};

// -- FUnção para limpar o buffer de entrada --
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// -- Função Principal --			
int main() {
    // A variável foi corrigida de "terrotorio" para "territorios"
    // Este é o array que armazena todos os territórios.
    struct territorio territorios[NUM_TERRITORIOS];
    int totalterritorios = 0;
    int opcao;

    // -- Laço Principal do Menu --
    do {
        // Exibe o menu de opções
        printf("================================================\n");
        printf("WAR PARTE 1 \n");
        printf("================================================\n");
        printf("1 - Cadastrar novo territorio\n");
        printf("2 - Listar todos os territorios\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");

        // Lê a opção do usuário
        if (scanf("%d", &opcao) != 1) {
            // Tratamento de erro para entrada invalida (nao numerica)
            limparBuffer();
            opcao = -1; // Define uma opcao invalida para continuar o loop
        }

        limparBuffer(); // Limpa o \n deixado pelo scanf

        switch (opcao) {
       case 1: // Cadastro de territorio
            printf("--- Cadastro de territorio Novo ---\n");
            if (totalterritorios < NUM_TERRITORIOS) {
                printf("Digite o nome do territorio: ");
                // Usa o array "territorios" e o indice correto
                fgets(territorios[totalterritorios].nome, TAMANHO_MAXIMO_NOME, stdin);

                printf("Digite a cor do exercito: ");
                // Usa o array "territorios" e o indice correto
                fgets(territorios[totalterritorios].cor, TAMANHO_MAXIMO_NOME, stdin);

                // Remove o caractere de nova linha (\n) do final das strings lidas por fgets
                territorios[totalterritorios].nome[strcspn(territorios[totalterritorios].nome, "\n")] = 0;
                territorios[totalterritorios].cor[strcspn(territorios[totalterritorios].cor, "\n")] = 0;

                printf("Digite a quantidade de tropas: ");
                // Corrigido para usar o campo "tropas"
				scanf("%d", &territorios[totalterritorios].tropas);
				limparBuffer(); // Limpa o buffer após a leitura do numero

				totalterritorios++; // Incrementa o total de territorios cadastrados
 				printf("\nTerritorio cadastrado com sucesso!\n\n");
            }
            else {
                printf("Limite de territorios atingido!\n\n");
            }
            break; // Finaliza o case 1

        case 2: // Listar os territorios
            {
            printf("--- Lista de territorios ---\n");
            // Laço para percorrer e exibir todos os territorios ja cadastrados
            for (int i = 0; i < totalterritorios; i++) {
                printf("territorio %d:\n", i + 1);
                printf("Nome: %s\n", territorios[i].nome);
                printf("Cor: %s\n", territorios[i].cor);
                // Corrigido para exibir o campo "tropas"
                printf("Quantidade de tropas: %d\n", territorios[i].tropas);
                printf("----------------------\n");
            }
            if (totalterritorios == 0) {
                printf("Nenhum territorio cadastrado.\n");
            }
            printf("\n");
            break; // Finaliza o case 2
        }

        case 3:
            printf("Saindo do programa...\n");
            break;

        default:
            printf("Opcao invalida! Tente novamente.\n\n");
            break;
        };
    } while (opcao != 3); // Corrige o fechamento do laço do-while

    return 0; // Adiciona retorno explicito da funçao main
}