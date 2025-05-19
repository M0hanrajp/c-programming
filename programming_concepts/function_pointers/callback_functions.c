// A program to understand callback functions.
// refer mini_dbus_service/ for understanding of callbacks in real time use case scenario
/* A callback in C is a function that is provided to another function to "call back to" at some point when
            the other function is doing its task.
 * A callback function is usually used in dbus service/UI implementation to manage communications.
 * Usually a function registers a callback, when the main loop starts, the callback is registered.
 * Callback is triggered based on the events & signals reported by other processes.
 * A user context is also passed to the function that records context and states
 */

#include <stdio.h>
#include <stdlib.h> // exit
#include <unistd.h> // usleep


// Holds mutable state that the callback can update.
typedef struct {
    int counter;
} myObject;

// Signature for any function that handles an “event.”
typedef void (*eventHandler)(int eventId, myObject *ctx);

// creates the object
myObject createMyObject(void) {
    myObject ctx;
    ctx.counter = 0;
    printf("object created, counter = %d\n", ctx.counter);
    return ctx;
}

// register the event handler
static myObject *userCtx = NULL;
static eventHandler regCallback = NULL;
void registerEventHandler(eventHandler cb, myObject *ctx) {
    userCtx = ctx;
    regCallback = cb;
    printf("[%s] Handler registered\n", __func__);
}

// destroyes the object
void destroyMyObject(myObject *ctx) {
    printf("object state: %p, destroying object...\n", userCtx);
    usleep(500000);
    ctx->counter = 0;
    printf("object destroyed, counter is invalid, final user data state = %d\n", ctx->counter);
}

// unregister the event handler, clear the locals
void unregisterEventHandler(eventHandler cb, myObject *ctx) {
    userCtx = NULL;
    regCallback = NULL;
    printf("[%s] Handler unregistered\n", __func__);
}

// Increments the counter, the callback function that is registered.
// This is synchronous callback
void onMessage(int eventId, myObject *ctx) {
    ctx->counter++;
    printf("%s: received event %2d, counter now %2d\n", __func__, eventId, ctx->counter);
}

// Emits event based on the user context and registered callback
void emitEvent(int eventId) {
    if(userCtx != NULL && regCallback != NULL) {
        regCallback(eventId, userCtx);
    } else {
        printf("No handler registered for event id = %d\n", eventId);
        exit(-1);
    }
}

// create the events
void runMainLoop(void) {
    printf("[%s] starts!\n", __func__);
    int retCode = 1;
    for(int eventId = 1; eventId < 9; eventId++) {
        retCode = usleep(500000);
        !retCode ? printf("program sleeps for 500ms\n") : printf("usleep failed\n");
        emitEvent(eventId);
    }
}

// driver code
int main(void) {
    myObject userData = createMyObject();
    // register onMessage as the callback which updates the counter, pass the address of userData
    registerEventHandler(onMessage, &userData);
    
    runMainLoop();
    unregisterEventHandler(onMessage, &userData);
    destroyMyObject(&userData); // userData stays valid as it's on main stack, we make globals NULL
    
    runMainLoop();
    return 0;
}

// output
/*
s$ ./a.out
object created, counter = 0
[registerEventHandler] Handler registered
[runMainLoop] starts!
program sleeps for 500ms
onMessage: received event  1, counter now  1
program sleeps for 500ms
onMessage: received event  2, counter now  2
program sleeps for 500ms
onMessage: received event  3, counter now  3
program sleeps for 500ms
onMessage: received event  4, counter now  4
program sleeps for 500ms
onMessage: received event  5, counter now  5
program sleeps for 500ms
onMessage: received event  6, counter now  6
program sleeps for 500ms
onMessage: received event  7, counter now  7
program sleeps for 500ms
onMessage: received event  8, counter now  8
[unregisterEventHandler] Handler unregistered
object state: (nil), destroying object...
object destroyed, counter is invalid, final user data state = 0
[runMainLoop] starts!
program sleeps for 500ms
No handler registered for event id = 1
*/

/*
 * Callback Registration & Invocation
 *
 * In many DBus services, UI frameworks, or asynchronous systems,
 * callbacks are the primary mechanism for notifying your code
 * about events (messages, user actions, state changes, etc.).
 *
 * 1. Registration
 *    - At startup (or when a subsystem is initialized), your code
 *      registers a callback handler:
 *          register_event_handler(on_event, user_context);
 *    - The handler signature typically includes a context pointer
 *      so each callback can carry its own state:
 *          typedef void (*EventHandler)(Event *evt, void *context);
 *
 * 2. Invocation
 *    - When an event occurs (e.g. a DBus signal arrives, or
 *      a user clicks a button), the framework:
 *          if (handler != NULL) {
 *              handler(&event, context);
 *          }
 *    - Always check for NULL handlers before invoking to avoid crashes.
 *
 * 3. User Context
 *    - The `void *context` lets you pass in anything you need:
 *        • Object instances
 *        • Connection handles
 *        • State flags
 *    - Ensures your callback is re-entrant and thread-safe, if required.
 *
 * 4. Unregistration & Cleanup
 *    - If a component shuts down, unregister its callback:
 *          unregister_event_handler(on_event, user_context);
 *    - Prevents “dangling” callbacks into freed memory.
 *
 * 5. Threading & Concurrency
 *    - If callbacks can fire from multiple threads, protect shared
 *      data with mutexes or use thread-affinity queues.
 *
 * 6. Error Handling
 *    - Callback implementations should never long-jmp or throw—
 *      always return cleanly and report errors via return codes
 *      or secondary callbacks (e.g. error handlers).
 *
 * By following these conventions, your callback-driven code remains
 * clear, safe, and maintainable.
 */
