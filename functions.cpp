#include "header.h"

/*************************************************************************************************************************************
  @name         :
  @description  :
  @param
  @return
*************************************************************************************************************************************/
int initialize()
{
    /* Parameters */
    globalParam.marryAgeMale = 21;
    globalParam.marryAgeFemale = 18;
    globalParam.marryAgeMargin = 15;
    globalParam.lifeExpectency = 85;
    globalParam.lifeExpectencyMargin = 20;
    globalParam.nextChildGap = 3;
    globalParam.tfr = 6; 
    globalParam.maxMaleFertilityAge = 60; 
    globalParam.maxFemaleFertilityAge = 45; 

    /* Statistics */
    globalStats.mIndex = 0;
    globalStats.fIndex = 0;
    globalStats.totalMaleAge = 0;
    globalStats.totalFemaleAge = 0;
    globalStats.totalCouples = 0;
    globalStats.totalMaleDeath = 0;
    globalStats.totalFemaleDeath = 0;
    globalStats.totalYears = 1;
    globalStats.birthsThisYear = 0;
    globalStats.deathsThisYear = 0;
    globalStats.totalChildren = 0;

    /* Adam & Eve */
    person_t m1;
    person_t f1;

    m1.id = 1;
    m1.age = globalParam.marryAgeMale;
    f1.id = 1;
    f1.age = globalParam.marryAgeFemale;

    addPerson(MALE, m1);
    addPerson(FEMALE, f1);

    return SUCCESS;
}

/*************************************************************************************************************************************
  @name         :
  @description  :
  @param
  @return
*************************************************************************************************************************************/
int addPerson(int sex, person_t person)
{
    int retval = 0;

    if (sex == MALE)
    {
        mList.push_back(person);
        globalStats.mIndex++;
        globalStats.totalMales++;
        globalStats.totalMaleAge =+ person.age;
    }
    else
    {
        fList.push_back(person);
        globalStats.fIndex++;
        globalStats.totalFemales++;
        globalStats.totalFemaleAge =+ person.age;
    }

    return SUCCESS;
}

/*************************************************************************************************************************************
  @name         :
  @description  :
  @param
  @return
*************************************************************************************************************************************/
void displayMenu()
{
    cout<<endl;
    cout<<"1> Advance years"<<endl;
    cout<<"2> View/Modify parameters"<<endl;
    cout<<"3> Display stats"<<endl;
    cout<<"0> Exit"<<endl;
    cout<<"Choice: ";
}

/*************************************************************************************************************************************
  @name         :
  @description  :
  @param
  @return
*************************************************************************************************************************************/
void displayModifyMenu()
{
    cout<<endl;
    cout<<"+----------------------------------------------------------+"<<endl;
    cout<<"|                      PARAMETERS                          |"<<endl;
    cout<<"+----------------------------------------------------------+"<<endl;
    printf("| 1> Male Marriage Age              : %-20d |\n", globalParam.marryAgeMale);
    printf("| 2> Female Marriage Age            : %-20d |\n", globalParam.marryAgeFemale);
    printf("| 3> Marriage Age Margin            : %-20d |\n", globalParam.marryAgeMargin);
    printf("| 4> Life Expectancy                : %-20d |\n", globalParam.lifeExpectency);
    printf("| 5> Life Expectancy Margin         : %-20d |\n", globalParam.lifeExpectencyMargin);
    printf("| 6> Next Child Gap                 : %-20d |\n", globalParam.nextChildGap);
    printf("| 7> Total Fertility Rate           : %-20d |\n", globalParam.tfr);
    printf("| 8> Max Male Fertility Age         : %-20d |\n", globalParam.maxMaleFertilityAge);
    printf("| 9> Max Female Fertility Age       : %-20d |\n", globalParam.maxFemaleFertilityAge);
    cout<<"+----------------------------------------------------------+"<<endl;
    cout<<"| 0> Back                                                  |"<<endl;
    cout<<"+----------------------------------------------------------+"<<endl;

}

int processModifyRequest (char *choice)
{
    int val = 0;

    if (strcmp(choice, "1") == 0)
    {
        cout<<"Enter new value: ";
        cin>>val;
        globalParam.marryAgeMale = val;
    }
    else if (strcmp(choice, "2") == 0)
    {
        cout<<"Enter new value: ";
        cin>>val;
        globalParam.marryAgeFemale = val;
    }
    else if (strcmp(choice, "3") == 0)
    {
        cout<<"Enter new value: ";
        cin>>val;
        globalParam.marryAgeMargin = val;
    }
    else if (strcmp(choice, "4") == 0)
    {
        cout<<"Enter new value: ";
        cin>>val;
        globalParam.lifeExpectency = val;
    }
    else if (strcmp(choice, "5") == 0)
    {
        cout<<"Enter new value: ";
        cin>>val;
        globalParam.lifeExpectencyMargin = val;
    }
    else if (strcmp(choice, "6") == 0)
    {
        cout<<"Enter new value: ";
        cin>>val;
        globalParam.nextChildGap = val;
    }
    else if (strcmp(choice, "7") == 0)
    {
        cout<<"Enter new value: ";
        cin>>val;
        globalParam.tfr = val;
    }
    else if (strcmp(choice, "8") == 0)
    {
        cout<<"Enter new value: ";
        cin>>val;
        globalParam.maxMaleFertilityAge = val;
    }
    else if (strcmp(choice, "9") == 0)
    {
        cout<<"Enter new value: ";
        cin>>val;
        globalParam.maxFemaleFertilityAge = val;
    }
    else if (strcmp(choice, "0") == 0)
    {
        return SUCCESS;
    }
    else
    {
        cout<<"ERROR: Invalid Option selected\n";
    }

    return SUCCESS;
}

/*************************************************************************************************************************************
  @name         :
  @description  :
  @param
  @return
*************************************************************************************************************************************/
int displayStats()
{
    unsigned int sexRatio = 0;
    double deathRate = 0;
    double birthRate = 0;
    double avgNumOfChildren = 0;

    if (globalStats.totalMales != 0)
    {
        sexRatio = (globalStats.totalFemales * 1000); 
        sexRatio = sexRatio/globalStats.totalMales;
    }

    if ((globalStats.totalMales + globalStats.totalFemales) == 0)
    {
        birthRate = 0;
    }
    else
    {
        birthRate = (double)(globalStats.birthsThisYear * 10)/(globalStats.totalMales + globalStats.totalFemales);
    }

    if ((globalStats.totalMales + globalStats.totalFemales) == 0)
    {
        deathRate = 0;
    }
    else
    {
        deathRate = (double)(globalStats.deathsThisYear * 10)/(globalStats.totalMales + globalStats.totalFemales);
    }

    if (globalStats.totalCouples == 0)
    {
        avgNumOfChildren = 0;
    }
    else
    {
        avgNumOfChildren = (double)globalStats.totalChildren/globalStats.totalCouples;
    }

    cout<<endl;
    cout<<"+----------------------------------------------------------+"<<endl;
    cout<<"|                      STATISTICS                          |"<<endl;
    cout<<"+----------------------------------------------------------+"<<endl;
    printf("| Elapsed time (yrs)                : %-20u |\n", globalStats.totalYears);
    printf("| Total Males                       : %-20u |\n", globalStats.totalMales);
    printf("| Total Females                     : %-20u |\n", globalStats.totalFemales);
    printf("| Sex Ratio (females/1000 males)    : %-20u |\n", sexRatio);
    printf("| Avg Male age                      : %-20u |\n", !globalStats.totalMales ? 0  : (globalStats.totalMaleAge/globalStats.totalMales));
    printf("| Avg Female age                    : %-20u |\n", !globalStats.totalFemales ? 0 : (globalStats.totalFemaleAge/globalStats.totalFemales));
    printf("| Total Couples                     : %-20u |\n", globalStats.totalCouples);
    printf("| Avg Children per family           : %-20f |\n", avgNumOfChildren);
    printf("| Deaths till now                   : %-20u |\n", globalStats.totalMaleDeath + globalStats.totalFemaleDeath);
    printf("| Crude Birth rate (/10 people)     : %-20f |\n", birthRate);
    printf("| Crude Death rate (/10 people)     : %-20f |\n", deathRate);
    cout<<"+----------------------------------------------------------+"<<endl;
    printf("| Total Population                  : %-20u |\n", globalStats.totalMales + globalStats.totalFemales);
    cout<<"+----------------------------------------------------------+"<<endl;

    return SUCCESS;
}

/*************************************************************************************************************************************
  @name         :
  @description  : Updates Male/Female list by 1 year advancement.
  @param
  @return
*************************************************************************************************************************************/
int updateIndividualList(list<person_t> *lst, int sex)
{
    list<person_t>::iterator it; 

    if ((*lst).size() == 0)
    {
        //debug_print(("DEBUG: %s No person in list\n", __FUNCTION__));
        return SUCCESS;
    }

    it = (*lst).begin();

    while (it != (*lst).end())
    {
        (it->age)++;

        /* Update Stats */
        if (sex == MALE)
        {
            globalStats.totalMaleAge++;
        }
        else
        {
            globalStats.totalFemaleAge++;
        }
        it++;
    }

    return SUCCESS;
}

/*************************************************************************************************************************************
  @name         :
  @description  : Updates Male/Female list by 1 year advancement.
  @param
  @return
*************************************************************************************************************************************/
int updateCoupleList()
{
    list<couple_t>::iterator it; 

    if (cpList.size() == 0)
    {
        //debug_print(("DEBUG: %s No person in couple list\n", __FUNCTION__));
        return SUCCESS;
    }

    it = cpList.begin();

    while (it != cpList.end())
    {
        if (!it->mDead)
        {
            (it->mAge)++;
            globalStats.totalMaleAge++;
        }

        if (!it->fDead)
        {
            (it->fAge)++;
            globalStats.totalFemaleAge++;
        }

        (it->lastChildDuration)++;

        if ((it->fAge > globalParam.maxFemaleFertilityAge) || (it->mAge > globalParam.maxMaleFertilityAge))
        {
            it->isDormant = true;
        }

        it++;
    }

    return SUCCESS;
}

/*************************************************************************************************************************************
  @name         :
  @description  : Checks if an individual has reached his life expectency. Handle death scenario and counters.
  @param
  @return
*************************************************************************************************************************************/
int checkDeath(list<person_t> *lst, int sex)
{
    list<person_t>::iterator it; 
    int testAge = 0;
    bool died = false;
    int min = globalParam.lifeExpectency - globalParam.lifeExpectencyMargin; 
    int max = globalParam.lifeExpectency + globalParam.lifeExpectencyMargin; 

    globalStats.deathsThisYear = 0;

    if ((*lst).size() == 0)
    {
        //debug_print(("DEBUG: No person in list\n"));
        return EMPTY_LIST;
    }

    it = (*lst).begin();

    while (it != (*lst).end())
    {
        died = false;
        testAge = generateRandom(min, max);
        if (it->age > testAge)
        {
            /* Update Stats. We need the data of the person to update stats.
               So clearing is done after this.*/
            if (sex == MALE)
            {
                debug_print(("# M-%d died at the age of %d\n", it->id, it->age));
                globalStats.totalMaleAge = globalStats.totalMaleAge - it->age;
                globalStats.totalMales--;
                globalStats.totalMaleDeath++;
                globalStats.deathsThisYear++;
                mList.erase(it++);
                died = true;
            }
            else
            {
                debug_print(("# F-%d died at the age of %d\n", it->id, it->age));
                globalStats.totalFemaleAge = globalStats.totalFemaleAge - it->age;
                globalStats.totalFemales--;
                globalStats.totalFemaleDeath++;
                globalStats.deathsThisYear++;
                fList.erase(it++);
                died = true;

            }

        }

        if (died == false)
        {
            it++;
        }
    }

    return TRUE;
}

/*************************************************************************************************************************************
  @name         :
  @description  : Checks if an individual has reached his life expectency. Handle death scenario and counters. Keep the individual in
                  the couple list as long as both of them have not died.
  @param
  @return
*************************************************************************************************************************************/
int checkCoupleDeath()
{
    list<couple_t>::iterator it; 
    int testAge = 0;
    bool died = false;
    int min = globalParam.lifeExpectency - globalParam.lifeExpectencyMargin; 
    int max = globalParam.lifeExpectency + globalParam.lifeExpectencyMargin; 

    if (cpList.empty())
    {
        //debug_print(("DEBUG: No person in list\n"));
        return EMPTY_LIST;
    }

    it = cpList.begin();

    while (it != cpList.end())
    {
        died = false;

        /* check for husband */
        testAge = generateRandom(min, max);
        if ((it->mDead == false) && (it->mAge >= testAge))
        { 
            debug_print(("# M-%d died at the age of %d\n", it->mId, it->mAge));
            it->mDead = true;
            it->isPartnerDead = true;
            globalStats.totalMaleAge = globalStats.totalMaleAge - it->mAge;
            globalStats.totalMales--;
            globalStats.totalMaleDeath++;
            globalStats.deathsThisYear++;

        }

        /* check for wife */
        testAge = generateRandom(min, max);
        if ((it->fDead == false) && (it->fAge >= testAge))
        {
            debug_print(("# F-%d died at the age of %d\n", it->fId, it->fAge));
            it->fDead = true;
            it->isPartnerDead = true;
            globalStats.totalFemaleAge = globalStats.totalFemaleAge - it->fAge;
            globalStats.totalFemales--;
            globalStats.totalFemaleDeath++;
            globalStats.deathsThisYear++;

        }

        /* Couple dead */
        if (it->mDead && it->fDead)
        {
            globalStats.totalCouples--;
            if (globalStats.totalChildren >= it->children)
            {
                globalStats.totalChildren = globalStats.totalChildren - it->children;
            }
            cpList.erase(it++);
            died = true;
        }

        if (died == false)
        {
            it++;
        }
    }

    return SUCCESS;
}

/*************************************************************************************************************************************
  @name         :
  @description  : Check if a person is eligible for marriage. Choose a suitable partner. get them married and add to the couple list.
  @param
  @return
*************************************************************************************************************************************/
int checkMarriage()
{
    list<person_t>::iterator it;
    list<person_t>::iterator it2;
    bool married = false;

    if (mList.size() == 0)
    {
        //debug_print(("DEBUG: No person in couple list\n"));
        return SUCCESS;
    }

    /* Pick one male and check his eligibility */
    it = mList.begin();
    while (it != mList.end())
    {
        married = false;

        /* Check if he has reached his legal marriage age */
        if (it->age < globalParam.marryAgeMale)
        {
            it++;
            continue;
        }
        
        int testAge = 0;
        int min = globalParam.marryAgeMale;
        int max = globalParam.marryAgeMale + globalParam.marryAgeMargin;
        testAge = generateRandom(min, max);

        if (it->age > testAge)
        {
            /* Suitable male candidate, now search a partner for him. */
            it2 = fList.begin();
            while (it2 != fList.end())
            {
                /* Check if she has reached his legal marriage age */
                if (it2->age < globalParam.marryAgeFemale)
                {
                    it2++;
                    continue;
                }

                int testAge2 = 0;
                int min2 = globalParam.marryAgeFemale;
                int max2 = globalParam.marryAgeFemale + globalParam.marryAgeMargin;
                testAge2 = generateRandom(min2, max2);

                if (it2->age < testAge2)
                {
                    /* VOILA!, we found a couple */
                    person_t m = *it;
                    person_t f = *it2;

                    debug_print(("# M-%d [%d] marries to F-%d [%d]\n", it->id, it->age, it2->id, it2->age));

                    /* Remove from individual list */
                    mList.erase(it++);
                    fList.erase(it2++);
                    married = true;

                    /* Add to couple list */
                    addToCoupleList(m, f);
                    break;
                }

                if (married == false)
                {
                    it2++;
                }
            }
        }

        if (married == false)
        {
            //debug_print(("No partner found for M-%d.\n", it->id));
            it++;
        }
    }
    return SUCCESS;
}

/*************************************************************************************************************************************
  @name         :
  @description  : Add the couple to couple list and initialize the data.
  @param
  @return
*************************************************************************************************************************************/
int addToCoupleList(person_t m, person_t f)
{
    couple_t couple;
    
    /* Initialize couple data */
    couple.mId = m.id;
    couple.fId = f.id;
    couple.mAge = m.age;
    couple.fAge = f.age;
    couple.children = 0;
    couple.isDormant = false;
    couple.lastChildDuration = 0;
    couple.isPartnerDead = false;
    couple.mDead = false;
    couple.fDead = false;

    /* Add to couple list */
    cpList.push_back(couple);

    globalStats.totalCouples++;

    return SUCCESS;
}

/*************************************************************************************************************************************
  @name         :
  @description  :
  @param
  @return
*************************************************************************************************************************************/
int checkBirth()
{
    list<couple_t>::iterator it;

    if (cpList.empty())
    {
        //debug_print(("No couple present\n"));
        return FAILURE;
    }

    it = cpList.begin();
    globalStats.birthsThisYear = 0;

    while (it != cpList.end())
    {
        if (it->isDormant) 
        {
            it++;
            //debug_print(("DEBUG: Cannot reproduce. Dormant.\n"));
            continue;
        }
 
        if (it->lastChildDuration < globalParam.nextChildGap) 
        {
            it++;
            //debug_print(("DEBUG: Cannot reproduce. Child gap not attained\n"));
            continue;
        }
           
        if (it->children >= globalParam.tfr)
        {
            it++;
            //debug_print(("DEBUG: Cannot reproduce. TFR exceeded!\n"));
            continue;
        }

        int testAge = 0;
        int min = globalParam.marryAgeFemale;
        int max = globalParam.maxFemaleFertilityAge ;
        testAge = generateRandom(min, max);
       
        if (it->fAge > testAge)
        {
            /* Reproduce */
            int testSample = 0;
            int min = 1;
            int max = 10 ;
            testSample = generateRandom(min, max);

            if (testSample <= 5)
            {
                /* Baby girl */
                person_t f;
                globalStats.fIndex++;
                globalStats.totalFemales++;
                f.age = 0;
                f.id = globalStats.fIndex;
                fList.push_back(f);
                debug_print(("# M-%d [%d] and F-%d [%d] gave birth to a baby girl F-%d\n", it->mId, it->mAge, it->fId, it->fAge, f.id)); 
                
            }
            else
            {
                /* Baby boy */
                person_t m;
                globalStats.mIndex++;
                globalStats.totalMales++;
                m.age = 0;
                m.id = globalStats.mIndex;
                mList.push_back(m);
                debug_print(("# M-%d [%d] and F-%d [%d] gave birth to a baby boy M-%d \n", it->mId, it->mAge, it->fId, it->fAge, m.id)); 
            }

            globalStats.birthsThisYear++;

            /* Update couple details */
            it->children++;
            globalStats.totalChildren++;
            it->lastChildDuration = 0;
            if (it->children >= globalParam.tfr)
            {
                it->isDormant = true;
            }



        }

        it++;
    }

    return SUCCESS;
}

/*************************************************************************************************************************************
  @name         :
  @description  : Simulates advancement of 1 year. Following are simulated:-
                    1) Ageing
                    2) Marriage
                    3) Birth
                    4) Death
  @param
  @return
*************************************************************************************************************************************/
int simulate(int yearsToAdvance)
{
    int i = 0;
    int retval = 0;

    cout<<endl<<"Processing..."<<endl<<endl;

    while (i < yearsToAdvance)
    {
        /* Check current status of population */
        int categoryCount = 0;
        if ((mList.empty()) || (globalStats.totalMales == 0))
        {
            //debug_print(("# No males present \n"));
            categoryCount++;
        }
        if ((fList.empty()) || ((globalStats.totalFemales == 0))) 
        {
            //debug_print(("# No females present \n"));
            categoryCount++;
        }
        if ((cpList.empty()) || (globalStats.totalCouples == 0))
        {
            categoryCount++;
        }

        if (categoryCount >= 3)
        {
            debug_print(("# Population Wiped out.\n"));

            /* Update elapsed time counter */
            globalStats.totalYears++;
            i++;
            continue;
        }

        /* Advance age of males by 1 year */
        if (globalStats.totalMales >= 1)
        {
            retval = updateIndividualList(&mList, MALE); 
        }

        /* Advance age of females by 1 year */
        if (globalStats.totalFemales >= 1)
        {
            retval = updateIndividualList(&fList, FEMALE); 
        }

        /* Advance age of couples by 1 year */
        if (globalStats.totalCouples >= 1)
        {
            retval = updateCoupleList();
        }

        /* Check Male death */
        if (globalStats.totalMales >= 1)
        {
            retval = checkDeath(&mList, MALE);
        }

        /* Check female death */
        if (globalStats.totalFemales >= 1)
        {
            retval = checkDeath(&fList, FEMALE);
        }

        /* Check death in couple */
        if (globalStats.totalCouples >= 1)
        {
            retval = checkCoupleDeath();
        }

        /* Marriage Eligiblity */
        if ((globalStats.totalMales >= 1) && (globalStats.totalFemales >= 1))
        {
            retval = checkMarriage();
        }

        /* Birth check */
        if (globalStats.totalCouples >= 1)
        {
            retval = checkBirth();
        }

        /* Update elapsed time counter */
        globalStats.totalYears++;

        i++;
    }

    return SUCCESS;
}
