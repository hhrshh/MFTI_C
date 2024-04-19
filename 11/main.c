#include <stdlib.h>
#include "main.h"
#include "temp.h"


int main(int argc, char* argv[])
{
    struct sensors data[SIZE];
    print(data, add_info_sensors(data));
    return 0;
}