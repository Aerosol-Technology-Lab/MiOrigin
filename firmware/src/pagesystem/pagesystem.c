#ifdef __cplusplus
extern "C"
{
#endif

#include "pagesystem.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "cpp_wrapper.h"

void PageSystem_init(PageSystem_t *pgt)
{
#ifdef DYNAMIC_PAGES
    pgt->pages = NULL;    
#else
    memset(pgt->pages, 0, sizeof(pgt->pages));
#endif

    pgt->numPages = 0;
    pgt->activePage = NULL;
    pgt->defaultParams  = NULL;
    pgt->preSwitch      = NULL;
    pgt->midSwitch      = NULL;
    pgt->postSwitch     = NULL;
}

void PageSystem_start(PageSystem_t *pgt)
{
    size_t i;
    for (i = 0; i < pgt->numPages; ++i) {
        cprintln("Hello");
        if (pgt->pages[i].onStart) pgt->pages[i].onStart(pgt->defaultParams);
    }
    pgt->started = true;
}

bool PageSystem_add_page(PageSystem_t *pgt, Page_t *page)
{
#ifdef DYNAMIC_PAGES
    // todo fix this while loop because it is inefficient
    while (1) {
        if (pgt->numPages >= pgt->maxPages) {
            Page_t *oldPages = pgt->pages;
            pgt->pages = malloc(sizeof(*pgt->pages) * (pgt->maxPages + 1));
            memcpy(pgt->pages, oldPages, sizeof(*pgt->pages) * pgt->maxPages);
            free(oldPages);
            pgt->maxPages++;
        }
        else {
            break;
        }
    }

#else
    
    if (pgt->numPages >= MAX_PAGES) {
        cprintln("Error: Cannot add anymore pages!");
        return false;
    }
#endif

    pgt->pages[pgt->numPages] = *page;
    ++(pgt->numPages);
    
    if (pgt->started && page->onStart) {
        page->onStart(pgt->defaultParams);
    }

    return true;
}

bool PageSystem_findSwitch(PageSystem_t *pgt, const char *name, void *args)
{
    uint16_t i;
    cprintln("Searching for page...");
    for (i = 0; i < pgt->numPages; ++i) {
        cprintln("Searching...");
        if (!strcmp(pgt->pages[i].name, name)) {
            cprintln("Found!");
            return PageSystem_switch(pgt, &pgt->pages[i], args);
        }
    }

    if (name) {

        char buffer[32] = { 0 };
        strncpy(buffer, name, sizeof(buffer) / sizeof(buffer[0]) - 1);
        char msg[64];
        sprintf(msg, "Cannot find the page \"%sbuffer\"", buffer);
        cprintln(msg);
    }

    cprintln("Cannot find the page!");
    return false;
}

bool PageSystem_switch(PageSystem_t *pgt, Page_t *page, void *args)
{
    pgt->stagedPage = page;
    pgt->stagedArgs = args;
}

void PageSystem_execute_switch(PageSystem_t *pgt)
{
    if (pgt->stagedPage) {
        cprintln("Pre switch");
        if (pgt->preSwitch) pgt->preSwitch();
        
        #ifndef PAGESYSTEM_FAST
        if (page == NULL) {
            return PAGESYSTEM_FAIL;
        }
        #endif

        cprintln("on exit");
        if (pgt->activePage != NULL) {
            pgt->activePage->onExit();
        }

        cprintln("mid switch");
        if (pgt->midSwitch) pgt->midSwitch();
        
        cprintln("on load");
        pgt->activePage = pgt->stagedPage;
        pgt->activePage->onLoad(pgt->defaultParams, pgt->stagedArgs);
        pgt->stagedPage = NULL;
        pgt->stagedArgs = NULL;

        cprintln("post switch");
        if (pgt->postSwitch) pgt->postSwitch();

        cprintln("done");
        return true;
    }
}

void PageSystem_end(PageSystem_t *pgt)
{
#ifdef DYNAMIC_PAGES
    free(pages);
#endif
}

#ifdef __cplusplus
}
#endif
