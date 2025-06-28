
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
void Statistics();
void Coversions();

int main()
{
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
    printf("saffa");
}

void Geometry()
{
    printf("This is for geometry");
}

void Statistics()
{
    printf("this for stats");
}

void Coversions()
{
    printf("this for conves");
}
