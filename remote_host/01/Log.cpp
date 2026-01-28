//
// Created by 71702 on 2024/12/20.
//
#include <stdio.h>
#include <stdlib.h>
#include "Log.h"
void err(bool condition, const char *errmsg){
    if(condition){
        perror(errmsg);
        exit(EXIT_FAILURE);
    }
}
