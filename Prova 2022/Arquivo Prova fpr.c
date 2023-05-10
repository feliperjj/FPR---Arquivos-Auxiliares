
Considerando a existência de uma matriz de inteiros M, de ordem N (ou seja, o nº de linhas e o nº de colunas são iguais
a N), onde N é uma constante, desenvolver uma função que retorne 1 se a seguinte regra for atendida por M (caso
contrário, o valor 0 deverá ser retornado):
▪ A soma dos elementos da diagonal principal deve ser igual à soma dos elementos que estão acima desta
diagonal, assim como à soma dos elementos abaixo da diagonal.
#include <stdio.h>

int removeLinhasArquivo(const char* nomeArquivo, int linhaInicial, int linhaFinal) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        // Não foi possível abrir o arquivo
        return 0;
    }

    // Abre um arquivo temporário para escrever os dados sem as linhas removidas
    FILE* arquivoTemp = fopen("temp.txt", "w");
    if (arquivoTemp == NULL) {
        // Não foi possível abrir o arquivo temporário
        fclose(arquivo);
        return 0;
    }

    int numeroLinhas = 0;
    int numeroRemovidos = 0;
    char linha[100];

    // Copia as linhas do arquivo original para o arquivo temporário
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        numeroLinhas++;

        if (numeroLinhas < linhaInicial || numeroLinhas > linhaFinal) {
            fputs(linha, arquivoTemp);
        } else {
            numeroRemovidos++;
        }
    }

    // Fecha os arquivos
    fclose(arquivo);
    fclose(arquivoTemp);

    // Remove o arquivo original
    remove(nomeArquivo);

    // Renomeia o arquivo temporário para o nome do arquivo original
    rename("temp.txt", nomeArquivo);

    // Verifica se algum valor foi removido
    if (numeroRemovidos > 0) {
        return 1;
    } else {
        return 0;
    }
}
