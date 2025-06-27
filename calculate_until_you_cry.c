 
//     printf("\t-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//     printf("\t|                                                                                                                                                                                                               |\n");
//     printf("\t|               ░█████╗░░█████╗░██╗░░░░░░█████╗░██╗░░░██╗██╗░░░░░░█████╗░████████╗███████╗     ██╗░░░██╗███╗░░██╗████████╗██╗██╗░░░░░     ██╗░░░██╗░█████╗░██╗░░░██╗      ░█████╗░██████╗░██╗░░░██╗             |\n");
//     printf("\t|               ██╔══██╗██╔══██╗██║░░░░░██╔══██╗██║░░░██║██║░░░░░██╔══██╗╚══██╔══╝██╔════╝     ██║░░░██║████╗░██║╚══██╔══╝██║██║░░░░░     ╚██╗░██╔╝██╔══██╗██║░░░██║      ██╔══██╗██╔══██╗╚██╗░██╔╝             |\n");
//     printf("\t|               ██║░░╚═╝███████║██║░░░░░██║░░╚═╝██║░░░██║██║░░░░░███████║░░░██║░░░█████╗░░     ██║░░░██║██╔██╗██║░░░██║░░░██║██║░░░░░     ░╚████╔╝░██║░░██║██║░░░██║      ██║░░╚═╝██████╔╝░╚████╔╝░             |\n");
//     printf("\t|               ██║░░██╗██╔══██║██║░░░░░██║░░██╗██║░░░██║██║░░░░░██╔══██║░░░██║░░░██╔══╝░░     ██║░░░██║██║╚████║░░░██║░░░██║██║░░░░░     ░░╚██╔╝░░██║░░██║██║░░░██║      ██║░░██╗██╔══██╗░░╚██╔╝░░             |\n");
//     printf("\t|               ╚█████╔╝██║░░██║███████╗╚█████╔╝╚██████╔╝███████╗██║░░██║░░░██║░░░███████╗     ╚██████╔╝██║░╚███║░░░██║░░░██║███████╗     ░░░██║░░░╚█████╔╝╚██████╔╝      ╚█████╔╝██║░░██║░░░██║░░░             |\n");
//     printf("\t|               ░╚════╝░╚═╝░░╚═╝╚══════╝░╚════╝░░╚═════╝░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░╚══════╝     ░╚═════╝░╚═╝░░╚══╝░░░╚═╝░░░╚═╝╚══════╝     ░░░╚═╝░░░░╚════╝░░╚═════╝░      ░╚════╝░╚═╝░░╚═╝░░░╚═╝░░░             |\n");
//     printf("\t|                                                                                                                                                                                                               |\n");
//     printf("\t|                                                                                                                                                                                                               |\n");
//     printf("\t|                                                                                                                                                                                                               |\n");
//     printf("\t|                                                                                                                                                                                                               |\n");
//     printf("\t|                                                                                                                                                                                                               |\n");
//     printf("\t|                                                                                                                                                                                                               |\n");
//     printf("\t|                                                                                                                                                                                                               |\n");
//     printf("\t|                                                                                                                                                                                                               |\n");
//     printf("\t----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");




#include <stdio.h>
#include <stdlib.h>

// sleep settings
#ifdef _WIN32
#include <windows.h> // for sleep
#else
#include <time.h> // for sleep
#endif

void wait_ms(int milliseconds){
    #ifdef _WIN32
        Sleep(milliseconds);
    #else
        struct timespec ts;
        ts.tv_sec = milliseconds / 1000;
        ts.tv_nsec = (milliseconds % 1000) * 1000000;
        nanosleep(&ts, NULL);
    #endif
}


// clear screen settings
void clear_screen(){
    printf("\033[2J\033[H");
    fflush(stdout);
}



void Arithmetic();

void Trigonometry();
void Trignometric_Eval();
void Inverse_Trigno();
void Angle_Conversions();
void Triangle_Solver();

void Geometry();
void Statistics();
void Coversions();






int main(){
    int choice_menu;
    main_menu:
    

    
    printf("\t----------------------------------------------------------------------------------------\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                        CALCULATE   UNTIL   YOU   CRY                                 |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|        1. Arithmetic            2. Trigonometry              3. Geometry             |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|        4. Statistics            5. Coversions                6.                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                  99. EXIT                                            |\n");
    printf("\t|                                                                                      |\n");
    printf("\t----------------------------------------------------------------------------------------\n");
    
    printf("ENTER YOUR OPTION : ");
    scanf("%d", &choice_menu);
    
    if (choice_menu == 1){
        clear_screen();
        Arithmetic();
    }

    else if (choice_menu == 2){
        clear_screen();
        Trigonometry();
    }
    else if (choice_menu == 3){
        clear_screen();
        Geometry();
    }
    else if (choice_menu == 4){
        clear_screen();
        Statistics();
    }
    else if (choice_menu == 5){ 
        clear_screen();
        Coversions();
    }
    else if (choice_menu == 6){
        clear_screen();
        printf("UNDER DEVELOPMENT.........");
    }
    // to exit the whole program
    else if (choice_menu == 99){    
        clear_screen();
        printf("\nEXITING THE PROGRAM ...\n");
        wait_ms(500);
        clear_screen();
        printf("\nEXITING THE PROGRAM .\n");
        wait_ms(500);
        clear_screen();
        printf("\nEXITING THE PROGRAM ..\n");
        wait_ms(500);
        clear_screen();
        printf("\nEXITING THE PROGRAM ...\n");
        wait_ms(500);
        clear_screen();
        printf("\nEXITING THE PROGRAM .\n");
        wait_ms(500);
        clear_screen();
        printf("\nEXITING THE PROGRAM ..\n");
        wait_ms(500);
        clear_screen();
        printf("\nEXITING THE PROGRAM ...\n");
        wait_ms(500);
        clear_screen();
        printf("\nEXITING THE PROGRAM .\n");
        wait_ms(500);
        clear_screen();
        printf("\nEXITING THE PROGRAM ..\n");
        wait_ms(500);
        clear_screen();
        printf("\nEXITED THE PROGRAM SUCCESSFULLY\n");

        wait_ms(1500);

        return 0;

    }
    else {
        clear_screen();
        printf("ERROR, PLEASE ENTER CORRECT VALUE !!!!!!!!!\n");
        wait_ms(2000);
        goto main_menu;
    }

    
    return 0;
}



void Arithmetic(){
    int Arithmetic_choice;
    float Addition_choice1, Addition_choice2, Subtraction_choice1, Subtraction_choice2, Multiplication_choice1, Multiplication_choice2, Division_choice1, Division_choice2;

    Arithmetic:

    printf("\t----------------------------------------------------------------------------------------\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                 ARITHMETIC                                           |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|        1. Addition            2. Subtraction              3. Multiplication          |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|        4. Division                                                                   |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                             99. Back to main menu                                    |\n");
    printf("\t|                                                                                      |\n");
    printf("\t----------------------------------------------------------------------------------------\n");

    printf("ENTER YOUR OPTION : ");
    scanf("%d", &Arithmetic_choice);
    clear_screen();

    if (Arithmetic_choice == 1){
        printf("Enter first number : ");
        scanf("%f", &Addition_choice1);
        printf("Enter second number : ");
        scanf("%f", &Addition_choice2);
        printf("SUM : %f\n", Addition_choice1+Addition_choice2);

        printf("\n\t\tPRESS ENTER TO CONTINUE...");
        getchar();
        getchar();
        clear_screen();
        goto Arithmetic;
    }
    else if (Arithmetic_choice == 2){
        printf("Enter first number : ");
        scanf("%f", &Subtraction_choice1);
        printf("Enter second number : ");
        scanf("%f", &Subtraction_choice2);
        printf("DIFFERENCE : %f\n", Subtraction_choice1-Subtraction_choice2);

        printf("\n\t\tPRESS ENTER TO CONTINUE...");
        getchar();
        getchar();
        clear_screen();
        goto Arithmetic;
        
    }
    else if (Arithmetic_choice == 3){
        printf("Enter first number : ");
        scanf("%f", &Multiplication_choice1);
        printf("Enter second number : ");
        scanf("%f", &Multiplication_choice2);
        printf("PRODUCT : %f\n", Multiplication_choice1*Multiplication_choice2);

        printf("\n\t\tPRESS ENTER TO CONTINUE...");
        getchar();
        getchar();
        clear_screen();
        goto Arithmetic;
    }
    else if (Arithmetic_choice == 4){
        printf("Enter first number : ");
        scanf("%f", &Division_choice1);
        printf("Enter second number : ");
        scanf("%f", &Division_choice2);
        printf("DIVISION : %f\n", Division_choice1/Division_choice2);

        printf("\n\t\tPRESS ENTER TO CONTINUE...");
        getchar();
        getchar();
        clear_screen();
        goto Arithmetic;
    }
    else if (Arithmetic_choice == 99){
        clear_screen();
        main();
    }
    else {
        printf("\nERROR, PLEASE ENTER CORRECT OPTION !!!\n");
        
        printf("\n\t\tPRESS ENTER TO CONTINUE...");
        getchar();
        getchar();
        clear_screen();
        goto Arithmetic;

    }
}


void Trigonometry(){
    
    int Trignometric_choice;

    Trignometry:

    printf("\t----------------------------------------------------------------------------------------\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                 Trignometry                                          |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|        1. Trignometric Evaluation               2. Inverse Trignometry               |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|        3. Angle Conversions                     4. Triangle Solver                   |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                             99. Back to main menu                                    |\n");
    printf("\t|                                                                                      |\n");
    printf("\t----------------------------------------------------------------------------------------\n");

    printf("ENTER YOUR OPTION : ");
    scanf("%d", &Trignometric_choice);
    clear_screen();

    if (Trignometric_choice == 1){
        clear_screen();
        Trignometric_Eval();
    }
    else if (Trignometric_choice == 2){
        clear_screen();
        Inverse_Trigno();
    }
    else if (Trignometric_choice == 3){
        clear_screen();
        Angle_Conversions();
    }
    else if (Trignometric_choice == 4){
        clear_screen();
        Triangle_Solver();
    }
    else if (Trignometric_choice == 99){
        clear_screen();
        main();
    }
    else {
        printf("\nERROR, PLEASE ENTER CORRECT OPTION !!!\n");

        printf("\n\t\tPRESS ENTER TO CONTINUE...");
        getchar();
        getchar();
        clear_screen();
        goto Trignometry;
    }


}

void Trignometric_Eval(){
    printf("aywdyaowda");
}
void Inverse_Trigno(){
    printf("sdgfas");
}
void Angle_Conversions(){
    printf("afasf");
}
void Triangle_Solver(){
    printf("saffa");
}


void Geometry(){
    printf("This is for geometry");
}

void Statistics(){
    printf("this for stats");
}

void Coversions(){
    printf("this for conves");
}


















