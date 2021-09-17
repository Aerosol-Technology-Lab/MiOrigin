#pragma once

#include <stdint.h>
#include <stddef.h>
#include "../pagesystem/page.h"

#define PAGES_NUMBERFIELDPAGE_LABEL_SIZE 10
#define PAGES_NUMBERFIELDPAGE_POSTFIX_SIZE 10

namespace NumberFieldDefs
{
    typedef void (*ChangeValue_f)(void *props, int8_t c);
    typedef void (*GetValue_f)(void *props, char * buffer, size_t size);
    typedef void (*ClearValue_f)(void *_props);

    typedef struct {
        void *value;
        char label[PAGES_NUMBERFIELDPAGE_LABEL_SIZE];
        char postfix[PAGES_NUMBERFIELDPAGE_LABEL_SIZE];
        char returnPageName[PAGE_NAME_SIZE];
        void *returnPageArgs;

        ChangeValue_f changeValue;
        GetValue_f getValue;
        ClearValue_f clearValue;
    } Props_t;
}
