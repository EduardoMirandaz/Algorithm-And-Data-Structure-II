#include "operations.h"
#include "util.h"

void makeSelectedOperation(STUDENT *studentsVector, int operation, int howManyStudents){
    if(studentsVector == NULL || howManyStudents == ERRO){
        printf("There's no student!");
        exit(1);
    }
    int startRange = 0, endRange = 0, position = 0; 
    switch(operation){
        case 1:
        	// mostrar todos os registros
            printStudents(studentsVector, 0 , howManyStudents-1, howManyStudents-1);
            break;
        case 2:
        	// mostrar metade dos registros, do começo ao meio
            printStudents(studentsVector, 0 , (howManyStudents/2)-1, howManyStudents-1);
            break;
        case 3:
        	// mostrar metade dos registros, do meio ao fim
            printStudents(studentsVector, (howManyStudents/2), howManyStudents-1, howManyStudents-1);
            break;
        case 4:
        	// exibir uma faixa de registros, de "startRange" até "endRange"
            if(!scanf("%d", &startRange)) exit(1);
            if(!scanf("%d", &endRange)) exit(1);
            printStudents(studentsVector, startRange-1, endRange-1, howManyStudents-1);
            break;
        case 5:
        	// exibir um registro específico
            if(!scanf("%d", &position)) exit(1);
            printStudents(studentsVector, position-1 ,position-1, howManyStudents-1);
        break;        
    }
}
