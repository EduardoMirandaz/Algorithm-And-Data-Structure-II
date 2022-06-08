# Registros de Alunos com Busca por Índices Primários
Esse exercício consiste na execução de opercações de inserção, busca e remoção LOGICA em índices primários

Qual é a ideia?
Ler os comandos da entrada padrão e executa-los sequencialemente. Os comandos são:
- insert: Insere um registro no arquivo binário, a linha estará no formato csv
- search: executa a busca de um registro por meio de sua chave primária
- delete: remove um registro por meio de sua chave primária(Nada deve ser exibido)
- exit: finaliza a execução


`O que é um CSV?`
Um arquivo CSV(comma-separated-values) é um arquivo texto puro onde os campos de cada registro são separados por algum desses caracteres: vírgula, ponto e vírgula, pipe ou espaço. Os separadores mais comuns são vírgula e ponto e vírgula. Os campos de texto, em alguns casos, estão entre aspas simples ou duplas. Para o nosso caso não há aspas.

## Organização interna do arquivo binário
Cada registro dentro do arquivo deverá estar estruturado da seguinte forma:
- Numero USP      -    int
- Nome            -    char[?]
- Sobrenome       -    char[?]
- Curso           -    char[?]
- Nota            -    float

Dê o tamanho que achar necessário para os campos CHAR

# Entradas do exercício
```sh
insert 1,Raymond,Adeline,Sistemas de informacao,2
insert 2,Jeanne,Alice,Ciencia da computacao,6
insert 3,Gregory,Alicia,Engenharia da computacao,0
insert 4,Elizabeth,Alla,Sistemas de informacao,1
insert 5,Carl,Alma,Ciencia da computacao,7
search 1
search 2
search 3
search 4
search 5
delete 1
delete 2
delete 3
delete 4
delete 5
exit
```


# Saída esperada
```sh
-------------------------------
USP number: 1
Name: Raymond
Surname: Adeline
Course: Sistemas de informacao
Test grade: 2.00
-------------------------------
-------------------------------
USP number: 2
Name: Jeanne
Surname: Alice
Course: Ciencia da computacao
Test grade: 6.00
-------------------------------
-------------------------------
USP number: 3
Name: Gregory
Surname: Alicia
Course: Engenharia da computacao
Test grade: 0.00
-------------------------------
-------------------------------
USP number: 4
Name: Elizabeth
Surname: Alla
Course: Sistemas de informacao
Test grade: 1.00
-------------------------------
-------------------------------
USP number: 5
Name: Carl
Surname: Alma
Course: Ciencia da computacao
Test grade: 7.00
-------------------------------
```
OBS: Registros que não exitem ou que já estão armazenados devem ser exibidos da seguinte forma:
`NÂO VALE PRO DELETE. NESSE CASO NÂO EXIBA NADA`
```sh
O Registro ja existe!
O Registro ja existe!
O Registro ja existe!
O Registro ja existe!
O Registro ja existe!
O Registro ja existe!
O Registro ja existe!
O Registro ja existe!
O Registro ja existe!
O Registro ja existe!
Registro nao encontrado!
Registro nao encontrado!
Registro nao encontrado!
Registro nao encontrado!
Registro nao encontrado!
-------------------------------
USP number: 6
Name: Amy
Surname: Amy
Course: Engenharia da computacao
Test grade: 3.00
-------------------------------
```
# Obrigações
Você `deve`:
- Comentar o código.
- Usar alocações dinâmicas.
- As seguintes funções são obrigatórias: ftell, fseek e fread.
- Salvar os dados em um arquivo binário e depois lê-lo.
- Ler apenas o que será escrito na saída padrão.
- Fechar o arquivo ao final

# Dicas
- Usem struct para organizar as informações do registro.
- Modularizem o código em várias funções pequenas.
- Deem nomes significativos para as variáveis
- Após escreverem um registro utilizem o fflush para escrever o buffer, contido na struct FILE, para o disco.

# Duvidas
Mandem no grupo, por email, ou combinem um dia de atendimento comigo!
Bom exercício. Se cuidem!!!
