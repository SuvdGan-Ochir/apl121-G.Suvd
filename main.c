/*
 * APL121 - Bie daalt No1 - Code Quest
 * Sedev 1: Tegsh, sondgoin udur (Ulaanbaatar-iin mashin hoorlolt)
 *
 * Durem: 1-r udur 1,6 | 2-r udur 2,7 | 3-r udur 3,8
 *        4-r udur 4,9 | 5-r udur 5,0 | Byamba, Nyam hoorilgui
 */
#include <stdio.h>
#include <stdlib.h>

#define CARS 3
#define DAYS 7

/* Element 5: dad algoritm - udriin ner (switch: element 3) */
const char *dayName(int day) {
    switch (day) {
        case 1: return "Davaa";
        case 2: return "Myagmar";
        case 3: return "Lhagva";
        case 4: return "Purev";
        case 5: return "Baasan";
        case 6: return "Byamba";
        case 7: return "Nyam";
        default: return "?";
    }
}

/* Element 5: dad algoritm - yavj boloh eseh (1 = bolno, 0 = bolohgui) */
int canDrive(int digit, int day) {
    if (day >= 6) {
        return 1;                      /* Byamba, Nyam: hoorilgui */
    }
    return (digit % 5) != (day % 5);   /* 5 ba 0 -> Baasan deer hoorlono */
}

/* Element 5: 7 honogt yavj boloh udriin too */
int countDays(int digit) {
    int total = 0;
    for (int day = 1; day <= DAYS; day++) {
        total += canDrive(digit, day);
    }
    return total;
}

/* Element 7: orolt shalgalt (do-while) */
int readInt(const char *prompt, int min, int max) {
    int x = min - 1;
    int ok;
    do {
        printf("%s", prompt);
        ok = scanf("%d", &x);
        if (ok == EOF) {
            printf("\nOrolt duuslaa.\n");
            exit(1);
        }
        if (ok != 1) {                 /* too bish orolt */
            while (getchar() != '\n') { }
            x = min - 1;
        }
        if (x < min || x > max) {
            printf("Buruu utga! %d-%d hoorond too oruul.\n", min, max);
        }
    } while (x < min || x > max);
    return x;
}

int main(void) {
    int digit[CARS];
    int count[CARS];
    char prompt[64];

    /* Element 1: orolt */
    printf("=== Tegsh, sondgoin udur ===\n");
    for (int i = 0; i < CARS; i++) {
        snprintf(prompt, sizeof(prompt),
                 "Mashin %d-iin dugaariin suuliin tsifr (0-9): ", i + 1);
        digit[i] = readInt(prompt, 0, 9);
    }
    int today = readInt("Onoodriin garag (1=Davaa ... 7=Nyam): ", 1, 7);

    /* Element 2 + 3: uildel, nohtsol - onoodor */
    printf("\nOnoodor (%s):\n", dayName(today));
    for (int i = 0; i < CARS; i++) {
        if (canDrive(digit[i], today)) {
            printf("  Mashin %d (tsifr %d): hotiin tuviar yavj BOLNO\n",
                   i + 1, digit[i]);
        } else {
            printf("  Mashin %d (tsifr %d): yavj BOLOHGUI\n",
                   i + 1, digit[i]);
        }
    }

    /* Element 4: davtalt ba husnegt - 7 honogiin husnegt */
    printf("\n7 honogiin husnegt:\n");
    printf("%-10s", "Garag");
    for (int i = 0; i < CARS; i++) {
        printf("%-10s", (i == 0) ? "Mashin 1" : (i == 1) ? "Mashin 2" : "Mashin 3");
    }
    printf("\n");
    for (int day = 1; day <= DAYS; day++) {
        printf("%-10s", dayName(day));
        for (int i = 0; i < CARS; i++) {
            printf("%-10s", canDrive(digit[i], day) ? "Yavna" : "Horiotoi");
        }
        printf("\n");
    }

    /* Element 6: hailt - hamgiin olon udur yavah mashin */
    for (int i = 0; i < CARS; i++) {
        count[i] = countDays(digit[i]);
    }
    int best = 0;
    for (int i = 1; i < CARS; i++) {
        if (count[i] > count[best]) {
            best = i;
        }
    }

    printf("\nNiit yavah udur (7 honogt):\n");
    for (int i = 0; i < CARS; i++) {
        printf("  Mashin %d: %d udur\n", i + 1, count[i]);
    }
    printf("Hamgiin olon udur yavah (%d udur):", count[best]);
    for (int i = 0; i < CARS; i++) {
        if (count[i] == count[best]) {
            printf(" Mashin %d", i + 1);
        }
    }
    printf("\n");

    return 0;
}
