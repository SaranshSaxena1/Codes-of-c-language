#include <stdio.h>
#include <stdbool.h>

int getChineseZodiac(int year) {
    // Add logic to determine Chinese zodiac sign based on year
    int zodiacYear = (year - 1900) % 12;
    switch(zodiacYear) {
        case 0: return 8; // Monkey
        case 1: return 9; // Rooster
        case 2: return 10; // Dog
        case 3: return 11; // Boar
        case 4: return 0; // Rat
        case 5: return 1; // Ox
        case 6: return 2; // Tiger
        case 7: return 3; // Rabbit
        case 8: return 4; // Dragon
        case 9: return 5; // Snake
        case 10: return 6; // Horse
        case 11: return 7; // Ram
        default: return -1; // Error
    }
}

void printChineseZodiac(int year) {
    // Print Chinese zodiac sign based on year
    int zodiacIndex = getChineseZodiac(year);
    if (zodiacIndex != -1) {
        const char *zodiacs[] = {"Monkey", "Rooster", "Dog", "Boar", "Rat", "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Ram"};
        printf("You are born on the Year of the %s.\n", zodiacs[zodiacIndex]);
    } else {
        printf("Failed to determine Chinese zodiac sign.\n");
    }
}

void printZodiacInfo(int month, int day, int year) {
    // Add logic to determine zodiac sign and birthstone based on month and day
    const char *zodiacSigns[] = {"Capricorn", "Aquarius", "Pisces", "Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn"};
    const char *birthstones[] = {"Garnet", "Amethyst", "Aquamarine or Bloodstone", "Diamond", "Emerald", "Pearl, Alexandrite or Moonstone", "Ruby", "Peridot or Sardonyx", "Sapphire", "Opal or Tourmaline", "Topaz", "Turquoise or Zircon", "Garnet"};
    
    printf("You are born on %d-%d-%d.\n", month, day, year);
    printf("You are born on the month of %s.\n", zodiacSigns[month - 1]);
    printf("Your BirthStone is %s.\n", birthstones[month - 1]);

    // Add logic to determine zodiac sign based on month and day
    if ((month == 1 && day > 19) || (month == 2 && day <= 18)) {
        printf("You are an Aquarius.\n");
    } else if ((month == 2 && day > 18) || (month == 3 && day <= 20)) {
        printf("You are a Pisces.\n");
    } else if ((month == 3 && day > 20) || (month == 4 && day <= 19)) {
        printf("You are an Aries.\n");
    } else if ((month == 4 && day > 19) || (month == 5 && day <= 20)) {
        printf("You are a Taurus.\n");
    } else if ((month == 5 && day > 20) || (month == 6 && day <= 20)) {
        printf("You are a Gemini.\n");
    } else if ((month == 6 && day > 20) || (month == 7 && day <= 22)) {
        printf("You are a Cancer.\n");
    } else if ((month == 7 && day > 22) || (month == 8 && day <= 22)) {
        printf("You are a Leo.\n");
    } else if ((month == 8 && day > 22) || (month == 9 && day <= 22)) {
        printf("You are a Virgo.\n");
    } else if ((month == 9 && day > 22) || (month == 10 && day <= 22)) {
        printf("You are a Libra.\n");
    } else if ((month == 10 && day > 22) || (month == 11 && day <= 21)) {
        printf("You are a Scorpio.\n");
    } else if ((month == 11 && day > 21) || (month == 12 && day <= 21)) {
        printf("You are a Sagittarius.\n");
    } else if ((month == 12 && day > 21) || (month == 1 && day <= 19)) {
        printf("You are a Capricorn.\n");
    }
}

int main() {
    int year, month, day;

    printf("Enter Year (1970-2005): ");
    scanf("%d", &year);

    while (year < 1970 || year > 2005) {
        printf("Invalid year. Enter Year (1970-2005): ");
        scanf("%d", &year);
    }

    printf("Enter Month (1-12): ");
    scanf("%d", &month);

    while (month < 1 || month > 12) {
        printf("Invalid month. Enter Month (1-12): ");
        scanf("%d", &month);
    }

    printf("Enter Day (1-31): ");
    scanf("%d", &day);

    // Add logic to validate day based on month

    printZodiacInfo(month, day, year);
    printChineseZodiac(year);

    return 0;
}
