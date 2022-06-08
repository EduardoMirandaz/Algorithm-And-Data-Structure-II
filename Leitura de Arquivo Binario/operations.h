#ifndef OPERATIONS_H
#define OPERATIONS_H
#include "student.h"


// As operações possíveis são:
// 1 - Exibição de todos os registros
// 2 - Exibição de metade dos registros, do começo ao meio
// 3 - Exibição de metade dos registros, do meio ao fim
// 4 - Exibição de uma faixa de registros
// 5 - Exibição de um registro específico
// por parâmetro, deve ser passado o vetor de registros, a operação e quantos registros tem.
void makeSelectedOperation(STUDENT *studentsVector, int operation, int howManyStudents);

#endif // OPERATIONS_H
