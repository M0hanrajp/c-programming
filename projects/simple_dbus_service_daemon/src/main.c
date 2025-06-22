#include <stdio.h>
#include <stdlib.h>
#include "daemon.h"

int main(void) {

    // https://docs.gtk.org/glib/ctor.MainLoop.new.html
    GMainLoop *loop = g_main_loop_new(NULL, FALSE);

    /* [1] Request is sent to message bus to own name
     */
    guint busId = 0;
    const gchar *busName = "com.mpunixDaemon";
    busId = g_bus_own_name(
    /* GBusType bus_type */ G_BUS_TYPE_SESSION,
    /* const gchar *name */ busName,
    /* GBusNameOwnerFlags flags */ G_BUS_NAME_OWNER_FLAGS_DO_NOT_QUEUE,
    /* GBusAcquiredCallback bus_acquired_handler */ onBusAcquiredHandler,
    /* GBusNameAcquiredCallback name_acquired_handler */ onNameAcquiredHandler,
    /* GBusNameLostCallback name_lost_handler */ onNameLostHandler,
    /* gpointer user_data */ NULL,
    /* GDestroyNotify user_data_free_func */ NULL
    );

    if(busId == 0) {
        printf("[%s]: failed to create daemon\n", busName);
        exit(-1);
    }

    // Run the daemon
    // https://docs.gtk.org/glib/method.MainLoop.run.html
    printf("[INFO]: g_main_loop_run is invoked\n");
    g_main_loop_run(loop);

    g_bus_unown_name(busId);
    // https://docs.gtk.org/glib/method.MainLoop.unref.html
    g_main_loop_unref(loop);
    return 0;
}
