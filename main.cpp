#include "header.h"

/* Global vars */
globalParam_t globalParam;
globalStats_t globalStats;
list<person_t> mList;
list<person_t> fList;
list<couple_t> cpList;

/**************************************************************************************
  M A I N
***************************************************************************************/
int main()
{
    int retval = 0;
    char userInput[10];

    /* Initialize global parameters */
    retval = initialize();

    /* Wait for input */
    while (1)
    {
        displayMenu();
        cin>>userInput;

        if (strcmp(userInput, "1") == 0)
        {
            /* Advance years */
            int yearsToAdvance = 0;
            cout<<" Enter years to advance: ";
            cin>>yearsToAdvance;
            retval = simulate(yearsToAdvance);
            if (retval != SUCCESS)
            {
                cout<<"ERROR: Could not simulate!"<<endl;
            }

        }
        else if (strcmp(userInput, "2") == 0)
        {
            /* View/Modify Parameters */
            char modifyOption[10];
            displayModifyMenu();
            cout<<"Select option to modify: ";
            cin>>modifyOption;
            retval = processModifyRequest(modifyOption);
        }

        else if (strcmp(userInput, "3") == 0)
        {
            /* Display Stats */
            retval = displayStats();
            if (retval != SUCCESS)
            {
                cout<<"ERROR: Could not display statistics!"<<endl;
            }
        }
        else if (strcmp(userInput, "0") == 0)
        {
            /* Quit */
            cout<<"Terminating application...\n"<<endl;
            break;
        }
       else
        {
            cout<<"Invalid choice!"<<endl;
        }

        //NOT USED: consistencyCheck();
    
    }

    return 0;
}
