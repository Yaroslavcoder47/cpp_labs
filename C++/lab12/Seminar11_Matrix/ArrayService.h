#pragma once

#ifndef ARRAYSERVICE_H
#define ARRAYSERVICE_H

#include <string>
#include <iostream>
#include "Array.h"

template<class T>
class ArrayService
{
protected:
    virtual T itemSum() { return 0; };
    virtual T findMinItem() { return 0; };
    virtual T findMaxItem() { return 0; };
    virtual int findIndexMinItem() { return 0; };
    virtual int findIndexMaxItem() { return 0; };
};
#endif // ARRAYONVECTORSERVICE_H