#include<iostream>
#include <sys/time.h>
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <list>
#include <vector>
#include <string.h>

/* Comment below line to switch OFF debugging */
#define DEBUG 1

#define SUCCESS 0
#define FAILURE 1
#define MALE 100
#define FEMALE 101
#define TRUE 1
#define FALSE 0
#define EMPTY_LIST 99

#ifdef DEBUG
#define debug_print(x) printf x
#else
#define debug_print(x)
#endif

using namespace std;

/* GLOBALS */

/* Parameters */
typedef struct globalParam_tag
{
    int marryAgeMale;
    int marryAgeFemale;
    int marryAgeMargin;
    int lifeExpectency;
    int lifeExpectencyMargin;
    int nextChildGap;
    int tfr; /* Total Fertility Rate */
    int maxMaleFertilityAge;
    int maxFemaleFertilityAge;
}globalParam_t;

/* Stats */
typedef struct globalStats_tag
{
    unsigned int mIndex;
    unsigned int fIndex;
    unsigned int totalMales;
    unsigned int totalFemales;
    unsigned int totalCouples;
    unsigned int totalMaleAge;
    unsigned int totalFemaleAge;
    unsigned int totalMaleDeath;
    unsigned int totalFemaleDeath;
    unsigned int totalYears;
    unsigned int birthsThisYear;
    unsigned int deathsThisYear;
    unsigned int totalChildren;
}globalStats_t;

typedef struct person_tag
{
    unsigned id;
    int age;
}person_t;

typedef struct couple_tag
{
    unsigned mId;
    unsigned fId;
    int mAge;
    int fAge;
    bool mDead;
    bool fDead;
    int children;
    int lastChildDuration;
    bool isDormant;
    bool isPartnerDead;
}couple_t;

extern globalParam_t globalParam;
extern globalStats_t globalStats;
extern list<person_t> mList;
extern list<person_t> fList;
extern list<couple_t> cpList;


/* Main functions */
int initialize();
void displayMenu();
int displayStats();
int simulate(int yearsToAdvance);
int addPerson(int sex, person_t person);
int updateIndividualList(list<person_t> *list);
int checkDeath(list<person_t> *list);
int addToCoupleList(person_t m, person_t f);
void displayModifyMenu();
int  processModifyRequest (char *choice);
/* Utility functions */
unsigned int generateRandom(int min, int max);

