sse exercício consiste na leitura de um arquivo binário e exibição de seu conteúdo na saída padrão.

Por que um arquivo binário? R: Observe abaixo duas possibilidades de representação de um número inteiro. A primeira consiste em uma cadeia de caracteres em texto puro ASCII, cada caractere consome 1 byte. A segunda, por sua vez, está no formato de um número inteiro 'int' na linguagem C, seu tamanho é 4 bytes em uma arquitetura X86 64 bits. O tamanho final em bytes está calculado após o número.

"78765234" - 8 bytes
78765234 - 4 bytes
Organização interna do arquivo binário
Cada registro dentro do arquivo contém os seguintes dados:

Numero USP - int
Nome completo - char[50]
Curso - char[50]
Nota - float
Seguindo a ordem anterior os registros estão dispostos da seguinte forma: [[Numero USP][Nome][Curso][Nota]][[Numero USP][Nome][Curso][Nota]][[Numero USP][Nome][Curso][Nota]] Sendo assim, os registros são de tamanho fixo com campos de tamanho fixo. OBS: Os colchetes não existem no arquivo, serve apenas para demarcar onde começam e terminam os registros e os campos

Entradas do exercício
Você receberá entradas diferentes para cada caso de teste, use a forma que achar melhor para lê-las. Todas virão pela entrada padrão. As dispostas abaixo nunca mudarão para qualquer operação.

1ª Entrada[string] - Nome do arquivo binário
2ª Entrada[int] - Operação
As operações são:

1 - Exibição de todos os registros
2 - Exibição de metade dos registros, do começo ao meio
3 - Exibição de metade dos registros, do meio ao fim
4 - Exibição de uma faixa de registros
5 - Exibição de um registro específico
Para a operação 4, após o número da operação, você deverá ler os valores:

3ª Entrada[int] - Início da faixa(inclusive)
4ª Entrada[int] - Final da faixa(inclusive)
Para a operação 5:

3ª Entrada[int] - Posição do registro
Neste exercício estamos tratando a 'faixa' e o 'registro específico' como posições relativas dentro do arquivo binário, ou seja: 1º registro; 2º registro; ... 10º registro. O número USP não passa de um valor numérico armazenado, futuramente usaremos como chave primária. OBS: Caso o valor final da faixa supere o total de registros, exiba até o último disponível. O run.codes aceitará tanto um arquivo .zip contendo o Makefile quanto apenas o arquivo .c. Recomendo que usem o Makefile.

Saída esperada
nUSP: 1
Nome: Winter Y. Hodges
Curso: Engenharia da Computacao
Nota: 5.00

nUSP: 2
Nome: Doris S. Mathis
Curso: Sistemas de Informacao
Nota: 5.00

nUSP: 3
Nome: Vernon U. Dunlap
Curso: Sistemas de Informacao
Nota: 0.00
OBS: Não há pulo de linha para o último registro exbido

Obrigações
Você deve:

Comentar o código. Não é pra escrever um romance. É COMENTÁRIO
Usar alocações dinâmica. Fazer tudo na pilha é uma péssima prática de programação
As seguintes funções são obrigatórias: ftell, fseek e fread.
Ler apenas o que será escrito na saída padrão
Fechar o arquivo ao final
Dicas
Usem struct para organizar as informações do registro.
Não tentem ler os registros como struct, leiam cada campo do registro separadamente.
Modularizem o código em várias funções pequenas.
Deem nomes significativos para as variáveis