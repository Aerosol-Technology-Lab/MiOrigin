#ifndef PAGE_H
#define PAGE_H

#include <stddef.h>
#include <string.h>

#define PAGE_NAME_SIZE 16
#define CALIBRATION_PAGE_NAME "calibration"

typedef void (*PageOperationFunction) (void *, void *);
typedef PageOperationFunction Page_onLoadFunction;
typedef void (*Page_onExitFunction)();
typedef void (*Page_onStartFunction)(void *);

typedef struct {
    char name[PAGE_NAME_SIZE];

    void *params;

    Page_onStartFunction onStart;
    Page_onLoadFunction onLoad;
    Page_onExitFunction onExit;
} Page_t;

static void Page_init(Page_t *page)
{
    strncpy(page->name, "", PAGE_NAME_SIZE);
    page->params = NULL;
    page->onStart = NULL;
    page->onLoad = NULL;
    page->onExit = NULL;
}

#endif
