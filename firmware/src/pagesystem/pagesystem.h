#ifndef PAGESYSTEM_H
#define PAGESYSTEM_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "page.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PAGES 6
// #define DYNAMIC_PAGES    // if this is enabled, MAX_PAGES does nothing
                            // and uses pointers to dynamically increase pages
                            // todo: implement

#define PAGESYSTEM_FAST     // if this is enabled, some runtime code checking is disabled. Make
                            // sure that there are no bugs. Enabling this is less safe

// #define PAGESYSTEM_UNSAFE_SUPER_FAST     // if this is enabled, PAGESYSTEM_FAST will be
                                            // enabled and further runtime check is disabled
                                            // for performance. Enabling this is strongly
                                            // not recommended

#if defined(PAGESYSTEM_UNSAFE_SUPER_FAST) && !defined(PAGESYSTEM_FAST)
    #define PAGESYSTEM_FAST
#endif

typedef struct {

#ifndef DYNAMIC_PAGES
    Page_t pages[MAX_PAGES];
#else
    Page_t *pages;
    uint16_t maxPages;
#endif
    uint16_t numPages;
    
    Page_t *activePage;

    bool started;

    /* DO NOT TOUCH ANYTHING ABOVE THIS LINE */

    void *defaultParams;

    void (*preSwitch)();
    void (*midSwitch)();
    void (*postSwitch)();

    
} PageSystem_t;

/**
 * @brief Initialized a page system object
 * 
 * @param pgt Page system to initialize
 */
extern void PageSystem_init(PageSystem_t *pgt);

extern void PageSystem_start(PageSystem_t *pgt);

extern bool PageSystem_add_page(PageSystem_t *pgt, Page_t *page);

/**
 * @brief Finds a page in the PageSystem that matches the name. If found,
 *          then an attempt to switch to the page is performed.
 * 
 * @param pgt 
 * @param name 
 * @param args 
 * @return PageSystem_state 
 */
extern bool PageSystem_findSwitch(PageSystem_t *pgt, const char *name, void *args);

/**
 * @brief Switches to the desired page
 * 
 * @param pgt 
 * @param page Do NOT pass in NULL when PAGESYSTEM_FAST is defined
 * @return PageSystem_state 
 */
extern bool PageSystem_switch(PageSystem_t *pgt, Page_t *page, void *args);

/**
 * @brief Cleans up PageSystem_t resources. Once this is is called, the PageSystem
 *          passed will no longer be valid until it is re-initialized
 * 
 * @param pgt PageSystem to end / cleanup
 */
extern void PageSystem_end(PageSystem_t *pgt);

#ifdef __cplusplus
}
#endif

#endif
