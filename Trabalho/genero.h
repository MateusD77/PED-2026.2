/*
 * genero.h - TAD Genero (MiauNet)
 *
 * Representa os generos (Acao, Drama, Terror...) usados para classificar
 * as obras do catalogo. Estrutura escolhida: LISTA SEQUENCIAL ESTATICA
 * (vetor de tamanho fixo), mantida ordenada por codigo.
 *
 * Chave: codigo (inteiro gerado automaticamente, como AUTO_INCREMENT).
 */
#ifndef GENERO_H
#define GENERO_H

#define TAM_NOME_GENERO 50   /* nome com ate 49 caracteres + '\0'          */
#define MAX_GENEROS     50   /* capacidade fixa (o catalogo tem ~15 hoje)  */

/* Um genero do catalogo. */
typedef struct {
    int  codigo;                    /* chave primaria (>= 1)  */
    char nome[TAM_NOME_GENERO];     /* nome do genero         */
} Genero;

/* Colecao de generos: vetor estatico + controle de uso. */
typedef struct {
    Genero itens[MAX_GENEROS];  /* posicoes 0..qtd-1 ocupadas, ordenadas por codigo */
    int    qtd;                 /* quantidade de generos cadastrados                */
    int    proximo_codigo;      /* proximo codigo a ser gerado (nunca reutilizado)  */
} TabelaGeneros;

/* Codigos de retorno das operacoes que podem falhar. */
typedef enum {
    GENERO_OK = 0,
    GENERO_ERRO_PARAMETRO,       /* ponteiro NULL, nome vazio/longo, codigo invalido */
    GENERO_ERRO_CHEIA,           /* tabela atingiu MAX_GENEROS                       */
    GENERO_ERRO_DUPLICADO,       /* ja existe genero com esse nome                   */
    GENERO_ERRO_NAO_ENCONTRADO   /* codigo inexistente                               */
} ResultadoGenero;

/* Inicializa a tabela vazia (qtd = 0, proximo_codigo = 1).
 * Parametros: t - tabela a inicializar (se NULL, nao faz nada). */
void genero_criar(TabelaGeneros *t);

/* Insere um novo genero no fim do vetor, gerando o codigo automaticamente.
 * Parametros: t - tabela; nome - nome do novo genero;
 *             codigo_gerado - recebe o codigo criado (pode ser NULL).
 * Retorna: GENERO_OK, ou ERRO_PARAMETRO / ERRO_CHEIA / ERRO_DUPLICADO. */
ResultadoGenero genero_inserir(TabelaGeneros *t, const char *nome, int *codigo_gerado);

/* Busca um genero pelo codigo (busca binaria, pois o vetor e ordenado por codigo).
 * Retorna: ponteiro para o genero dentro da tabela, ou NULL se nao existir. */
const Genero *genero_buscar_por_codigo(const TabelaGeneros *t, int codigo);

/* Busca um genero pelo nome (busca sequencial, sem diferenciar maiusculas).
 * Retorna: ponteiro para o genero, ou NULL se nao existir. */
const Genero *genero_buscar_por_nome(const TabelaGeneros *t, const char *nome);

/* Altera o nome de um genero existente (o codigo nao muda).
 * Retorna: GENERO_OK, ou ERRO_PARAMETRO / ERRO_NAO_ENCONTRADO / ERRO_DUPLICADO. */
ResultadoGenero genero_atualizar_nome(TabelaGeneros *t, int codigo, const char *novo_nome);

/* Remove o genero de codigo informado, deslocando os seguintes uma posicao
 * para a esquerda. ATENCAO: quem chama deve garantir que nenhuma obra ainda
 * usa o genero (ver obra_contar_por_genero), mantendo a chave estrangeira valida.
 * Retorna: GENERO_OK, ou ERRO_PARAMETRO / ERRO_NAO_ENCONTRADO. */
ResultadoGenero genero_remover(TabelaGeneros *t, int codigo);

/* Imprime todos os generos (codigo e nome), em ordem de codigo.
 * Se a tabela estiver vazia, imprime uma mensagem informando. */
void genero_listar(const TabelaGeneros *t);

/* Retorna a quantidade de generos cadastrados (0 se t for NULL). */
int genero_quantidade(const TabelaGeneros *t);

/* Retorna 1 se a tabela estiver vazia (ou t for NULL), 0 caso contrario. */
int genero_vazia(const TabelaGeneros *t);

#endif /* GENERO_H */
