
// Somente para testar o merge

void searchStudent(STUDENT * students, int size, char *nuspKey){
    char * id = strchr(nuspKey, ' ') + 1;

    for(int i = 0; i < size; i++){
        if(atoi(id) == students[i].nusp){
            printStudent(students[i]);
        }
    }
}
