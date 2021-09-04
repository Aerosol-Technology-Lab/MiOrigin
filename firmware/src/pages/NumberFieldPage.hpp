#pragma once

#include "../pagesystem/page.h"
#include <stdint.h>

#define PAGES_NUMBERFIELDPAGE_NAME "numfield"
#define PAGES_NUMBERFIELDPAGE_LABEL_SIZE 10
#define PAGES_NUMBERFIELDPAGE_POSTFIX_SIZE 10
class _NumberFieldPage
{
public:
    typedef struct {
        int32_t *value;
        char label[PAGES_NUMBERFIELDPAGE_LABEL_SIZE];
        char postfix[PAGES_NUMBERFIELDPAGE_LABEL_SIZE];
        char returnPageName[PAGE_NAME_SIZE];
    } Props_t;

private:
    Props_t *props;

public:
    static Page_t page;

    _NumberFieldPage();

    static void onStart(void *);
    static void onLoad(void *, void *);
    static void onExit();

    static void generatePage(Page_t &page);
    static Page_t generatePage();

    static void ts_onPress();
    static void ts_onRelease();
    // static void generatePage(Page_t &page)
};

extern _NumberFieldPage NumberFieldPage;
