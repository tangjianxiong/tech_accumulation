#include <stdio.h>

#define BB

#ifdef AA

#define HELLO "hello world"

#elif BB

#define HELLO "hello CC"

#endifint main()

{

printf("%s\n",HELLO);

return 1;

}