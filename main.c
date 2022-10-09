#include "forca.h"
#include <stdio.h>

int main()
{
    escolhePalavra();
    abertura();

    do
    {
        desenhaForca();
        chuta();

    } while (!acertou() && !enforcou());

} 