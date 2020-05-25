/*Enum example*/

#include <iostream>

using namespace std;

int main()
{
    //define MONTHS as having 12 possible values
 typedef enum {Jan = 0x01, Feb = 0x02, Mar = 0x03, Apr = 0x04, May = 0x05, Jun = 0x06, Jul = 0x07, Aug = 0x08, Sep = 0x09, Oct = 0x0A, Nov = 0x0B, Dec = 0x0C} MONTHS;

 typedef enum{first = 0x00, second = 0x01} evar_t;
    
    //define bestMonth as a variable type MONTHS
    MONTHS bestMonth;
    evar_t v{first};
    
    //assign bestMonth one of the values of MONTHS
    bestMonth = Jan;
    
    //now we can check the value of bestMonths just 
    //like any other variable
    if(bestMonth == Jan || first == v)
    {
        cout<<"I'm not so sure January is the best month\n";
    }

    cout << "size of evar " << sizeof(evar_t) << "\n";
    return 0;
}
