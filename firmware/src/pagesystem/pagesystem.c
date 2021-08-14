#include "pagesystem/pagesystem.h"
#include <stdlib.h>
#include <stdbool.h>

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
    for (size_t i = 0; i < pgt->numPages; ++i) {
        if (pgt->pages[i].onStart) pgt->pages[i].onStart(pgt->defaultParams);
    }
}

PageSystem_state PageSystem_add_page(PageSystem_t *pgt, Page_t *page)
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
        return PAGESYSTEM_FAIL;
    }
#endif

    pgt->pages[pgt->numPages] = *page;
    ++pgt->numPages;
    
    if (pgt->started && page->onStart) {
        page->onStart(pgt->defaultParams);
    }

    return PAGESYSTEM_SUCESS;
}

PageSystem_state PageSystem_findSwitch(PageSystem_t *pgt, char *name, void *args)
{
    uint16_t i;
    for (i = 0; i < pgt->numPages; ++i) {
        if (!strcmp(pgt->pages[i].name, name)) {
            return PageSystem_switch(pgt, &pgt->pages[i], args);
        }
    }

    return PAGESYSTEM_FAIL;
}

PageSystem_state PageSystem_switch(PageSystem_t *pgt, Page_t *page, void *args)
{
    if (pgt->preSwitch) pgt->preSwitch();
    
#ifndef PAGESYSTEM_FAST
    if (page == NULL) {
        return PAGESYSTEM_FAIL;
    }
#endif

    if (pgt->activePage != NULL) {
        pgt->activePage->onExit();
    }

    if (pgt->midSwitch) pgt->midSwitch();
    
    pgt->activePage = page;
    page->onLoad(pgt->defaultParams, args);

    if (pgt->postSwitch) pgt->postSwitch();

    return PAGESYSTEM_SUCESS;
}

void PageSystem_end(PageSystem_t *pgt)
{
#ifdef DYNAMIC_PAGES
    free(pages);
#endif
}
