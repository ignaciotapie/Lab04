#include "../h/ControladorReloj.h"

ControladorReloj* ControladorReloj::instance = NULL;

ControladorReloj* ControladorReloj::getInstance()
{
    if (!instance)
    {
        instance = new ControladorReloj();
    }
    return instance;
}