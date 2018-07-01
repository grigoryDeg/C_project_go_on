#include <stdio.h>
#include <stdlib.h>
#define N 3
#define SIZE_M 35

//Константы:
int count_x = 0;
int count_y = 0;
int count_z = 0;

int poisk(char* mass, char* yeah);
char* kvadrat(char* mass, char* vyr);
char* kvadrati(char* mass);
char* zamena(char* mass, int size_mass, int key_to_change, char symbol);
char* vstavka(char* mass, int size_mass, int key_input_aft, int symbol);
char* zamena_na_massiv(char* mass, int size_mass, int key_to_change, char* symbols, int size_symbols);

int main () {
    char mass[] = "x*x + 2*x*y + y*y + x*x + x*x + y*y";
    int i;
    char* mass_pt = malloc(SIZE_M*sizeof(char));
    for(i = 0; i < SIZE_M; ++i) {
        mass_pt[i] = mass[i];
    }
    mass_pt = kvadrati(mass_pt);
    for(i = 0; i < SIZE_M; ++i) {
        printf("%c", mass_pt[i]);
    }
    puts("\n");
    int size_skob = 15;
    char skobka[15] = "(sin(x)+cos(y))";
    char* skob_ptr = malloc(size_skob*sizeof(char));
    for(i = 0; i < size_skob; ++i) {
        skob_ptr[i] = skobka[i];
    }
    skob_ptr = zamena_na_massiv(mass_pt, SIZE_M, 0, skob_ptr, size_skob);
    for(i = 0; i < SIZE_M+size_skob-1; ++i) {
        printf("%c", skob_ptr[i]);
    }
    return 0;
}

int poisk(char* mass, char* yeah) {
    char vyr[3];
    int element = 0;
    for(element = 0; element < SIZE_M; ++element) {
        for(int i = 0; i < 3; ++i) {
            vyr[i] = mass[i+element];
            //printf("%c", vyr[i]);
        }
            //printf("\n");
        if(vyr[0] == yeah[0] && vyr[1] == yeah[1] && vyr[2] == yeah[2]) {
           //printf("%i", element);
           break;
        }
    }
    return element;
}

char* kvadrat(char* mass, char* vyr) {
    int change_zero = poisk(mass, vyr);
    char bukva = mass[change_zero];
    char* new_mass = malloc(SIZE_M*sizeof(char));
    for(int i = 0; i < SIZE_M; ++i) {
        new_mass[i] = mass[i];
    }
    new_mass[change_zero] = bukva;
    new_mass[change_zero+1] = '^';
    new_mass[change_zero+2] = '2';
    return new_mass;
}

char* kvadrati(char* mass) {
    while(poisk(mass, "x*x") != SIZE_M) {
        mass = kvadrat(mass, "x*x");
        ++count_x;
    }
    while(poisk(mass, "y*y") != SIZE_M) {
        mass = kvadrat(mass, "y*y");
        ++count_y;
    }
    while(poisk(mass, "z*z") != SIZE_M) {
        mass = kvadrat(mass, "z*z");
        ++count_z;
    }
    return mass;
}

char* zamena(char* mass, int size_mass, int key_to_change, char symbol) {
    int i;
    char* new_mass = malloc(sizeof(char)*(size_mass));
    for(i = 0; i < size_mass; ++i) {
        new_mass[i] = mass[i];
    }
    new_mass[key_to_change] = symbol;
    return new_mass;
}

char* vstavka(char* mass, int size_mass, int key_input_aft, int symbol) {
    int i;
    char* new_mass = malloc(sizeof(char)*(size_mass+1));
    for(i = 0; i <= key_input_aft; ++i) {
        new_mass[i] = mass[i];
    }
    new_mass[key_input_aft+1] = symbol;
    if(key_input_aft > size_mass-1) {
        ;
    }
    else{
        for(i = key_input_aft+2; i < size_mass+1; ++i) {
            new_mass[i] = mass[i-1];
        }
    }
    return new_mass;
}

char* zamena_na_massiv(char* mass, int size_mass, int key_to_change, char* symbols, int size_symbols) {
    int i;
    char* new_mass = malloc(sizeof(char)*(size_mass));
    for(i = 0; i < size_mass; ++i) {
        new_mass[i] = mass[i];
    }
    new_mass = zamena(mass, size_mass, key_to_change, symbols[0]);
    for(i = 1; i < size_symbols; ++i) {
        new_mass = vstavka(new_mass, size_mass + i - 1, key_to_change + i - 1, symbols[i]);
    }
    return new_mass;
}

