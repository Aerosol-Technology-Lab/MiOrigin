#ifndef PAGE_H
#define PAGE_H

#define PAGE_NAME_SIZE 16

typedef void (*PageOperationFunction) (void *, void *);
typedef PageOperationFunction Page_onLoadFunction;
typedef void (*Page_onExitFunction)();
typedef void (*Page_onStartFunction)(void *);

typedef struct {
    char name[PAGE_NAME_SIZE];

    Page_onStartFunction onStart;
    Page_onLoadFunction onLoad;
    Page_onExitFunction onExit;
} Page_t;

#endif
