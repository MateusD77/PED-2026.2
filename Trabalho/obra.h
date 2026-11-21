/*
 * obra.h - TAD Obra (MiauNet)
 *
 * Representa um filme ou seriado do catalogo. Estrutura escolhida:
 * LISTA ENCADEADA SIMPLES DINAMICA, com ponteiros para o inicio e o fim.
 * (Nao e pilha nem fila: busca e remocao ocorrem em qualquer posicao.)
 *
 * Chave: titulo (texto, unico no catalogo - diferencia maiusculas/minusculas).
 */
#ifndef OBRA_H
#define OBRA_H

#define TAM_TITULO 100   /* titulo com ate 99 caracteres + '\0' */

/* Tipo da obra, igual ao campo 'tipo' ('Filme' ou 'Seriado') do banco. */
typedef enum {
    TIPO_FILME = 0,
    TIPO_SERIADO = 1
} TipoObra;

/* Uma obra do catalogo. */
typedef struct {
    char     titulo[TAM_TITULO];  /* chave primaria                          */
    TipoObra tipo;                /* filme ou seriado                        */
    int      codigo_genero;       /* chave estrangeira -> Genero.codigo      */
    int      duracao;             /* duracao em minutos (> 0)                */
} Obra;

/* No da lista encadeada. */
typedef struct NoObra {
    Obra           dado;   /* informacoes da obra            */
    struct NoObra *prox;   /* proximo no (NULL no ultimo)    */
} NoObra;

/* Cabecalho da lista: acesso ao primeiro e ao ultimo no. */
typedef struct {
    NoObra *inicio;   /* primeiro no (NULL se vazia)                          */
    NoObra *fim;      /* ultimo no: permite inserir no fim sem percorrer      */
    int     qtd;      /* quantidade de obras cadastradas                      */
} ListaObras;

/* Codigos de retorno das operacoes que podem falhar. */
typedef enum {
    OBRA_OK = 0,
    OBRA_ERRO_PARAMETRO,       /* ponteiro NULL, titulo vazio/longo, duracao <= 0 */
    OBRA_ERRO_MEMORIA,         /* malloc falhou                                   */
    OBRA_ERRO_DUPLICADA,       /* ja existe obra com esse titulo                  */
    OBRA_ERRO_NAO_ENCONTRADA,  /* titulo inexistente                              */
    OBRA_ERRO_VAZIA            /* lista sem elementos                             */
} ResultadoObra;

/* Inicializa a lista vazia (inicio = fim = NULL, qtd = 0).
 * Parametros: l - lista a inicializar (se NULL, nao faz nada). */
void obra_criar(ListaObras *l);

/* Insere uma nova obra no fim da lista, apos verificar que o titulo ainda nao existe.
 * Parametros: l - lista; titulo; tipo; codigo_genero (o chamador valida que o
 *             genero existe via genero_buscar_por_codigo); duracao em minutos.
 * Retorna: OBRA_OK, ou ERRO_PARAMETRO / ERRO_DUPLICADA / ERRO_MEMORIA. */
ResultadoObra obra_inserir(ListaObras *l, const char *titulo, TipoObra tipo,
                           int codigo_genero, int duracao);

/* Busca uma obra pelo titulo exato (busca sequencial a partir do inicio).
 * Retorna: ponteiro para a obra dentro da lista, ou NULL se nao encontrada. */
const Obra *obra_buscar_por_titulo(const ListaObras *l, const char *titulo);

/* Atualiza tipo, genero e duracao da obra de titulo informado.
 * O titulo (chave) nao pode ser alterado: para isso, remover e inserir de novo.
 * Retorna: OBRA_OK, ou ERRO_PARAMETRO / ERRO_VAZIA / ERRO_NAO_ENCONTRADA. */
ResultadoObra obra_atualizar(ListaObras *l, const char *titulo, TipoObra novo_tipo,
                             int novo_codigo_genero, int nova_duracao);

/* Remove a obra de titulo informado, religando o no anterior ao seguinte
 * (nenhum elemento e deslocado) e liberando o no removido com free.
 * Retorna: OBRA_OK, ou ERRO_PARAMETRO / ERRO_VAZIA / ERRO_NAO_ENCONTRADA. */
ResultadoObra obra_remover(ListaObras *l, const char *titulo);

/* Imprime todas as obras na ordem de insercao.
 * Retorna: quantidade de obras impressas (0 se a lista estiver vazia). */
int obra_listar_todas(const ListaObras *l);

/* Imprime as obras que pertencem ao genero informado.
 * Retorna: quantidade de obras impressas. */
int obra_listar_por_genero(const ListaObras *l, int codigo_genero);

/* Imprime as obras do tipo informado (filmes ou seriados).
 * Retorna: quantidade de obras impressas. */
int obra_listar_por_tipo(const ListaObras *l, TipoObra tipo);

/* Conta quantas obras usam o genero informado. Usada antes de remover um
 * genero, para impedir que sobrem obras com genero inexistente.
 * Retorna: quantidade encontrada (0 se l for NULL). */
int obra_contar_por_genero(const ListaObras *l, int codigo_genero);

/* Retorna a quantidade de obras cadastradas (0 se l for NULL). */
int obra_quantidade(const ListaObras *l);

/* Retorna 1 se a lista estiver vazia (ou l for NULL), 0 caso contrario. */
int obra_vazia(const ListaObras *l);

/* Libera todos os nos da lista e deixa-a vazia. Deve ser chamada ao fim do programa. */
void obra_destruir(ListaObras *l);

#endif /* OBRA_H */
