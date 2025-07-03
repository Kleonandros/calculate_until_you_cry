
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
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include <windows.h>

// for colours to work cross platform
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

void enable_virtual_terminal()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}

// colours
#define CYAN "\033[1;36m"
#define MAGENTA "\033[1;35m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define GRAY "\033[90m"
#define RESET "\033[0m"
// Neon & Cyber ANSI Colors
#define BOLD "\033[1m"
#define DIM "\033[2m"
#define ITALIC "\033[3m"
#define UNDERLINE "\033[4m"

// sleep settings
#ifdef _WIN32
#include <windows.h> // for sleep
#else
#include <time.h> // for sleep
#endif

void wait_ms(int milliseconds)
{
#ifdef _WIN32
    Sleep(milliseconds);
#else
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
#endif
}

// rainbow colour func

void hsv_to_rgb(float h, float s, float v, int *r, int *g, int *b)
{
    float c = v * s;
    float x = c * (1 - fabs(fmod(h / 60.0, 2) - 1));
    float m = v - c;
    float r1, g1, b1;

    if (h < 60)
    {
        r1 = c;
        g1 = x;
        b1 = 0;
    }
    else if (h < 120)
    {
        r1 = x;
        g1 = c;
        b1 = 0;
    }
    else if (h < 180)
    {
        r1 = 0;
        g1 = c;
        b1 = x;
    }
    else if (h < 240)
    {
        r1 = 0;
        g1 = x;
        b1 = c;
    }
    else if (h < 300)
    {
        r1 = x;
        g1 = 0;
        b1 = c;
    }
    else
    {
        r1 = c;
        g1 = 0;
        b1 = x;
    }

    *r = (int)((r1 + m) * 255);
    *g = (int)((g1 + m) * 255);
    *b = (int)((b1 + m) * 255);
}

void print_rainbow(const char *text)
{
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        float hue = (float)i / len * 360; // full color wheel
        int r, g, b;
        hsv_to_rgb(hue, 1.0, 1.0, &r, &g, &b);
        printf("\033[38;2;%d;%d;%dm%c", r, g, b, text[i]);
    }
    printf("\033[0m");
}

// for triangle solver
double toRad(double degree)
{
    return degree * M_PI / 180.0;
}

double toDeg(double radian)
{
    return radian * 180.0 / M_PI;
}

// clear screen settings
void clear_screen()
{
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
void twod_shapes();
void threed_shapes();
void triangles_geometry();
void circles_geometry();
void coordinate_geometry();
void transformations_geometry();

void Statistics();
void Coversions();

int main()
{
    enable_virtual_terminal(); // for colours cross platform

    int choice_menu;
main_menu:

    printf(BOLD MAGENTA "\t----------------------------------------------------------------------------------------\n" RESET);
    printf(BOLD MAGENTA "\t|" RESET "                                                                                      " BOLD MAGENTA "|\n\t|" RESET);
    print_rainbow("                               CALCULATE UNTIL YOU CRY                                ");
    printf(BOLD MAGENTA "|" RESET);
    printf(BOLD MAGENTA "\n\t|                                                                                      |\n" RESET);
    printf(BOLD MAGENTA UNDERLINE "\t|                                                                                      " BOLD MAGENTA "|\n" RESET);
    printf(BOLD MAGENTA "\t|                                                                                      |\n");
    printf(BOLD MAGENTA "\t|" RESET "                                                                                      " BOLD MAGENTA "|\n" RESET);
    printf(BOLD MAGENTA "\t|" RESET CYAN "        1." RESET YELLOW " Arithmetic" RESET "            " CYAN " 2." RESET YELLOW " Trigonometry" RESET "              " CYAN "3." RESET YELLOW " Geometry" RESET "            " BOLD MAGENTA "|\n" RESET);
    printf(BOLD MAGENTA "\t|" RESET "                                                                                      " BOLD MAGENTA "|\n" RESET);
    printf(BOLD MAGENTA "\t|" RESET CYAN "        4. " RESET YELLOW " Statistics" RESET "            " CYAN "5." RESET YELLOW " Coversions" RESET "                " CYAN "6." RESET YELLOW " (in development)" RESET "    " BOLD MAGENTA "|\n" RESET);
    printf(BOLD MAGENTA "\t|" RESET "                                                                                      " BOLD MAGENTA "|\n" RESET);
    printf(BOLD MAGENTA "\t|" RESET "                                                                                      " BOLD MAGENTA "|\n" RESET);
    printf(BOLD MAGENTA "\t|" RESET "                                                                                      " BOLD MAGENTA "|\n" RESET);
    printf(BOLD MAGENTA "\t|" RESET "                                                                                      " BOLD MAGENTA "|\n" RESET);
    printf(BOLD MAGENTA "\t|" RESET "                                                                                      " BOLD MAGENTA "|\n" RESET);
    printf(BOLD MAGENTA "\t|" RESET "                                                                                      " BOLD MAGENTA "|\n" RESET);
    printf(BOLD MAGENTA "\t|" RESET GRAY "                                  99. EXIT                                            " RESET BOLD MAGENTA "|\n" RESET);
    printf(BOLD MAGENTA "\t|" RESET "                                                                                      " BOLD MAGENTA "|\n" RESET);
    printf(BOLD MAGENTA "\t----------------------------------------------------------------------------------------\n" RESET);
    printf(BOLD ITALIC GREEN "ENTER YOUR OPTION : " RESET);
    scanf("%d", &choice_menu);

    if (choice_menu == 1)
    {
        clear_screen();
        Arithmetic();
    }

    else if (choice_menu == 2)
    {
        clear_screen();
        Trigonometry();
    }
    else if (choice_menu == 3)
    {
        clear_screen();
        Geometry();
    }
    else if (choice_menu == 4)
    {
        clear_screen();
        Statistics();
    }
    else if (choice_menu == 5)
    {
        clear_screen();
        Coversions();
    }
    else if (choice_menu == 6)
    {
        clear_screen();
        printf("UNDER DEVELOPMENT.........");
    }
    // to exit the whole program
    else if (choice_menu == 99)
    {
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
    else
    {
        clear_screen();
        printf("ERROR, PLEASE ENTER CORRECT VALUE !!!!!!!!!\n");
        wait_ms(2000);
        goto main_menu;
    }

    return 0;
}

void Arithmetic()
{
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

    if (Arithmetic_choice == 1)
    {
        printf("Enter first number : ");
        scanf("%f", &Addition_choice1);
        printf("Enter second number : ");
        scanf("%f", &Addition_choice2);
        printf("SUM : %f\n", Addition_choice1 + Addition_choice2);

        printf("\n\t\tPRESS ENTER TO CONTINUE...");
        getchar();
        getchar();
        clear_screen();
        goto Arithmetic;
    }
    else if (Arithmetic_choice == 2)
    {
        printf("Enter first number : ");
        scanf("%f", &Subtraction_choice1);
        printf("Enter second number : ");
        scanf("%f", &Subtraction_choice2);
        printf("DIFFERENCE : %f\n", Subtraction_choice1 - Subtraction_choice2);

        printf("\n\t\tPRESS ENTER TO CONTINUE...");
        getchar();
        getchar();
        clear_screen();
        goto Arithmetic;
    }
    else if (Arithmetic_choice == 3)
    {
        printf("Enter first number : ");
        scanf("%f", &Multiplication_choice1);
        printf("Enter second number : ");
        scanf("%f", &Multiplication_choice2);
        printf("PRODUCT : %f\n", Multiplication_choice1 * Multiplication_choice2);

        printf("\n\t\tPRESS ENTER TO CONTINUE...");
        getchar();
        getchar();
        clear_screen();
        goto Arithmetic;
    }
    else if (Arithmetic_choice == 4)
    {
        printf("Enter first number : ");
        scanf("%f", &Division_choice1);
        printf("Enter second number : ");
        scanf("%f", &Division_choice2);
        printf("DIVISION : %f\n", Division_choice1 / Division_choice2);

        printf("\n\t\tPRESS ENTER TO CONTINUE...");
        getchar();
        getchar();
        clear_screen();
        goto Arithmetic;
    }
    else if (Arithmetic_choice == 99)
    {
        clear_screen();
        main();
    }
    else
    {
        printf("\nERROR, PLEASE ENTER CORRECT OPTION !!!\n");

        printf("\n\t\tPRESS ENTER TO CONTINUE...");
        getchar();
        getchar();
        clear_screen();
        goto Arithmetic;
    }
}

void Trigonometry()
{

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

    if (Trignometric_choice == 1)
    {
        clear_screen();
        Trignometric_Eval();
        clear_screen();
    }
    else if (Trignometric_choice == 2)
    {
        clear_screen();
        Inverse_Trigno();
        clear_screen();
    }
    else if (Trignometric_choice == 3)
    {
        clear_screen();
        Angle_Conversions();
        clear_screen();
    }
    else if (Trignometric_choice == 4)
    {
        clear_screen();
        Triangle_Solver();
        clear_screen();
    }
    else if (Trignometric_choice == 99)
    {
        clear_screen();
        main();
    }
    else
    {
        printf("\nERROR, PLEASE ENTER CORRECT OPTION !!!\n");

        printf("\n\t\tPRESS ENTER TO CONTINUE...");
        getchar();
        getchar();
        clear_screen();
        goto Trignometry;
    }
}

void Trignometric_Eval()
{
    int Trignometric_eval_choice;
    double Trignometric_eval_angle_choice, eval_result, eval_radians;

Trignometric_eval:

    printf("\t----------------------------------------------------------------------------------------\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                           Trignometric Evaluation                                    |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|        1. Sin                   2. Cosine                3. Tangent                  |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|        4. Cosecant              5. Secant                6. Cotangent                |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                             99. Back to Trignometry                                  |\n");
    printf("\t|                                                                                      |\n");
    printf("\t----------------------------------------------------------------------------------------\n");

    printf("ENTER YOUR OPTION : ");
    scanf("%d", &Trignometric_eval_choice);
    clear_screen();

    if (Trignometric_eval_choice == 1)
    {
        printf("Enter angle : ");
        scanf("%lf", &Trignometric_eval_angle_choice);
        eval_radians = Trignometric_eval_angle_choice * M_PI / 180.0000;

        eval_result = sin(eval_radians);

        printf("The value of sin(%.2lf) = %.5lf\n", Trignometric_eval_angle_choice, eval_result);

        printf("\n\t\tPRESS ENTER TO CONTINUE...");
        getchar();
        getchar();
        clear_screen();
        goto Trignometric_eval;
    }
    else if (Trignometric_eval_choice == 2)
    {
        printf("Enter angle : ");
        scanf("%lf", &Trignometric_eval_angle_choice);
        eval_radians = Trignometric_eval_angle_choice * M_PI / 180.00000;

        eval_result = cos(eval_radians);

        printf("The value of cos(%.2lf) = %.5lf\n", Trignometric_eval_angle_choice, eval_result);

        printf("\n\t\tPRESS ENTER TO CONTINUE...");
        getchar();
        getchar();
        clear_screen();
        goto Trignometric_eval;
    }
    else if (Trignometric_eval_choice == 3)
    {
        printf("Enter angle : ");
        scanf("%lf", &Trignometric_eval_angle_choice);
        eval_radians = Trignometric_eval_angle_choice * M_PI / 180.00000;

        eval_result = tan(eval_radians);

        printf("The value of tan(%.2lf) = %.5lf\n", Trignometric_eval_angle_choice, eval_result);

        printf("\n\t\tPRESS ENTER TO CONTINUE...");
        getchar();
        getchar();
        clear_screen();
        goto Trignometric_eval;
    }
    else if (Trignometric_eval_choice == 4)
    {
        printf("Enter angle : ");
        scanf("%lf", &Trignometric_eval_angle_choice);
        eval_radians = Trignometric_eval_angle_choice * M_PI / 180.00000;

        eval_result = 1.0 / sin(eval_radians);

        printf("The value of cosec(%.2lf) = %.5lf\n", Trignometric_eval_angle_choice, eval_result);

        printf("\n\t\tPRESS ENTER TO CONTINUE...");
        getchar();
        getchar();
        clear_screen();
        goto Trignometric_eval;
    }
    else if (Trignometric_eval_choice == 5)
    {
        printf("Enter angle : ");
        scanf("%lf", &Trignometric_eval_angle_choice);
        eval_radians = Trignometric_eval_angle_choice * M_PI / 180.00000;

        eval_result = 1.0 / cos(eval_radians);

        printf("The value of sec(%.2lf) = %.5lf\n", Trignometric_eval_angle_choice, eval_result);

        printf("\n\t\tPRESS ENTER TO CONTINUE...");
        getchar();
        getchar();
        clear_screen();
        goto Trignometric_eval;
    }
    else if (Trignometric_eval_choice == 6)
    {
        printf("Enter angle : ");
        scanf("%lf", &Trignometric_eval_angle_choice);
        eval_radians = Trignometric_eval_angle_choice * M_PI / 180.00000;

        eval_result = 1.0 / tan(eval_radians);

        printf("The value of cot(%.2lf) = %.5lf\n", Trignometric_eval_angle_choice, eval_result);

        printf("\n\t\tPRESS ENTER TO CONTINUE...");
        getchar();
        getchar();
        clear_screen();
        goto Trignometric_eval;
    }
    else if (Trignometric_eval_choice == 99)
    {
        clear_screen();
        Trigonometry();
    }
    else
    {
        printf("\nERROR, PLEASE ENTER CORRECT OPTION !!!\n");

        printf("\n\t\tPRESS ENTER TO CONTINUE...");
        getchar();
        getchar();
        clear_screen();
        goto Trignometric_eval;
    }
}

void Inverse_Trigno()
{
    int Trignometric_inverse_choice;
    double input_val, result_radian, result_deg;

Trignometric_inverse:

    printf("\t----------------------------------------------------------------------------------------\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                             Inverse Trignometry                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|        1. Sin                   2. Cosine                3. Tangent                  |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|        4. Cosecant              5. Secant                6. Cotangent                |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                             99. Back to Trignometry                                  |\n");
    printf("\t|                                                                                      |\n");
    printf("\t----------------------------------------------------------------------------------------\n");

    printf("ENTER YOUR OPTION : ");
    scanf("%d", &Trignometric_inverse_choice);
    clear_screen();

    if (Trignometric_inverse_choice == 1)
    {
        printf("Enter the value of sin between -1 to 1 : ");
        scanf("%lf", &input_val);
        if (input_val < -1 || input_val > 1)
        {
            clear_screen();
            goto erro;
        }
        else
        {
            result_radian = asin(input_val);
            result_deg = result_radian * 180.000000 / M_PI;
            printf("The value of sin^-1(%.4lf) = %.5lf degrees\n", input_val, result_deg);
            printf("\n\t\tPRESS ENTER TO CONTINUE...");
            getchar();
            getchar();
            clear_screen();
            goto Trignometric_inverse;
        }
    }
    else if (Trignometric_inverse_choice == 2)
    {
        printf("Enter the value cosine between -1 to 1 : ");
        scanf("%lf", &input_val);
        if (input_val < -1 || input_val > 1)
        {
            clear_screen();
            goto erro;
        }
        else
        {
            result_radian = asin(input_val);
            result_deg = result_radian * 180.000000 / M_PI;
            printf("The value of cos^-1(%.4lf) = %.5lf degrees\n", input_val, result_deg);
            printf("\n\t\tPRESS ENTER TO CONTINUE...");
            getchar();
            getchar();
            clear_screen();
            goto Trignometric_inverse;
        }
    }
    else if (Trignometric_inverse_choice == 3)
    {
        printf("Enter the value of tangent : ");
        scanf("%lf", &input_val);
        result_radian = asin(input_val);
        result_deg = result_radian * 180.000000 / M_PI;
        printf("The value of sin^-1(%.4lf) = %.5lf degrees\n", input_val, result_deg);
        printf("\n\t\tPRESS ENTER TO CONTINUE...");
        getchar();
        getchar();
        clear_screen();
        goto Trignometric_inverse;
    }
    else if (Trignometric_inverse_choice == 4)
    {
        printf("Enter the value  of cosecant (|x| >= 1) : ");
        scanf("%lf", &input_val);
        if (input_val == 0 || fabs(input_val) < 1)
        {
            clear_screen();
            goto erro;
        }
        else
        {
            double reciprocal = 1.0 / input_val;
            result_radian = asin(reciprocal);
            result_deg = result_radian * 180.0 / M_PI;

            printf("The value of cosec^-1(%.4lf) = %.5lf degrees\n", input_val, result_deg);

            printf("\n\t\tPRESS ENTER TO CONTINUE...");
            getchar();
            getchar();
            clear_screen();
            goto Trignometric_inverse;
        }
    }
    else if (Trignometric_inverse_choice == 5)
    {
        printf("Enter the value of secant (|x| >= 1) : ");
        scanf("%lf", &input_val);

        if (input_val == 0 || fabs(input_val) < 1)
        {
            clear_screen();
            goto erro; // make sure the label 'erro:' exists
        }
        else
        {
            double reciprocal = 1.0 / input_val;
            result_radian = acos(reciprocal);
            result_deg = result_radian * 180.0 / M_PI;

            printf("The value of sec^-1(%.4lf) = %.5lf degrees\n", input_val, result_deg);

            printf("\n\t\tPRESS ENTER TO CONTINUE...");
            getchar(); // flush newline
            getchar(); // wait for Enter
            clear_screen();
            goto Trignometric_inverse;
        }
    }
    else if (Trignometric_inverse_choice == 6)
    {
        printf("Enter the value of cotangent : ");
        scanf("%lf", &input_val);

        if (input_val == 0)
        {
            result_deg = 90.0;
            printf("The value of cot^-1(%.4lf) = %.5lf degrees\n", input_val, result_deg);
        }
        else
        {
            double reciprocal = 1.0 / input_val;
            result_radian = atan(reciprocal);
            result_deg = result_radian * 180.0 / M_PI;

            // Optional: adjust to get 0-180 degree range
            if (input_val < 0)
                result_deg += 180.0;

            printf("The value of cot^-1(%.4lf) = %.5lf degrees\n", input_val, result_deg);
        }

        printf("\n\t\tPRESS ENTER TO CONTINUE...");
        getchar(); // flush newline
        getchar(); // wait for Enter
        clear_screen();
        goto Trignometric_inverse;
    }
    else if (Trignometric_inverse_choice == 99)
    {
        clear_screen();
        Trigonometry();
    }
    else
    {
    erro:
        printf("\nERROR, PLEASE ENTER CORRECT OPTION !!!\n");

        printf("\n\t\tPRESS ENTER TO CONTINUE...");
        getchar();
        getchar();
        clear_screen();
        goto Trignometric_inverse;
    }
}

void Angle_Conversions()
{
    int angle_conversion_choice;
    double degree_input1, radian_result1, radian_input1, degree_result1;

Angle_conversions:

    printf("\t----------------------------------------------------------------------------------------\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                Angle Conversions                                     |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|        1. Degrees to Radians                        2. Radians to Degrees            |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                             99. Back to main menu                                    |\n");
    printf("\t|                                                                                      |\n");
    printf("\t----------------------------------------------------------------------------------------\n");

    printf("ENTER YOUR OPTION : ");
    scanf("%d", &angle_conversion_choice);
    clear_screen();

    if (angle_conversion_choice == 1)
    {
        printf("Enter the value angle in Degrees : ");
        scanf("%lf", &degree_input1);

        // printf("DEBUG: Degree input = %lf\n", degree_input);

        // printf("DEBUG: PI = %.15f, factor = %.15f\n", M_PI, (M_PI / 180.0));

        radian_result1 = degree_input1 * (M_PI / 180.0000);
        printf("%lf deg = %lf rad", degree_input1, radian_result1);

        printf("\n\t\tPRESS ENTER TO CONTINUE...");
        getchar();
        getchar();
        clear_screen();
        goto Angle_conversions;
    }
    else if (angle_conversion_choice == 2)
    {

        printf("Enter the value angle in Radians : ");
        scanf("%lf", &radian_input1);

        // Optional debug if needed
        // printf("DEBUG: Radian input = %lf\n", radian_input);
        // printf("DEBUG: PI = %.15f, factor = %.15f\n", M_PI, (180.0 / M_PI));

        degree_result1 = radian_input1 * (180.0 / M_PI);
        printf("%lf rad = %lf deg", radian_input1, degree_result1);

        printf("\n\t\tPRESS ENTER TO CONTINUE...");
        getchar();
        getchar();
        clear_screen();
        goto Angle_conversions;
    }
    else if (angle_conversion_choice == 99)
    {
        clear_screen();
        Trigonometry();
    }
    else
    {
        printf("\nERROR, PLEASE ENTER CORRECT OPTION !!!\n");

        printf("\n\t\tPRESS ENTER TO CONTINUE...");
        getchar();
        getchar();
        clear_screen();
        goto Angle_conversions;
    }
}

void Triangle_Solver()
{
    int triangle_choice;

    double a, b, c, A, B, C;

Triangle_solver:

    printf("\t----------------------------------------------------------------------------------------\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                  Triangle Solver                                     |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|      1. SSS (Three sides)                    2. SAS (Two Sides + Included Angle)     |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|      3. ASA / AAS (Two Angles + One Side)    4. SSA (Two Sides + Angle NOT between)  |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                 99. Back to main menu                                |\n");
    printf("\t|                                                                                      |\n");
    printf("\t----------------------------------------------------------------------------------------\n");

    printf("ENTER YOUR OPTION : ");
    scanf("%d", &triangle_choice);
    clear_screen();

    if (triangle_choice == 1)
    {
        printf("Enter side a : ");
        scanf("%lf", &a);
        printf("\nEnter side b : ");
        scanf("%lf", &b);
        printf("\nEnter side c : ");
        scanf("%lf", &c);

        A = toDeg(acos((b * b + c * c - a * a) / (2 * b * c)));
        B = toDeg(acos((a * a + c * c - b * b) / (2 * a * c)));
        C = 180.0 - A - B;

        printf("Angles : A = %.2lf deg, B = %.2lf deg, C = %.2lf deg\n", A, B, C);

        printf("\n\t\tPRESS ENTER TO CONTINUE...");
        getchar();
        getchar();
        clear_screen();
        goto Triangle_solver;
    }
    else if (triangle_choice == 2)
    {
        printf("Enter side a : ");
        scanf("%lf", &a);
        printf("Enter side b : ");
        scanf("%lf", &b);
        printf("Enter angle c (deg) : ");
        scanf("%lf", &C);

        c = sqrt(a * a + b * b - 2 * a * b * cos(toRad(C)));
        A = toDeg(asin((a * sin(toRad(C))) / c));
        B = 180.0 - A - C;

        printf("Side c = %.2lf\n", c);
        printf("Angles : A = %.2lf deg, B = %.2lf deg, C = %.2lf deg\n", A, B, C);

        printf("\n\t\tPRESS ENTER TO CONTINUE...");
        getchar();
        getchar();
        clear_screen();
        goto Triangle_solver;
    }
    else if (triangle_choice == 3)
    {
        printf("Enter angles a (deg) : ");
        scanf("%lf", &A);
        printf("Enter angles b (deg) : ");
        scanf("%lf", &B);
        printf("Enter side c : ");
        scanf("%lf", &c);

        C = 180.0 - A - B;
        a = (c * sin(toRad(A))) / sin(toRad(C));
        b = (c * sin(toRad(B))) / sin(toRad(C));

        printf("Sides a = %.2lf, b = %.2lf\n", a, b);
        printf("Angles : A = %.2lf deg, B = %.2lf deg, C = %.2lf deg\n", A, B, C);

        printf("\n\t\tPRESS ENTER TO CONTINUE...");
        getchar();
        getchar();
        clear_screen();
        goto Triangle_solver;
    }
    else if (triangle_choice == 4)
    {
        printf("Enter side a : ");
        scanf("%lf", &a);
        printf("Enter side b : ");
        scanf("%lf", &b);
        printf("Enter angle a (deg) : ");
        scanf("%lf", &A);

        double sinB = (b * sin(toRad(A))) / a;

        if (sinB < -1.0 || sinB > 1.0)
        {
            printf("Invalid triangle: no real solution.\n");
            printf("\n\t\tPRESS ENTER TO CONTINUE...");
            getchar();
            getchar();
            clear_screen();
            goto Triangle_solver;
        }
        else
        {
            B = toDeg(asin(sinB));
            C = 180.0 - A - B;
            c = (a * sin(toRad(C))) / sin(toRad(A));

            printf("Side c = %.2lf\n", c);
            printf("Angles : A = %.2lf deg, B = %.2lf deg, C = %.2lf deg\n", A, B, C);

            printf("\n\t\tPRESS ENTER TO CONTINUE...");
            getchar();
            getchar();
            clear_screen();
            goto Triangle_solver;
        }
    }
    else if (triangle_choice == 99)
    {
        clear_screen();
        Trigonometry();
    }
    else
    {
        printf("Invalid choice! Please enter a valid option.\n");
        printf("\n\t\tPRESS ENTER TO CONTINUE...");
        getchar();
        getchar();
        clear_screen();
        goto Triangle_solver;
    }
}

void Geometry()
{
    int geometry_menu_choice;

    geometry:

    printf("\t----------------------------------------------------------------------------------------\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                   GEOMETRY                                           |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|        1. 2D Shapes             2. 3D Shapes               3. Triangles              |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|        4. Circles           5. Coordinate Geometry        6. Transformations         |\n");
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
    scanf("%d", &geometry_menu_choice);

    if(geometry_menu_choice == 1){
        clear_screen();
        twod_shapes();
    }
    else if(geometry_menu_choice == 2){
        clear_screen();  
        threed_shapes(); 
    }
    else if(geometry_menu_choice == 3){
        clear_screen();
        triangles_geometry();
    }
    else if(geometry_menu_choice == 4){
        clear_screen();
        circles_geometry();
    }
    else if(geometry_menu_choice == 5){
        clear_screen();
        coordinate_geometry();
    }
    else if(geometry_menu_choice == 6){
        clear_screen();
        transformations_geometry();
    }
    else if(geometry_menu_choice == 99){
        clear_screen();
        main();
    }
    else {
        printf("\nERROR, PLEASE ENTER CORRECT OPTION !!!\n");

        printf("\n\t\tPRESS ENTER TO CONTINUE...");
        getchar();
        getchar();
        clear_screen();
        goto geometry;
    }


}

/*
FEATURES TO ADD

| Shape             | Properties to Add                         |
| ----------------- | ----------------------------------------- |
| **Square**        | Area, Perimeter                           |
| **Rectangle**     | Area, Perimeter                           |
| **Circle**        | Area, Circumference                       |
| **Triangle**      | Area (various methods), Perimeter, Angles |
| **Parallelogram** | Area, Perimeter                           |
| **Rhombus**       | Area, Perimeter                           |
| **Trapezium**     | Area, Perimeter                           |
| **Kite**          | Area, Perimeter                           |
| **Ellipse**       | Area, Circumference (approx)              |

*/

void twod_shapes(){
    int twod_choice;


    printf("\t----------------------------------------------------------------------------------------\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                   GEOMETRY                                           |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|        1. Square            2. Rectangle               3. Circle                     |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|        4. Triangle           5. Parallelogram        6. Rhombus                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|        7. Trapezium          8. Kite                 9. Ellipse                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                                                                                      |\n");
    printf("\t|                             99. Back to main menu                                    |\n");
    printf("\t|                                                                                      |\n");
    printf("\t----------------------------------------------------------------------------------------\n");
    printf("ENTER YOUR OPTION : ");

}

/*
features to add

| Shape           | Volume                      | Surface Area               |
| --------------- | --------------------------- | -------------------------- |
| **Cube**        | a³                          | 6a²                        |
| **Cuboid**      | l × b × h                   | 2(lb + bh + hl)            |
| **Sphere**      | (4/3)πr³                    | 4πr²                       |
| **Cylinder**    | πr²h                        | 2πr(h + r)                 |
| **Cone**        | (1/3)πr²h                   | πr(l + r)                  |
| **Torus**       | 2π²Rr²                      | 4π²Rr                      |
| **Hemisphere**  | (2/3)πr³                    | 3πr²                       |
| **Pyramid**     | (1/3) × base\_area × height | base\_area + lateral\_area |
| **Tetrahedron** | (a³ / (6√2))                | √3 × a²                    |

*/
void threed_shapes(){

}

/*
features to add

| Formula             | Use                        |
| ------------------- | -------------------------- |
| Heron’s Formula     | Area from 3 sides          |
| ½ × base × height   | Classic area               |
| Sine Rule           | Non-right triangle solving |
| Cosine Rule         | Side-angle relations       |
| Pythagorean Theorem | Right triangles            |
| Angle Sum Property  | A + B + C = 180°           |

*/
void triangles_geometry(){

}

/*
features to add

| Feature               | Formula                                   | Description                                                |
| --------------------- | ----------------------------------------- | ---------------------------------------------------------- |
| **Radius (r)**        | User input / derived                      | Basic length from center to any point on circle            |
| **Diameter (d)**      | `d = 2r`                                  | Distance across the circle                                 |
| **Circumference (C)** | `C = 2πr` or `πd`                         | Perimeter of the circle                                    |
| **Area (A)**          | `A = πr²`                                 | Total area enclosed                                        |
| **Arc Length (s)**    | `s = (θ/360) × 2πr`                       | Length of a curved part of the circle                      |
| **Sector Area**       | `A = (θ/360) × πr²`                       | Area of the ‘pizza slice’ of the circle                    |
| **Segment Area**      | `A = (r²/2)(θ - sinθ)` (θ in radians)     | Area of segment (between chord and arc)                    |
| **Chord Length (c)**  | `c = 2r * sin(θ/2)`                       | Length of a straight line between two points on the circle |
| **Central Angle (θ)** | `θ = (s / (2πr)) × 360`                   | Angle at center for arc length s                           |
| **Inscribed Angle**   | `= ½ × central angle`                     | Angle with vertex on circle boundary                       |
| **Circle Equation**   | `(x - a)² + (y - b)² = r²`                | Used in coordinate geometry (center (a, b))                |
| **Tangents**          | `length = √(d² - r²)` from external point | Tangent from a point outside the circle                    |

*/
void circles_geometry(){

}

/*
features to add

| Formula                   | Meaning                     |                                   |   |
| ------------------------- | --------------------------- | --------------------------------- | - |
| Distance between 2 points | √\[(x₂ − x₁)² + (y₂ − y₁)²] |                                   |   |
| Midpoint of line segment  | ((x₁ + x₂)/2 , (y₁ + y₂)/2) |                                   |   |
| Slope (m) of line         | (y₂ − y₁)/(x₂ − x₁)         |                                   |   |
| Equation of line          | y = mx + c                  |                                   |   |
| Area of triangle          | ½ ×                         | x₁(y₂−y₃) + x₂(y₃−y₁) + x₃(y₁−y₂) |   |

*/
void coordinate_geometry(){

}

/*
features to add

| Formula                   | Meaning                     |                                   |   |
| ------------------------- | --------------------------- | --------------------------------- | - |
| Distance between 2 points | √\[(x₂ − x₁)² + (y₂ − y₁)²] |                                   |   |
| Midpoint of line segment  | ((x₁ + x₂)/2 , (y₁ + y₂)/2) |                                   |   |
| Slope (m) of line         | (y₂ − y₁)/(x₂ − x₁)         |                                   |   |
| Equation of line          | y = mx + c                  |                                   |   |
| Area of triangle          | ½ ×                         | x₁(y₂−y₃) + x₂(y₃−y₁) + x₃(y₁−y₂) |   |

*/
void transformations_geometry(){

}







void Statistics()
{
    printf("this for stats");
}

void Coversions()
{
    printf("this for conves");
}
